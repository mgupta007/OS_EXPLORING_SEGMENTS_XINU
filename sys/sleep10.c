/* sleep10.c - sleep10 */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sleep.h>
#include <stdio.h>


/*------------------------------------------------------------------------
 * sleep10  --  delay the caller for a time specified in tenths of seconds
 *------------------------------------------------------------------------
 */


unsigned long ctr1000;

SYSCALL	sleep10(int n)
{





unsigned long a,b;

        struct pentry *callp;
callp=&proctab[currpid];
callp->call[19]=callp->call[19]+1;
callp->flag=1;

a=ctr1000;
	STATWORD ps;    
	if (n < 0  || clkruns==0)
	         return(SYSERR);
	disable(ps);
	if (n == 0) {		/* sleep10(0) -> end time slice */
	        ;
	} else {
		insertd(currpid,clockq,n*100);
		slnempty = TRUE;
		sltop = &q[q[clockq].qnext].qkey;
		proctab[currpid].pstate = PRSLEEP;
	}
	resched();
        restore(ps);
b=ctr1000;
callp->time[19]=callp->time[19]+ b-a;


	return(OK);
}
