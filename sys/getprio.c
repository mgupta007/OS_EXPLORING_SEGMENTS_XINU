/* getprio.c - getprio */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>


/*------------------------------------------------------------------------
 * getprio -- return the scheduling priority of a given process
 *------------------------------------------------------------------------
 */


unsigned long ctr1000;
//unsigned long a12,b12;
//a12=ctr1000;
//b12=ctr1000;
//callp->time[3]=callp->time[3]+ b12-a12;




SYSCALL getprio(int pid)
{
	
              struct pentry *callp;
callp=&proctab[currpid];
callp->call[4]=callp->call[4]+1;
callp->flag=1;

unsigned long a12,b12;
a12=ctr1000;


        STATWORD ps;    
	struct	pentry	*pptr;

	disable(ps);
	if (isbadpid(pid) || (pptr = &proctab[pid])->pstate == PRFREE) {
		restore(ps);
		return(SYSERR);
	}
	restore(ps);

b12=ctr1000;
callp->time[4]=callp->time[4]+ b12-a12;



	return(pptr->pprio);
}
