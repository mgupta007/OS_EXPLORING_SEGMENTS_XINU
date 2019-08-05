/* getpid.c - getpid */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <lab0.h>
/*------------------------------------------------------------------------
 * getpid  --  get the process id of currently executing process
 *------------------------------------------------------------------------
 */


SYSCALL getpid()
{

struct pentry *p;
p=&proctab[currpid];	
p->call[0]=p->call[0]+1;
p->flag=1;


return(currpid);
}
