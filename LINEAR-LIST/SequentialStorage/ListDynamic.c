/*************************************************************************
> File Name: ListDynamic.c
> Author: Armyer
> Mail: 79288428jj@gmail.com
> Created Time: 2017年08月03日 星期四 17时18分29秒
************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/**
*线性表基本操作
*
*1. InitList(&L) 初始化线性表
*2. Length(L) 求线性表长度
*3. LocateElem(L,e)   按值查找
*4. GetElem(L,i)    按位查找
*5. ListInsert(&L,i,e)  插入
*6. ListDelete(&L,i,&e)  删除
*7. PrintList(L)  输出
*8. Empty(L) 判断是否为空
*9. DestroyList(&L) 销毁操作
*
*在传参时，要注意如果要修改线性表的值，需要传入指针，方可修改对应地址的值，否则结束函数，值不变
*而如果只是获得线性表的值，则只需将线性表传入，对应进行操作即可
*
*
*
*/

#define InitSize 100   //线性表初始化长度


typedef int ElemType;

/**
*静态分配
*/
typedef struct 
{
    ElemType *data;  //顺序表的元素
    int MaxSize;        //数组的最大容量
    int length;         //顺序表的长度
}SqList;                //结构体变量的定义


/**
*初始化线性表函数,使用静态分配
*前置条件：线性表不存在
*输入：无
*功能：线性表的初始化
*输出：无
*后置条件：一个空的线性表
*
*/
void InitList(SqList *L)
{
    L->data = (ElemType*)malloc(sizeof(ElemType)*InitSize);
    if(!L->data)
    {
        perror("初始化线性表失败\n");
    }
    L->length = 0;  //当前长度
    L->MaxSize = InitSize; //当前分配量
}

/**
*求表长
*前置条件：线性表已经存在
*输入：线性表
*功能：求线性表长度
*输出：线性表长度
*后置条件：线性表不变
*
*/
int Length(SqList L)
{
    return L.length;
}

/**
* 按值查找函数
* 前置条件：线性表已经存在
* 输入：线性表L，数据元素X
* 功能：按值查找，在线性表中查找值等于X的元素
* 输出：如果查找成功，返回元素X在表中序号，否则返回-1
*
*/
int LocateElem(SqList L, ElemType X)
{
    int i = 0;
    for(i = 0;i<L.length;i++)
    {
        if(L.data[i]==X)
        {
            return i;
        }
    }
    return -1;
}

/**
* 按位查找函数
* 前置条件：线性表存在
* 输入：线性表L，元素的序号i
* 功能：按位查找，获取线性表中第i个元素的值
* 输出：如果序号合法，返回序号位i的值，否则返回-1
* 后置条件：线性表不变
*
*/
ElemType GetElem(SqList L, ElemType i)
{
    if(i<0 || i>L.length)
    {
        return -1;
    }
    else
    {
        return L.data[i];
    }

}



/**
* 前置条件：线性表已存在
* 输入：线性表L
* 功能：便利线性表的各个数据元素
* 输出：打印线性表的各个数据元素
* 后置条件：线性表不变
*
*/
void PrintList(SqList L)
{
    int i ;
    for(i = 0;i < L.length;i++)
    {
        printf("i=%d ,data=%d\n",i,L.data[i]);
    }
}
/**
* 插入操作函数
* 前置条件：线性表已存在
* 输入：线性表L，插入位置i,插入元素e
* 功能：插入操作，在线性表的第i个元素位置出插入一个新元素e
* 输出：若插入不成功，返回-1，成功返回1
* 后置条件：若插入成功，线性表增加一个元素
*
*/
int ListInsert(SqList *L,int i,ElemType e)
{
    if(i<1 || i>L->length+1)    //判断i的有效性
    {
        return -1;
    }
    if(L->length >=L->MaxSize) //判断存储空间已满，不能插入
    {
        return -1;
    }
    int j;
    for(j = L->length; j>=i;j--)  //将第i个元素及之后的元素后移
    {
        L->data[j] = L->data[j-1];  

    }

    L->data[i-1] = e;
    L->length++;
    return 1;
}





/**
* 判断是否为空线性表
* 前置条件：线性表已存在
* 输入：线性表
* 功能：判空操作，判断线性表是否位空表
* 输出：若是空表，返回1，否则返回0
* 后置条件：线性表不变
*
*/
int Empty(SqList L)
{
    if(L.length == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
* 删除操作
* 前置条件：线性表已存在
* 输入：删除位置i
* 功能：删除操作，删除线性表中的第i个元素
* 输出：若删除成功，返回1，否则抛出异常
* 后置条件：若删除成功，表中减少一个元素
*
*/
ElemType ListDelete(SqList *L, int i, ElemType *e)
{
    if(i<0 || i>L->length)
    {
        perror("error");
    }

    *e = L->data[i-1];

    for(; i<L->length;i++) //将线性表i以后的元素前移一个位置
    {
        L->data[i-1] = L->data[i];
    }
    L->length --;      //线性表长度减1
    return 1;

}


/**
* 销毁线性表
* 前置条件：线性表已存在
* 输入：无
* 功能：销毁线性表
* 输出：无
* 后置条件：释放线性表所占用的存储空间
*/
void DestroyList(SqList *L)
{
    L->length = 0;
}


/**
*测试代码
*
*/
void test()
{
}

int main()
{


    SqList L;

    //初始化线性表
    InitList(&L);

    //线性表初始化赋值
    int i;
    for(i = 0;i<10;i++)
    {
        L.data[i] = i;
        L.length++;
    }

    //测试打印函数
    PrintList(L);

    //测试插入函数
    ListInsert(&L, 3,100);
    PrintList(L);

    //测试按值查找和按位查找函数
    int l =  LocateElem(L,1);
    int g =  GetElem(L,2);
    printf("l=%d,g=%d\n",l,g);

    //测试删除函数
    int d;
    ListDelete(&L, 2, &d);
    printf("d = %d\n", d);
    PrintList(L);

    //测试销毁函数
    DestroyList(&L);
    PrintList(L);

}





