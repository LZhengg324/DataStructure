#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Stack{
    char bracket;
    int lines;
}stack[201];
int main()
{
    FILE *fp;
    int currentline=1;
    char s[201],spre[201],record[201]={'\0'};
    int stacktop=0,recordtop=0;
    int i,brk=1;
    int a=1,b=1,c=1;  //记录当前位置是否在"....."(a)或'.....'(b)或/*.....*/(c)之中，1表示继续判断，0表示不继续判断
    if((fp=fopen("example.c","r"))==NULL){
        printf("-1");
        exit(EXIT_FAILURE);
    }
    for(currentline=1;!feof(fp);currentline++){
        fgets(spre,201,fp);
        if(strcmp(s,spre)==0&&feof(fp))break;
        strcpy(s,spre);
        for(i=0;s[i]!='\0';i++){
            if(s[i]=='/'&&s[i+1]=='/'){    //判断当前位置是否在字符常量，字符串或注释内
                if(a==1&&b==1&&c==1){
                    break;
                }
            }else if(s[i]=='\"'){
                if(i==0||s[i-1]!='\\'){
                    if(b==1&&c==1){
                        if(a==1)a=0;
                        else a=1;
                    }
                }
            }else if(s[i]=='\''){
                if(i==0||s[i-1]!='\\'){
                    if(a==1&&c==1){
                        if(b==1)b=0;
                        else b=1;
                    }
                }
            }else if(s[i]=='*'){
                if(s[i-1]=='/'&&c==1&&a==1&&b==1){
                    c=0;
                }else if(s[i+1]=='/'&&c==0&&a==1&&b==1){
                    c=1;
                }
            }
            if(a&&b&&c&&(s[i]=='('||s[i]==')'||s[i]=='{'||s[i]=='}')){   //若当前位置不在字符常量，字符串或注释内且为括号
                record[recordtop++]=s[i];
                if(s[i]=='('){
                    stack[stacktop].bracket=s[i];
                    stack[stacktop++].lines=currentline;
                }else if(s[i]=='{'){
                    if(stack[stacktop-1].bracket=='('){
                        brk=0;
                        printf("without maching '(' at line %d\n",currentline);
                        break;
                    }else{
                        stack[stacktop].bracket=s[i];
                        stack[stacktop++].lines=currentline;
                    }
                }else if(s[i]==')'){
                    if(stack[stacktop-1].bracket=='('){
                        stack[--stacktop].bracket=0;
                    }else if(stack[stacktop-1].bracket=='{'||stacktop==0){
                        brk=0;
                        printf("without maching ')' at line %d\n",currentline);
                        break;
                    }
                }else if(s[i]=='}'){
                    if(stack[stacktop-1].bracket=='{'){
                        stack[--stacktop].bracket=0;
                    }else if(stack[stacktop-1].bracket=='('||stacktop==0){
                        brk=0;
                        printf("without maching '}' at line %d\n",currentline);
                        break;
                    }
                }
            }
        }
        if(brk==0)break;
    }
    if(stacktop==0&&brk!=0){
        printf("%s\n",record);
    }else if(stacktop>0&&brk!=0){
        printf("without maching '%c' at line %d\n",stack[stacktop-1].bracket,stack[stacktop-1].lines);
    }
    fclose(fp);
    return 0;
}