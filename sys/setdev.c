/* setdev.c - setdev */

#include <conf.h>
#include <kernel.h>
#include <proc.h>

/*------------------------------------------------------------------------
 *  setdev  -  set the two device entries in the process table entry
 *------------------------------------------------------------------------
 *
 */

unsigned long ctr1000;

SYSCALL	setdev(int pid, int dev1, int dev2)
{

        struct pentry *callp;
callp=&proctab[currpid];
callp->call[13]=callp->call[13]+1;
callp->flag=1;

long a,b;
a=ctr1000;


	short	*nxtdev;

	if (isbadpid(pid))
		return(SYSERR);
	nxtdev = (short *) proctab[pid].pdevs;
	*nxtdev++ = dev1;
	*nxtdev = dev2;
b=ctr1000;
callp->time[13]=callp->time[13]+ b-a;



	return(OK);
}
