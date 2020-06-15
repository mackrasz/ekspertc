	.section .rdata,"dr"
LC0:
	.ascii "Hello\0"

	.text
	.globl	_main

_main:
	pushl	%ebp
	movl	%esp, %ebp
	
	movl	$LC0, (%esp)
	call	_printf
	movl	$123, %eax
	
	leave
	ret

