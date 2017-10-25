#include <iostream>

using namespace std;

void print(int num,char ch)
{
    for(;num;num--)
    {
        cout<<" ";
    }
    cout<<ch;
}

int main()
{
    char num,L,R;
    char line=0;
	cout<<"please input a number:\n";
input:
	cin>>num;
	if(num>=49&&num<=57)
	{
	    cout<<"the num is "<<num<<"\n";
	    L=num-'0'-1;
	    R=0;
	    for(;line<num-'0';line++)
	    {
	        print(L,'/');
	        print(R,'\\');
	        cout<<"\n";
	        L--;
	        R+=2;
	    }
        for(;line;line--)
	    {
            L++;
	        R-=2;
            print(L,'\\');
	        print(R,'/');
	        cout<<"\n";
	    }
	}
	else
	{
		cout<<"please input a num between 1-9:\n";
		goto input;
	}
	return 0;
}
/*
  /\
 /  \
/    \
\    /
 \  /
  \/
*/



