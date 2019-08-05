#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>



unsigned long	ctr1000;

void syscallsummary_start()
{


int i,j;
struct pentry *p1;

kprintf("\nprintsyscallsummary()\n");

for(j=0;j<NPROC;j++)
{
p1=&proctab[j];
for(i=0;i<27;i++)
{
p1->call[i]=0;
p1->time[i]=0;
}
}
}





void syscallsummary_stop()
{
}



void printsyscallsummary()
{
int i,j;

struct pentry *p1;

kprintf("\nprintsyscallsummary()\n");

for(j=0;j<NPROC;j++)
{


p1=&proctab[j];

if(p1->flag==1)
{
kprintf("\nProcess Id [pid %d] [pname: %s]\n ",j, p1->pname );



for(i=0;i<27;i++)
{

if(p1->call[i]>0)
{

switch(i)
{

case 0: kprintf("syscal getpid: count = %d average execution time = %d\n", p1->call[i], p1->time[i]/p1->call[i]);break;
case 1: kprintf("syscal kill: count = %d average execution time = %d\n", p1->call[i], p1->time[i]/p1->call[i]);break;
case 2: kprintf("syscal freemem: count = %d average execution time = %d\n", p1->call[i], p1->time[i]/p1->call[i]);break;
case 3: kprintf("syscal chprio: count = %d average execution time = %d\n", p1->call[i], p1->time[i]/p1->call[i]);break;
case 4: kprintf("syscal getprio: count = %d average execution time = %d\n", p1->call[i], p1->time[i]/p1->call[i]);break;
case 5: kprintf("syscal gettime: count = %d average execution time = %d\n", p1->call[i], p1->time[i]/p1->call[i]);break;
case 6: kprintf("syscal receive: count = %d average execution time = %d\n", p1->call[i], p1->time[i]/p1->call[i]);break;
case 7: kprintf("syscal recvclr: count = %d average execution time = %d\n", p1->call[i], p1->time[i]/p1->call[i]);break;
case 8: kprintf("syscal recvtim: count = %d average execution time = %d\n", p1->call[i], p1->time[i]/p1->call[i]);break;
case 9: kprintf("syscal resume: count = %d average execution time = %d\n", p1->call[i], p1->time[i]/p1->call[i]);break;
case 10: kprintf("syscal scount: count = %d average execution time = %d\n", p1->call[i], p1->time[i]/p1->call[i]);break;
case 11: kprintf("syscal sdelete: count = %d average execution time = %d\n", p1->call[i], p1->time[i]/p1->call[i]);break;
case 12: kprintf("syscal send: count = %d average execution time = %d\n", p1->call[i], p1->time[i]/p1->call[i]);break;
case 13: kprintf("syscal setdev: count = %d average execution time = %d\n", p1->call[i], p1->time[i]/p1->call[i]);break;
case 14: kprintf("syscal setnok: count = %d average execution time = %d\n", p1->call[i], p1->time[i]/p1->call[i]);break;
case 15: kprintf("syscal screate: count = %d average execution time = %d\n", p1->call[i], p1->time[i]/p1->call[i]);break;
case 16: kprintf("syscal signal: count = %d average execution time = %d\n", p1->call[i], p1->time[i]/p1->call[i]);break;
case 17: kprintf("syscal signaln: count = %d average execution time = %d\n", p1->call[i], p1->time[i]/p1->call[i]);break;
case 18: kprintf("syscal sleep: count = %d average execution time = %d\n", p1->call[i], p1->time[i]/p1->call[i]);break;
case 19: kprintf("syscal sleep10: count = %d average execution time = %d\n", p1->call[i], p1->time[i]/p1->call[i]);break;
case 20: kprintf("syscal sleep100: count = %d average execution time = %d\n", p1->call[i], p1->time[i]/p1->call[i]);break;
case 21: kprintf("syscal sleep1000: count = %d average execution time = %d\n", p1->call[i], p1->time[i]/p1->call[i]);break;
case 22: kprintf("syscal sreset: count = %d average execution time = %d\n", p1->call[i], p1->time[i]/p1->call[i]);break;
case 23: kprintf("syscal stacktrace: count = %d average execution time = %d\n", p1->call[i], p1->time[i]/p1->call[i]);break;
case 24: kprintf("syscal suspend: count = %d average execution time = %d\n", p1->call[i], p1->time[i]/p1->call[i]);break;
case 25: kprintf("syscal unsleep: count = %d average execution time = %d\n", p1->call[i], p1->time[i]/p1->call[i]);break;
case 26: kprintf("syscal wait: count = %d average execution time = %d\n", p1->call[i], p1->time[i]/p1->call[i]);break;




default: break;

}


}
}
}
}

}
