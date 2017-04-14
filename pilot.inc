        list 0                  ;disable listing

;-----------------------------------------------------------------------------
; pilot.inc
;
;   include file for pila
;
;   processed from USR Pilot include files
;
;-----------------------------------------------------------------------------

; buildrules.h
EMULATION_NONE         equ 0
EMULATION_WINDOWS      equ 1
EMULATION_DOS          equ 2
EMULATION_MAC          equ 3

MEMORY_LOCAL           equ 0
MEMORY_REMOTE          equ 1

ENVIRONMENT_CW         equ 0
ENVIRONMENT_MPW        equ 1

ERROR_CHECK_NONE       equ 0
ERROR_CHECK_PARTIAL    equ 1
ERROR_CHECK_FULL       equ 2

CPU_68K                equ 0
CPU_x86                equ 1

HW_TARGET_NONE         equ 0
HW_TARGET_302          equ 1
HW_TARGET_328EMU       equ 2
HW_TARGET_328          equ 3
HW_TARGET_TD1          equ 4

MEMORY_FORCE_LOCK_OFF  equ 0
MEMORY_FORCE_LOCK_ON   equ 1

DEBUG_LEVEL_NONE       equ 1
DEBUG_LEVEL_PARTIAL    equ 2
DEBUG_LEVEL_FULL       equ 3

COUNTRY_UNITED_STATES  equ 0
COUNTRY_FRANCE         equ 1
COUNTRY_GERMANY        equ 2

LANGUAGE_ENGLISH       equ 0
LANGUAGE_FRENCH        equ 1
LANGUAGE_GERMAN        equ 2

MEMORY_FORCE_LOCK      equ 1
MEMORY_TYPE            equ $00000000
ENVIRONMENT            equ $00000000
ERROR_CHECK_LEVEL      equ $00000002
CPU_TYPE               equ $00000000
HW_TARGET              equ $00000000
COUNTRY                equ $00000000
LANGUAGE               equ $00000000


; appbuildrules.h
SHELL_COMMAND_DB        equ 0
SHELL_COMMAND_UI        equ 0
SHELL_COMMAND_APP       equ 0
SHELL_COMMAND_EMULATOR  equ 1


; common.h
USE_TRAPS equ 1

NULL  equ 0

false equ 0
true  equ 1

; hardware\m68khwr.h
m68kTrapInstr                   equ $00004e40
m68kTrapVectorMask              equ $0000000f
M68KExcTableType_initStack      equ 0
M68KExcTableType_initPC         equ 4
M68KExcTableType_busErr         equ 8
M68KExcTableType_addressErr     equ 12
M68KExcTableType_illegalInstr   equ 16
M68KExcTableType_divideByZero   equ 20
M68KExcTableType_chk            equ 24
M68KExcTableType_trap           equ 28
M68KExcTableType_privilege      equ 32
M68KExcTableType_trace          equ 36
M68KExcTableType_aTrap          equ 40
M68KExcTableType_fTrap          equ 44
M68KExcTableType_reserved12     equ 48
M68KExcTableType_coproc         equ 52
M68KExcTableType_formatErr      equ 56
M68KExcTableType_unitializedInt equ 60
M68KExcTableType_reserved       equ 64
M68KExcTableType_spuriousInt    equ 96
M68KExcTableType_autoVec1       equ 100
M68KExcTableType_autoVec2       equ 104
M68KExcTableType_autoVec3       equ 108
M68KExcTableType_autoVec4       equ 112
M68KExcTableType_autoVec5       equ 116
M68KExcTableType_autoVec6       equ 120
M68KExcTableType_autoVec7       equ 124
M68KExcTableType_trapN          equ 128
M68KExcTableType_unassigned     equ 192
M68KExcTableType_sizeof         equ 256
M68KRegsType_d                  equ 0
M68KRegsType_a                  equ 32
M68KRegsType_usp                equ 60
M68KRegsType_ssp                equ 64
M68KRegsType_pc                 equ 68
M68KRegsType_sr                 equ 72
M68KRegsType_sizeof             equ 74
m68kSrTraceMask                 equ $00008000
m68kSrTraceBit                  equ 15
m68kSrSupervisorMask            equ $00002000
m68kSrInterruptMask             equ $00000700
m68kSrInterruptOffset           equ 8
m68kSrExtendMask                equ $00000010
m68kSrNegativeMask              equ $00000008
m68kSrZeroMask                  equ $00000004
m68kSrOverflowMask              equ $00000002
m68kSrCarryMask                 equ $00000001

; system\systraps.h
sysTrapBase                            equ $0000a000
sysTrapMemInit                         equ 40960
sysTrapMemInitHeapTable                equ 40961
sysTrapMemStoreInit                    equ 40962
sysTrapMemCardFormat                   equ 40963
sysTrapMemCardInfo                     equ 40964
sysTrapMemStoreInfo                    equ 40965
sysTrapMemStoreSetInfo                 equ 40966
sysTrapMemNumHeaps                     equ 40967
sysTrapMemNumRAMHeaps                  equ 40968
sysTrapMemHeapID                       equ 40969
sysTrapMemHeapPtr                      equ 40970
sysTrapMemHeapFreeBytes                equ 40971
sysTrapMemHeapSize                     equ 40972
sysTrapMemHeapFlags                    equ 40973
sysTrapMemHeapCompact                  equ 40974
sysTrapMemHeapInit                     equ 40975
sysTrapMemHeapFreeByOwnerID            equ 40976
sysTrapMemChunkNew                     equ 40977
sysTrapMemChunkFree                    equ 40978
sysTrapMemPtrNew                       equ 40979
sysTrapMemPtrFree                      equ sysTrapMemChunkFree
sysTrapMemPtrRecoverHandle             equ 40980
sysTrapMemPtrFlags                     equ 40981
sysTrapMemPtrSize                      equ 40982
sysTrapMemPtrOwner                     equ 40983
sysTrapMemPtrHeapID                    equ 40984
sysTrapMemPtrCardNo                    equ 40985
sysTrapMemPtrToLocalID                 equ 40986
sysTrapMemPtrSetOwner                  equ 40987
sysTrapMemPtrResize                    equ 40988
sysTrapMemPtrResetLock                 equ 40989
sysTrapMemHandleNew                    equ 40990
sysTrapMemHandleLockCount              equ 40991
sysTrapMemHandleToLocalID              equ 40992
sysTrapMemHandleLock                   equ 40993
sysTrapMemHandleUnlock                 equ 40994
sysTrapMemLocalIDToGlobal              equ 40995
sysTrapMemLocalIDKind                  equ 40996
sysTrapMemLocalIDToPtr                 equ 40997
sysTrapMemMove                         equ 40998
sysTrapMemSet                          equ 40999
sysTrapMemStoreSearch                  equ 41000
sysTrapMemPtrDataStorage               equ 41001
sysTrapMemKernelInit                   equ 41002
sysTrapMemHandleFree                   equ 41003
sysTrapMemHandleFlags                  equ 41004
sysTrapMemHandleSize                   equ 41005
sysTrapMemHandleOwner                  equ 41006
sysTrapMemHandleHeapID                 equ 41007
sysTrapMemHandleDataStorage            equ 41008
sysTrapMemHandleCardNo                 equ 41009
sysTrapMemHandleSetOwner               equ 41010
sysTrapMemHandleResize                 equ 41011
sysTrapMemHandleResetLock              equ 41012
sysTrapMemPtrUnlock                    equ 41013
sysTrapMemLocalIDToLockedPtr           equ 41014
sysTrapMemSetDebugMode                 equ 41015
sysTrapMemHeapScramble                 equ 41016
sysTrapMemHeapCheck                    equ 41017
sysTrapMemNumCards                     equ 41018
sysTrapMemDebugMode                    equ 41019
sysTrapMemSemaphoreReserve             equ 41020
sysTrapMemSemaphoreRelease             equ 41021
sysTrapMemHeapDynamic                  equ 41022
sysTrapMemNVParams                     equ 41023
sysTrapDmInit                          equ 41024
sysTrapDmCreateDatabase                equ 41025
sysTrapDmDeleteDatabase                equ 41026
sysTrapDmNumDatabases                  equ 41027
sysTrapDmGetDatabase                   equ 41028
sysTrapDmFindDatabase                  equ 41029
sysTrapDmDatabaseInfo                  equ 41030
sysTrapDmSetDatabaseInfo               equ 41031
sysTrapDmDatabaseSize                  equ 41032
sysTrapDmOpenDatabase                  equ 41033
sysTrapDmCloseDatabase                 equ 41034
sysTrapDmNextOpenDatabase              equ 41035
sysTrapDmOpenDatabaseInfo              equ 41036
sysTrapDmResetRecordStates             equ 41037
sysTrapDmGetLastErr                    equ 41038
sysTrapDmNumRecords                    equ 41039
sysTrapDmRecordInfo                    equ 41040
sysTrapDmSetRecordInfo                 equ 41041
sysTrapDmAttachRecord                  equ 41042
sysTrapDmDetachRecord                  equ 41043
sysTrapDmMoveRecord                    equ 41044
sysTrapDmNewRecord                     equ 41045
sysTrapDmRemoveRecord                  equ 41046
sysTrapDmDeleteRecord                  equ 41047
sysTrapDmArchiveRecord                 equ 41048
sysTrapDmNewHandle                     equ 41049
sysTrapDmRemoveSecretRecords           equ 41050
sysTrapDmQueryRecord                   equ 41051
sysTrapDmGetRecord                     equ 41052
sysTrapDmResizeRecord                  equ 41053
sysTrapDmReleaseRecord                 equ 41054
sysTrapDmGetResource                   equ 41055
sysTrapDmGet1Resource                  equ 41056
sysTrapDmReleaseResource               equ 41057
sysTrapDmResizeResource                equ 41058
sysTrapDmNextOpenResDatabase           equ 41059
sysTrapDmFindResourceType              equ 41060
sysTrapDmFindResource                  equ 41061
sysTrapDmSearchResource                equ 41062
sysTrapDmNumResources                  equ 41063
sysTrapDmResourceInfo                  equ 41064
sysTrapDmSetResourceInfo               equ 41065
sysTrapDmAttachResource                equ 41066
sysTrapDmDetachResource                equ 41067
sysTrapDmNewResource                   equ 41068
sysTrapDmRemoveResource                equ 41069
sysTrapDmGetResourceIndex              equ 41070
sysTrapDmQuickSort                     equ 41071
sysTrapDmQueryNextInCategory           equ 41072
sysTrapDmNumRecordsInCategory          equ 41073
sysTrapDmPositionInCategory            equ 41074
sysTrapDmSeekRecordInCategory          equ 41075
sysTrapDmMoveCategory                  equ 41076
sysTrapDmOpenDatabaseByTypeCreator     equ 41077
sysTrapDmWrite                         equ 41078
sysTrapDmStrCopy                       equ 41079
sysTrapDmGetNextDatabaseByTypeCreator  equ 41080
sysTrapDmWriteCheck                    equ 41081
sysTrapDmMoveOpenDBContext             equ 41082
sysTrapDmFindRecordByID                equ 41083
sysTrapDmGetAppInfoID                  equ 41084
sysTrapDmFindSortPosition              equ 41085
sysTrapDmSet                           equ 41086
sysTrapDmCreateDatabaseFromImage       equ 41087
sysTrapDbgSrcMessage                   equ 41088
sysTrapDbgMessage                      equ 41089
sysTrapDbgGetMessage                   equ 41090
sysTrapDbgCommSettings                 equ 41091
sysTrapErrDisplayFileLineMsg           equ 41092
sysTrapErrSetJump                      equ 41093
sysTrapErrLongJump                     equ 41094
sysTrapErrThrow                        equ 41095
sysTrapErrExceptionList                equ 41096
sysTrapSysBroadcastActionCode          equ 41097
sysTrapSysUnimplemented                equ 41098
sysTrapSysColdBoot                     equ 41099
sysTrapSysReset                        equ 41100
sysTrapSysDoze                         equ 41101
sysTrapSysAppLaunch                    equ 41102
sysTrapSysAppStartup                   equ 41103
sysTrapSysAppExit                      equ 41104
sysTrapSysSetA5                        equ 41105
sysTrapSysSetTrapAddress               equ 41106
sysTrapSysGetTrapAddress               equ 41107
sysTrapSysTranslateKernelErr           equ 41108
sysTrapSysSemaphoreCreate              equ 41109
sysTrapSysSemaphoreDelete              equ 41110
sysTrapSysSemaphoreWait                equ 41111
sysTrapSysSemaphoreSignal              equ 41112
sysTrapSysTimerCreate                  equ 41113
sysTrapSysTimerWrite                   equ 41114
sysTrapSysTaskCreate                   equ 41115
sysTrapSysTaskDelete                   equ 41116
sysTrapSysTaskTrigger                  equ 41117
sysTrapSysTaskID                       equ 41118
sysTrapSysTaskUserInfoPtr              equ 41119
sysTrapSysTaskDelay                    equ 41120
sysTrapSysTaskSetTermProc              equ 41121
sysTrapSysUILaunch                     equ 41122
sysTrapSysNewOwnerID                   equ 41123
sysTrapSysSemaphoreSet                 equ 41124
sysTrapSysDisableInts                  equ 41125
sysTrapSysRestoreStatus                equ 41126
sysTrapSysUIAppSwitch                  equ 41127
sysTrapSysCurAppInfoP                  equ 41128
sysTrapSysHandleEvent                  equ 41129
sysTrapSysInit                         equ 41130
sysTrapSysQSort                        equ 41131
sysTrapSysCurAppDatabase               equ 41132
sysTrapSysFatalAlert                   equ 41133
sysTrapSysResSemaphoreCreate           equ 41134
sysTrapSysResSemaphoreDelete           equ 41135
sysTrapSysResSemaphoreReserve          equ 41136
sysTrapSysResSemaphoreRelease          equ 41137
sysTrapSysSleep                        equ 41138
sysTrapSysKeyboardDialog               equ 41139
sysTrapSysAppLauncherDialog            equ 41140
sysTrapSysSetPerformance               equ 41141
sysTrapSysBatteryInfo                  equ 41142
sysTrapSysLibInstall                   equ 41143
sysTrapSysLibRemove                    equ 41144
sysTrapSysLibTblEntry                  equ 41145
sysTrapSysLibFind                      equ 41146
sysTrapSysBatteryDialog                equ 41147
sysTrapSysCopyStringResource           equ 41148
sysTrapSysKernelInfo                   equ 41149
sysTrapSysLaunchConsole                equ 41150
sysTrapSysTimerDelete                  equ 41151
sysTrapSysSetAutoOffTime               equ 41152
sysTrapSysFormPointerArrayToStrings    equ 41153
sysTrapSysRandom                       equ 41154
sysTrapSysTaskSwitching                equ 41155
sysTrapSysTimerRead                    equ 41156
sysTrapStrCopy                         equ 41157
sysTrapStrCat                          equ 41158
sysTrapStrLen                          equ 41159
sysTrapStrCompare                      equ 41160
sysTrapStrIToA                         equ 41161
sysTrapStrCaselessCompare              equ 41162
sysTrapStrIToH                         equ 41163
sysTrapStrChr                          equ 41164
sysTrapStrStr                          equ 41165
sysTrapStrAToI                         equ 41166
sysTrapStrToLower                      equ 41167
sysTrapSerReceiveISP                   equ 41168
sysTrapSlkOpen                         equ 41169
sysTrapSlkClose                        equ 41170
sysTrapSlkOpenSocket                   equ 41171
sysTrapSlkCloseSocket                  equ 41172
sysTrapSlkSocketRefNum                 equ 41173
sysTrapSlkSocketSetTimeout             equ 41174
sysTrapSlkFlushSocket                  equ 41175
sysTrapSlkSetSocketListener            equ 41176
sysTrapSlkSendPacket                   equ 41177
sysTrapSlkReceivePacket                equ 41178
sysTrapSlkSysPktDefaultResponse        equ 41179
sysTrapSlkProcessRPC                   equ 41180
sysTrapConPutS                         equ 41181
sysTrapConGetS                         equ 41182
sysTrapFplInit                         equ 41183
sysTrapFplFree                         equ 41184
sysTrapFplFToA                         equ 41185
sysTrapFplAToF                         equ 41186
sysTrapFplBase10Info                   equ 41187
sysTrapFplLongToFloat                  equ 41188
sysTrapFplFloatToLong                  equ 41189
sysTrapFplFloatToULong                 equ 41190
sysTrapFplMul                          equ 41191
sysTrapFplAdd                          equ 41192
sysTrapFplSub                          equ 41193
sysTrapFplDiv                          equ 41194
sysTrapScrInit                         equ 41195
sysTrapScrCopyRectangle                equ 41196
sysTrapScrDrawChars                    equ 41197
sysTrapScrLineRoutine                  equ 41198
sysTrapScrRectangleRoutine             equ 41199
sysTrapScrScreenInfo                   equ 41200
sysTrapScrDrawNotify                   equ 41201
sysTrapScrSendUpdateArea               equ 41202
sysTrapScrCompressScanLine             equ 41203
sysTrapScrDeCompressScanLine           equ 41204
sysTrapTimGetSeconds                   equ 41205
sysTrapTimSetSeconds                   equ 41206
sysTrapTimGetTicks                     equ 41207
sysTrapTimInit                         equ 41208
sysTrapTimSetAlarm                     equ 41209
sysTrapTimGetAlarm                     equ 41210
sysTrapTimHandleInterrupt              equ 41211
sysTrapTimSecondsToDateTime            equ 41212
sysTrapTimDateTimeToSeconds            equ 41213
sysTrapTimAdjust                       equ 41214
sysTrapTimSleep                        equ 41215
sysTrapTimWake                         equ 41216
sysTrapCategoryCreateList              equ 41217
sysTrapCategoryFreeList                equ 41218
sysTrapCategoryFind                    equ 41219
sysTrapCategoryGetName                 equ 41220
sysTrapCategoryEdit                    equ 41221
sysTrapCategorySelect                  equ 41222
sysTrapCategoryGetNext                 equ 41223
sysTrapCategorySetTriggerLabel         equ 41224
sysTrapCategoryTruncateName            equ 41225
sysTrapClipboardAddItem                equ 41226
sysTrapClipboardCheckIfItemExist       equ 41227
sysTrapClipboardGetItem                equ 41228
sysTrapCtlDrawControl                  equ 41229
sysTrapCtlEraseControl                 equ 41230
sysTrapCtlHideControl                  equ 41231
sysTrapCtlShowControl                  equ 41232
sysTrapCtlGetValue                     equ 41233
sysTrapCtlSetValue                     equ 41234
sysTrapCtlGetLabel                     equ 41235
sysTrapCtlSetLabel                     equ 41236
sysTrapCtlHandleEvent                  equ 41237
sysTrapCtlHitControl                   equ 41238
sysTrapCtlSetEnabled                   equ 41239
sysTrapCtlSetUsable                    equ 41240
sysTrapCtlEnabled                      equ 41241
sysTrapEvtInitialize                   equ 41242
sysTrapEvtAddEventToQueue              equ 41243
sysTrapEvtCopyEvent                    equ 41244
sysTrapEvtGetEvent                     equ 41245
sysTrapEvtGetPen                       equ 41246
sysTrapEvtSysInit                      equ 41247
sysTrapEvtGetSysEvent                  equ 41248
sysTrapEvtProcessSoftKeyStroke         equ 41249
sysTrapEvtGetPenBtnList                equ 41250
sysTrapEvtSetPenQueuePtr               equ 41251
sysTrapEvtPenQueueSize                 equ 41252
sysTrapEvtFlushPenQueue                equ 41253
sysTrapEvtEnqueuePenPoint              equ 41254
sysTrapEvtDequeuePenStrokeInfo         equ 41255
sysTrapEvtDequeuePenPoint              equ 41256
sysTrapEvtFlushNextPenStroke           equ 41257
sysTrapEvtSetKeyQueuePtr               equ 41258
sysTrapEvtKeyQueueSize                 equ 41259
sysTrapEvtFlushKeyQueue                equ 41260
sysTrapEvtEnqueueKey                   equ 41261
sysTrapEvtDequeueKeyEvent              equ 41262
sysTrapEvtWakeup                       equ 41263
sysTrapEvtResetAutoOffTimer            equ 41264
sysTrapEvtKeyQueueEmpty                equ 41265
sysTrapEvtEnableGraffiti               equ 41266
sysTrapFldCopy                         equ 41267
sysTrapFldCut                          equ 41268
sysTrapFldDrawField                    equ 41269
sysTrapFldEraseField                   equ 41270
sysTrapFldFreeMemory                   equ 41271
sysTrapFldGetBounds                    equ 41272
sysTrapFldGetTextPtr                   equ 41273
sysTrapFldGetSelection                 equ 41274
sysTrapFldHandleEvent                  equ 41275
sysTrapFldPaste                        equ 41276
sysTrapFldRecalculateField             equ 41277
sysTrapFldSetBounds                    equ 41278
sysTrapFldSetText                      equ 41279
sysTrapFldGetFont                      equ 41280
sysTrapFldSetFont                      equ 41281
sysTrapFldSetSelection                 equ 41282
sysTrapFldGrabFocus                    equ 41283
sysTrapFldReleaseFocus                 equ 41284
sysTrapFldGetInsPtPosition             equ 41285
sysTrapFldSetInsPtPosition             equ 41286
sysTrapFldSetScrollPosition            equ 41287
sysTrapFldGetScrollPosition            equ 41288
sysTrapFldGetTextHeight                equ 41289
sysTrapFldGetTextAllocatedSize         equ 41290
sysTrapFldGetTextLength                equ 41291
sysTrapFldScrollField                  equ 41292
sysTrapFldScrollable                   equ 41293
sysTrapFldGetVisibleLines              equ 41294
sysTrapFldGetAttributes                equ 41295
sysTrapFldSetAttributes                equ 41296
sysTrapFldSendChangeNotification       equ 41297
sysTrapFldCalcFieldHeight              equ 41298
sysTrapFldGetTextHandle                equ 41299
sysTrapFldCompactText                  equ 41300
sysTrapFldDirty                        equ 41301
sysTrapFldWordWrap                     equ 41302
sysTrapFldSetTextAllocatedSize         equ 41303
sysTrapFldSetTextHandle                equ 41304
sysTrapFldSetTextPtr                   equ 41305
sysTrapFldGetMaxChars                  equ 41306
sysTrapFldSetMaxChars                  equ 41307
sysTrapFldSetUsable                    equ 41308
sysTrapFldInsert                       equ 41309
sysTrapFldDelete                       equ 41310
sysTrapFldUndo                         equ 41311
sysTrapFldSetDirty                     equ 41312
sysTrapFldSendHeightChangeNotification equ 41313
sysTrapFldMakeFullyVisible             equ 41314
sysTrapFntGetFont                      equ 41315
sysTrapFntSetFont                      equ 41316
sysTrapFntGetFontPtr                   equ 41317
sysTrapFntBaseLine                     equ 41318
sysTrapFntCharHeight                   equ 41319
sysTrapFntLineHeight                   equ 41320
sysTrapFntAverageCharWidth             equ 41321
sysTrapFntCharWidth                    equ 41322
sysTrapFntCharsWidth                   equ 41323
sysTrapFntDescenderHeight              equ 41324
sysTrapFntCharsInWidth                 equ 41325
sysTrapFntLineWidth                    equ 41326
sysTrapFrmInitForm                     equ 41327
sysTrapFrmDeleteForm                   equ 41328
sysTrapFrmDrawForm                     equ 41329
sysTrapFrmEraseForm                    equ 41330
sysTrapFrmGetActiveForm                equ 41331
sysTrapFrmSetActiveForm                equ 41332
sysTrapFrmGetActiveFormID              equ 41333
sysTrapFrmGetUserModifiedState         equ 41334
sysTrapFrmSetNotUserModified           equ 41335
sysTrapFrmGetFocus                     equ 41336
sysTrapFrmSetFocus                     equ 41337
sysTrapFrmHandleEvent                  equ 41338
sysTrapFrmGetFormBounds                equ 41339
sysTrapFrmGetWindowHandle              equ 41340
sysTrapFrmGetFormId                    equ 41341
sysTrapFrmGetFormPtr                   equ 41342
sysTrapFrmGetNumberOfObjects           equ 41343
sysTrapFrmGetObjectIndex               equ 41344
sysTrapFrmGetObjectId                  equ 41345
sysTrapFrmGetObjectType                equ 41346
sysTrapFrmGetObjectPtr                 equ 41347
sysTrapFrmHideObject                   equ 41348
sysTrapFrmShowObject                   equ 41349
sysTrapFrmGetObjectPosition            equ 41350
sysTrapFrmSetObjectPositon             equ 41351
sysTrapFrmGetControlValue              equ 41352
sysTrapFrmSetControlValue              equ 41353
sysTrapFrmGetControlGroupSelection     equ 41354
sysTrapFrmSetControlGroupSelection     equ 41355
sysTrapFrmCopyLabel                    equ 41356
sysTrapFrmSetLabel                     equ 41357
sysTrapFrmGetLabel                     equ 41358
sysTrapFrmSetCategoryLabel             equ 41359
sysTrapFrmGetTitle                     equ 41360
sysTrapFrmSetTitle                     equ 41361
sysTrapFrmAlert                        equ 41362
sysTrapFrmDoDialog                     equ 41363
sysTrapFrmCustomAlert                  equ 41364
sysTrapFrmHelp                         equ 41365
sysTrapFrmUpdateScrollers              equ 41366
sysTrapFrmGetFirstForm                 equ 41367
sysTrapFrmVisible                      equ 41368
sysTrapFrmGetObjectBounds              equ 41369
sysTrapFrmCopyTitle                    equ 41370
sysTrapFrmGotoForm                     equ 41371
sysTrapFrmPopupForm                    equ 41372
sysTrapFrmUpdateForm                   equ 41373
sysTrapFrmReturnToForm                 equ 41374
sysTrapFrmSetEventHandler              equ 41375
sysTrapFrmDispatchEvent                equ 41376
sysTrapFrmCloseAllForms                equ 41377
sysTrapFrmSaveAllForms                 equ 41378
sysTrapFrmGetGadgetData                equ 41379
sysTrapFrmSetGadgetData                equ 41380
sysTrapFrmSetCategoryTrigger           equ 41381
sysTrapUIInitialize                    equ 41382
sysTrapUIReset                         equ 41383
sysTrapInsPtInitialize                 equ 41384
sysTrapInsPtSetLocation                equ 41385
sysTrapInsPtGetLocation                equ 41386
sysTrapInsPtEnable                     equ 41387
sysTrapInsPtEnabled                    equ 41388
sysTrapInsPtSetHeight                  equ 41389
sysTrapInsPtGetHeight                  equ 41390
sysTrapInsPtCheckBlink                 equ 41391
sysTrapLstSetDrawFunction              equ 41392
sysTrapLstDrawList                     equ 41393
sysTrapLstEraseList                    equ 41394
sysTrapLstGetSelection                 equ 41395
sysTrapLstGetSelectionText             equ 41396
sysTrapLstHandleEvent                  equ 41397
sysTrapLstSetHeight                    equ 41398
sysTrapLstSetSelection                 equ 41399
sysTrapLstSetListChoices               equ 41400
sysTrapLstMakeItemVisible              equ 41401
sysTrapLstGetNumberOfItems             equ 41402
sysTrapLstPopupList                    equ 41403
sysTrapLstSetPosition                  equ 41404
sysTrapMenuInit                        equ 41405
sysTrapMenuDispose                     equ 41406
sysTrapMenuHandleEvent                 equ 41407
sysTrapMenuDrawMenu                    equ 41408
sysTrapMenuEraseStatus                 equ 41409
sysTrapMenuGetActiveMenu               equ 41410
sysTrapMenuSetActiveMenu               equ 41411
sysTrapRctSetRectangle                 equ 41412
sysTrapRctCopyRectangle                equ 41413
sysTrapRctInsetRectangle               equ 41414
sysTrapRctOffsetRectangle              equ 41415
sysTrapRctPtInRectangle                equ 41416
sysTrapRctGetIntersection              equ 41417
sysTrapTblDrawTable                    equ 41418
sysTrapTblEraseTable                   equ 41419
sysTrapTblHandleEvent                  equ 41420
sysTrapTblGetItemBounds                equ 41421
sysTrapTblSelectItem                   equ 41422
sysTrapTblGetItemInt                   equ 41423
sysTrapTblSetItemInt                   equ 41424
sysTrapTblSetItemStyle                 equ 41425
sysTrapTblUnhighlightSelection         equ 41426
sysTrapTblSetRowUsable                 equ 41427
sysTrapTblGetNumberOfRows              equ 41428
sysTrapTblSetCustomDrawProcedure       equ 41429
sysTrapTblSetRowSelectable             equ 41430
sysTrapTblRowSelectable                equ 41431
sysTrapTblSetLoadDataProcedure         equ 41432
sysTrapTblSetSaveDataProcedure         equ 41433
sysTrapTblGetBounds                    equ 41434
sysTrapTblSetRowHeight                 equ 41435
sysTrapTblGetColumnWidth               equ 41436
sysTrapTblGetRowID                     equ 41437
sysTrapTblSetRowID                     equ 41438
sysTrapTblMarkRowInvalid               equ 41439
sysTrapTblMarkTableInvalid             equ 41440
sysTrapTblGetSelection                 equ 41441
sysTrapTblInsertRow                    equ 41442
sysTrapTblRemoveRow                    equ 41443
sysTrapTblRowInvalid                   equ 41444
sysTrapTblRedrawTable                  equ 41445
sysTrapTblRowUsable                    equ 41446
sysTrapTblReleaseFocus                 equ 41447
sysTrapTblEditing                      equ 41448
sysTrapTblGetCurrentField              equ 41449
sysTrapTblSetColumnUsable              equ 41450
sysTrapTblGetRowHeight                 equ 41451
sysTrapTblSetColumnWidth               equ 41452
sysTrapTblGrabFocus                    equ 41453
sysTrapTblSetItemPtr                   equ 41454
sysTrapTblFindRowID                    equ 41455
sysTrapTblGetLastUsableRow             equ 41456
sysTrapTblGetColumnSpacing             equ 41457
sysTrapTblFindRowData                  equ 41458
sysTrapTblGetRowData                   equ 41459
sysTrapTblSetRowData                   equ 41460
sysTrapTblSetColumnSpacing             equ 41461
sysTrapWinCreateWindow                 equ 41462
sysTrapWinCreateOffscreenWindow        equ 41463
sysTrapWinDeleteWindow                 equ 41464
sysTrapWinInitializeWindow             equ 41465
sysTrapWinAddWindow                    equ 41466
sysTrapWinRemoveWindow                 equ 41467
sysTrapWinSetActiveWindow              equ 41468
sysTrapWinSetDrawWindow                equ 41469
sysTrapWinGetDrawWindow                equ 41470
sysTrapWinGetActiveWindow              equ 41471
sysTrapWinGetDisplayWindow             equ 41472
sysTrapWinGetFirstWindow               equ 41473
sysTrapWinEnableWindow                 equ 41474
sysTrapWinDisableWindow                equ 41475
sysTrapWinGetWindowFrameRect           equ 41476
sysTrapWinDrawWindowFrame              equ 41477
sysTrapWinEraseWindow                  equ 41478
sysTrapWinSaveBits                     equ 41479
sysTrapWinRestoreBits                  equ 41480
sysTrapWinCopyRectangle                equ 41481
sysTrapWinScrollRectangle              equ 41482
sysTrapWinGetDisplayExtent             equ 41483
sysTrapWinGetWindowExtent              equ 41484
sysTrapWinDisplayToWindowPt            equ 41485
sysTrapWinWindowToDisplayPt            equ 41486
sysTrapWinGetClip                      equ 41487
sysTrapWinSetClip                      equ 41488
sysTrapWinResetClip                    equ 41489
sysTrapWinClipRectangle                equ 41490
sysTrapWinDrawLine                     equ 41491
sysTrapWinDrawGrayLine                 equ 41492
sysTrapWinEraseLine                    equ 41493
sysTrapWinInvertLine                   equ 41494
sysTrapWinFillLine                     equ 41495
sysTrapWinDrawRectangle                equ 41496
sysTrapWinEraseRectangle               equ 41497
sysTrapWinInvertRectangle              equ 41498
sysTrapWinDrawRectangleFrame           equ 41499
sysTrapWinDrawGrayRectangleFrame       equ 41500
sysTrapWinEraseRectangleFrame          equ 41501
sysTrapWinInvertRectangleFrame         equ 41502
sysTrapWinGetFramesRectangle           equ 41503
sysTrapWinDrawChars                    equ 41504
sysTrapWinEraseChars                   equ 41505
sysTrapWinInvertChars                  equ 41506
sysTrapWinGetPattern                   equ 41507
sysTrapWinSetPattern                   equ 41508
sysTrapWinSetUnderlineMode             equ 41509
sysTrapWinDrawBitmap                   equ 41510
sysTrapWinModal                        equ 41511
sysTrapWinGetWindowBounds              equ 41512
sysTrapWinFillRectangle                equ 41513
sysTrapWinDrawInvertedChars            equ 41514
sysTrapPrefOpenPreferenceDB            equ 41515
sysTrapPrefGetPreferences              equ 41516
sysTrapPrefSetPreferences              equ 41517
sysTrapPrefGetAppPreferences           equ 41518
sysTrapPrefSetAppPreferences           equ 41519
sysTrapSndInit                         equ 41520
sysTrapSndSetDefaultVolume             equ 41521
sysTrapSndGetDefaultVolume             equ 41522
sysTrapSndDoCmd                        equ 41523
sysTrapSndPlaySystemSound              equ 41524
sysTrapAlmInit                         equ 41525
sysTrapAlmCancelAll                    equ 41526
sysTrapAlmAlarmCallback                equ 41527
sysTrapAlmSetAlarm                     equ 41528
sysTrapAlmGetAlarm                     equ 41529
sysTrapAlmDisplayAlarm                 equ 41530
sysTrapAlmEnableNotification           equ 41531
sysTrapHwrGetRAMMapping                equ 41532
sysTrapHwrMemWritable                  equ 41533
sysTrapHwrMemReadable                  equ 41534
sysTrapHwrDoze                         equ 41535
sysTrapHwrSleep                        equ 41536
sysTrapHwrWake                         equ 41537
sysTrapHwrSetSystemClock               equ 41538
sysTrapHwrSetCPUDutyCycle              equ 41539
sysTrapHwrLCDInit                      equ 41540
sysTrapHwrLCDSleep                     equ 41541
sysTrapHwrTimerInit                    equ 41542
sysTrapHwrCursor                       equ 41543
sysTrapHwrBatteryLevel                 equ 41544
sysTrapHwrDelay                        equ 41545
sysTrapHwrEnableDataWrites             equ 41546
sysTrapHwrDisableDataWrites            equ 41547
sysTrapHwrLCDBaseAddr                  equ 41548
sysTrapHwrLCDDrawBitmap                equ 41549
sysTrapHwrTimerSleep                   equ 41550
sysTrapHwrTimerWake                    equ 41551
sysTrapHwrLCDWake                      equ 41552
sysTrapHwrIRQ1Handler                  equ 41553
sysTrapHwrIRQ2Handler                  equ 41554
sysTrapHwrIRQ3Handler                  equ 41555
sysTrapHwrIRQ4Handler                  equ 41556
sysTrapHwrIRQ5Handler                  equ 41557
sysTrapHwrIRQ6Handler                  equ 41558
sysTrapHwrDockSignals                  equ 41559
sysTrapHwrPluggedIn                    equ 41560
sysTrapCrc16CalcBlock                  equ 41561
sysTrapSelectDay                       equ 41562
sysTrapSelectTime                      equ 41563
sysTrapDayDrawDaySelector              equ 41564
sysTrapDayHandleEvent                  equ 41565
sysTrapDayDrawDays                     equ 41566
sysTrapDayOfWeek                       equ 41567
sysTrapDaysInMonth                     equ 41568
sysTrapDayOfMonth                      equ 41569
sysTrapDateDaysToDate                  equ 41570
sysTrapDateToDays                      equ 41571
sysTrapDateAdjust                      equ 41572
sysTrapDateSecondsToDate               equ 41573
sysTrapDateToAscii                     equ 41574
sysTrapDateToDOWDMFormat               equ 41575
sysTrapTimeToAscii                     equ 41576
sysTrapFind                            equ 41577
sysTrapFindStrInStr                    equ 41578
sysTrapFindSaveMatch                   equ 41579
sysTrapFindGetLineBounds               equ 41580
sysTrapFindDrawHeader                  equ 41581
sysTrapPenOpen                         equ 41582
sysTrapPenClose                        equ 41583
sysTrapPenGetRawPen                    equ 41584
sysTrapPenCalibrate                    equ 41585
sysTrapPenRawToScreen                  equ 41586
sysTrapPenScreenToRaw                  equ 41587
sysTrapPenResetCalibration             equ 41588
sysTrapPenSleep                        equ 41589
sysTrapPenWake                         equ 41590
sysTrapResLoadForm                     equ 41591
sysTrapResLoadMenu                     equ 41592
sysTrapFtrInit                         equ 41593
sysTrapFtrUnregister                   equ 41594
sysTrapFtrGet                          equ 41595
sysTrapFtrSet                          equ 41596
sysTrapFtrGetByIndex                   equ 41597
sysTrapGrfInit                         equ 41598
sysTrapGrfFree                         equ 41599
sysTrapGrfGetState                     equ 41600
sysTrapGrfSetState                     equ 41601
sysTrapGrfFlushPoints                  equ 41602
sysTrapGrfAddPoint                     equ 41603
sysTrapGrfInitState                    equ 41604
sysTrapGrfCleanState                   equ 41605
sysTrapGrfMatch                        equ 41606
sysTrapGrfGetMacro                     equ 41607
sysTrapGrfFilterPoints                 equ 41608
sysTrapGrfGetNumPoints                 equ 41609
sysTrapGrfGetPoint                     equ 41610
sysTrapGrfFindBranch                   equ 41611
sysTrapGrfMatchGlyph                   equ 41612
sysTrapGrfGetGlyphMapping              equ 41613
sysTrapGrfGetMacroName                 equ 41614
sysTrapGrfDeleteMacro                  equ 41615
sysTrapGrfAddMacro                     equ 41616
sysTrapGrfGetAndExpandMacro            equ 41617
sysTrapGrfProcessStroke                equ 41618
sysTrapGrfFieldChange                  equ 41619
sysTrapGetCharSortValue                equ 41620
sysTrapGetCharAttr                     equ 41621
sysTrapGetCharCaselessValue            equ 41622
sysTrapPwdExists                       equ 41623
sysTrapPwdVerify                       equ 41624
sysTrapPwdSet                          equ 41625
sysTrapPwdRemove                       equ 41626
sysTrapGsiInitialize                   equ 41627
sysTrapGsiSetLocation                  equ 41628
sysTrapGsiEnable                       equ 41629
sysTrapGsiEnabled                      equ 41630
sysTrapGsiSetShiftState                equ 41631
sysTrapKeyInit                         equ 41632
sysTrapKeyHandleInterrupt              equ 41633
sysTrapKeyCurrentState                 equ 41634
sysTrapKeyResetDoubleTap               equ 41635
sysTrapKeyRates                        equ 41636
sysTrapKeySleep                        equ 41637
sysTrapKeyWake                         equ 41638
sysTrapCmBroadcast                     equ 41639
sysTrapDlkStartServer                  equ 41640
sysTrapDlkGetSyncInfo                  equ 41641
sysTrapDlkSetLogEntry                  equ 41642
sysTrapPsrInit                         equ 41643
sysTrapPsrClose                        equ 41644
sysTrapPsrGetCommand                   equ 41645
sysTrapPsrSendReply                    equ 41646
sysTrapAbtShowAbout                    equ 41647
sysTrapMdmDial                         equ 41648
sysTrapMdmHangUp                       equ 41649
sysTrapDmSearchRecord                  equ 41650
sysTrapSysInsertionSort                equ 41651
sysTrapDmInsertionSort                 equ 41652
sysTrapLstSetTopItem                   equ 41653
sysTrapLastTrapNumber                  equ 41654

sysLibTrapBase   equ $0000a800
sysLibTrapName   equ 43008
sysLibTrapOpen   equ 43009
sysLibTrapClose  equ 43010
sysLibTrapSleep  equ 43011
sysLibTrapWake   equ 43012
sysLibTrapCustom equ 43013

sysDbgBreakpointTrapNum    equ 0
sysDbgTrapNum              equ 8
sysDispatchTrapNum         equ 15

sysResIDBootReset          equ 10000
sysResIDBootInitCode       equ 10001
sysResIDBootSysCodeStart   equ 10100
sysResIDBootSysCodeMin     equ 10102
sysResIDBootUICodeStart    equ 10200
sysResIDBootUICodeMin      equ 10203
sysResIDFeatures           equ 10000
sysResIDGrfTemplate        equ 10000
sysResIDGrfDictionary      equ 10000
sysResIDGrfDefaultMacros   equ 10000
sysResIDDefaultDB          equ 1
sysResIDSysPrefMain        equ 0
sysResIDSysPrefPassword    equ 1
sysResIDSysPrefFindStr     equ 2
sysResIDSysPrefCalibration equ 3
sysResIDDlkUserInfo        equ 4


;ui\uicommon.h
appVersionID                equ 1
ainID                       equ 1000
systemVersionID             equ 10000
palmLogoBitmap              equ 10000
keyboardBackspaceBitmap     equ 10001
keyboardTabBitmap           equ 10002
keyboardReturnBitmap        equ 10003
InformationAlertBitmap      equ 10004
ConfirmationAlertBitmap     equ 10005
WarningAlertBitmap          equ 10006
ErrorAlertBitmap            equ 10007
keyboardShiftBitmap         equ 10008
keyboardCapBitmap           equ 10009
daysOfWeekStrID             equ 10000
dayFullNamesStrID           equ 10001
monthNamesStrID             equ 10002
monthFullNamesStrID         equ 10003
categoryAllStrID            equ 10004
categoryEditStrID           equ 10005
menuCommandStrID            equ 10006
launcherBatteryStrID        equ 10007
systemNameStrID             equ 10008
RenameCategoryAlert         equ 10000
RenameCategoryYes           equ 0
RenameCategoryNo            equ 1
RemoveCategoryAlert         equ 10001
RemoveCategoryYes           equ 0
RemoveCategoryNo            equ 1
LowBatteryAlert             equ 10002
VeryLowBatteryAlert         equ 10003
UndoAlert                   equ 10004
UndoCancelButton            equ 1
MergeCategoryAlert          equ 10005
MergeCategoryYes            equ 0
MergeCategoryNo             equ 1
privateRecordInfoAlert      equ 10006
ClipboardLimitAlert         equ 10007
CategoryExistsAlert         equ 10012
DeviceFullAlert             equ 10013
sysEditMenuID               equ 10000
sysEditMenuUndoCmd          equ 10000
sysEditMenuCutCmd           equ 10001
sysEditMenuCopyCmd          equ 10002
sysEditMenuPasteCmd         equ 10003
sysEditMenuSelectAllCmd     equ 10004
sysEditMenuSeparator        equ 10005
sysEditMenuKeyboardCmd      equ 10006
sysKeyboardMenuID           equ 10100
sysKeyboardEditUndoCmd      equ 100
sysKeyboardEditCutCmd       equ 101
sysKeyboardEditCopyCmd      equ 102
sysKeyboardEditPasteCmd     equ 103
sysKeyboardEditSelectAllCmd equ 104
noteMenuID                  equ 10200
noteUndoCmd                 equ 10000
noteCutCmd                  equ 10001
noteCopyCmd                 equ 10002
notePasteCmd                equ 10003
noteSelectAllCmd            equ 10004
noteSeparator               equ 10005
noteKeyboardCmd             equ 10006
noteTopOfPageCmd            equ 10200
noteBottomOfPageCmd         equ 10201
SystemKeyboardID            equ 10000
CategoriesEditForm          equ 10000
CategoriesEditDoneButton    equ 10002
CategoriesEditFirstField    equ 10004
DateSelectorForm            equ 10100
DateSelectorYearLabel       equ 10102
DateSelectorPriorYearButton equ 10103
DateSelectorNextYearButton  equ 10104
DateSelectorTodayButton     equ 10118
DateSelectorCancelButton    equ 10119
DateSelectorDayGadget       equ 10120
TimeSelectorForm            equ 10200
TimeSelectorStartTimeButton equ 10204
TimeSelectorEndTimeButton   equ 10205
TimeSelectorHourList        equ 10206
TimeSelectorMinuteList      equ 10207
TimeSelectorOKButton        equ 10208
TimeSelectorCancelButton    equ 10209
TimeSelectorNoTimeButton    equ 10210
KeyboardForm                equ 10300
KeyboardGadget              equ 10310
HelpForm                    equ 10400
HelpField                   equ 10402
HelpDoneButton              equ 10403
HelpUpButton                equ 10404
HelpDownButton              equ 10405
FindDialog                  equ 10500
FindStrField                equ 10503
FindOKButton                equ 10504
FindResultsDialog           equ 10600
FindResultsMsgLabel         equ 10602
FindResultsTable            equ 10603
FindResultsGoToButton       equ 10604
FindResultsCancelButton     equ 10605
FindResultsMoreButton       equ 10606
FindResultsSearchingStr     equ 10607
FindResultsMatchesStr       equ 10608
FindResultsNoMatchesStr     equ 10609
FindResultsContinueStr      equ 10610
NoteView                    equ 10900
NoteField                   equ 10901
NoteDoneButton              equ 10902
NoteSmallFontButton         equ 10903
NoteLargeFontButton         equ 10904
NoteDeleteButton            equ 10905
NoteUpButton                equ 10906
NoteDownButton              equ 10907
NoteFontGroup               equ 1
aboutDialog                 equ 11000
aboutNameLabel              equ 11001
aboutVersionLabel           equ 11002
aboutErrorStr               equ 11003

struct M68KExcTableType
    initStack.l
    initPC.l
    busErr.l
    addressErr.l
    illegalInstr.l
    divideByZero.l
    chk.l
    trap.l
    privilege.l
    trace.l
    aTrap.l
    fTrap.l
    reserved12.l
    coproc.l
    formatErr.l
    unitializedInt.l
    reserved.32
    spuriousInt.l
    autoVec1.l
    autoVec2.l
    autoVec3.l
    autoVec4.l
    autoVec5.l
    autoVec6.l
    autoVec7.l
    trapN.64
    unassigned.64
endstruct

struct M68KRegsType
    d.32
    a.28
    usp.l
    ssp.l
    pc.l
    sr.w
endstruct

struct AbsRectType
    left.w
    top.w
    right.w
    bottom.w
endstruct

struct PointType
    x.w
    y.w
endstruct

struct RectangleType
    topLeft.PointType
    extent.PointType
endstruct

; ui\font.h
struct FontCharInfoType
    offset.b
    width.b
endstruct

struct FontType
    fontType.w
    firstChar.w
    lastChar.w
    maxWidth.w
    kernMax.w
    nDescent.w
    fRectWidth.w
    fRectHeight.w
    owTLoc.w
    ascent.w
    descent.w
    leading.w
    rowWords.w
endstruct

stdFont equ 0
boldFont equ 1
largeFont equ 2
symbolFont equ 3
symbol11Font equ 4
symbol7Font equ 5
ledFont equ 6


; ui\window.h

up    equ 0
down  equ 1
left  equ 2
right equ 3

screenFormat  equ 0
genericFormat equ 1

scrCopy    equ 0
scrAND     equ 1
scrANDNOT  equ 2
scrXOR     equ 3
scrOR      equ 4
scrCopyNOT equ 5

blackPattern     equ 0
whitePattern     equ 1
grayPattern      equ 2
customPattern    equ 3
grayHLinePattern equ $000000aa
noUnderline      equ 0
grayUnderline    equ 1
solidUnderline   equ 2


BitmapFlagsType_compressed_shift equ 0
BitmapFlagsType_compressed_count equ 1
BitmapFlagsType_compressed_mask  equ $00000001
BitmapFlagsType_reserved_shift   equ 1
BitmapFlagsType_reserved_count   equ 15
BitmapFlagsType_reserved_mask    equ $0000fffe

struct BitmapType
    width.w
    height.w
    rowBytes.w
    flags.w ; BitmapFlagsType
    reserved.8
endstruct


struct GraphicStateType
    grafMode.b
    patternMode.b
    pattern.w
    customPtn.8
    fontId.b
    padding.b
    font.l
    underlineMode.w
endstruct


FrameBits_cornerDiam_shift  equ 0
FrameBits_cornerDiam_count  equ 8
FrameBits_cornerDiam_mask   equ $000000ff
FrameBits_reserved_shift    equ 8
FrameBits_reserved_count    equ 4
FrameBits_reserved_mask     equ $00000f00
FrameBits_shadowWidth_shift equ 12
FrameBits_shadowWidth_count equ 2
FrameBits_shadowWidth_mask  equ $00003000
FrameBits_width_shift       equ 14
FrameBits_width_count       equ 2
FrameBits_width_mask        equ $0000c000
FrameBits_sizeof            equ 2
FrameBitsType_bits          equ 0
FrameBitsType_word          equ 0
FrameBitsType_sizeof        equ 2

noFrame        equ 0
simpleFrame    equ 1
rectangleFrame equ 1
roundFrame     equ $00000401
boldRoundFrame equ $00000702
popupFrame     equ $00000205
dialogFrame    equ $00000302
menuFrame      equ $00000205

WindowFlagsType_format_shift     equ 0
WindowFlagsType_format_count     equ 1
WindowFlagsType_format_mask      equ $00000001
WindowFlagsType_offscreen_shift  equ 1
WindowFlagsType_offscreen_count  equ 1
WindowFlagsType_offscreen_mask   equ $00000002
WindowFlagsType_modal_shift      equ 2
WindowFlagsType_modal_count      equ 1
WindowFlagsType_modal_mask       equ $00000004
WindowFlagsType_focusable_shift  equ 3
WindowFlagsType_focusable_count  equ 1
WindowFlagsType_focusable_mask   equ $00000008
WindowFlagsType_enabled_shift    equ 4
WindowFlagsType_enabled_count    equ 1
WindowFlagsType_enabled_mask     equ $00000010
WindowFlagsType_visible_shift    equ 5
WindowFlagsType_visible_count    equ 1
WindowFlagsType_visible_mask     equ $00000020
WindowFlagsType_dialog_shift     equ 6
WindowFlagsType_dialog_count     equ 1
WindowFlagsType_dialog_mask      equ $00000040
WindowFlagsType_compressed_shift equ 7
WindowFlagsType_compressed_count equ 1
WindowFlagsType_compressed_mask  equ $00000080
WindowFlagsType_reserved_shift   equ 8
WindowFlagsType_reserved_count   equ 8
WindowFlagsType_reserved_mask    equ $0000ff00

struct WindowType
    displayWidth.w
    displayHeight.w
    displayAddr.l
    windowFlags.w
    windowBounds.RectangleType
    clippingBounds.AbsRectType
    viewOrigin.PointType
    frameType.w
    gstate.l
    nextWindow.l
endstruct


; ui\inspoint.h
insPtBlinkInterval equ 30
insPtWidth equ 2

; ui\event.h

nilEvent              equ 0
penDownEvent          equ 1
penUpEvent            equ 2
penMoveEvent          equ 3
keyDownEvent          equ 4
winEnterEvent         equ 5
winExitEvent          equ 6
ctlEnterEvent         equ 7
ctlExitEvent          equ 8
ctlSelectEvent        equ 9
ctlRepeatEvent        equ 10
lstEnterEvent         equ 11
lstSelectEvent        equ 12
lstExitEvent          equ 13
popSelectEvent        equ 14
fldEnterEvent         equ 15
fldHeightChangedEvent equ 16
fldChangedEvent       equ 17
tblEnterEvent         equ 18
tblSelectEvent        equ 19
daySelectEvent        equ 20
menuEvent             equ 21
appStopEvent          equ 22
frmLoadEvent          equ 23
frmOpenEvent          equ 24
frmGotoEvent          equ 25
frmUpdateEvent        equ 26
frmSaveEvent          equ 27
frmCloseEvent         equ 28
tblExitEvent          equ 29
firstUserEvent        equ 32767

; keyDownEvent modifiers
shiftKeyMask      equ $00000001
capsLockMask      equ $00000002
numLockMask       equ $00000004
commandKeyMask    equ $00000008
optionKeyMask     equ $00000010
controlKeyMask    equ $00000020
autoRepeatKeyMask equ $00000040
doubleTapKeyMask  equ $00000080
poweredOnKeyMask  equ $00000100

; Event timeouts
evtWaitForever equ -1

; EventType data unions
struct generic
    data1.w
    data2.w
    data3.w
    data4.w
    data5.w
    data6.w
    data7.w
    data8.w
endstruct

struct penUp
    start.PointType
    end.PointType
endstruct

struct keyDown
    chr.w
    keyCode.w
    modifiers.w
endstruct

struct winEnter
    enterWindow.l
    exitWindow.l
endstruct

struct winExit
    enterWindow.l
    exitWindow.l
endstruct

struct ctlEnter
    controlID.w
    pControl.l
endstruct

struct ctlSelect
    controlID.w
    pControl.l
    on.b
    bPad.b
endstruct

struct ctlRepeat
    controlID.w
    pControl.l
    time.l
endstruct

struct fldEnter
    fieldID.w
    pField.l
endstruct

struct fldHeightChanged
    fieldID.w
    pField.l
    newHeight.w
    currentPos.w
endstruct

struct fldChanged
    fieldID.w
    pField.l
endstruct

struct fldExit
    fieldID.w
    pField.l
endstruct

struct lstEnter
    listID.w
    pList.l
    selection.w
endstruct

struct lstExit
    listID.w
    pList.l
endstruct

struct lstSelect
    listID.w
    pList.l
    selection.w
endstruct

struct tblEnter
    tableID.w
    pTable.l
    row.w
    column.w
endstruct

struct tblExit
    tableID.w
    pTable.l
    row.w
    column.w
endstruct

struct tblSelect
    tableID.w
    pTable.l
    row.w
    column.w
endstruct

struct frmLoad
    formID.w
endstruct

struct frmOpen
    formID.w
endstruct

struct frmGoto
    formID.w
    recordNum.w
    matchPos.w
    matchLen.w
    matchFieldNum.w
    matchCustom.l
endstruct

struct frmClose
    formID.w
endstruct

struct frmUpdate
    formID.w
    updateCode.w
endstruct

struct daySelect
    pSelector.l
    selection.w
    useThisDate.b
    bPad.b
endstruct

struct menu
    itemID.w
endstruct

struct popSelect
    controlID.w
    controlP.l
    listID.w
    listP.l
    selection.w
    priorSelection.w
endstruct


struct EventType
    eType.w
    penDown.w
    screenX.w
    screenY.w
    data.16
endstruct

; system\systemmgr.h
sysAppLaunchCmdNormalLaunch        equ 0
sysAppLaunchCmdFind                equ 1
sysAppLaunchCmdGoTo                equ 2
sysAppLaunchCmdSyncNotify          equ 3
sysAppLaunchCmdTimeChange          equ 4
sysAppLaunchCmdSystemReset         equ 5
sysAppLaunchCmdAlarmTriggered      equ 6
sysAppLaunchCmdDisplayAlarm        equ 7
sysAppLaunchCmdCountryChange       equ 8
sysAppLaunchCmdSyncRequest         equ 9
sysAppLaunchCmdSaveData            equ 10
sysAppLaunchCmdInitDatabase        equ 11
sysAppLaunchCmdSyncCallApplication equ 12

sysAppLaunchFlagNewThread  equ $00000001
sysAppLaunchFlagNewStack   equ $00000002
sysAppLaunchFlagNewGlobals equ $00000004
sysAppLaunchFlagUIApp      equ $00000008
sysAppLaunchFlagSubCall    equ $00000010

sysDbgCommLibraryRefNum equ 0

memErrorClass equ $00000100
dmErrorClass  equ $00000200
serErrorClass equ $00000300
slkErrorClass equ $00000400
sysErrorClass equ $00000500
fplErrorClass equ $00000600
evtErrorClass equ $00000700
sndErrorClass equ $00000800
almErrorClass equ $00000900
timErrorClass equ $00000a00
penErrorClass equ $00000b00
ftrErrorClass equ $00000c00
cmpErrorClass equ $00000d00
dlkErrorClass equ $00000e00
padErrorClass equ $00000f00
grfErrorClass equ $00001000
mdmErrorClass equ $00001100

sysErrTimeout        equ $00000501
sysErrParamErr       equ $00000502
sysErrNoFreeResource equ $00000503
sysErrNoFreeRAM      equ $00000504
sysErrNotAllowed     equ $00000505
sysErrSemInUse       equ $00000506
sysErrInvalidID      equ $00000507
sysErrOutOfOwnerIDs  equ $00000508
sysErrNoFreeLibSlots equ $00000509
sysErrLibNotFound    equ $0000050a

sysFtrNumROMVersion equ 1
sysFtrNumProductID  equ 2

sysBatteryKindAlkaline equ 0
sysBatteryKindNiCad    equ 1
sysBatteryKindLithium  equ 2

sysTicksPerSecond equ 100

sysRandomMax equ $00007fff


struct SysAppLaunchCmdSaveDataType
    uiComing.b
endstruct

struct SysAppLaunchCmdSystemResetType
    hardReset.b
    createDefaultDB.b
endstruct

struct SysAppLaunchCmdInitDatabaseType
    dbP.l
    creator.l
    type.l
    version.w
endstruct

struct SysAppLaunchCmdSyncCallApplicationType
    action.w
    paramSize.w
    paramP.l
    remoteSocket.b
    tid.b
    handled.b
    bPad.b
endstruct

struct SysLibTblEntryType
    dispatchTblP.l
    globalsP.l
endstruct


; system\memorymgr.h
memIDPtr    equ 0
memIDHandle equ 1

memNewChunkFlagPreLock    equ $00000100
memNewChunkFlagNonMovable equ $00000200
memNewChunkFlagAtStart    equ $00000400
memNewChunkFlagAtEnd      equ $00000800

memDebugModeCheckOnChange        equ $00000001
memDebugModeCheckOnAll           equ $00000002
memDebugModeScrambleOnChange     equ $00000004
memDebugModeScrambleOnAll        equ $00000008
memDebugModeFillFree             equ $00000010
memDebugModeAllHeaps             equ $00000020
memDebugModeRecordMinDynHeapFree equ $00000040




; system\datamgr.h
dmRecAttrCategoryMask equ $0000000f

dmRecNumCategories equ 16

dmCategoryLength equ 16

dmAllCategories   equ $000000ff
dmUnfiledCategory equ 0
dmMaxRecordIndex  equ $0000ffff
dmRecAttrDelete   equ $00000080
dmRecAttrDirty    equ $00000040
dmRecAttrBusy     equ $00000020
dmRecAttrSecret   equ $00000010

dmDBNameLength equ 32

dmHdrAttrResDB        equ $00000001
dmHdrAttrReadOnly     equ $00000002
dmHdrAttrAppInfoDirty equ $00000004
dmHdrAttrBackup       equ $00000008
dmHdrAttrOpen         equ $00008000

dmModeReadOnly   equ $00000001
dmModeWrite      equ $00000002
dmModeReadWrite  equ $00000003
dmModeLeaveOpen  equ $00000004
dmModeExclusive  equ $00000008
dmModeShowSecret equ $00000010

dmSeekForward  equ 1
dmSeekBackward equ -1

struct DmSearchStateType
    info.32
endstruct


dmErrMemError             equ $0000021
dmErrIndexOutOfRange      equ $0000022
dmErrInvalidParam         equ $0000023
dmErrReadOnly             equ $0000024
dmErrDatabaseOpen         equ $0000025
dmErrCantOpen             equ $0000026
dmErrCantFind             equ $0000027
dmErrRecordInWrongCard    equ $0000028
dmErrCorruptDatabase      equ $0000029
dmErrRecordDeleted        equ $00000210
dmErrRecordArchived       equ $00000211
dmErrNotRecordDB          equ $00000212
dmErrNotResourceDB        equ $00000213
dmErrROMBased             equ $00000214
dmErrRecordBusy           equ $00000215
dmErrResourceNotFound     equ $00000216
dmErrNoOpenDatabase       equ $00000217
dmErrInvalidCategory      equ $00000218
dmErrNotValidRecord       equ $00000219
dmErrWriteOutOfBounds     equ $00000220
dmErrSeekFailed           equ $00000221
dmErrAlreadyOpenForWrites equ $00000222
dmErrOpenedByAnotherTask  equ $00000223
dmErrUniqueIDNotFound     equ $00000224
dmErrAlreadyExists        equ $00000225
dmErrInvalidDatabaseName  equ $00000226

; system\errormgr.h

struct ErrExceptionType
    nextP.l
    state.52
    err.l
endstruct

; system\preferences.h

preferenceDataVersion  equ 1
defaultAutoOffDuration equ 2

Australia          equ 0
Austria            equ 1
BelgiumDutch       equ 2
BelgiumFrench      equ 3
Brazil             equ 4
CanadaEnglish      equ 5
CanadaFrench       equ 6
Denmark            equ 7
Finland            equ 8
France             equ 9
Germany            equ 10
Iceland            equ 11
Ireland            equ 12
Italy              equ 13
Japan              equ 14
Mexico             equ 15
Netherlands        equ 16
NewZealand         equ 17
Norway             equ 18
Portugal           equ 19
SouthKorea         equ 20
Spain              equ 21
Sweden             equ 22
SwitzerlandFrench  equ 23
SwitzerlandGerman  equ 24
SwitzerlandItalian equ 25
Taiwan             equ 26
UnitedStates       equ 27
UnitedKingdom      equ 28

tfColon     equ 0
tfColonAMPM equ 1
tfColon24h  equ 2
tfDot       equ 3
tfDotAMPM   equ 4
tfDot24h    equ 5
tfHoursAMPM equ 6
tfHours24h  equ 7

slOn  equ 0
slOff equ 1

dfMDYWithSlashes   equ 0
dfDMYWithSlashes   equ 1
dfDMYWithDots      equ 2
dfDMYWithDashes    equ 3
dfYMDWithSlashes   equ 4
dfYMDWithDots      equ 5
dfYMDWithDashes    equ 6
dfMDYLongWithComma equ 7
dfDMYLong          equ 8
dfDMYLongWithDot   equ 9
dfDMYLongNoDay     equ 10
dfDMYLongWithComma equ 11
dfYMDLongWithDot   equ 12
dfMYMed            equ 13

nfCommaPeriod      equ 0
nfPeriodComma      equ 1
nfSpaceComma       equ 2
nfApostrophePeriod equ 3

struct SystemPreferencesType
    version.w
    country.b
    dateFormat.b
    longDateFormat.b
    weekStartDay.b
    timeFormat.b
    numberFormat.b
    autoOffDuration.b
    sysSoundLevel.b
    alarmSoundLevel.b
    hideSecretRecords.b
    deviceLocked.b
    bPad.b
    sysPrefFlags.w
    sysBatteryKind.b
    bPad2.b
endstruct

; system\timemgr.h
timErrMemory equ $00000a01

; system\alarmmgr.h
almErrMemory equ $00000901
almErrFull   equ $00000902

struct SysAlarmTriggeredParamType
    ref.l
    alarmSeconds.l
    purgeAlarm.w
endstruct

struct SysDisplayAlarmParamType
    ref.l
    alarmSeconds.l
    soundAlarm.w
endstruct


; sysstem\soundmgr.h
sndMaxAmp             equ 64
sndDefaultAmp         equ $00000040
sndCmdFreqDurationAmp equ 1

struct SndCommandType
    cmd.b
    padding.b
    param1.l
    param2.w
    param3.w
endstruct

sndInfo         equ 1
sndWarning      equ 2
sndError        equ 3
sndStartUp      equ 4
sndAlarm        equ 5
sndConfirmation equ 6
sndClick        equ 7

sndErrBadParam   equ $00000801
sndErrBadChannel equ $00000802
sndErrMemory     equ $00000803
sndErrOpen       equ $00000804
sndErrQFull      equ $00000805
sndErrQEmpty     equ $00000806


; system\keyboard.h
kbdShiftKey equ 2
kbdCapsKey  equ 1
kbdNoKey    equ -1

; ui\chars.h
downArrowChr             equ $0000001f
upArrowChr               equ $0000001e
leftArrowChr             equ $0000001c
rightArrowChr            equ $0000001d
pageUpChr                equ $0000000b
pageDownChr              equ $0000000c
lowBatteryChr            equ $00000101
enterDebuggerChr         equ $00000102
nextFieldChr             equ $00000103
startConsoleChr          equ $00000104
menuChr                  equ $00000105
commandChr               equ $00000106
confirmChr               equ $00000107
launchChr                equ $00000108
keyboardChr              equ $00000109
findChr                  equ $0000010a
calcChr                  equ $0000010b
prevFieldChr             equ $0000010c
alarmChr                 equ $0000010d
hardKeyMin               equ $00000200
hardKeyMax               equ $000002ff
hard1Chr                 equ $00000204
hard2Chr                 equ $00000205
hard3Chr                 equ $00000206
hard4Chr                 equ $00000207
hardPowerChr             equ $00000208
hardCradleChr            equ $00000209
nullChr                  equ $00000000
backspaceChr             equ $00000008
tabChr                   equ $00000009
linefeedChr              equ $0000000a
crChr                    equ $0000000d
colonChr                 equ $0000003a
periodChr                equ $0000002e
commaChr                 equ $0000002c
quoteChr                 equ $00000022
returnChr                equ $0000000d
escapeChr                equ $0000001b
spaceChr                 equ $00000020
lastAsciiChr             equ $000000ff
numericSpaceChr          equ $00000080
cutChr                   equ $0000012d
copyChr                  equ $0000012e
pasteChr                 equ $0000012f
lowSingleCommaQuoteChr   equ $00000082
scriptFChr               equ $00000083
lowDblCommaQuoteChr      equ $00000084
horizEllipsisChr         equ $00000085
daggerChr                equ $00000086
dblDaggerChr             equ $00000087
circumflexChr            equ $00000088
perMilleChr              equ $00000089
upSHacekChr              equ $0000008a
leftSingleGuillemetChr   equ $0000008b
upOEChr                  equ $0000008c
diamondChr               equ $0000008d
clubChr                  equ $0000008e
heartChr                 equ $0000008f
spadeChr                 equ $00000090
singleOpenCommaQuoteChr  equ $00000091
singleCloseCommaQuoteChr equ $00000092
dblOpenCommaQuoteChr     equ $00000093
dblCloseCommaQuoteChr    equ $00000094
bulletChr                equ $00000095
enDashChr                equ $00000096
emDashChr                equ $00000097
spacingTildeChr          equ $00000098
trademarkChr             equ $00000099
lowSHacekChr             equ $0000009a
rightSingleGuillemetChr  equ $0000009b
lowOEChr                 equ $0000009c
upYDiaeresisChr          equ $0000009f
nonBreakSpaceChr         equ $000000a0
invertedExclamationChr   equ $000000a1
centChr                  equ $000000a2
poundChr                 equ $000000a3
currencyChr              equ $000000a4
yenChr                   equ $000000a5
brokenVertBarChr         equ $000000a6
sectionChr               equ $000000a7
spacingDiaeresisChr      equ $000000a8
copyrightChr             equ $000000a9
feminineOrdinalChr       equ $000000aa
leftGuillemetChr         equ $000000ab
notChr                   equ $000000ac
softHyphenChr            equ $000000ad
registeredChr            equ $000000ae
spacingMacronChr         equ $000000af
degreeChr                equ $000000b0
plusMinusChr             equ $000000b1
superscript2Chr          equ $000000b2
superscript3Chr          equ $000000b3
spacingAcuteChr          equ $000000b4
microChr                 equ $000000b5
paragraphChr             equ $000000b6
middleDotChr             equ $000000b7
spacingCedillaChr        equ $000000b8
superscript1Chr          equ $000000b9
masculineOrdinalChr      equ $000000ba
rightGuillemetChr        equ $000000bb
fractOneQuarterChr       equ $000000bc
fractOneHalfChr          equ $000000bd
fractThreeQuartersChr    equ $000000be
invertedQuestionChr      equ $000000bf
upAGraveChr              equ $000000c0
upAAcuteChr              equ $000000c1
upACircumflexChr         equ $000000c2
upATildeChr              equ $000000c3
upADiaeresisChr          equ $000000c4
upARingChr               equ $000000c5
upAEChr                  equ $000000c6
upCCedillaChr            equ $000000c7
upEGraveChr              equ $000000c8
upEAcuteChr              equ $000000c9
upECircumflexChr         equ $000000ca
upEDiaeresisChr          equ $000000cb
upIGraveChr              equ $000000cc
upIAcuteChr              equ $000000cd
upICircumflexChr         equ $000000ce
upIDiaeresisChr          equ $000000cf
upEthChr                 equ $000000d0
upNTildeChr              equ $000000d1
upOGraveChr              equ $000000d2
upOAcuteChr              equ $000000d3
upOCircumflexChr         equ $000000d4
upOTildeChr              equ $000000d5
upODiaeresisChr          equ $000000d6
multiplyChr              equ $000000d7
upOSlashChr              equ $000000d8
upUGraveChr              equ $000000d9
upUAcuteChr              equ $000000da
upUCircumflexChr         equ $000000db
upUDiaeresisChr          equ $000000dc
upYAcuteChr              equ $000000dd
upThorn                  equ $000000de
lowSharpSChr             equ $000000df
lowAGraveChr             equ $000000e0
lowAAcuteChr             equ $000000e1
lowACircumflexChr        equ $000000e2
lowATildeChr             equ $000000e3
lowADiaeresisChr         equ $000000e4
lowARingChr              equ $000000e5
lowAEChr                 equ $000000e6
lowCCedillaChr           equ $000000e7
lowEGraveChr             equ $000000e8
lowEAcuteChr             equ $000000e9
lowECircumflexChr        equ $000000ea
lowEDiaeresisChr         equ $000000eb
lowIGraveChr             equ $000000ec
lowIAcuteChr             equ $000000ed
lowICircumflexChr        equ $000000ee
lowIDiaeresisChr         equ $000000ef
lowEthChr                equ $000000f0
lowNTildeChr             equ $000000f1
lowOGraveChr             equ $000000f2
lowOAcuteChr             equ $000000f3
lowOCircumflexChr        equ $000000f4
lowOTildeChr             equ $000000f5
lowODiaeresisChr         equ $000000f6
divideChr                equ $000000f7
lowOSlashChr             equ $000000f8
lowUGraveChr             equ $000000f9
lowUAcuteChr             equ $000000fa
lowUCircumflexChr        equ $000000fb
lowUDiaeresisChr         equ $000000fc
lowYAcuteChr             equ $000000fd
lowThorn                 equ $000000fe
lowYDiaeresisChr         equ $000000ff

symbolLeftArrow           equ 3
symbolRightArrow          equ 4
symbolUpArrow             equ 5
symbolDownArrow           equ 6
symbolSmallDownArrow      equ 7
symbolSmallUpArrow        equ 8
symbolMemo                equ 9
symbolHelp                equ 10
symbolNote                equ 11
symbolNoteSelected        equ 12
symbolCapsLock            equ 13
symbolNumLock             equ 14
symbolShiftUpper          equ 15
symbolShiftPunc           equ 16
symbolShiftExt            equ 17
symbolShiftNone           equ 18
symbolNoTime              equ 19
symbol7ScrollUp           equ 1
symbol7ScrollDown         equ 2
symbol7ScrollUpDisabled   equ 3
symbol7ScrollDownDisabled equ 4
symbolCheckboxOff         equ 0
symbolCheckboxOn          equ 1
symbol11LeftArrow         equ 2
symbol11RightArrow        equ 3

glfCapsLock         equ $00000001
glfNumLock          equ $00000002
gsiShiftNone        equ 0
gsiNumLock          equ 1
gsiCapsLock         equ 2
gsiShiftPunctuation equ 3
gsiShiftExtended    equ 4
gsiShiftUpper       equ 5
gsiShiftLower       equ 6

; ui\clipboard.h
numClipboardForamts equ 3
cbdMaxTextLength    equ 1000

clipboardText   equ 0
clipboardInk    equ 1
clipboardBitmap equ 2

struct ClipboardItem
    item.l
    length.w
endstruct

; ui\control.h
buttonCtl            equ 0
pushButtonCtl        equ 1
checkboxCtl          equ 2
popupTriggerCtl      equ 3
selectorTriggerCtl   equ 4
repeatingButtonCtl   equ 5
noButtonFrame        equ 0
standardButtonFrame  equ 1
boldButtonFrame      equ 2
rectangleButtonFrame equ 3

ControlAttrType_usable_shift     equ 0
ControlAttrType_usable_count     equ 1
ControlAttrType_usable_mask      equ $00000001
ControlAttrType_enabled_shift    equ 1
ControlAttrType_enabled_count    equ 1
ControlAttrType_enabled_mask     equ $00000002
ControlAttrType_visible_shift    equ 2
ControlAttrType_visible_count    equ 1
ControlAttrType_visible_mask     equ $00000004
ControlAttrType_on_shift         equ 3
ControlAttrType_on_count         equ 1
ControlAttrType_on_mask          equ $00000008
ControlAttrType_leftAnchor_shift equ 4
ControlAttrType_leftAnchor_count equ 1
ControlAttrType_leftAnchor_mask  equ $00000010
ControlAttrType_frame_shift      equ 5
ControlAttrType_frame_count      equ 3
ControlAttrType_frame_mask       equ $000000e0


struct ControlType
    id.w
    bounds.RectangleType
    text.l
    attr.w
    style.w
    font.b
    group.b
endstruct

; ui\field.h

maxFieldTextLen equ $00007fff
maxFieldLines   equ 11

leftAlign   equ 0
centerAlign equ 1
rightAlign  equ 2

undoBufferSize equ 100
undoNone       equ 0
undoTyping     equ 1
undoBackspace  equ 2
undoDelete     equ 3
undoPaste      equ 4
undoCut        equ 5

struct FieldUndoType
    mode.w
    start.w
    end.w
    bufferLen.w
    buffer.l
endstruct

struct LineInfoType
    start.w
    length.w
endstruct


FieldAttrType_usable_shift        equ 0
FieldAttrType_usable_count        equ 1
FieldAttrType_usable_mask         equ $00000001
FieldAttrType_visible_shift       equ 1
FieldAttrType_visible_count       equ 1
FieldAttrType_visible_mask        equ $00000002
FieldAttrType_editable_shift      equ 2
FieldAttrType_editable_count      equ 1
FieldAttrType_editable_mask       equ $00000004
FieldAttrType_singleLine_shift    equ 3
FieldAttrType_singleLine_count    equ 1
FieldAttrType_singleLine_mask     equ $00000008
FieldAttrType_hasFocus_shift      equ 4
FieldAttrType_hasFocus_count      equ 1
FieldAttrType_hasFocus_mask       equ $00000010
FieldAttrType_dynamicSize_shift   equ 5
FieldAttrType_dynamicSize_count   equ 1
FieldAttrType_dynamicSize_mask    equ $00000020
FieldAttrType_insPtVisible_shift  equ 6
FieldAttrType_insPtVisible_count  equ 1
FieldAttrType_insPtVisible_mask   equ $00000040
FieldAttrType_dirty_shift         equ 7
FieldAttrType_dirty_count         equ 1
FieldAttrType_dirty_mask          equ $00000080
FieldAttrType_underlined_shift    equ 8
FieldAttrType_underlined_count    equ 2
FieldAttrType_underlined_mask     equ $00000300
FieldAttrType_justification_shift equ 10
FieldAttrType_justification_count equ 2
FieldAttrType_justification_mask  equ $00000c00

struct FieldType
    id.w
    rect.RectangleType
    attr.w
    text.l
    textHandle.l
    lines.l
    textLen.w
    textBlockSize.w
    maxChars.w
    selFirstPos.w
    selLastPos.w
    insPtXPos.w
    insPtYPos.w
    fontID.b
    padding.b
endstruct

; ui\list.h
noListSelection equ $0000ffff

ListAttrType_usable_shift   equ 0
ListAttrType_usable_count   equ 1
ListAttrType_usable_mask    equ $00000001
ListAttrType_enabled_shift  equ 1
ListAttrType_enabled_count  equ 1
ListAttrType_enabled_mask   equ $00000002
ListAttrType_visible_shift  equ 2
ListAttrType_visible_count  equ 1
ListAttrType_visible_mask   equ $00000004
ListAttrType_poppedUp_shift equ 3
ListAttrType_poppedUp_count equ 1
ListAttrType_poppedUp_mask  equ $00000008
ListAttrType_reserved_shift equ 4
ListAttrType_reserved_count equ 4
ListAttrType_reserved_mask  equ $000000f0

struct ListType
    id.w
    bounds.RectangleType
    attr.b
    padding.b
    itemsText.l
    numItems.w
    currentItem.w
    topItem.w
    font.w
    popupWin.l
    drawItemsCallback.l
endstruct

; ui\table.h
tableDefaultColumnSpacing equ 1
tableNoteIndicatorWidth   equ 7
tableNoteIndicatorHeight  equ 11

checkboxTableItem     equ 0
customTableItem       equ 1
dateTableItem         equ 2
labelTableItem        equ 3
numericTableItem      equ 4
popupTriggerTableItem equ 5
textTableItem         equ 6
textWithNoteTableItem equ 7
timeTableItem         equ 8

struct TableItemType
    itemType.b
    fontID.b
    intValue.w
    ptr.l
endstruct

struct TableColumnAttrType
    width.w
    usable.w
    spacing.w
    drawCallback.l
    loadDataCallback.l
    saveDataCallback.l
endstruct

struct TableRowAttrType
    id.w
    height.w
    data.l
    usable.b
    selectable.b
    invalid.w
endstruct

TableAttrType_visible_shift  equ 0
TableAttrType_visible_count  equ 1
TableAttrType_visible_mask   equ $00000001
TableAttrType_editable_shift equ 1
TableAttrType_editable_count equ 1
TableAttrType_editable_mask  equ $00000002
TableAttrType_editing_shift  equ 2
TableAttrType_editing_count  equ 1
TableAttrType_editing_mask   equ $00000004
TableAttrType_selected_shift equ 3
TableAttrType_selected_count equ 1
TableAttrType_selected_mask  equ $00000008

struct TableType
    id.w
    bounds.RectangleType
    attr.b
    padding.b
    numColumns.w
    numRows.w
    currentRow.w
    currentColumn.w
    topRow.w
    columnAttrs.l
    rowAttrs.l
    items.l
    currentField.FieldType
endstruct

; ui\form.h
noFocus equ $0000ffff

frmRedrawUpdateCode equ $00008000

informationAlert  equ 0
confirmationAlert equ 1
warningAlert      equ 2
errorAlert        equ 3

struct AlertTemplateType
    alertType.w
    helpRscID.w
    numButtons.w
    defaultButton.w
endstruct


frmFieldObj         equ 0
frmControlObj       equ 1
frmListObj          equ 2
frmTableObj         equ 3
frmBitmapObj        equ 4
frmLineObj          equ 5
frmFrameObj         equ 6
frmRectangleObj     equ 7
frmLabelObj         equ 8
frmTitleObj         equ 9
frmPopupObj         equ 10
frmGraffitiStateObj equ 11
frmGadgetObj        equ 12

FormObjAttrType_usable_shift equ 0
FormObjAttrType_usable_count equ 1
FormObjAttrType_usable_mask  equ $00000001

struct FormBitmapType
    attr.b
    padding.b
    pos.PointType
    rscID.w
endstruct

struct FormLineType
    attr.b
    padding.b
    point1.PointType
    point2.PointType
endstruct

struct FormFrameType
    id.w
    attr.b
    padding.b
    rect.RectangleType
    frameType.w
endstruct

struct FormRectangleType
    attr.b
    padding.b
    rect.RectangleType
endstruct

struct FormLabelType
    id.w
    pos.PointType
    attr.b
    padding.b
    fontID.b
    padding.b
    text.l
endstruct

struct FormTitleType
    rect.RectangleType
    text.l
endstruct

struct FormPopupType
    controlID.w
    listID.w
endstruct

struct FrmGraffitiStateType
    pos.PointType
endstruct

struct FormGadgetType
    id.w
    attr.b
    padding.b
    rect.RectangleType
    data.l
endstruct

struct FormObjListType
    objectType.w
    object.l
endstruct

FormAttrType_usable_shift  equ 0
FormAttrType_usable_count  equ 1
FormAttrType_usable_mask   equ $00000001
FormAttrType_visible_shift equ 1
FormAttrType_visible_count equ 1
FormAttrType_visible_mask  equ $00000002
FormAttrType_dirty_shift   equ 2
FormAttrType_dirty_count   equ 1
FormAttrType_dirty_mask    equ $00000004
FormAttrType_saveBehind_shift  equ 3
FormAttrType_saveBehind_count  equ 1
FormAttrType_saveBehind_mask   equ $00000008
FormAttrType_graffitiShift_shift equ 4
FormAttrType_graffitiShift_count equ 1
FormAttrType_graffitiShift_mask  equ $00000010

struct FormType
    window.WindowType
    formId.w
    attr.w
    padding.w
    bitsBehindForm.l
    handler.l
    focus.w
    defaultButton.w
    helpRscId.w
    menuRscId.w
    numObjects.w
    objects.l
endstruct

; ui\menu.h
noMenuSelection     equ -1
noMenuItemSelection equ -1
MenuSeparatorChar   equ $0000002d

struct MenuItemType
    id.w
    command.b
    unused.b
    itemStr.l
endstruct

struct MenuPullDownType
    menuWin.l
    bounds.RectangleType
    bitsBehind.l
    titleBounds.RectangleType
    title.l
    numItems.w
    items.l
endstruct

MenuBarAttrType_visible_shift        equ 0
MenuBarAttrType_visible_count        equ 1
MenuBarAttrType_visible_mask         equ $00000001
MenuBarAttrType_commandPending_shift equ 1
MenuBarAttrType_commandPending_count equ 1
MenuBarAttrType_commandPending_mask  equ $00000002
MenuBarAttrType_insPtEnabled_shift   equ 2
MenuBarAttrType_insPtEnabled_count   equ 1
MenuBarAttrType_insPtEnabled_mask    equ $00000004
MenuBarAttrType_sizeof               equ 2

struct MenuBarType
    barWin.l
    bitsBehind.l
    savedActiveWin.l
    bitsBehindStatus.l
    attr.b
    padding.b
    curMenu.w
    curItem.w
    commandTick.l
    numMenus.w
    menus.l
endstruct

; ui\category.h

struct AppInfoType
    renamedCategories.w
    categoryLabels.256
    categoryUniqIDs.16
    lastUniqID.b
endstruct

; ui\find.h
maxFinds equ 9
maxFindStrLen equ 16

struct FindMatchType
    appCardNo.w
    appDbID.l
    foundInCaller.w
    dbCardNo.w
    dbID.l
    recordNum.w
    matchPos.w
    matchFieldNum.w
    matchCustom.l
endstruct

struct FindParamsType
    dbAccesMode.w
    recordNum.w
    more.b
    strAsTyped.17
    strToFind.17
    numMatches.w
    lineNumber.w
    continuation.b
    searchedCaller.b
    callerAppDbID.l
    callerAppCardNo.w
    appDbID.l
    appCardNo.w
    newSearch.w
    searchState.DmSearchStateType
    match0.FindMatchType
    match1.FindMatchType
    match2.FindMatchType
    match3.FindMatchType
    match4.FindMatchType
    match5.FindMatchType
    match6.FindMatchType
    match7.FindMatchType
    match8.FindMatchType
endstruct

struct GoToParamsType
    searchStrLen.w
    dbCardNo.w
    dbID.l
    recordNum.w
    matchPos.w
    matchFieldNum.w
    matchCustom.l
endstruct

; system\datetime.h
struct DateTimeType
    second.w
    minute.w
    hour.w
    day.w
    month.w
    year.w
    weekDay.w
endstruct

struct TimeType
    hours.b
    minutes.b
endstruct

noTime equ -1

DateType_year_shift  equ 0
DateType_year_count  equ 7
DateType_year_mask   equ $0000007f
DateType_month_shift equ 7
DateType_month_count equ 4
DateType_month_mask  equ $00000780
DateType_day_shift   equ 11
DateType_day_count   equ 5
DateType_day_mask    equ $0000f800


timeStringLength  equ 9
dateStringLength  equ 9
longDateStrLenght equ 15
firstYear         equ 1904
numberOfYears     equ 128
lastYear          equ $000007ef
minutesInSeconds  equ 60
hoursInMinutes    equ 60
hoursInSeconds    equ $00000e10
hoursPerDay       equ 24
daysInSeconds     equ $00015180
daysInWeek        equ 7
daysInYear        equ 365
daysInLeapYear    equ 366
daysInFourYears   equ $000005b5
monthsInYear      equ 12
maxTime           equ $00477180

sunday     equ 0
monday     equ 1
tuesday    equ 2
wednesday  equ 3
thursday   equ 4
friday     equ 5
saturday   equ 6

january    equ 1
february   equ 2
march      equ 3
april      equ 4
may        equ 5
june       equ 6
july       equ 7
august     equ 8
september  equ 9
october    equ 10
november   equ 11
december   equ 12

dom1stSun  equ 0
dom1stMon  equ 1
dom1stTue  equ 2
dom1stWen  equ 3
dom1stThu  equ 4
dom1stFri  equ 5
dom1stSat  equ 6
dom2ndSun  equ 7
dom2ndMon  equ 8
dom2ndTue  equ 9
dom2ndWen  equ 10
dom2ndThu  equ 11
dom2ndFri  equ 12
dom2ndSat  equ 13
dom3rdSun  equ 14
dom3rdMon  equ 15
dom3rdTue  equ 16
dom3rdWen  equ 17
dom3rdThu  equ 18
dom3rdFri  equ 19
dom3rdSat  equ 20
dom4thSun  equ 21
dom4thMon  equ 22
dom4thTue  equ 23
dom4thWen  equ 24
dom4thThu  equ 25
dom4thFri  equ 26
dom4thSat  equ 27
domLastSun equ 28
domLastMon equ 29
domLastTue equ 30
domLastWen equ 31
domLastThu equ 32
domLastFri equ 33
domLastSat equ 34

struct DaySelectorType
    bounds.RectangleType
    visible.w
    visibleMonth.w
    visibleYear.w
    selected.DateTimeType
endstruct

daySelectorMinYear equ $00000770
daySelectorMaxYear equ $000007ef
NumericSpaceChar   equ $00000080

; ui\seltime.h

struct HMSTime
    hours.b
    minutes.b
    seconds.b
endstruct

; system\globals.h
sysUIRsvGlobalsSize equ $000000a0

struct FixedGlobalsType
    memCardSlots.b
    dbgWasEntered.b
    memCardInfoP.l
    memSemaphoreID.l
    memDebugMode.w
    dmOpenList.l
    dbgInDebugger.b
    dbgTracing.b
    dbgGlobalsP.l
    dbgSerGlobalsP.l
    sysAppInfoP.l
    sysKernelDataP.l
    sysDispatchTableP.l
    sysOwnerIDsInUse.l
    sysAMXAppInfoP.l
    sysClockFreq.l
    sysHardKeyCreators.l
    sysBatteryCheckTimer.w
    sysBatteryMinThreshold.b
    hwrBatteryLevel.b
    sysNextBatteryAlertTimer.w
    sysBatteryWarnThreshold.b
    sysDispatchTableRev.b
    sysDispatchTableSize.w
    sysLibTableP.l
    sysLibTableEntries.w
    sysConsoleStackChunkP.l
    sysUIShellAppInfoP.l
    sysTimerID.l
    sysAutoOffEvtTicks.l
    sysAutoOffSeconds.w
    sysRandomSeed.l
    slkGlobalsP.l
    serGlobalsP.l
    scrGlobalsP.l
    fplGlobalsP.l
    penGlobalsP.l
    sysEvtMgrGlobalsP.l
    sndGlobalsP.l
    timGlobalsP.l
    almGlobalsP.l
    ftrGlobalsP.l
    grfGlobalsP.l
    keyGlobalsP.l
    uiGlobals.160
    uiExtensionsP.l
    curUIAppInfoP.l
    nextUIAppDBID.l
    nextUIAppCmd.w
    nextUIAppCmdPBP.l
    nextUIAppCardNo.b
    hwrDataWELevel.b
    hwrWakeUp.w
    hwrCPUDutyCycle.b
    hwrPenDown.b
    hwrCurTicks.l
    hwrTotalRAMSize.l
    hwrDozeSubTicks.l
    padGlobalsP.l
    sysResetFlags.b
    sysBatteryKind.b
    memMinDynHeapFree.l
    sysPrefFlags.w
    sysGlobalsP.l
    sysMiscFlags.w
endstruct

struct LowMemHdrType
    vectors.M68KExcTableType
    globals.FixedGlobalsType
endstruct

PilotGlobalsP equ 0

; ui\uiglobals.h
UINumFonts equ 7
eventQueueSize equ 10

struct UIGlobalsType
    activeWindow.l
    displayWindow.l
    drawWindow.l
    firstWindow.l
    exitWindowID.l
    enterWindowID.l
    exitedWindowID.l
    gState.GraphicStateType
    eventQ.l
    eventQIndex.w
    eventQLength.w
    lastScreenX.w
    lastScreenY.w
    lastPenDown.w
    needNullTickCount.l
    uiCurrentFontPtr.l
    uiFontTable.28
    uiCurrentFontID.b
    padding.b
    currentForm.l
    insPtIsEnabled.b
    insPtOn.b
    insPtLoc.PointType
    insPtHeight.w
    insPtLastTick.l
    insPtBitsBehind.l
    clipboard.18
    uiCurrentMenu.l
    undoGlobals.FieldUndoType
    gsiState.b
    gsiIsEnabled.b
    gsiLocation.PointType
endstruct

; system\serialmgr.h
serErrBadParam    equ $00000301
serErrBadPort     equ $00000302
serErrNoMem       equ $00000303
serErrBadConnID   equ $00000304
serErrTimeOut     equ $00000305
serErrLineErr     equ $00000306
serErrAlreadyOpen equ $00000307
serErrStillOpen   equ $00000308
serErrNotOpen     equ $00000309

struct SerSettingsType
    baudRate.l
    flags.l
    ctsTimeout.l
endstruct

serSettingsFlagStopBitsM    equ $00000001
serSettingsFlagStopBits1    equ $00000000
serSettingsFlagStopBits2    equ $00000001
serSettingsFlagParityOnM    equ $00000002
serSettingsFlagParityEvenM  equ $00000004
serSettingsFlagXonXoffM     equ $00000008
serSettingsFlagRTSAutoM     equ $00000010
serSettingsFlagCTSAutoM     equ $00000020
serSettingsFlagBitsPerCharM equ $000000c0
serSettingsFlagBitsPerChar5 equ $00000000
serSettingsFlagBitsPerChar6 equ $00000040
serSettingsFlagBitsPerChar7 equ $00000080
serSettingsFlagBitsPerChar8 equ $000000c0

serDefaultSettings equ $000000d0

serLineErrorParity    equ $00000001
serLineErrorHWOverrun equ $00000002
serLineErrorFraming   equ $00000004
serLineErrorBreak     equ $00000008
serLineErrorHShake    equ $00000010
serLineErrorSWOverrun equ $00000020

sysLibTrapSerName             equ 43008
sysLibTrapSerOpen             equ 43009
sysLibTrapSerClose            equ 43010
sysLibTrapSerSleep            equ 43011
sysLibTrapSerWake             equ 43012
sysLibTrapSerGetSettings      equ 43013
sysLibTrapSerSetSettings      equ 43014
sysLibTrapSerGetStatus        equ 43015
sysLibTrapSerClearErr         equ 43016
sysLibTrapSerSend             equ 43017
sysLibTrapSerSendWait         equ 43018
sysLibTrapSerSendCheck        equ 43019
sysLibTrapSerSendFlush        equ 43020
sysLibTrapSerReceive          equ 43021
sysLibTrapSerReceiveWait      equ 43022
sysLibTrapSerReceiveCheck     equ 43023
sysLibTrapSerReceiveFlush     equ 43024
sysLibTrapSerSetReceiveBuffer equ 43025

; system\featuremgr.h
ftrErrInvalidParam  equ $00000c01
ftrErrNoSuchFeature equ $00000c02
ftrErrAlreadyExists equ $00000c03
ftrErrROMBased      equ $00000c04
ftrErrInternalErr   equ $00000c05

; system\systemprv.h
struct SysAppInfoType
    cmd.w
    cmdPBP.l
    launchFlags.w
    taskID.l
    codeH.l
    dbP.l
    stackP.l
    globalsChunkP.l
    memOwnerID.w
    dmAccessP.l
    dmLastErr.w
    errExceptionP.l
endstruct

        list 1                  ;renable listing
