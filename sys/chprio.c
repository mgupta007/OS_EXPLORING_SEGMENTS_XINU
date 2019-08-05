/* chprio.c - chprio */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <stdio.h>


/*------------------------------------------------------------------------
 * chprio  --  change the scheduling priority of a process
 *------------------------------------------------------------------------
 *
 */


unsigned long ctr1000;





SYSCALL chprio(int pid, int newprio)
{

                struct pentry *callp;
callp=&proctab[currpid];
callp->call[3]=callp->call[3]+1;
callp->flag=1;
unsigned long a,b;
a=ctr1000;

	
        STATWORD ps;    
	struct	pentry	*pptr;

	disable(ps);
	if (isbadpid(pid) || newprio<=0 ||
	    (pptr = &proctab[pid])->pstate == PRFREE) {
		restore(ps);
		return(SYSERR);
	}
	pptr->pprio = newprio;
	restore(ps);
b=ctr1000;
callp->time[23]=callp->time[23]+ b-a;


	return(newprio);
}
