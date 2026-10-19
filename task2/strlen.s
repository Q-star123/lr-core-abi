.global my_strlen
my_strlen:
    xor %rcx, %rcx
loop_start:
    movb (%rdi), %al
    test %al, %al
    jz loop_end
    inc %rcx
    inc %rdi
    jmp loop_start
loop_end:
    mov %rcx, %rax
    ret
