#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include<lab0.h>

static unsigned long	*esp;
static unsigned long	*ebp;


void printtos()
{

unsigned long *a, *b;
int i;


kprintf("\nprinttos()\n");


asm("movl %esp,esp");
asm("movl %ebp,ebp");
a=esp;
b=ebp;

kprintf("Before [0x%08x] : 0x%08x\n", b+2, *(b+2));
kprintf("After  [0x%08x] : 0x%08x\n", b, *(b));


for(i=0;i<4;i++)
{

kprintf("element [0x%08X] : 0x%08x \n", a,*a);
a=a+1;
}


}
