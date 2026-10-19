.global set_ctx
.global jmp_to
.global start_thunk

set_ctx:
    movq %rbx, 16(%rdi)
    movq %rbp, 24(%rdi)
    movq %r12, 32(%rdi)
    movq %r13, 40(%rdi)
    movq %r14, 48(%rdi)
    movq %r15, 56(%rdi)

    movq %rsp, 8(%rdi)
    movq (%rsp), %rax
    movq %rax, 0(%rdi)

    xorl %eax, %eax
    ret

jmp_to:
    movq 16(%rdi), %rbx
    movq 24(%rdi), %rbp
    movq 32(%rdi), %r12
    movq 40(%rdi), %r13
    movq 48(%rdi), %r14
    movq 56(%rdi), %r15

    movq 8(%rdi), %rsp
    movq 0(%rdi), %rdx
    movq %rsi, %rax
    jmp *%rdx

start_thunk:
    mov $60, %rax
    mov $0, %rdi
    syscall
