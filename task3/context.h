#ifndef CONTEXT_H
#define CONTEXT_H

/* 要求：完整保存程序执行所需上下文；切回后调用者应能继续往下执行。 */
typedef struct {
    unsigned long rip;    // 0
    unsigned long rsp;    // 8
    unsigned long rbx;    //16
    unsigned long rbp;    //24
    unsigned long r12;    //32
    unsigned long r13;    //40
    unsigned long r14;    //48
    unsigned long r15;    //56
} context_t;

long set_ctx(context_t *ctx);
void jmp_to(context_t *ctx, long value);

#endif
