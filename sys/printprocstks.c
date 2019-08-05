#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>

static unsigned long *esp;




void printprocstks(int priority)
{

kprintf("\n printprocstks() \n");
int i=0;


struct pentry *Higher_Priority, *Curr_Process;




Curr_Process=&proctab[currpid];

if (Curr_Process->pprio<priority)
{
asm("movl %esp,esp");

kprintf("process [%s] \n", Curr_Process->pname );
kprintf("pid: %d\n", currpid);
kprintf("priority: %d \n", Curr_Process->pprio);
kprintf("base: 0x%08X \n", Curr_Process->pbase);
kprintf("limit: 0x%08X \n", Curr_Process->plimit );
kprintf("length: %d \n", Curr_Process->pstklen);
kprintf("pointer: 0x%08X \n", esp);
}




for(i=0;i<NPROC;i++)
{
Higher_Priority= &proctab[i];


if( (i!=currpid) && (Higher_Priority->pprio<priority))
{

if(Higher_Priority->pstate!=PRFREE)
{
kprintf("process [%s] \n", Higher_Priority->pname );
kprintf("pid: %d \n", i);
kprintf("priority: %d \n", Higher_Priority->pprio);
kprintf("base: 0x%08X \n", Higher_Priority->pbase);
kprintf("limit: 0x%08X \n", Higher_Priority->plimit );
kprintf("length: %d \n", Higher_Priority->pstklen);
kprintf("pointer: 0x%08X \n", Higher_Priority->pesp);
}
}

}
}


