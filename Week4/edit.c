#include<stdio.h>
#include<string.h>
struct Stack{
    int op;
    int pos;
    char str[512];
}stack[100];
int main()
{
    char s[10001],t[10001];
    int n,i,len;
    int deletechar;
    int currentop=0;
    int stacktop=0;
    gets(s);
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d%s",&stack[stacktop].op,&stack[stacktop].pos,stack[stacktop].str);
        stacktop++;
    }
/*    for(i=0;i<n;i++){
        printf("%d %d %s\n",stack[i].op,stack[i].pos,stack[i].str);
    }*/
    for(i=0;currentop!=-1;i++){
        scanf("%d",&currentop);
        if(currentop==1){  //插入
            stack[stacktop].op=1;
            scanf("%d%s",&stack[stacktop].pos,stack[stacktop].str);
            strcpy(t,&s[stack[stacktop].pos]);
            s[stack[stacktop].pos]='\0';
            strcat(s,stack[stacktop].str);
            len=strlen(s);
            s[len]='\0';
            strcat(s,t);
            len=strlen(s);
            s[len]='\0';
            stacktop++;
//            printf("%s\n",s);
        }else if(currentop==2){   //删除
            stack[stacktop].op=2;
            scanf("%d%d",&stack[stacktop].pos,&deletechar);
            if(deletechar>strlen(s)-stack[stacktop].pos){
                strcpy(stack[stacktop].str,&s[stack[stacktop].pos]);
                strcpy(&s[stack[stacktop].pos],"\0");
                stacktop++;
//                printf("%s\n",s);
                continue;
            }
            strcpy(t,&s[stack[stacktop].pos+deletechar]);
            s[stack[stacktop].pos+deletechar]='\0';
            strcpy(stack[stacktop].str,&s[stack[stacktop].pos]);
            strcpy(&s[stack[stacktop].pos],"\0");
            strcat(s,t);
            len=strlen(s);
            s[len]='\0';
            stacktop++;
//            printf("%s\n",s);
        }else if(currentop==3){
            if(stacktop<=0)continue;
            if(stack[stacktop-1].op==1){
                stacktop--;
                len=strlen(stack[stacktop].str);
                strcpy(t,&s[stack[stacktop].pos+len]);
 //               printf("%s\n",t);
                s[stack[stacktop].pos]='\0';
                strcat(s,t);
                stack[stacktop].op=0;
                stack[stacktop].pos=0;
                strcpy(stack[stacktop].str,"\0");
 //               printf("%s\n",s);
            }else if(stack[stacktop-1].op==2){
                stacktop--;
                strcpy(t,&s[stack[stacktop].pos]);
                strcpy(&s[stack[stacktop].pos],"\0");
                strcat(s,stack[stacktop].str);
                len=strlen(s);
                s[len]='\0';
                strcat(s,t);
                len=strlen(s);
                s[len]='\0';
                stack[stacktop].op=0;
                stack[stacktop].pos=0;
                strcpy(stack[stacktop].str,"\0");
//                printf("%s\n",s);
            }
        }
    }
    printf("%s",s);
    return 0;
}