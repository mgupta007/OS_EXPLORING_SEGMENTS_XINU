/* signaln.c - signaln */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sem.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 *  signaln -- signal a semaphore n times
 *------------------------------------------------------------------------
 */

unsigned long ctr1000;

SYSCALL signaln(int sem, int count)
{



        struct pentry *callp;
callp=&proctab[currpid];
callp->call[17]=callp->call[17]+1;
callp->flag=1;


long a,b;
a=ctr1000;
	STATWORD ps;    
	struct	sentry	*sptr;

	disable(ps);
	if (isbadsem(sem) || semaph[sem].sstate==SFREE || count<=0) {
		restore(ps);
		return(SYSERR);
	}
	sptr = &semaph[sem];
	for (; count > 0  ; count--)
		if ((sptr->semcnt++) < 0)
			ready(getfirst(sptr->sqhead), RESCHNO);
	resched();
	restore(ps);

b=ctr1000;
callp->time[17]=callp->time[17]+ b-a;



	return(OK);
}
