/* send.c - send */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>


/*------------------------------------------------------------------------
 *  send  --  send a message to another process
 *------------------------------------------------------------------------
 */

unsigned long ctr1000;
SYSCALL	send(int pid, WORD msg)
{

        struct pentry *callp;
callp=&proctab[currpid];
callp->call[12]=callp->call[12]+1;
callp->flag=1;

unsigned long a,b;
a=ctr1000;

	STATWORD ps;    
	struct	pentry	*pptr;

	disable(ps);
	if (isbadpid(pid) || ( (pptr= &proctab[pid])->pstate == PRFREE)
	   || pptr->phasmsg != 0) {
		restore(ps);
		return(SYSERR);
	}
	pptr->pmsg = msg;
	pptr->phasmsg = TRUE;
	if (pptr->pstate == PRRECV)	/* if receiver waits, start it	*/
		ready(pid, RESCHYES);
	else if (pptr->pstate == PRTRECV) {
		unsleep(pid);
		ready(pid, RESCHYES);
	}
	restore(ps);

b=ctr1000;
callp->time[12]=callp->time[12]+ b-a;


	return(OK);
}
