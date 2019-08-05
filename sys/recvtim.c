/* recvtim.c - recvtim */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sleep.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 *  recvtim  -  wait to receive a message or timeout and return result
 *------------------------------------------------------------------------
 */

unsigned long ctr1000;
SYSCALL	recvtim(int maxwait)
{

        struct pentry *callp;
callp=&proctab[currpid];
callp->call[8]=callp->call[8]+1;
callp->flag=1;

long a,b;
a=ctr1000;

        
	STATWORD ps;    
	struct	pentry	*pptr;
	int	msg;

	if (maxwait<0 || clkruns == 0)
		return(SYSERR);
	disable(ps);
	pptr = &proctab[currpid];
	if ( !pptr->phasmsg ) {		/* if no message, wait		*/
	        insertd(currpid, clockq, maxwait*1000);
		slnempty = TRUE;
		sltop = (int *)&q[q[clockq].qnext].qkey;
	        pptr->pstate = PRTRECV;
		resched();
	}
	if ( pptr->phasmsg ) {
		msg = pptr->pmsg;	/* msg. arrived => retrieve it	*/
		pptr->phasmsg = FALSE;
	} else {			/* still no message => TIMEOUT	*/
		msg = TIMEOUT;
	}
	restore(ps);
b=ctr1000;
callp->time[8]=callp->time[8]+ b-a;



	return(msg);
}
