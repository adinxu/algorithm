#ifndef PARALLELMENU_API_H_INCLUDED
#define PARALLELMENU_API_H_INCLUDED

#define MAX_NUM_OF_PAGE 24


#include <stdlib.h>
#include <stdio.h>
#ifdef __WIN__
#include <conio.h>
#else
static inline int getch()
{
    int ret = 0;
    char c;
    ret = system("stty -echo");
    c=getchar();
    ret = system("stty echo");
    return (int)c;
}
#endif
typedef enum//��ֵö�ٱ���
{
  keyup,
  keydown,
  keyleft,
  keyright,
  keyenter
}KeyValue;
typedef enum //��Ļλ��ö�ٱ���
{
  fristline,
  secondline,
  thirdline,
  fourthline
}OptPosition;
typedef enum
{
    strings,//0
    number,//1
    smallnum,//2
    adjustblestr,//3
    adjustablenum,//4
    adjustblesmall//5
}Type;
struct _SmallNum
{
    int integer;
    unsigned char leave;
};
union optcontent
{
    unsigned char* str;
    int* num;
    struct _SmallNum smallnum;
};
struct _Page
{
    char optnum;//ѡ����Ŀ
    struct _Option* option;//��ҳѡ��ṹ������ָ��
    char selection;//��ǰѡ�е�ѡ���ţ���0��ʼ����
};

struct _Option
{
  Type flag;//������ʶ��ͨѡ����ɵ���ѡ��ı�־λ  0��ͨ 1�ɵ���
  unsigned char* name;
  union optcontent content;
};

  typedef struct _Page Page;
  typedef struct _Option Option;
  typedef struct _SmallNum SmallNum;



void _SetPosition();

void process_KeyAction(KeyValue keyvalue);

void process_optchange(char flag);
void process_valuechange(char flag);
void process_Enter();

void _adjustblestr(char flag);
void _adjustablenum(char flag);
void _adjustblesmall(char flag);

void DrawOpt(OptPosition position);

void SetPageNum(int num);
void SetPage(int num,int optnum,unsigned char* str);
void SetOptContent(char flag,unsigned char* name,void* content);
void EndPageSet();
void switchtokeyvalue();
#endif // PARALLELMENU_H_INCLUDED
