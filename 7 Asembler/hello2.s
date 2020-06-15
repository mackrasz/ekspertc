	.section .rdata,"dr"
LC0:
	.ascii "%d\0"
	.text
	.globl	_main
	
_main:
	pushl	%ebp
	movl	%esp, %ebp
	
	#printf("%d", add(2, 3))
	pushl	$2
	pushl	$3
	call	_add

	pushl 	%eax
	pushl	$LC0
	call	_printf
	movl	$123, %eax
	leave
	ret

_add:
	pushl	%ebp
	movl	%esp, %ebp

	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	add		%edx, %eax

	leave
	ret
