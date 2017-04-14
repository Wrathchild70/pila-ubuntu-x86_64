# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101
# TARGTYPE "Macintosh Application" 0x0301

!IF "$(CFG)" == ""
CFG=PilA - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to PilA - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "PilA - Win32 Release" && "$(CFG)" != "PilA - Win32 Debug" &&\
 "$(CFG)" != "PilA - Macintosh Release" && "$(CFG)" != "PilA - Macintosh Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "pila.mak" CFG="PilA - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "PilA - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "PilA - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "PilA - Macintosh Release" (based on "Macintosh Application")
!MESSAGE "PilA - Macintosh Debug" (based on "Macintosh Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "PilA - Win32 Debug"

!IF  "$(CFG)" == "PilA - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\Release
INTDIR=.\Release

ALL : "$(OUTDIR)\pila.exe"

CLEAN : 
	-@erase "$(INTDIR)\assemble.obj"
	-@erase "$(INTDIR)\build.obj"
	-@erase "$(INTDIR)\codegen.obj"
	-@erase "$(INTDIR)\directiv.obj"
	-@erase "$(INTDIR)\error.obj"
	-@erase "$(INTDIR)\eval.obj"
	-@erase "$(INTDIR)\globals.obj"
	-@erase "$(INTDIR)\instlook.obj"
	-@erase "$(INTDIR)\insttabl.obj"
	-@erase "$(INTDIR)\lex.obj"
	-@erase "$(INTDIR)\listing.obj"
	-@erase "$(INTDIR)\main.obj"
	-@erase "$(INTDIR)\movem.obj"
	-@erase "$(INTDIR)\object.obj"
	-@erase "$(INTDIR)\opparse.obj"
	-@erase "$(INTDIR)\pp.obj"
	-@erase "$(INTDIR)\PRC.obj"
	-@erase "$(INTDIR)\symbol.obj"
	-@erase "$(OUTDIR)\pila.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

F90=fl32.exe
# ADD BASE F90 /I "Release/"
# ADD F90 /I "Release/"
F90_PROJ=/I "Release/" /Fo"Release/" 
F90_OBJS=.\Release/

.for{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

.f{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

.f90{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

CPP=cl.exe
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS"\
 /Fp"$(INTDIR)/pila.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\.

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

MTL=mktyplib.exe
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/pila.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# SUBTRACT LINK32 /pdb:none
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:console /incremental:no\
 /pdb:"$(OUTDIR)/pila.pdb" /machine:I386 /out:"$(OUTDIR)/pila.exe" 
LINK32_OBJS= \
	"$(INTDIR)\assemble.obj" \
	"$(INTDIR)\build.obj" \
	"$(INTDIR)\codegen.obj" \
	"$(INTDIR)\directiv.obj" \
	"$(INTDIR)\error.obj" \
	"$(INTDIR)\eval.obj" \
	"$(INTDIR)\globals.obj" \
	"$(INTDIR)\instlook.obj" \
	"$(INTDIR)\insttabl.obj" \
	"$(INTDIR)\lex.obj" \
	"$(INTDIR)\listing.obj" \
	"$(INTDIR)\main.obj" \
	"$(INTDIR)\movem.obj" \
	"$(INTDIR)\object.obj" \
	"$(INTDIR)\opparse.obj" \
	"$(INTDIR)\pp.obj" \
	"$(INTDIR)\PRC.obj" \
	"$(INTDIR)\symbol.obj"

"$(OUTDIR)\pila.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "PilA - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "$(OUTDIR)\pila.exe" "$(OUTDIR)\pila.bsc"

CLEAN : 
	-@erase "$(INTDIR)\assemble.obj"
	-@erase "$(INTDIR)\assemble.sbr"
	-@erase "$(INTDIR)\build.obj"
	-@erase "$(INTDIR)\build.sbr"
	-@erase "$(INTDIR)\codegen.obj"
	-@erase "$(INTDIR)\codegen.sbr"
	-@erase "$(INTDIR)\directiv.obj"
	-@erase "$(INTDIR)\directiv.sbr"
	-@erase "$(INTDIR)\error.obj"
	-@erase "$(INTDIR)\error.sbr"
	-@erase "$(INTDIR)\eval.obj"
	-@erase "$(INTDIR)\eval.sbr"
	-@erase "$(INTDIR)\globals.obj"
	-@erase "$(INTDIR)\globals.sbr"
	-@erase "$(INTDIR)\instlook.obj"
	-@erase "$(INTDIR)\instlook.sbr"
	-@erase "$(INTDIR)\insttabl.obj"
	-@erase "$(INTDIR)\insttabl.sbr"
	-@erase "$(INTDIR)\lex.obj"
	-@erase "$(INTDIR)\lex.sbr"
	-@erase "$(INTDIR)\listing.obj"
	-@erase "$(INTDIR)\listing.sbr"
	-@erase "$(INTDIR)\main.obj"
	-@erase "$(INTDIR)\main.sbr"
	-@erase "$(INTDIR)\movem.obj"
	-@erase "$(INTDIR)\movem.sbr"
	-@erase "$(INTDIR)\object.obj"
	-@erase "$(INTDIR)\object.sbr"
	-@erase "$(INTDIR)\opparse.obj"
	-@erase "$(INTDIR)\opparse.sbr"
	-@erase "$(INTDIR)\pp.obj"
	-@erase "$(INTDIR)\pp.sbr"
	-@erase "$(INTDIR)\PRC.obj"
	-@erase "$(INTDIR)\PRC.sbr"
	-@erase "$(INTDIR)\symbol.obj"
	-@erase "$(INTDIR)\symbol.sbr"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\pila.bsc"
	-@erase "$(OUTDIR)\pila.exe"
	-@erase "$(OUTDIR)\pila.ilk"
	-@erase "$(OUTDIR)\pila.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

F90=fl32.exe
# ADD BASE F90 /I "Debug/"
# ADD F90 /I "Debug/"
F90_PROJ=/I "Debug/" /Fo"Debug/" 
F90_OBJS=.\Debug/

.for{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

.f{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

.f90{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

CPP=cl.exe
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FR /YX /c
CPP_PROJ=/nologo /MLd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /FR"$(INTDIR)/" /Fp"$(INTDIR)/pila.pch" /YX /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\Debug/

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

MTL=mktyplib.exe
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/pila.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\assemble.sbr" \
	"$(INTDIR)\build.sbr" \
	"$(INTDIR)\codegen.sbr" \
	"$(INTDIR)\directiv.sbr" \
	"$(INTDIR)\error.sbr" \
	"$(INTDIR)\eval.sbr" \
	"$(INTDIR)\globals.sbr" \
	"$(INTDIR)\instlook.sbr" \
	"$(INTDIR)\insttabl.sbr" \
	"$(INTDIR)\lex.sbr" \
	"$(INTDIR)\listing.sbr" \
	"$(INTDIR)\main.sbr" \
	"$(INTDIR)\movem.sbr" \
	"$(INTDIR)\object.sbr" \
	"$(INTDIR)\opparse.sbr" \
	"$(INTDIR)\pp.sbr" \
	"$(INTDIR)\PRC.sbr" \
	"$(INTDIR)\symbol.sbr"

"$(OUTDIR)\pila.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386
# SUBTRACT LINK32 /pdb:none
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:console /incremental:yes\
 /pdb:"$(OUTDIR)/pila.pdb" /debug /machine:I386 /out:"$(OUTDIR)/pila.exe" 
LINK32_OBJS= \
	"$(INTDIR)\assemble.obj" \
	"$(INTDIR)\build.obj" \
	"$(INTDIR)\codegen.obj" \
	"$(INTDIR)\directiv.obj" \
	"$(INTDIR)\error.obj" \
	"$(INTDIR)\eval.obj" \
	"$(INTDIR)\globals.obj" \
	"$(INTDIR)\instlook.obj" \
	"$(INTDIR)\insttabl.obj" \
	"$(INTDIR)\lex.obj" \
	"$(INTDIR)\listing.obj" \
	"$(INTDIR)\main.obj" \
	"$(INTDIR)\movem.obj" \
	"$(INTDIR)\object.obj" \
	"$(INTDIR)\opparse.obj" \
	"$(INTDIR)\pp.obj" \
	"$(INTDIR)\PRC.obj" \
	"$(INTDIR)\symbol.obj"

"$(OUTDIR)\pila.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "PilA - Macintosh Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "MacRel"
# PROP BASE Intermediate_Dir "MacRel"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "MacRel"
# PROP Intermediate_Dir "MacRel"
# PROP Target_Dir ""
OUTDIR=.\MacRel
INTDIR=.\MacRel

ALL : "$(OUTDIR)\pila.exe" "$(OUTDIR)\pila.trg"

CLEAN : 
	-@erase "$(INTDIR)\assemble.obj"
	-@erase "$(INTDIR)\build.obj"
	-@erase "$(INTDIR)\codegen.obj"
	-@erase "$(INTDIR)\directiv.obj"
	-@erase "$(INTDIR)\error.obj"
	-@erase "$(INTDIR)\eval.obj"
	-@erase "$(INTDIR)\globals.obj"
	-@erase "$(INTDIR)\instlook.obj"
	-@erase "$(INTDIR)\insttabl.obj"
	-@erase "$(INTDIR)\lex.obj"
	-@erase "$(INTDIR)\listing.obj"
	-@erase "$(INTDIR)\main.obj"
	-@erase "$(INTDIR)\movem.obj"
	-@erase "$(INTDIR)\object.obj"
	-@erase "$(INTDIR)\opparse.obj"
	-@erase "$(INTDIR)\pp.obj"
	-@erase "$(INTDIR)\PRC.obj"
	-@erase "$(INTDIR)\symbol.obj"
	-@erase "$(OUTDIR)\pila.exe"
	-@erase "$(OUTDIR)\pila.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

MTL=mktyplib.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mac
# ADD MTL /nologo /D "NDEBUG" /mac
MTL_PROJ=/nologo /D "NDEBUG" /mac 
CPP=cl.exe
# ADD BASE CPP /nologo /AL /Q68s /W3 /GX /O2 /D "_WINDOWS" /D "_MAC" /D "_68K_" /D "WIN32" /D "NDEBUG" /YX /c
# ADD CPP /nologo /AL /Q68s /W3 /GX /O2 /D "_WINDOWS" /D "_MAC" /D "_68K_" /D "WIN32" /D "NDEBUG" /YX /c
CPP_PROJ=/nologo /AL /Q68s /W3 /GX /O2 /D "_WINDOWS" /D "_MAC" /D "_68K_" /D\
 "WIN32" /D "NDEBUG" /Fp"$(INTDIR)/pila.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\MacRel/
CPP_SBRS=.\.

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

RSC=rc.exe
# ADD BASE RSC /l 0x409 /r /d "_MAC" /d "_68K_" /d "NDEBUG"
# ADD RSC /l 0x409 /r /d "_MAC" /d "_68K_" /d "NDEBUG"
MRC=mrc.exe
# ADD BASE MRC /D "_68K_" /D "_MAC" /D "NDEBUG" /NOLOGO
# ADD MRC /D "_68K_" /D "_MAC" /D "NDEBUG" /NOLOGO
MRC_PROJ=/D "_68K_" /D "_MAC" /D "NDEBUG" /l 0x409 /NOLOGO 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/pila.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /MAC:bundle /machine:M68K
# ADD LINK32 /nologo /MAC:bundle /machine:M68K
LINK32_FLAGS=/nologo /MAC:bundle /MAC:type="APPL" /MAC:creator="????"\
 /pdb:"$(OUTDIR)/pila.pdb" /machine:M68K /out:"$(OUTDIR)/pila.exe" 
LINK32_OBJS= \
	"$(INTDIR)\assemble.obj" \
	"$(INTDIR)\build.obj" \
	"$(INTDIR)\codegen.obj" \
	"$(INTDIR)\directiv.obj" \
	"$(INTDIR)\error.obj" \
	"$(INTDIR)\eval.obj" \
	"$(INTDIR)\globals.obj" \
	"$(INTDIR)\instlook.obj" \
	"$(INTDIR)\insttabl.obj" \
	"$(INTDIR)\lex.obj" \
	"$(INTDIR)\listing.obj" \
	"$(INTDIR)\main.obj" \
	"$(INTDIR)\movem.obj" \
	"$(INTDIR)\object.obj" \
	"$(INTDIR)\opparse.obj" \
	"$(INTDIR)\pp.obj" \
	"$(INTDIR)\PRC.obj" \
	"$(INTDIR)\symbol.obj"

"$(OUTDIR)\pila.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

MFILE32=mfile.exe
# ADD BASE MFILE32 COPY /NOLOGO
# ADD MFILE32 COPY /NOLOGO
MFILE32_FLAGS=COPY /NOLOGO 
MFILE32_FILES= \
	"$(OUTDIR)\pila.exe"

"$(OUTDIR)\pila.trg" : "$(OUTDIR)" $(MFILE32_FILES)
    $(MFILE32) $(MFILE32_FLAGS) .\MacRel\pila.exe\
 "$(MFILE32_DEST):pila.exe">"$(OUTDIR)\pila.trg"

DOWNLOAD : "$(OUTDIR)" $(MFILE32_FILES)
    $(MFILE32) $(MFILE32_FLAGS) .\MacRel\pila.exe\
 "$(MFILE32_DEST):pila.exe">"$(OUTDIR)\pila.trg"

!ELSEIF  "$(CFG)" == "PilA - Macintosh Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "MacDbg"
# PROP BASE Intermediate_Dir "MacDbg"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "MacDbg"
# PROP Intermediate_Dir "MacDbg"
# PROP Target_Dir ""
OUTDIR=.\MacDbg
INTDIR=.\MacDbg

ALL : "$(OUTDIR)\pila.exe" "$(OUTDIR)\pila.trg"

CLEAN : 
	-@erase "$(INTDIR)\assemble.obj"
	-@erase "$(INTDIR)\build.obj"
	-@erase "$(INTDIR)\codegen.obj"
	-@erase "$(INTDIR)\directiv.obj"
	-@erase "$(INTDIR)\error.obj"
	-@erase "$(INTDIR)\eval.obj"
	-@erase "$(INTDIR)\globals.obj"
	-@erase "$(INTDIR)\instlook.obj"
	-@erase "$(INTDIR)\insttabl.obj"
	-@erase "$(INTDIR)\lex.obj"
	-@erase "$(INTDIR)\listing.obj"
	-@erase "$(INTDIR)\main.obj"
	-@erase "$(INTDIR)\movem.obj"
	-@erase "$(INTDIR)\object.obj"
	-@erase "$(INTDIR)\opparse.obj"
	-@erase "$(INTDIR)\pp.obj"
	-@erase "$(INTDIR)\PRC.obj"
	-@erase "$(INTDIR)\symbol.obj"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\pila.exe"
	-@erase "$(OUTDIR)\pila.pdb"
	-@erase "$(OUTDIR)\pila.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

MTL=mktyplib.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mac
# ADD MTL /nologo /D "_DEBUG" /mac
MTL_PROJ=/nologo /D "_DEBUG" /mac 
CPP=cl.exe
# ADD BASE CPP /nologo /AL /Q68s /Q68m /W3 /GX /Zi /Od /D "_WINDOWS" /D "_MAC" /D "_68K_" /D "WIN32" /D "_DEBUG" /YX /c
# ADD CPP /nologo /AL /Q68s /Q68m /W3 /GX /Zi /Od /D "_WINDOWS" /D "_MAC" /D "_68K_" /D "WIN32" /D "_DEBUG" /YX /c
CPP_PROJ=/nologo /AL /Q68s /Q68m /W3 /GX /Zi /Od /D "_WINDOWS" /D "_MAC" /D\
 "_68K_" /D "WIN32" /D "_DEBUG" /Fp"$(INTDIR)/pila.pch" /YX /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\MacDbg/
CPP_SBRS=.\.

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

RSC=rc.exe
# ADD BASE RSC /l 0x409 /r /d "_MAC" /d "_68K_" /d "_DEBUG"
# ADD RSC /l 0x409 /r /d "_MAC" /d "_68K_" /d "_DEBUG"
MRC=mrc.exe
# ADD BASE MRC /D "_68K_" /D "_MAC" /D "_DEBUG" /NOLOGO
# ADD MRC /D "_68K_" /D "_MAC" /D "_DEBUG" /NOLOGO
MRC_PROJ=/D "_68K_" /D "_MAC" /D "_DEBUG" /l 0x409 /NOLOGO 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/pila.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /MAC:bundle /debug /machine:M68K
# ADD LINK32 /nologo /MAC:bundle /debug /machine:M68K
LINK32_FLAGS=/nologo /MAC:bundle /MAC:type="APPL" /MAC:creator="????"\
 /pdb:"$(OUTDIR)/pila.pdb" /debug /machine:M68K /out:"$(OUTDIR)/pila.exe" 
LINK32_OBJS= \
	"$(INTDIR)\assemble.obj" \
	"$(INTDIR)\build.obj" \
	"$(INTDIR)\codegen.obj" \
	"$(INTDIR)\directiv.obj" \
	"$(INTDIR)\error.obj" \
	"$(INTDIR)\eval.obj" \
	"$(INTDIR)\globals.obj" \
	"$(INTDIR)\instlook.obj" \
	"$(INTDIR)\insttabl.obj" \
	"$(INTDIR)\lex.obj" \
	"$(INTDIR)\listing.obj" \
	"$(INTDIR)\main.obj" \
	"$(INTDIR)\movem.obj" \
	"$(INTDIR)\object.obj" \
	"$(INTDIR)\opparse.obj" \
	"$(INTDIR)\pp.obj" \
	"$(INTDIR)\PRC.obj" \
	"$(INTDIR)\symbol.obj"

"$(OUTDIR)\pila.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

MFILE32=mfile.exe
# ADD BASE MFILE32 COPY /NOLOGO
# ADD MFILE32 COPY /NOLOGO
MFILE32_FLAGS=COPY /NOLOGO 
MFILE32_FILES= \
	"$(OUTDIR)\pila.exe"

"$(OUTDIR)\pila.trg" : "$(OUTDIR)" $(MFILE32_FILES)
    $(MFILE32) $(MFILE32_FLAGS) .\MacDbg\pila.exe\
 "$(MFILE32_DEST):pila.exe">"$(OUTDIR)\pila.trg"

DOWNLOAD : "$(OUTDIR)" $(MFILE32_FILES)
    $(MFILE32) $(MFILE32_FLAGS) .\MacDbg\pila.exe\
 "$(MFILE32_DEST):pila.exe">"$(OUTDIR)\pila.trg"

!ENDIF 

################################################################################
# Begin Target

# Name "PilA - Win32 Release"
# Name "PilA - Win32 Debug"
# Name "PilA - Macintosh Release"
# Name "PilA - Macintosh Debug"

!IF  "$(CFG)" == "PilA - Win32 Release"

!ELSEIF  "$(CFG)" == "PilA - Win32 Debug"

!ELSEIF  "$(CFG)" == "PilA - Macintosh Release"

!ELSEIF  "$(CFG)" == "PilA - Macintosh Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\symbol.c

!IF  "$(CFG)" == "PilA - Win32 Release"

DEP_CPP_SYMBO=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\symbol.obj" : $(SOURCE) $(DEP_CPP_SYMBO) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Win32 Debug"

DEP_CPP_SYMBO=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\symbol.obj" : $(SOURCE) $(DEP_CPP_SYMBO) "$(INTDIR)"

"$(INTDIR)\symbol.sbr" : $(SOURCE) $(DEP_CPP_SYMBO) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Release"

DEP_CPP_SYMBO=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\symbol.obj" : $(SOURCE) $(DEP_CPP_SYMBO) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Debug"

DEP_CPP_SYMBO=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\symbol.obj" : $(SOURCE) $(DEP_CPP_SYMBO) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\build.c

!IF  "$(CFG)" == "PilA - Win32 Release"

DEP_CPP_BUILD=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\build.obj" : $(SOURCE) $(DEP_CPP_BUILD) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Win32 Debug"

DEP_CPP_BUILD=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\build.obj" : $(SOURCE) $(DEP_CPP_BUILD) "$(INTDIR)"

"$(INTDIR)\build.sbr" : $(SOURCE) $(DEP_CPP_BUILD) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Release"

DEP_CPP_BUILD=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\build.obj" : $(SOURCE) $(DEP_CPP_BUILD) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Debug"

DEP_CPP_BUILD=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\build.obj" : $(SOURCE) $(DEP_CPP_BUILD) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\codegen.c

!IF  "$(CFG)" == "PilA - Win32 Release"

DEP_CPP_CODEG=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\codegen.obj" : $(SOURCE) $(DEP_CPP_CODEG) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Win32 Debug"

DEP_CPP_CODEG=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\codegen.obj" : $(SOURCE) $(DEP_CPP_CODEG) "$(INTDIR)"

"$(INTDIR)\codegen.sbr" : $(SOURCE) $(DEP_CPP_CODEG) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Release"

DEP_CPP_CODEG=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\codegen.obj" : $(SOURCE) $(DEP_CPP_CODEG) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Debug"

DEP_CPP_CODEG=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\codegen.obj" : $(SOURCE) $(DEP_CPP_CODEG) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\directiv.c

!IF  "$(CFG)" == "PilA - Win32 Release"

DEP_CPP_DIREC=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\prc.h"\
	".\proto.h"\
	

"$(INTDIR)\directiv.obj" : $(SOURCE) $(DEP_CPP_DIREC) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Win32 Debug"

DEP_CPP_DIREC=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\prc.h"\
	".\proto.h"\
	

"$(INTDIR)\directiv.obj" : $(SOURCE) $(DEP_CPP_DIREC) "$(INTDIR)"

"$(INTDIR)\directiv.sbr" : $(SOURCE) $(DEP_CPP_DIREC) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Release"

DEP_CPP_DIREC=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\prc.h"\
	".\proto.h"\
	

"$(INTDIR)\directiv.obj" : $(SOURCE) $(DEP_CPP_DIREC) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Debug"

DEP_CPP_DIREC=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\prc.h"\
	".\proto.h"\
	

"$(INTDIR)\directiv.obj" : $(SOURCE) $(DEP_CPP_DIREC) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\error.c

!IF  "$(CFG)" == "PilA - Win32 Release"

DEP_CPP_ERROR=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\error.obj" : $(SOURCE) $(DEP_CPP_ERROR) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Win32 Debug"

DEP_CPP_ERROR=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\error.obj" : $(SOURCE) $(DEP_CPP_ERROR) "$(INTDIR)"

"$(INTDIR)\error.sbr" : $(SOURCE) $(DEP_CPP_ERROR) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Release"

DEP_CPP_ERROR=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\error.obj" : $(SOURCE) $(DEP_CPP_ERROR) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Debug"

DEP_CPP_ERROR=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\error.obj" : $(SOURCE) $(DEP_CPP_ERROR) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\eval.c

!IF  "$(CFG)" == "PilA - Win32 Release"

DEP_CPP_EVAL_=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	".\util.h"\
	

"$(INTDIR)\eval.obj" : $(SOURCE) $(DEP_CPP_EVAL_) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Win32 Debug"

DEP_CPP_EVAL_=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	".\util.h"\
	

"$(INTDIR)\eval.obj" : $(SOURCE) $(DEP_CPP_EVAL_) "$(INTDIR)"

"$(INTDIR)\eval.sbr" : $(SOURCE) $(DEP_CPP_EVAL_) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Release"

DEP_CPP_EVAL_=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	".\util.h"\
	

"$(INTDIR)\eval.obj" : $(SOURCE) $(DEP_CPP_EVAL_) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Debug"

DEP_CPP_EVAL_=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	".\util.h"\
	

"$(INTDIR)\eval.obj" : $(SOURCE) $(DEP_CPP_EVAL_) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\globals.c

!IF  "$(CFG)" == "PilA - Win32 Release"

DEP_CPP_GLOBA=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\globals.obj" : $(SOURCE) $(DEP_CPP_GLOBA) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Win32 Debug"

DEP_CPP_GLOBA=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\globals.obj" : $(SOURCE) $(DEP_CPP_GLOBA) "$(INTDIR)"

"$(INTDIR)\globals.sbr" : $(SOURCE) $(DEP_CPP_GLOBA) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Release"

DEP_CPP_GLOBA=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\globals.obj" : $(SOURCE) $(DEP_CPP_GLOBA) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Debug"

DEP_CPP_GLOBA=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\globals.obj" : $(SOURCE) $(DEP_CPP_GLOBA) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\instlook.c

!IF  "$(CFG)" == "PilA - Win32 Release"

DEP_CPP_INSTL=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\instlook.obj" : $(SOURCE) $(DEP_CPP_INSTL) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Win32 Debug"

DEP_CPP_INSTL=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\instlook.obj" : $(SOURCE) $(DEP_CPP_INSTL) "$(INTDIR)"

"$(INTDIR)\instlook.sbr" : $(SOURCE) $(DEP_CPP_INSTL) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Release"

DEP_CPP_INSTL=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\instlook.obj" : $(SOURCE) $(DEP_CPP_INSTL) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Debug"

DEP_CPP_INSTL=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\instlook.obj" : $(SOURCE) $(DEP_CPP_INSTL) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\insttabl.c

!IF  "$(CFG)" == "PilA - Win32 Release"

DEP_CPP_INSTT=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\insttabl.obj" : $(SOURCE) $(DEP_CPP_INSTT) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Win32 Debug"

DEP_CPP_INSTT=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\insttabl.obj" : $(SOURCE) $(DEP_CPP_INSTT) "$(INTDIR)"

"$(INTDIR)\insttabl.sbr" : $(SOURCE) $(DEP_CPP_INSTT) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Release"

DEP_CPP_INSTT=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\insttabl.obj" : $(SOURCE) $(DEP_CPP_INSTT) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Debug"

DEP_CPP_INSTT=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\insttabl.obj" : $(SOURCE) $(DEP_CPP_INSTT) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\listing.c

!IF  "$(CFG)" == "PilA - Win32 Release"

DEP_CPP_LISTI=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\listing.obj" : $(SOURCE) $(DEP_CPP_LISTI) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Win32 Debug"

DEP_CPP_LISTI=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\listing.obj" : $(SOURCE) $(DEP_CPP_LISTI) "$(INTDIR)"

"$(INTDIR)\listing.sbr" : $(SOURCE) $(DEP_CPP_LISTI) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Release"

DEP_CPP_LISTI=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\listing.obj" : $(SOURCE) $(DEP_CPP_LISTI) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Debug"

DEP_CPP_LISTI=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\listing.obj" : $(SOURCE) $(DEP_CPP_LISTI) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\main.c

!IF  "$(CFG)" == "PilA - Win32 Release"

DEP_CPP_MAIN_=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\prc.h"\
	".\proto.h"\
	

"$(INTDIR)\main.obj" : $(SOURCE) $(DEP_CPP_MAIN_) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Win32 Debug"

DEP_CPP_MAIN_=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\prc.h"\
	".\proto.h"\
	

"$(INTDIR)\main.obj" : $(SOURCE) $(DEP_CPP_MAIN_) "$(INTDIR)"

"$(INTDIR)\main.sbr" : $(SOURCE) $(DEP_CPP_MAIN_) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Release"

DEP_CPP_MAIN_=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\prc.h"\
	".\proto.h"\
	

"$(INTDIR)\main.obj" : $(SOURCE) $(DEP_CPP_MAIN_) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Debug"

DEP_CPP_MAIN_=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\prc.h"\
	".\proto.h"\
	

"$(INTDIR)\main.obj" : $(SOURCE) $(DEP_CPP_MAIN_) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\movem.c

!IF  "$(CFG)" == "PilA - Win32 Release"

DEP_CPP_MOVEM=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\movem.obj" : $(SOURCE) $(DEP_CPP_MOVEM) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Win32 Debug"

DEP_CPP_MOVEM=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\movem.obj" : $(SOURCE) $(DEP_CPP_MOVEM) "$(INTDIR)"

"$(INTDIR)\movem.sbr" : $(SOURCE) $(DEP_CPP_MOVEM) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Release"

DEP_CPP_MOVEM=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\movem.obj" : $(SOURCE) $(DEP_CPP_MOVEM) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Debug"

DEP_CPP_MOVEM=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\movem.obj" : $(SOURCE) $(DEP_CPP_MOVEM) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\object.c

!IF  "$(CFG)" == "PilA - Win32 Release"

DEP_CPP_OBJEC=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\prc.h"\
	".\proto.h"\
	

"$(INTDIR)\object.obj" : $(SOURCE) $(DEP_CPP_OBJEC) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Win32 Debug"

DEP_CPP_OBJEC=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\prc.h"\
	".\proto.h"\
	

"$(INTDIR)\object.obj" : $(SOURCE) $(DEP_CPP_OBJEC) "$(INTDIR)"

"$(INTDIR)\object.sbr" : $(SOURCE) $(DEP_CPP_OBJEC) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Release"

DEP_CPP_OBJEC=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\prc.h"\
	".\proto.h"\
	

"$(INTDIR)\object.obj" : $(SOURCE) $(DEP_CPP_OBJEC) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Debug"

DEP_CPP_OBJEC=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\prc.h"\
	".\proto.h"\
	

"$(INTDIR)\object.obj" : $(SOURCE) $(DEP_CPP_OBJEC) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\opparse.c

!IF  "$(CFG)" == "PilA - Win32 Release"

DEP_CPP_OPPAR=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\opparse.obj" : $(SOURCE) $(DEP_CPP_OPPAR) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Win32 Debug"

DEP_CPP_OPPAR=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\opparse.obj" : $(SOURCE) $(DEP_CPP_OPPAR) "$(INTDIR)"

"$(INTDIR)\opparse.sbr" : $(SOURCE) $(DEP_CPP_OPPAR) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Release"

DEP_CPP_OPPAR=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\opparse.obj" : $(SOURCE) $(DEP_CPP_OPPAR) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Debug"

DEP_CPP_OPPAR=\
	".\asm.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	

"$(INTDIR)\opparse.obj" : $(SOURCE) $(DEP_CPP_OPPAR) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\assemble.c

!IF  "$(CFG)" == "PilA - Win32 Release"

DEP_CPP_ASSEM=\
	".\asm.h"\
	".\lex.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	".\std.h"\
	".\util.h"\
	

"$(INTDIR)\assemble.obj" : $(SOURCE) $(DEP_CPP_ASSEM) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Win32 Debug"

DEP_CPP_ASSEM=\
	".\asm.h"\
	".\lex.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	".\std.h"\
	".\util.h"\
	

"$(INTDIR)\assemble.obj" : $(SOURCE) $(DEP_CPP_ASSEM) "$(INTDIR)"

"$(INTDIR)\assemble.sbr" : $(SOURCE) $(DEP_CPP_ASSEM) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Release"

DEP_CPP_ASSEM=\
	".\asm.h"\
	".\lex.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	".\std.h"\
	".\util.h"\
	

"$(INTDIR)\assemble.obj" : $(SOURCE) $(DEP_CPP_ASSEM) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Debug"

DEP_CPP_ASSEM=\
	".\asm.h"\
	".\lex.h"\
	".\pila.h"\
	".\pp.h"\
	".\proto.h"\
	".\std.h"\
	".\util.h"\
	

"$(INTDIR)\assemble.obj" : $(SOURCE) $(DEP_CPP_ASSEM) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\PRC.c

!IF  "$(CFG)" == "PilA - Win32 Release"

DEP_CPP_PRC_C=\
	".\pila.h"\
	".\prc.h"\
	

"$(INTDIR)\PRC.obj" : $(SOURCE) $(DEP_CPP_PRC_C) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Win32 Debug"

DEP_CPP_PRC_C=\
	".\pila.h"\
	".\prc.h"\
	

"$(INTDIR)\PRC.obj" : $(SOURCE) $(DEP_CPP_PRC_C) "$(INTDIR)"

"$(INTDIR)\PRC.sbr" : $(SOURCE) $(DEP_CPP_PRC_C) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Release"

DEP_CPP_PRC_C=\
	".\pila.h"\
	".\prc.h"\
	

"$(INTDIR)\PRC.obj" : $(SOURCE) $(DEP_CPP_PRC_C) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Debug"

DEP_CPP_PRC_C=\
	".\pila.h"\
	".\prc.h"\
	

"$(INTDIR)\PRC.obj" : $(SOURCE) $(DEP_CPP_PRC_C) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\pp.c

!IF  "$(CFG)" == "PilA - Win32 Release"

DEP_CPP_PP_C20=\
	".\lex.h"\
	".\pp.h"\
	".\std.h"\
	".\util.h"\
	

"$(INTDIR)\pp.obj" : $(SOURCE) $(DEP_CPP_PP_C20) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Win32 Debug"

DEP_CPP_PP_C20=\
	".\lex.h"\
	".\pp.h"\
	".\std.h"\
	".\util.h"\
	

"$(INTDIR)\pp.obj" : $(SOURCE) $(DEP_CPP_PP_C20) "$(INTDIR)"

"$(INTDIR)\pp.sbr" : $(SOURCE) $(DEP_CPP_PP_C20) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Release"

DEP_CPP_PP_C20=\
	".\lex.h"\
	".\pp.h"\
	".\std.h"\
	".\util.h"\
	

"$(INTDIR)\pp.obj" : $(SOURCE) $(DEP_CPP_PP_C20) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Debug"

DEP_CPP_PP_C20=\
	".\lex.h"\
	".\pp.h"\
	".\std.h"\
	".\util.h"\
	

"$(INTDIR)\pp.obj" : $(SOURCE) $(DEP_CPP_PP_C20) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\lex.c

!IF  "$(CFG)" == "PilA - Win32 Release"

DEP_CPP_LEX_C=\
	".\lex.h"\
	".\std.h"\
	".\util.h"\
	

"$(INTDIR)\lex.obj" : $(SOURCE) $(DEP_CPP_LEX_C) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Win32 Debug"

DEP_CPP_LEX_C=\
	".\lex.h"\
	".\std.h"\
	".\util.h"\
	

"$(INTDIR)\lex.obj" : $(SOURCE) $(DEP_CPP_LEX_C) "$(INTDIR)"

"$(INTDIR)\lex.sbr" : $(SOURCE) $(DEP_CPP_LEX_C) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Release"

DEP_CPP_LEX_C=\
	".\lex.h"\
	".\std.h"\
	".\util.h"\
	

"$(INTDIR)\lex.obj" : $(SOURCE) $(DEP_CPP_LEX_C) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PilA - Macintosh Debug"

DEP_CPP_LEX_C=\
	".\lex.h"\
	".\std.h"\
	".\util.h"\
	

"$(INTDIR)\lex.obj" : $(SOURCE) $(DEP_CPP_LEX_C) "$(INTDIR)"


!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
