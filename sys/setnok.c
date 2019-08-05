/* setnok.c - setnok */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 *  setnok  -  set next-of-kin (notified at death) for a given process
 *------------------------------------------------------------------------
 */

unsigned long ctr1000;
SYSCALL	setnok(int nok, int pid)
{


        struct pentry *callp;
callp=&proctab[currpid];
callp->call[14]=callp->call[14]+1;
callp->flag=1;

long a,b;
a=ctr1000;

	STATWORD ps;    
	struct	pentry	*pptr;

	disable(ps);
	if (isbadpid(pid)) {
		restore(ps);
		return(SYSERR);
	}
	pptr = &proctab[pid];
	pptr->pnxtkin = nok;
	restore(ps);


b=ctr1000;
callp->time[14]=callp->time[14]+ b-a;

	return(OK);
}
