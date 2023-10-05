#include<stdio.h>
#include<string.h>
struct Function{
    char name[21];
    char invoke[10][21];
    int n;  //记录这个函数调用了多少函数
}function[100];
int main()
{
    char stack[201][21];
    int stacktop=-1,stackbase=0;
    int operation;
    int i,j,k,functionnow=0;       //functionnow记录function结构体当前共存入多少的元素
    do{
        scanf("%d",&operation);
        if(operation==8){
            scanf("%s",stack[++stacktop]);
            for(i=0;i<(stacktop-stackbase+1);i++){   //查找是否在之前已出现过此函数
                if(strcmp(function[i].name,stack[stacktop])==0){
                    break;
                }
            }
            if(i==(stacktop-stackbase+1)){           //若无，将此函数写在function结构体中新的位子来记录所有函数出现的顺序
                strcpy(function[functionnow].name,stack[stacktop]);
                function[functionnow++].n=0;
            }
            for(j=0;j<functionnow;j++){              //查找前一个栈顶函数在function结构体的位置
                if(strcmp(stack[stacktop-1],function[j].name)==0){
                    break;
                }
            }
            for(k=0;k<function[j].n;k++){            //查找前一个栈顶函数所调用的函数中是否有当前栈顶函数
                if(strcmp(function[j].invoke[k],stack[stacktop])==0){
                    break;
                }
            }
            if(k==function[j].n){                    //若无，则将当前栈顶函数写入前一个栈顶函数的invoke中
                strcpy(function[j].invoke[k],stack[stacktop]);
                function[j].n++;
            }
        }else if(operation==0){
            strcpy(stack[stacktop],"\0");
            stacktop--;
        }
    }while(stacktop>=stackbase);
    for(i=0;i<functionnow;i++){
        if(function[i].n!=0){                        //若function结构体中该位置的函数有调用的其他函数才输出
            printf("%s:",function[i].name);
            for(k=0;k<function[i].n-1;k++){
                printf("%s,",function[i].invoke[k]);
            }
            printf("%s\n",function[i].invoke[k]);
        }
    }
    return 0;
}