register_A: .word 0
register_X: .word 0
register_Y: .word 0

.globl _loadVM
_loadVM:
	ldr r0, register_A
	ldr r1, register_X
	ldr r2, register_Y
	mov pc, lr

vmContinueHandler: .word 0

.globl _enterVM
_enterVM:
	bl _loadVM
	/*ldr lr, cCodeLR FIXME*/
	bl vmContinueHandler
.globl _initVM
_initVM:
	b resetVM
_resetVM:
	mov pc, lr
_exitVM:
	/*ldr lr, cCodeLR FIXME */
	mov pc, lr
