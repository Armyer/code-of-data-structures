/*************************************************************************
	> File Name: list.c
	> Author: Armyer
	> Mail: 79288428jj@gmail.com
	> Created Time: 2017年08月04日 星期五 15时32分21秒
 ************************************************************************/

/**
 *链接存储实现线性表-单链表
 *
 */
#include<stdio.h>
#include<stdlib.h>


typedef int ElemType;   //定义节点存储数据元素类型

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;


/**
 *
 * 前置条件：线性表不存在
 * 输入：n表示要建立的单链表结点个数
 * 功能： 头插法建立单链表
 * 输出：返回一个已建立好的单链表头结点
 * 后置条件：一个n个结点的单链表
 *
 */
LNode* CreateList1(int n)
{
    //从表尾到表头逆向建立单链表L，每次均在头节点之后插入元素
    LNode *L;
   
    L=(LNode*)malloc(sizeof(LNode));    //创建头节点
    
    L->next=NULL;                         //初始化为空链表
    
    LNode *p;
    
    int i;
    for(i = n; i>0; i--)             
    {                    
        p = (LNode*)malloc(sizeof(LNode));   //结点分配空间
        
        scanf("%d",&p->data);
    
        p->next = L->next;           //将p结点插入头指针后一位
 
        L->next = p;               //将头指针指向p结点
       
    }                   
    return L;
}

/**
 *
 * 前置条件：线性表不存在
 * 输入：n表示要建立的单链表结点个数
 * 功能：尾插法建立单链表
 * 输出：返回一个已建立好的单链表头结点
 * 后置条件：一个n个结点的单链表
 *
 */
LNode* CreateList2(int n)
{
    //从表头到表尾正向建立单链表L，每次均在表尾插入元素
    LNode* L;
    
    L=(LNode*)malloc(sizeof(LNode));

    L->next=NULL;

    LNode* p,*r =L;

    int i;

    ElemType x;  //结点数据类型
    for(i = n;i>0;i--)
    {
        p = (LNode*)malloc(sizeof(LNode));

        scanf("%d",&x);

        p->data = x;

        r->next = p;    //r指向新的表尾结点

        r = p;
    }

    return L;
}


/**
 * 前置条件：线性表已存在
 * 输入:单链表的头结点
 * 功能：打印单链表
 * 输出：无
 * 后置条件：线性表不变
 *
 */
void PrintList(LNode* L)
{
    if(L->next == NULL)
    {
        perror("over\n");
    }
    while(L->next!=NULL)
    {
        L = L->next;
        printf("%d\n",L->data);
    }
}


/**
 * 前置条件：线性表已存在
 * 输入：线性表头结点，要查找的第i个位置的结点
 * 功能：按序号查找元素值
 * 输出：要查找的结点
 * 后置条件：线性表不改变
 *
 */
LNode * GetElem(LNode* L, int i)
{
    int j = 1;
    LNode* p = L->next;
    if(i == 0)     
    {
        return L;              //若i=0,返回头结点
    }
    if(i<1)
    {
        return NULL;    //若i无效，返回NULL
    }
    while(p&&j<i)     //从第一个结点开始找，查找第i个结点
    {
        p = p->next;
        j++;
    }
    return p;   //返回第i个结点的指针，如果i大于表长，p=NULL,直接返回p即可
}

/**
 * 前置条件：线性表存在
 * 输入：单链表头结点，要查找的元素值e
 * 功能：查找单链表中的数据为e的结点
 * 输出：查找到匹配的结点
 * 后置条件：线性表不变
 *
 *
 */
LNode * LocateElem(LNode *L,ElemType e)
{
    LNode* p = L->next;
    while(p!=NULL&&p->data!=e)
    {
        p = p->next;
    }
    return p;
}

/**
 * 前置条件：线性表已存在
 * 输入：线性表头结点，要插入的位置i，要插入的结点数据e
 * 功能：插入结点
 * 输出：无
 * 后置条件：如插入成功，线性表结点加1
 */
void InsertList(LNode *L, int i,ElemType e)
{
    LNode* p = GetElem(L,i);

    LNode* s;
    s = (LNode*)malloc(sizeof(LNode));//创建要插入的结点

    s->data = e;   //将要查入的值赋给结点

    if(p->next!=NULL)
    {
        s->next = p->next;
        p->next = s;
    }
}

/**
 * 前置条件：线性表已存在
 * 输入：线性表头结点，要删除的结点位置i
 * 功能：删除线性表第i个结点
 * 输出:无
 * 后置条件：若删除成功，则线性表结点减少一个
 *
 */
void DeleteList(LNode* L, int i)
{

    LNode* q ;
    LNode* p = GetElem(L,i-1);
    
    q = p->next; //要删除的结点为q
    p->next = q->next;//将要删除的结点的前驱结点指向删除结点的后驱结点
    free(q);  //释放结点
}

/**
 * 前置条件：线性表已存在
 * 输入：线性表头结点
 * 功能：求单链表长度
 * 输出：线性表长度
 * 后置条件：线性表不改变
 *
 */
int LengthList(LNode* L)
{
    int length = 0;
    if(L->next == NULL)
    {
        return length;
    }
    while(L->next!=NULL)
    {
        length ++;
        L = L->next;
    }
    return length;
}




int main()
{
    int n = 5;
   //LNode* L = CreateList1(n);
    //初始化创建单链表
    LNode *L = CreateList1(n);
    PrintList(L);
    printf("\n");

    //测试按位查找单链表
    LNode* r= GetElem(L,2);
    PrintList(r);
    printf("\n");

    //测试按值查找函数
    LNode* e = LocateElem(L,5);
    printf("e=%d\n",e->data);
    printf("\n");

    //测试插入结点函数
    InsertList(L,2,10);
    PrintList(L);
    printf("\n");

    //测试删除结点函数
    DeleteList(L,1);
    PrintList(L);
    printf("\n");

    //测试求表长函数
    int length = LengthList(L);
    printf("length is %d\n",length);

}
