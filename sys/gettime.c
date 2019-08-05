/* gettime.c - gettime */

#include <conf.h>
#include <kernel.h>
#include <date.h>
#include<proc.h>

extern int getutim(unsigned long *);

/*------------------------------------------------------------------------
 *  gettime  -  get local time in seconds past Jan 1, 1970
 *------------------------------------------------------------------------
 */



unsigned long ctr1000;


SYSCALL	gettime(long *timvar)
{

        struct pentry *callp;
callp=&proctab[currpid];
callp->call[5]=callp->call[5]+1;
callp->flag=1;


    /* long	now; */

	/* FIXME -- no getutim */

    return OK;
}
