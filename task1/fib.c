#include<stdio.h>
long long fib(int x)
{
long long a = 0;
long long b = 1;
long long c;
if (x==0) 
return 0;
if (x==1)
return 1;
for(int i=2;i<=x;i++)
{
c = b;
b = a + b;
a = c;
}
return b;
}
