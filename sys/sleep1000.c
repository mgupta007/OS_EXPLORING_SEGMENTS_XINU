/* sleep1000.c - sleep1000 */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sleep.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 * sleep1000 --  delay the caller for a time specified in 1/100 of seconds
 *------------------------------------------------------------------------
 */
unsigned long ctr1000;
SYSCALL sleep1000(int n)
{

        struct pentry *callp;
callp=&proctab[currpid];
callp->call[21]=callp->call[21]+1;
callp->flag=1;

unsigned long a,b;
a=ctr1000;

	STATWORD ps;    

	if (n < 0  || clkruns==0)
	         return(SYSERR);
	disable(ps);
	if (n == 0) {		/* sleep1000(0) -> end time slice */
	        ;
	} else {
		insertd(currpid,clockq,n);
		slnempty = TRUE;
		sltop = &q[q[clockq].qnext].qkey;
		proctab[currpid].pstate = PRSLEEP;
	}
	resched();
        restore(ps);

b=ctr1000;
callp->time[21]=callp->time[21]+ b-a;



	return(OK);
}
