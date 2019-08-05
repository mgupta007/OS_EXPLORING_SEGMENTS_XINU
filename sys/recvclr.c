/* recvclr.c - recvclr */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 *  recvclr  --  clear messages, returning waiting message (if any)
 *------------------------------------------------------------------------
 */

unsigned long ctr1000;
SYSCALL	recvclr()
{


        struct pentry *callp;
callp=&proctab[currpid];
callp->call[7]=callp->call[7]+1;
callp->flag=1;

long a,b;
a=ctr1000;
       
	STATWORD ps;    
	WORD	msg;

	disable(ps);
	if (proctab[currpid].phasmsg) {
		proctab[currpid].phasmsg = 0;
		msg = proctab[currpid].pmsg;
	} else
		msg = OK;
	restore(ps);


b=ctr1000;
callp->time[3]=callp->time[7]+ b-a;

	return(msg);
}
