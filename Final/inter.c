#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct Stack
{
    char name[200];
    double n;
}stack[200];
int top;
int main()
{
    char op[201];
    char s[200],t[200];
    double num[200];
    double houzhui[200];
    double ysf[200];
    int houzhuitop=0;
    int ysftop=0;
    int numtop=0;
    int i,k=0,j,m=0,mark=1;
    while (1){
        scanf("%s",op);
        if(strcmp(op,"exit")==0)break;
        else if(strcmp(op,"print")==0){
            gets(s);
            for(i=0;s[i]!='\0';i++){
                if(s[i]!=' ')t[k++]=s[i];
                else{
                    t[k]='\0';
                    for(j=0;j<top;j++){
                        if(strcmp(stack[j].name,t)==0){
                            printf("%s=%.3f ",stack[j].name,stack[j].n);
                        }
                    }
                    strcpy(t,"\0");
                    k=0;
                }
            }
            t[k]='\0';
            for(j=0;j<top;j++){
                if(strcmp(stack[j].name,t)==0){
                    printf("%s=%.3f ",stack[j].name,stack[j].n);
                }
            }
            k=0;
            strcpy(t,"\0");
            printf("\n");   
        }else{
            strcpy(s,op);
            m=0,k=0;
            while(s[m]!='=')t[k++]=s[m++];
            t[k]='\0';
            for(i=0;i<top;i++){
                if(strcmp(stack[top].name,t)==0)break;
            }
            if(i==top){
                strcpy(stack[top++].name,t);
            }
            strcpy(t,"\0");
            m++;
            j=m;
            while(s[j]!='\0'){
                if(s[j]=='+'||s[j]=='-'||s[j]=='*'||s[j]=='/'){
                    mark=0;
                    break;
                }
                j++;
            }
            if(mark){
                stack[i].n=atof(&s[m]);
                continue;
            }else if(!mark){
                mark=1;
                strcpy(t,&s[m]);
                //printf("%s\n",t);
                strcpy(s,t);
                for(i=0;s[i]!='\0';i++){
                    if(isdigit(s[i])){
                        num[numtop++]=atof(&s[i]);
                        while(isdigit(s[i+1]))i++;
                    }else if(isalpha(s[i])){
                        for(j=i,k=0;isalpha(s[j]);j++)t[k++]=s[j];
                        t[k]='\0';
                        for(m=0;m<top;m++){
                            if(strcmp(stack[m].name,t)==0)num[numtop++]=stack[m].n;
                        }
                        i=j-1;
                        strcpy(t,"\0");
                    }else{
                        switch(s[i]){
                            case '(' : 
                            num[numtop++]=-1.0;
                            break;

                            case '+' : 
                            num[numtop++]=-2.0;
                            break;

                            case '-' :
                            num[numtop++]=-3.0;
                            break;

                            case '*' :
                            num[numtop++]=-4.0;
                            break;

                            case '/' :
                            num[numtop++]=-5.0;
                            break;

                            case ')' :
                            num[numtop++]=-6.0;
                            break;
                        }
                    }
                }
                for(i=0;i<numtop;i++){
                    printf("%f ",num[i]);
                }
                printf("\n");
                for(i=0;i<numtop;i++){
                    if(num[i]>=0){
                        houzhui[houzhuitop++]=num[i];
                    }else if(num[i]<0){
                        if(num[i]==-1.0){
                            ysf[ysftop++]=num[i];
                        }else if(num[i]==-6.0){
                            while(ysf[ysftop-1]!=-1.0)houzhui[houzhuitop++]=ysf[--ysftop];
                            ysftop--;
                        }else if(num[i]==-2.0||num[i]==-3.0){
                            while(ysf[ysftop-1]!=-1.0&&ysftop>0)houzhui[houzhuitop++]=ysf[--ysftop];
                            ysf[ysftop++]=num[i];
                        }else if(num[i]==-4.0||num[i]==-5.0){
                            if(ysf[ysftop-1]==-2.0||ysf[ysftop-1]==-3.0){
                                ysf[ysftop++]=num[i];
                            }else if(ysf[ysftop-1]==-4.0||ysf[ysftop-1]==-5.0){
                                houzhui[houzhuitop++]=ysf[--ysftop];
                                ysf[ysftop++]=num[i];
                            }
                        }   
                    }
                }
                while(ysftop>0){
                    houzhui[houzhuitop++]=ysf[--ysftop];
                }
                for(i=0;i<houzhuitop;i++){
                    printf("%f ",houzhui[i]);
                }
            }
        }
    }
    return 0;
}