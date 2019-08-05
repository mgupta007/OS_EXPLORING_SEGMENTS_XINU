/* receive.c - receive */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>


/*------------------------------------------------------------------------
 *  receive  -  wait for a message and return it
 *------------------------------------------------------------------------
 */


unsigned long ctr1000;
SYSCALL	receive()
{


        struct pentry *callp;
callp=&proctab[currpid];
callp->call[6]=callp->call[6]+1;
callp->flag=1;

long a,b;
a=ctr1000;

	STATWORD ps;    
	struct	pentry	*pptr;
	WORD	msg;

	disable(ps);
	pptr = &proctab[currpid];
	if ( !pptr->phasmsg ) {		/* if no message, wait for one	*/
		pptr->pstate = PRRECV;
		resched();
	}
	msg = pptr->pmsg;		/* retrieve message		*/
	pptr->phasmsg = FALSE;
	restore(ps);

b=ctr1000;
callp->time[6]=callp->time[6]+ b-a;


	return(msg);
}
