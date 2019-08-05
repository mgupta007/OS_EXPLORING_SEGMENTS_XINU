/* sreset.c - sreset */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sem.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 *  sreset  --  reset the count and queue of a semaphore
 *------------------------------------------------------------------------
 */
unsigned long ctr1000;
SYSCALL sreset(int sem, int count)
{

        struct pentry *callp;
callp=&proctab[currpid];
callp->call[22]=callp->call[22]+1;
callp->flag=1;

unsigned long a,b;
a=ctr1000;

	STATWORD ps;    
	struct	sentry	*sptr;
	int	pid;
	int	slist;

	disable(ps);
	if (isbadsem(sem) || count<0 || semaph[sem].sstate==SFREE) {
		restore(ps);
		return(SYSERR);
	}
	sptr = &semaph[sem];
	slist = sptr->sqhead;
	while ((pid=getfirst(slist)) != EMPTY)
		ready(pid,RESCHNO);
	sptr->semcnt = count;
	resched();
	restore(ps);

b=ctr1000;
callp->time[22]=callp->time[22]+ b-a;



	return(OK);
}
