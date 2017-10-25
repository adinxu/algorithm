#include "FindPath.h"
#include "string.h"
extern Path path;
/** \brief 求取路径
 *
 * \param 需定义Path类型（见头文件）全局变量path
 * \param 使用前先设定起始位置与目标位置，对应区域1~9，函数运行后此两坐标数值无效不可用
 * \param 路径存储于pathlist成员数组中，遇0则表示已到达目的地
 * \param 成员变量index用于记忆当前坐标序号
 * \return
 *
 */

void ChangeBase(unsigned char* pos)
{
    switch(*pos)
    {
    case 1://2n-1
    case 2:
    case 3: break;

    case 4://2(n+2)-1
    case 5:
    case 6: (*pos)+=2;break;

    case 7://2(n+4)-1
    case 8:
    case 9: (*pos)+=4;break;
    default: break;
    }
    (*pos)<<=1;(*pos)--;
}
void FindPath()
{
    memset(path.pathlist,0,sizeof(path.pathlist));
    unsigned char sign=0;
    unsigned char res;
    path.index=0;
    if(path.src<path.des) res=path.des-path.src;
    else if(path.src>path.des)
    {
        res=path.src-path.des;
        unsigned char i=path.src;
        path.src=path.des;
        path.des=i;
        sign=1;
    }//至此src保存序号小的点，des保存序号大的点
    else return;//重合，保留
    ChangeBase(&(path.src));
    ChangeBase(&(path.des));
    char p,q;
    p=path.src%5;
    if(!p) p=5;
    q=path.des%5;
    if(!q) q=5;
    if(p<q)//终点在起点右
    {
        if(res==1) path.pathlist[0]=path.src+1;
        else if(res==3) path.pathlist[0]=path.src+5;//相邻的两种情况
        else
        {
            path.pathlist[0]=path.src+5+1;
            if(res==2||res==5||res==8)//相邻的左边正方形或对角
            {
                path.pathlist[2]=(path.pathlist[1]=path.pathlist[0]+1)+1;
                path.index=2;
                if(res==8)
                {
                    path.pathlist[4]=(path.pathlist[3]=path.pathlist[2]+5)+5;
                    path.index=4;
                }
            }
            else if(res==6||res==7)
            {
                path.pathlist[2]=(path.pathlist[1]=path.pathlist[0]+5)+5;
                path.index=2;
            }
        }
    }
    else//终点在起点左或同列
    {
        if(res==3) path.pathlist[0]=path.src+5;
        else
        {
            path.pathlist[0]=path.src+4;
            if(res==1||res==4)
            {
                path.pathlist[2]=(path.pathlist[1]=path.pathlist[0]-1)-1;
                path.index=2;
                if(res==4)
                {
                    path.pathlist[4]=(path.pathlist[3]=path.pathlist[2]+5)+5;
                    path.index=4;
                }
            }
            else if(res==5||res==6)
            {
                path.pathlist[2]=(path.pathlist[1]=path.pathlist[0]+5)+5;
                path.index=2;
            }
        }
    }
    if(sign)
    {
        char m;
        unsigned char store;
        if(m=path.index/2)//倒序 奇数个
        {
            for(unsigned char n=0;n<m;n++)
            {
                store=path.pathlist[n];
                path.pathlist[n]=path.pathlist[path.index-n];
                path.pathlist[path.index-n]=store;
            }
        }
        path.pathlist[++path.index]=path.src;
    }
    else path.pathlist[++path.index]=path.des;
    path.index=0;
}





















