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
	push lr
	cmp vmContinueHandler, 0
	bleq initVM
	bl vmContinueHandler
	pop lr
	mov pc, lr
