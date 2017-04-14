; Hello.asm -- a minimal pilot application to be assembled by Pila

	appl	"Hello", 'hllo'

	include	"Pilot.inc"

	include	"Startup.inc"

kidrHelloAlert	equ	1000
kidrHelpString	equ	1001
kidrPREF	equ	1
kidrTVER	equ	1

	code

PilotMain		;(word cmd, void *cmdPBP, word launchFlags)
cmd	set	8
cmdPBP	set	10
launchFlags set	14
	
	link	a6,#0

	tst.w	cmd(a6)			;sysAppLaunchCmdNormalLaunch is 0
	bne	PmReturn		;not a normal launch, bag out

	move.w	#kidrHelloAlert,-(a7)	;push alert id on stack
	trap	#15			;PalmOS API call
	dc.w	sysTrapFrmAlert		;invoke the alert dialog!

PmReturn
	unlk	a6
	rts

; Alert resource

	res	'Talt', kidrHelloAlert	;Alert resource
	dc.w	informationAlert	;alertType
	dc.w	kidrHelpString		;helpRscID
	dc.w	1			;numButtons
	dc.w	0			;defaultButton
	dc.b	'Red Alert', 0		;title text
	dc.b	'Hello world!', 0	;message text
	dc.b	'Most excellent!', 0	;button text

; Help string resource

	res	'tSTR', kidrHelpString
	dc.b	'I am a Pilot programming stud!', 0

; Version resource

	res	'tver', kidrTVER
	dc.b	'1.0', 0

; 'pref' resource. Defines app launch flags, stack and heap size

	res	'PREF', kidrPref
	dc.w	sysAppLaunchFlagNewStack|sysAppLaunchFlagNewGlobals|sysAppLaunchFlagUIApp|sysAppLaunchFlagSubCall
	dc.l	$1000			; stack size
	dc.l	$1000			; heap size

	end
