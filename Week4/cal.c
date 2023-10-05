#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct Stack{
    double data[202];
    int top;
}stack;
int main()
{
    char s[202],t[202];
    double num[202]={0},numback[202]={0};
    int i,k;
    stack.top=0;
    gets(s);
    for(i=0;s[i]!='\0';i++){
        if(s[i]==' '){
            strcpy(t,&s[i+1]);
            s[i]='\0';
            strcat(s,t);
            i=i-1;
        }
    }
    for(i=0,k=0;s[i]!='=';i++){
        if(isdigit(s[i])){
            num[k++]=atoi(&s[i])*1.0;
            while(isdigit(s[i+1]))i++;
        }else if(!isdigit(s[i])){
            switch(s[i]){
                case '(' : 
                num[k++]=-1.0;
                break;

                case '+' : 
                num[k++]=-2.0;
                break;

                case '-' :
                num[k++]=-3.0;
                break;

                case '*' :
                num[k++]=-4.0;
                break;

                case '/' :
                num[k++]=-5.0;
                break;

                case ')' :
                num[k++]=-6.0;
                break;
            }
        }
    }
    for(i=0,k=0;num[i]!=0;i++){
        if(num[i]>0){
            numback[k++]=num[i];
        }else if(num[i]<0){
            if(num[i]==-1.0){
                stack.data[stack.top++]=num[i];
            }else if(num[i]==-2.0||num[i]==-3.0){
                if(stack.data[stack.top-1]!=-2&&stack.data[stack.top-1]!=-3&&stack.data[stack.top-1]!=-4&&stack.data[stack.top-1]!=-5){
                    stack.data[stack.top++]=num[i];
                }else{
                    do{
                        numback[k++]=stack.data[--stack.top];
                        stack.data[stack.top]=0;
                    }while(stack.data[stack.top-1]!=-1.0&&stack.top>0);
                    stack.data[stack.top++]=num[i];
                }
            }else if(num[i]==-4.0||num[i]==-5.0){
                if(stack.data[stack.top-1]!=-4.0&&stack.data[stack.top-1]!=-5.0){
                    stack.data[stack.top++]=num[i];
                }else if(stack.data[stack.top-1]==-4.0||stack.data[stack.top-1]==-5.0){
                    do{
                        numback[k++]=stack.data[--stack.top];
                        stack.data[stack.top]=0;
                    }while((stack.data[stack.top-1]==-4.0||stack.data[stack.top-1]==-5.0)&&stack.top>0);
                    stack.data[stack.top++]=num[i];
                }
            }else if(num[i]==-6.0){
                do{
                    numback[k++]=stack.data[--stack.top];
                    stack.data[stack.top]=0;
                }while(stack.data[stack.top-1]!=-1.0);
                stack.data[--stack.top]=0;
            }
        }
    }
    while(stack.top>0){
        numback[k++]=stack.data[--stack.top];
        stack.data[stack.top]=0;
    }
    for(i=0;numback[i]!=0;i++){
        if(numback[i]>0){
            stack.data[stack.top++]=numback[i];
        }else if(numback[i]<0){
            if(numback[i]==-2.0){
                stack.data[stack.top-2]=stack.data[stack.top-2]+stack.data[stack.top-1];
                stack.top--;
            }else if(numback[i]==-3.0){
                stack.data[stack.top-2]=stack.data[stack.top-2]-stack.data[stack.top-1];
                stack.top--;
            }else if(numback[i]==-4.0){
                stack.data[stack.top-2]=stack.data[stack.top-2]*stack.data[stack.top-1];
                stack.top--;
            }else if(numback[i]==-5.0){
                stack.data[stack.top-2]=stack.data[stack.top-2]/stack.data[stack.top-1];
                stack.top--;
            }
        }
    }
    printf("%.2f",stack.data[stack.top-1]);
    return 0;
}