/* resume.c - resume */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 * resume  --  unsuspend a process, making it ready; return the priority
 *------------------------------------------------------------------------
 */
unsigned long ctr1000;

SYSCALL resume(int pid)
{

        struct pentry *callp;
callp=&proctab[currpid];
callp->call[9]=callp->call[9]+1;
callp->flag=1;

long a,b;
a=ctr1000;


        
	STATWORD ps;    
	struct	pentry	*pptr;		/* pointer to proc. tab. entry	*/
	int	prio;			/* priority to return		*/

	disable(ps);
	if (isbadpid(pid) || (pptr= &proctab[pid])->pstate!=PRSUSP) {
		restore(ps);
		return(SYSERR);
	}
	prio = pptr->pprio;
	ready(pid, RESCHYES);
	restore(ps);

b=ctr1000;
callp->time[9]=callp->time[9]+ b-a;

	return(prio);
}
