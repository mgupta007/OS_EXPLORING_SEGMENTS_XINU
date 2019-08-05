/* sleep100.c - sleep100 */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sleep.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 * sleep100  --  delay the caller for a time specified in 1/100 of seconds
 *------------------------------------------------------------------------
 */ 
unsigned long ctr1000;
SYSCALL sleep100(int n)
{

        struct pentry *callp;
callp=&proctab[currpid];
callp->call[20]=callp->call[20]+1;
callp->flag=1;


unsigned long a,b;
a=ctr1000;




	STATWORD ps;    

	if (n < 0  || clkruns==0)
	         return(SYSERR);
	disable(ps);
	if (n == 0) {		/* sleep100(0) -> end time slice */
	        ;
	} else {
		insertd(currpid,clockq,n*10);
		slnempty = TRUE;
		sltop = &q[q[clockq].qnext].qkey;
		proctab[currpid].pstate = PRSLEEP;
	}
	resched();
        restore(ps);

b=ctr1000;
callp->time[20]=callp->time[20]+ b-a;




	return(OK);
}
