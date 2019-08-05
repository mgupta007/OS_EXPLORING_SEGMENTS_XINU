/* scount.c - scount */

#include <conf.h>
#include <kernel.h>
#include <sem.h>
#include<proc.h>
/*------------------------------------------------------------------------
 *  scount  --  return a semaphore count
 *------------------------------------------------------------------------
 */ 


unsigned long ctr1000;
SYSCALL scount(int sem)
{

        struct pentry *callp;
callp=&proctab[currpid];
callp->call[10]=callp->call[10]+1;
callp->flag=1;

long a,b;
a=ctr1000;


extern	struct	sentry	semaph[];

	if (isbadsem(sem) || semaph[sem].sstate==SFREE)
		return(SYSERR);


b=ctr1000;
callp->time[10]=callp->time[10]+ b-a;


	return(semaph[sem].semcnt);
}
