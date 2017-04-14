// prc.c
//
// Routines for writing a Pilot PRC file
//
// Description:
// The functions in this file are used to write a Pilot PRC format
// executable (application) file.  In the absence of any official
// documentation on the PRC and executable image format I have been
// forced to make some guesses about the file structure based on what
// I've been able to discover from available PRC files.  Some of my
// guesses are probably flawed but until I can get my hands on some
// official documentation this is the best I can do.
//
// Author: Darrin Massena (darrin@massena.com)
// Date: 6/24/96

#include "pila.h"
#include "prc.h"
#ifndef unix
#include <windows.h>
#endif

#ifdef unix
typedef unsigned long DWORD;
typedef long int LONG;
typedef short int WORD;
typedef char BYTE;

typedef struct {
	DWORD  biSize;
	LONG   biWidth;
	LONG   biHeight;
	WORD   biPlanes;
	WORD   biBitCount;
	DWORD  biCompression;
	DWORD  biSizeImage;
	LONG   biXPelsPerMeter;
	LONG   biYPelsPerMeter;
	DWORD  biClrUsed;
	DWORD  biClrImportant;
} BITMAPINFOHEADER;

typedef struct {
	BYTE    rgbBlue;
	BYTE    rgbGreen;
	BYTE    rgbRed;
	BYTE rgbReserved;
} RGBQUAD;

typedef struct {
	BITMAPINFOHEADER bmiHeader;
	RGBQUAD          bmiColors[1];
} BITMAPINFO;
#endif


/////////////////////////////////////////////////////////////////////////////

extern char gfPass2;
extern int gfResourcesOnly;
extern long gcbResTotal;
long gcbDataCompressed;

#define kcbPrcMax	(512 * 1024)	// 512k should be plenty
#define kcrmeMax	1000			// 1000 resources should be enough

#define offsetof(s,m)  (ulong)&(((s *)0)->m)

ResourceMapEntry garme[kcrmeMax];
long gcrme;
byte gpbPrc[kcbPrcMax];
long gcbPrc;
FourCC gfcAppId = 'TEMP';


bool CompressData(byte *pbData, ulong cbData, ulong cbUninitData,
                  byte **ppbCompData, ulong *pcbCompData);
bool ConvertResource(ulong ulTypeOriginal, byte *pbResData,
                     ResourceMapEntry *prme);

/////////////////////////////////////////////////////////////////////////////

bool AddResource(FourCC fcType, ushort usId, byte *pbData, ulong cbData,
                 bool fHead)
{
    ResourceMapEntry *prme;

    if (!gfPass2)
        return TRUE;

    if (fHead) {
        prme = garme;
        memmove(prme + 1, prme, sizeof(ResourceMapEntry) * gcrme);
    } else {
        prme = &garme[gcrme];
    }

    prme->fcType = fcType;
    prme->usId = usId;
    //	prme->pbData = pbData;
    prme->cbData = cbData;
    gcrme++;

    //

    if (gfResourcesOnly) {
        prme->pbData = malloc(cbData);
        memcpy(prme->pbData, pbData, cbData);
    } else {
        if (!ConvertResource(fcType, pbData, prme))
            return FALSE;
    }

    gcbResTotal += cbData + 10;     // 10 bytes = resource map overhead

    return TRUE;
}

/////////////////////////////////////////////////////////////////////////////


// cbData = cbA + cbB;
// a5 = new byte[cbData] + cbB;
// *a5 = SysAppInfoPtr

struct CodeZeroResource {
    ulong cbA;      // Initialized data size
    ulong cbB;      // Uninitialized data size
} czr;

long WritePrc(char *pszFileName, char *pszAppName, byte *pbCode, long cbCode,
              byte *pbData, long cbData)
{
    extern bool LayoutPrc(char *pszFilename, char *pszAppName);
    bool fSuccess;
    FILE *pfilOut;
    char szName[_MAX_PATH];
    long cbRes;

    if (!gfResourcesOnly) {
        //
        // Add resources for code, data info, and data.
        //

        if (cbData != 0)
            AddResource('data', 0x0000, pbData, cbData, TRUE);

        // Write the mystery 'code' 0000 resource.

        // FIX:
        czr.cbA = ReverseLong(cbData);
        czr.cbB = ReverseLong(0);

        AddResource('code', 0x0000, (byte *)&czr, sizeof(czr), TRUE);

        // Write the real 'code' resource.

        AddResource('code', 0x0001, pbCode, cbCode, TRUE);
    }

    // Create file for writing.

    pfilOut = fopen(pszFileName, "wb");
    if (pfilOut == NULL || pfilOut == (FILE *)-1) {
        printf("Error: Can't open output file \"%s\"\n", pszFileName);
        return 0;
    }

    if (pszAppName == NULL || *pszAppName == 0) {
#ifdef unix
        pszAppName = strrchr(szName, '/');
        if (pszAppName == NULL)
            pszAppName = szName;
        else
            pszAppName++;
#else
        _splitpath(pszFileName, NULL, NULL, szName, NULL);
        pszAppName = szName;
#endif
    }

    if (strlen(pszAppName) > 31) {
        printf("Error: Application name %s is too long. 31 characters max.\n",
               pszAppName);
        return 0;
    }

    fSuccess = LayoutPrc(pszFileName, pszAppName);
    if (fSuccess)
        fSuccess = fwrite(gpbPrc, gcbPrc, 1, pfilOut) == 1;

    cbRes = ftell(pfilOut);
    fclose(pfilOut);
    return cbRes;
}


/////////////////////////////////////////////////////////////////////////////

byte abHeader1[] = {
    0x00, 0x01, 0x00, 0x01
};

byte abHeader2[] = {
    0xad, 0xc0, 0xbe, 0xa0,
    0xad, 0xc0, 0xbe, 0xa0,
    0x00, 0x00, 0x00, 0x00
};

byte abAppType[] = {
    'a', 'p', 'p', 'l'
};

byte abHeader4[] = {
    0x28, 0x00, 0x00, 0x00, 0x00, 0x00
};

/////////////////////////////////////////////////////////////////////////////

bool LayoutPrc(char *pszFilename, char *pszAppName)
{
    extern FourCC gfcPrcType;

    byte *pbT, *pbResData;
    ResourceMapEntry *prme;
    int i;
    ulong ulT;

    //
    // Here we go!
    //

    // Initialize the output buffer to all zeros.

    memset(gpbPrc, 0, kcbPrcMax);

    // Sneak "Pila" into the (most likely) unused app name space.

    *(ulong *)&gpbPrc[28] = 'aliP';

    // The first 32 bytes of a PRC is the filename.

    strcpy((char *)gpbPrc, pszAppName);

    // The next 4 bytes are a mystery.  Following is the sequence
    // found on all but one PRC EXE file (WorldTime) but not the same
    // on non-EXE PRC files.

    memcpy(gpbPrc + 0x20, abHeader1, 4);

    // The next 3 entries are timestamps of some sort.  The timestamps
    // found on PRC EXEs are not in the valid time range!  The ones on
    // files backed up from the Pilot are (e.g., Giraffe_High_Scores.prc)
    // valid.

    // For now, copy Puzzle's timestamps.

    memcpy(gpbPrc + 0x24, abHeader2, 3 * 4);

    // File type and id

    ulT = ReverseLong(gfcPrcType);
    memcpy(gpbPrc + 0x3c, &ulT, 4);
    ulT = ReverseLong(gfcAppId);
    memcpy(gpbPrc + 0x40, &ulT, 4);

    // Another unknown string of 6 bytes of zeros preceding the resource
    // map.

    memcpy(gpbPrc + 0x44, abHeader4, 6);

    // Write the resource map.  Each entry is 10 bytes long in the format:
    // FourCC type (4), ushort id (2), ulong ulOffset (4)

    pbT = gpbPrc + 0x4e;
    pbResData = pbT + (10 * gcrme) + 2;
    prme = garme;
    for (i = 0; i < gcrme; i++, prme++) {
        ushort usT;
        ulong ulT;

        // Copy the resource type to the resource map

        ulT = ReverseLong(prme->fcType);
        memcpy(pbT, &ulT, 4);

        // Copy the resource id to the resource map

        usT = SwapBytes(prme->usId);
        memcpy(pbT + 4, &usT, 2);

        // Copy the offset to the resource data in the resource map

        ulT = ReverseLong(pbResData - gpbPrc);
        memcpy(pbT + 6, &ulT, 4);

        // Copy the resource data to the appropriate offset

        memcpy(pbResData, prme->pbData, prme->cbData);

        // Point to the next available resource map and data destination.

        pbT += 10;
        pbResData += prme->cbData;
    }

    // 4 bytes (might actually only supposed to be 2 bytes with the other
    // 2 being part of the abHeader4 range) count of resources.

    ulT = ReverseLong(gcrme);
    memcpy(gpbPrc + 0x4a, &ulT, 4);

#if 0	// We initialize memory to 0 so these are already filled

    // Following the resource map there are 2 bytes which have been
    // zero in all the PRC's I've examined so far.

    byte abHeader5[] = {
        0x00, 0x00
    };
    memcpy(pbT, abHeader5, 2);
#endif

    gcbPrc = pbResData - gpbPrc;

    return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
//
// This information was sent to me by Steve Lemke (a Palm Computing
// developer).
//
// Here's the structure of a Metrowerks DATA 0 resource:
//
// +---------------------------------+
// | long:   offset of CODE 1 xrefs  |---+
// +---------------------------------+   |
// | char[]: compressed init data    |   |
// +---------------------------------+   |
// | char[]: compressed DATA 0 xrefs |   |
// +---------------------------------+   |
// | char[]: compressed CODE 1 xrefs |<--+
// +---------------------------------+

bool CompressData(byte *pbData, ulong cbData, ulong cbUninitData,
                  byte **ppbCompData, ulong *pcbCompData)
{
    long lOffset;

    // Allocate a temporary compression buffer.

    byte *pbCompBuffer = (byte *)malloc(
            (cbData * 2) + (3 * 5) + (6 * sizeof(ulong)) + 40);   // +40 is just in case
    byte *pbComp = pbCompBuffer;

    // The first ulong in a 'data' resource is an offset to the compressed
    // CODE 1 xrefs. In PalmOS 1.0 it appears to be unused by the loader.

    *(ulong *)pbComp = ReverseLong(cbData);
    pbComp += 4;

    //
    // NOTE: Read this fascinating PalmOS tidbit and corresponding workaround
    //
    // After the PalmOS loads an application the application startup code calls
    // it back (SysAppStartup) to allocate dynamic memory for its data section,
    // point A5 to the dynamic memory, then decompress the stored data into it.
    // After allocating and initializing A5 but before decompressing
    // SysAppStartup stuffs a pointer to the app's SysAppInfo structure at the
    // location pointed to by A5.
    //
    // This is a problem because the Pila data section decompresses at the
    // address pointed to by A5, overwriting the SysAppInfo pointer. Apparently
    // PalmOS APIs (at least the Frm* APIs) need the SysAppInfo pointer and
    // look for it hanging off A5 so the nasty side-effect of this collision
    // are some interesting (and somewhat random, depending on what data
    // values are decompressed) crashes.
    //
    // The fix is to force decompression to start at A5+4 (skipping the
    // SysAppInfo pointer). No problem, the PalmOS DecompressData routine has
    // a facility for such things. We can't just change move the data by
    // 4 bytes though because the assembled code assumes the data is based
    // at A5. So we include a unused dummy long of data in the Startup.inc
    // code. Assuming the first long is unused, this code skips it and sets
    // things up so the rest of the data will be decompressed from there.
    //

    lOffset = 4;    // skip first 4 bytes where SysAppInfo* will be stored
    cbData -= 4;
    pbData += 4;

    // The second ulong in a 'data' resource is the offset from A5
    // (positive or negative) that the data should be stored at.

    *(ulong *)pbComp = ReverseLong(lOffset);
    pbComp += 4;

    // Compress the data.
    // LATER: this doesn't actually compress anything, just copies in the
    // format Pilot understands (enhanced RLE) as a series of non-repeating
    // data runs.

    while (cbData > 0) {
        byte cbT = (byte)((cbData < 0x80) ? cbData : 0x80);
        *pbComp++ = (cbT - 1) | 0x80;
        memcpy(pbComp, pbData, cbT);
        pbComp += cbT;
        pbData += cbT;
        cbData -= cbT;
    }

    // The decompressor expects 3 groups of { a5offset, compressed stream }
    // separated by a 0 byte. This code fills out the remainder.

    *pbComp++ = 0;

    *(ulong *)pbComp = 0;
    pbComp += sizeof(ulong);
    *pbComp++ = 0;

    *(ulong *)pbComp = 0;
    pbComp += sizeof(ulong);
    *pbComp++ = 0;

    // An additional six ulongs of zero

// From Steve Lemke (Palm):
// "However, this DATA 0 resource SHOULD contain an additional SIX
// longwords each set to zero to specify that each of the sub-blocks of
// relocation data (three sub-blocks in the DATA 0 xrefs section and three
// sub-blocks in the CODE 1 xref section) contains no xrefs.  The first
// longword in each of the six sub-blocks is a count of that sub-block's xrefs."

    memset(pbComp, 0, 6 * sizeof(ulong));
    pbComp += 6 * sizeof(ulong);

    // Copy the compressed results to a right-sized buffer.

    *pcbCompData = pbComp - pbCompBuffer;
    *ppbCompData = (byte *)malloc(*pcbCompData);
    memcpy(*ppbCompData, pbCompBuffer, *pcbCompData);

    // Free temp compression buffer.

    free(pbCompBuffer);

    gcbDataCompressed = pbComp - pbCompBuffer;

    return TRUE;
}

/////////////////////////////////////////////////////////////////////////////

// Test bit in a 1bpp bitmap

bool TestBit(int cx, int cy, byte *pb, int x, int y, int cBitsAlign)
{
    int cbRow = (cx + (cBitsAlign - 1)) & ~(cBitsAlign - 1);
    pb += (cbRow >> 3) * y + (x >> 3);
    return (*pb & (1 << (7 - (x & 7))));
}

// Set bit in a 1bpp bitmap

void SetBit(int cx, int cy, byte *pb, int x, int y, int cBitsAlign)
{
    int cbRow = (cx + (cBitsAlign - 1)) & ~(cBitsAlign - 1);
    pb += (cbRow >> 3) * y + (x >> 3);
    *pb |= (1 << (7 - (x & 7)));
}

/////////////////////////////////////////////////////////////////////////////

// Pilot bitmap resource format

typedef struct _Bitmap { // bm
    ushort cx;
    ushort cy;
    ushort cbRow;
    ushort ff;
    ushort ausUnk[4];
    byte abBits[1];
} Bitmap;

bool ConvertBitmapResource(byte *pbResData, ResourceMapEntry *prme)
{
    byte *pbSrc;
    int cbDst, cbRow;
    Bitmap *pbmDst;
    int x, y;

#ifndef unix
    BITMAPINFO *pbmi = (BITMAPINFO *)(pbResData + sizeof(BITMAPFILEHEADER));
#else
    BITMAPINFO *pbmi = (BITMAPINFO *)(pbResData + 14);
#endif
    pbSrc = ((byte *)pbmi) + pbmi->bmiHeader.biSize +
            sizeof(RGBQUAD) * 2;

    // If image not 1bpp, bail	

    if (pbmi->bmiHeader.biBitCount != 1) {
        printf("Bitmap not 1 bpp!");
        return FALSE;
    }

    // Alloc what we need for image data
    // Pilot images are word aligned

    cbRow = ((pbmi->bmiHeader.biWidth + 15) & ~15) / 8;
    cbDst = cbRow * pbmi->bmiHeader.biHeight + offsetof(Bitmap, abBits);
    pbmDst = (Bitmap *)malloc(cbDst);

    // Image data has been inverted for Macintosh, so invert back

    memset(pbmDst, 0, cbDst);

    // Convert from source bitmap format (dword aligned) to dst format (word
    // aligned).

    for (y = 0; y < pbmi->bmiHeader.biHeight; y++) {
        for (x = 0; x < pbmi->bmiHeader.biWidth; x++) {
            // Reverse bits so we get WYSIWYG in msdev (white
            // pixels become background (0), black pixels become
            // foreground (1)).

            int yT = y;
            if (pbmi->bmiHeader.biHeight > 0)
                yT = pbmi->bmiHeader.biHeight - y - 1;

            if (!TestBit(pbmi->bmiHeader.biWidth, pbmi->bmiHeader.biHeight,
                         pbSrc, x, yT, 32)) {
                SetBit(pbmi->bmiHeader.biWidth, pbmi->bmiHeader.biHeight,
                       &pbmDst->abBits[0], x, y, 16);
            }
        }
    }
    pbmDst->cx = SwapBytes((ushort)pbmi->bmiHeader.biWidth);
    pbmDst->cy = SwapBytes((ushort)pbmi->bmiHeader.biHeight);
    pbmDst->cbRow = SwapBytes(cbRow);

    // Update resource entry with new pos / size

    prme->pbData = (byte *)pbmDst;
    prme->cbData = cbDst;

    // Special case: if bitmap id is 7FFE, make it the app
    // icon

    if (prme->usId == 0x7FFE) {
        prme->fcType = 'tAIB';
        prme->usId = 1000;

        // Make sure it's the right size / height

        if (abs(pbmi->bmiHeader.biHeight) !=32 || pbmi->bmiHeader.biWidth != 32) {
            printf("Icon resource not 32x32!\n");
            return FALSE;
        }
    } else {
        prme->fcType = 'Tbmp';
    }

    return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// - Compresses 'data' resource
// - Converts 'WBMP' resources to either 'tBMP' or 'tAIB'

bool ConvertResource(ulong ulTypeOriginal, byte *pbResData,
                     ResourceMapEntry *prme)
{
    switch (ulTypeOriginal) {
    case 'data':
        // Compress the 'data' data before adding it.

        CompressData(pbResData, prme->cbData, 0, &prme->pbData,
                     &prme->cbData);
        break;

    case 'WBMP':
        if (!ConvertBitmapResource(pbResData, prme))
            return FALSE;
        break;

    default:
        // No conversion, just copy

        prme->pbData = malloc(prme->cbData);
        memcpy(prme->pbData, pbResData, prme->cbData);
        break;
    }

    return TRUE;
}
