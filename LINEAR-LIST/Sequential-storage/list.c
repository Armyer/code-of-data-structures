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


#define MaxSize 50

typedef struct 
{
	int data[MaxSize];
	int length;
}SqList;      //结构体变量的定义


/**
 *初始化线性表，先分配内存，后判断是否分配成功
 */
int InitList(SqList L)
{
       // L.data = (int*)malloc(sizeof(int*)*MaxSize);
       int i; 
       L.length = 0;
       for(i=0;i<50;i++)
       {
	  L.data[i] = 0;
	  L.length ++;
	  printf("%d\n",L.data[i]);
       }      

       if(L.data[0] == -1)
       {
	     printf("a\n");
	     return -1;
       }
       else
       {
	   //  L.length = 0;
	     return 1;
       }
}

int main()
{
	/*typedef struct 
	{
		int data[MaxSize];
		int length;
	}SqList;*/
        SqList l;
        // l->data[0]=2;
	int result = InitList(l);

	printf("%d\n",result);
	return 0;
}
