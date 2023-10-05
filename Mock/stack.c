#include<stdio.h>
#include<string.h>
struct Function{
    char name[21];
    char invoke[10][21];
    int n;
}function[100];
int main()
{
    char stack[201][21];
    int stacktop=-1;
    int op;
    int i,j,k,functionnow=0;
    do{
        scanf("%d",&op);
        if(op==8){
            scanf("%s",stack[++stacktop]);
            for(i=0;i<(stacktop+1);i++){   
                if(strcmp(function[i].name,stack[stacktop])==0){
                    break;
                }
            }
            if(i==(stacktop+1)){           
                strcpy(function[functionnow].name,stack[stacktop]);
                function[functionnow++].n=0;
            }
            for(j=0;j<functionnow;j++){             
                if(strcmp(stack[stacktop-1],function[j].name)==0){
                    break;
                }
            }
            if(j!=functionnow){
                for(k=0;k<function[j].n;k++){ 
                    if(strcmp(function[j].invoke[k],stack[stacktop])==0){
                        break;
                    }
                }
            }else k=-1;
            if(k==function[j].n){                    
                strcpy(function[j].invoke[k],stack[stacktop]);
                function[j].n++;
            }
        }else if(op==0){
            strcpy(stack[stacktop],"\0");
            stacktop--;
        }
    }while(stacktop>=0);
    for(i=0;i<functionnow;i++){
        if(function[i].n!=0){                      
            printf("%s:",function[i].name);
            for(k=0;k<function[i].n-1;k++){
                printf("%s,",function[i].invoke[k]);
            }
            printf("%s\n",function[i].invoke[k]);
        }
    }
    return 0;
}