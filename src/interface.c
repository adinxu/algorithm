#include"interface.h"
#include<stdio.h>

int interface()
{
    char c;
    while(1)
    {
	c=getchar();
        if(c=='1')
	{
            parallelmenu();
	}
    }
   return 0;
}
