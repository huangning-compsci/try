#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 30
#define  TRUE   1
#define  FALSE  0
#define  OK     1
#define  ERROR 0
#define  OVERFLOW  -1
typedef int Status;
typedef   int ElemType;
typedef struct LNode  /* 定义链式存储结构 */
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;
int  Get_LinkList(LinkList H, ElemType key) ;//按值查询，找到则返回其位置，未找到则返回0
Status ListInsert(LinkList &H,int i,ElemType e);
Status ListDelete(LinkList &H,int i);
Status Creat_LinkList(LinkList &L)               /* 创建链式表 */
  {
    LinkList head,r,s;
    int k;
    head=(LinkList)malloc(sizeof(LNode));
    head->next=NULL;
    r=head;
    scanf("%d",&k);
    while(k>0)
    {
      s=(LNode *)malloc(sizeof(LNode));
      s->data=k;
      s->next=NULL;
      r->next=s;
      r=s;
      scanf("%d",&k);
    }
    L=head;
    return OK;
  }/* Creat_LinkList */
void Print_LinkList( LinkList H)     /* 输出链式表 */
{
    LNode *p;
    p=H->next;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
   }
   printf("\n");
  }/* Print_LinkList */


int  main()
  {
    ElemType key;
    LinkList L;
    int p,loc;
    Creat_LinkList(L);  //创建单链表
    Print_LinkList(L);   //输出单链表
    scanf("%d",&key);  //读入待查找的值
    p=Get_LinkList(L,key);  //
    printf("key在第%d位\n",p);
    scanf("%d%d",&key,&loc);  //输入要插入的值key以及位置loc
    ListInsert(L,loc,key);
    Print_LinkList(L);
    scanf("%d",&loc);//输入要删除元素的位置
    ListDelete(L,loc);
    Print_LinkList(L);
    return 0;
}

/* 请在这里填写答案 */
int Get_LinkList(LinkList H,ElemType key)
{LinkList p=H;
 int count=0;
    while(p)
    {if(p->data!=key)
        {p=p->next;
         count++;
        }
else{return count;}
        
    }
return 0;
    
}
Status ListInsert(LinkList &H,int i,ElemType e)
{LinkList p=H;
 int j=0;
 while(p != NULL && j<i-1)
     {p=p->next;
     j++;}
if(p==NULL ||j!=i-1)
{return ERROR;} 
LinkList s=(LinkList)malloc(sizeof(LNode));
if(s==NULL)
{return OVERFLOW;}
 s->data=e;
 s->next=p->next;
 p->next=s;
    return OK;
}

Status ListDelete(LinkList &H,int i)
{LinkList p=H;
 int j=0;
 while(p != NULL && j<i-1)
     {p=p->next;
     j++;}
if(p==NULL ||j!=i-1)
{return ERROR;} 
 LinkList q=p->next;
 p->next=p->next->next;
 free(q);

return OK;
}