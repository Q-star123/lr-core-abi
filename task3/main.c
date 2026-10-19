#include "context.h"
#include <stdio.h>

context_t main_ctx;
context_t worker_ctx;
char worker_stack[4096];

void worker_func()
{
    jmp_to(&main_ctx, 123);
}

int main(void)
{
    set_ctx(&main_ctx);

    if (main_ctx.rip == 0)
    {
        worker_ctx.rsp = (unsigned long)(worker_stack + sizeof(worker_stack));
        worker_ctx.rip = (unsigned long)worker_func;
        jmp_to(&worker_ctx, 0);
    }
    else
    {
        printf("023");
    }

    return 0;
}

