/*************************************************************************
	> File Name: list2.c   双链表
	> Author: Armyer 
	> Mail: 79288428jj@gmail.com
	> Created Time: 2017年08月05日 星期六 15时37分56秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>



typedef int ElemType;

/**
 * 1.双链表结构体如下，因为单链表访问前驱结点较为复杂，从而出现双链表解决这类问题
 * 2.仅仅只是在单链表的结点中增加一个指向其前驱的prior指针
 * 3.按值查找和按位查找和单链表相同，但双链表在插入和删除操作的实现上有较大不同
 * 4.插入，删除结点复杂度仅为O(1）
 */
typedef struct DNode
{
    ElemType data;
    struct DNode *prior,*next;
}DNode;


/**
 * 前置条件：线性表不存在
 * 输入：初始化结点个数n
 * 功能：初始化线性表
 * 输出：返回一条线性表头结点
 * 后置条件：创建一条线性表
 *
 */
DNode* CreateList(int n)
{
    DNode*  L;
    DNode* r;

    L = (DNode*)malloc(sizeof(DNode));

    r = L;

    L->data = 0;
    L->next=NULL;   //头结点
    L->prior=NULL;   

    DNode* p;      //新建结点

    int i,x;
    //头插法
    for(i = n;i>0;i--)
    {
        p = (DNode*)malloc(sizeof(DNode)); //分配内存
        
        scanf("%d",&x);   //输入数据
        p->data = x;

        L->next = p;     //牢记先断后链
        p->prior = L;
        p->next=NULL;
        L = p;

    }

    return r;
}





/**
 * 前置条件：线性表存在
 * 输入：线性表头结点
 * 功能：打印线性表结点数据
 * 输出：无
 * 后置条件：线性表不改变
 */
void PrintList(DNode* L)
{
    if(L->next == NULL)
    {
        perror("error!\n");
    }

    while(L->next!=NULL)
    {
        L = L->next;
        printf("%d\n",L->data);

    }
}


/**
 * 前置条件：线性表已存在
 * 输入：线性表头结点
 * 功能：求表长
 * 输出：表长
 * 后置条件：线性表不改变
 */
int Length(DNode* L)
{
    int length = 0;
    while(L->next!=NULL)
    {
        length++;
        L = L->next;
    }
    return length;



}


/**
 * 前置条件：线性表已存在
 * 输入：线性表位置i，线性表头结点L
 * 功能：根据位置获得结点
 * 输出：结点
 * 后置条件：线性表不改变
 */
DNode* GetELem(DNode* L,int i)
{
    if(i<0||i>Length(L))
    {
        perror("error i\n");
        exit(-1);
    }

   // DNode* r;
   // r = (DNode*)malloc(sizeof(DNode));

    while(i--)
    {
        L = L->next;
    }

    return L;
}





/**
 * 前置条件：线性表已存在
 * 输入：线性表头结点，插入的位置i，插入的值e
 * 功能：插入结点
 * 输出：无
 * 后置条件：插入成功，线性表增加一个结点
 *
 */
void InsertList(DNode* L, int i, ElemType e)
{

    if(i<0||i>Length(L))
    {
        perror("error!\n");
        exit(-1);
    }

    DNode* s ;//将s结点插入p之后
    
    s = (DNode*)malloc(sizeof(DNode));
    
    s ->data = e;
    
    DNode* p = L;
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;

}

int main()
{

    /*DNode* L;
    L = (DNode*)malloc(sizeof(DNode));
    L->data =1;
    
    printf("%d\n",L->data);*/

    DNode* L = CreateList(3);
    PrintList(L);
    int length = Length(L);
    printf("length is %d\n",length);

    DNode* r = GetELem(L,3);
    printf("data is %d\n",r->data);

    InsertList(L,2,10);
    PrintList(L);
    return 0;


}
