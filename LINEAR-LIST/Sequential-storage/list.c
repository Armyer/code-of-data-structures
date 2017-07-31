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

#define InitSize 100
#define MaxSize 50


/**
*静态分配
*/
typedef struct 
{
    int data[MaxSize];  //顺序表的元素

    int length;         //顺序表的长度
}SqList;                //结构体变量的定义

/**
*动态分配

typedef struct
{

    int *data;           //该处int为数据类型，可定义为其他类型,表示指示动态分配数组的指针
    int MaxSize,length;  //数组最大容量和当前个数
}SqList1                 //动态分配数组顺序表的类型定义

/**
*初始化线性表函数
*
*使用静态分配，下面还有动态分配
*
*初始化成功返回1,失败返回-1
*
*/
int InitList(SqList L)
{
    // L.data = (int*)malloc(sizeof(int*)*MaxSize);
    int i; 
    L.length = 50;
    for(i=0;i<50;i++)
    {
        L.data[i] = 0;
       // L.length ++;
        printf("%d\n",L.data[i]);
    }      

    if(L.data[0] == -1)
    {
        printf("a\n");
        return -1;
    }
    else
    {
        return 1;
    }
}

/**
*求表长函数
*
*传入线性表，返回线性表长度
*/
int Length(SqList L)
{
    return L.length;
}

int main()
{


    SqList l;
    int result = InitList(l);
   // int le = Length(l);
    printf("result %d,length is %d \n",result,l.length);
    return 0;
}
