#include<stdio.h>
struct Stack
{
    int data[100];
    int top;
}stack;
void pushstack(int n)
{
    if(stack.top<99){
        stack.data[stack.top++]=n;
    }else{
        printf("error ");
    }
}
void popstack()
{
    if(stack.top>0){
        printf("%d ",stack.data[--stack.top]);
    }else{
        printf("error ");
    }
}
int main()
{
    int operation;
    int num;
    stack.top=0;
    while(scanf("%d",&operation)!=-1){
        if(operation==1){
            scanf("%d",&num);
            pushstack(num);
        }else if(operation==0){
            popstack();
        }
    }
    getchar();
    return 0;
}