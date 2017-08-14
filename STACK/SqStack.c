/*************************************************************************
	> File Name: SqStack.c
	> Author:Armyer 
	> Mail: 79288428jj@gmail.com
	> Created Time: 2017年08月14日 星期一 15时35分04秒
 ************************************************************************/

#include<stdio.h>

#define MaxSize 50

typedef int ElemType;

typedef struct
{
    ElemType data[MaxSize];
    int top;
}SqStack;



/**
*初始化栈
*
*
*/
void InitStack(SqStack* S)
{

    S->top = -1;
}

/**
 *判断栈是否为空
 *
 */
int StackEmpty(SqStack S)
{
    if(S.top==-1)
    {
        return 1;
    }
    
    return 0;
}

/**
 *进栈操作
 *
 */
int Push(SqStack* S, ElemType x)
{
    if(S->top==MaxSize)
    {
        return -1;
    }

    S->data[++S->top] = x;
    return 1;
}

/**
 *得到栈顶元素
 *
 */
int GetTop(SqStack S,int* e)
{
    if(S.top==-1)
    {
        return -1;
    }
    *e = S.data[S.top];
    return 1;
}


/**
 *出栈
 *
 */
int Pop(SqStack* S,ElemType* x)
{
    if(S->top==-1)
    {
        return -1;
    }
    *x = S->data[S->top--];
    return 1;
}



int main()
{
    SqStack s;
    InitStack(&s);
    StackEmpty(s);
    Push(&s, 1);
    Push(&s, 2);
    Push(&s, 3);
    
    int e ;
    GetTop(s,&e);
    printf("e=%d\n",e);
    int x;
    Pop(&s,&x);
    printf("x=%d\n",x);

    GetTop(s,&e);
    printf("e=%d\n",e);
    return 0;


}
