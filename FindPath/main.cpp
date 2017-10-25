#include <iostream>
#include "FindPath.h"
using namespace std;
Path path;
int main()
{
    path.src=1;
    path.des=3;
    FindPath();
    for(char i=0;i<6&&*(path.pathlist+i);i++)
    {
        cout<<(int)*(path.pathlist+i)<<"\n";
    }
    //cout <<(int)path.src<<"\n"<<(int)path.des<<"\n"<<endl;
    return 0;
}
