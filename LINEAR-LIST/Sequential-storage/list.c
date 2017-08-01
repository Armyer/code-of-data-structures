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
*/

#define InitSize 100  //线性表初始化长度
#define MaxSize 50    //线性表最大长度

typedef int ElemType;

/**
*静态分配
*/
typedef struct 
{
    ElemType data[MaxSize];  //顺序表的元素
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
    L->length = 0;
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




int main()
{


    SqList l;
    InitList(&l);
    
    int le = Length(l);
    
    printf("length is %d \n",le);

    int i;
    for(i=0;i<50;i++)
    {
        l.data[i]=i;
        l.length ++ ;
    }
    int k = LocateElem(l,10);
    printf("i is %d\n",k);

    int getElem = GetElem(l,5);
    printf("get is %d\n",getElem);

    return 0;
}


































