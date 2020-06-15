.globl  _add

_add:
    pushl   %ebp
    movl    %esp, %ebp

    movl    8(%ebp), %edx
    movl    12(%ebp), %eax

    addl    %edx, %eax

    leave
    ret    
    