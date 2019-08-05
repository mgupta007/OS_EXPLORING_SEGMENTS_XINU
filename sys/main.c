/* user.c - main */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include<lab0.h>

/*------------------------------------------------------------------------
 *  main  --  user main program
 *------------------------------------------------------------------------
 */

int prX, prY;
void halt();

/*------------------------------------------------------------------------
 *  *  main  --  user main program
 *   *------------------------------------------------------------------------
 *    */
prch(c)
char c;
{
	int i;
	sleep(5);	
}



int main()
{           
       

   
	long i = 0xaabbccdd;           
	kprintf("input%x",i);     
	long o=zfunction(i);
	kprintf("\noutput%8x\n",o);

 
        printsegaddress();
        printtos();
        printprocstks(55);

        kprintf("Task 5 (printsyscallsummary)\n");
	syscallsummary_start();        
       
       

          resume(prX = create(prch,2000,20,"proc x",1,'A'));


	sleep(15);

	syscallsummary_stop();
	printsyscallsummary();
	kprintf("\n\nHello World, Xinu lives\n\n");
	return 0;
}
