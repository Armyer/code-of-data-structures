/*************************************************************************
	> File Name: list2.c   双链表
	> Author: Armyer 
	> Mail: 79288428jj@gmail.com
	> Created Time: 2017年08月05日 星期六 15时37分56秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>



typedef int ElemType;

typedef struct DNode
{
    ElemType data;
    struct DNode *prior,*next;
}DNode;


int main()
{

    DNode* L;
    L = (DNode*)malloc(sizeof(DNode));
    L->data =1;
    
    printf("%d\n",L->data);
    return 0;


}
