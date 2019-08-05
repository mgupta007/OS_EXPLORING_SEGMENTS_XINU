/* sleep.c - sleep */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sleep.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 * sleep  --  delay the calling process n seconds
 *------------------------------------------------------------------------
 */
unsigned long	ctr1000;
SYSCALL	sleep(int n)
{

        struct pentry *callp;
callp=&proctab[currpid];
callp->call[18]=callp->call[18]+1;
callp->flag=1;

unsigned long a,b;
a=ctr1000;

	STATWORD ps;    
	if (n<0 || clkruns==0)
		return(SYSERR);
	if (n == 0) {
	        disable(ps);
		resched();
		restore(ps);
               b=ctr1000;
               callp->time[18]=callp->time[18]+ b-a;

 
		return(OK);
	}
	while (n >= 1000) {
		sleep10(10000);
		n -= 1000;
	}
	if (n > 0)
		sleep10(10*n);
b=ctr1000;
callp->time[18]=callp->time[18]+ b-a;


	return(OK);
}
