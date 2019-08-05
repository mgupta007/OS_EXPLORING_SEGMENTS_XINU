/* signal.c - signal */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sem.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 * signal  --  signal a semaphore, releasing one waiting process
 *------------------------------------------------------------------------
 */

unsigned long ctr1000;
SYSCALL signal(int sem)
{


        struct pentry *callp;
callp=&proctab[currpid];
callp->call[16]=callp->call[16]+1;
callp->flag=1;

long a,b;
a=ctr1000;


	STATWORD ps;    
	register struct	sentry	*sptr;

	disable(ps);
	if (isbadsem(sem) || (sptr= &semaph[sem])->sstate==SFREE) {
		restore(ps);
		return(SYSERR);
	}
	if ((sptr->semcnt++) < 0)
		ready(getfirst(sptr->sqhead), RESCHYES);
	restore(ps);


b=ctr1000;
callp->time[16]=callp->time[16]+ b-a;


	return(OK);
}
