
#include <stdio.h>
//#include<kernel.h>





extern long etext, edata, end;

void printsegaddress()
{

kprintf("\n printsegaddress() \n");

kprintf("Current: etext[0x%08X]=0x%08X \n",&(etext), etext);
kprintf("Current: edata[0x%08X]=0x%08X \n",&edata, edata);
kprintf("Current: end[0x%08X]=0x%08X \n",&end, end);


long *a=&etext, *b=&edata, *c=&end;



a=a-1;
b=b-1;
c=c-1;



kprintf("Preceding: etext[0x%08X]=0x%08X \n",a, *a);

kprintf("Preceding: edata[0x%08X]=0x%08X \n",b, *b);

kprintf("Preceding: end[0x%08X]=0x%08X \n",c, *c);


a=a+2;
b=b+2;
c=c+2;

kprintf("After: etext[0x%08X]=0x%08X \n",a, *a);

kprintf("After: edata[0x%08X]=0x%08X \n",b, *b);

kprintf("After: end[0x%08X]=0x%08X \n",c, *c);



}
