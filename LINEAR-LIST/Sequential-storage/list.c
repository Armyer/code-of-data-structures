#include <stdio.h>

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
 *
 *
 */


#define MaxSize 50

typedef struct 
{
	int data[MaxSize];
	int length;
}SqList;


int main()
{
	/*typedef struct 
	{
		int data[MaxSize];
		int length;
	}SqList;*/
	SqList *l;
        l->data[0]=2;

	printf("%d\n",l->data[0]);
	return 0;
}
