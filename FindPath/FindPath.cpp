#include "FindPath.h"
#include "string.h"
extern Path path;
/** \brief ��ȡ·��
 *
 * \param �趨��Path���ͣ���ͷ�ļ���ȫ�ֱ���path
 * \param ʹ��ǰ���趨��ʼλ����Ŀ��λ�ã���Ӧ����1~9���������к����������ֵ��Ч������
 * \param ·���洢��pathlist��Ա�����У���0���ʾ�ѵ���Ŀ�ĵ�
 * \param ��Ա����index���ڼ��䵱ǰ�������
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
    }//����src�������С�ĵ㣬des������Ŵ�ĵ�
    else return;//�غϣ�����
    ChangeBase(&(path.src));
    ChangeBase(&(path.des));
    char p,q;
    p=path.src%5;
    if(!p) p=5;
    q=path.des%5;
    if(!q) q=5;
    if(p<q)//�յ��������
    {
        if(res==1) path.pathlist[0]=path.src+1;
        else if(res==3) path.pathlist[0]=path.src+5;//���ڵ��������
        else
        {
            path.pathlist[0]=path.src+5+1;
            if(res==2||res==5||res==8)//���ڵ���������λ�Խ�
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
    else//�յ���������ͬ��
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
        if(m=path.index/2)//���� ������
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





















