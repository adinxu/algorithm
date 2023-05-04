#include"interface.h"
#include<stdio.h>

int interface()
{
    char c;
    while(1)
    {
	printf("please give a num of the case to run\n");
	c=getchar();
        if(c=='1')
	{
            parallelmenu();
	}
    }
   return 0;
}
