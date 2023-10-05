#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 1000

struct sym{
    char sym;
    int line;
}symstack[MAXSIZE],allsym[MAXSIZE];//symstack括号栈，allsym储存文件中所有符合规则的括号

int top=-1;
int front=0,rear=0;

void enter(char sym,int line){
    if(rear>MAXSIZE){
        exit(0);
    }
    allsym[rear].sym=sym;
    allsym[rear++].line=line;
}

void push(char sym,int line){
    if(top==MAXSIZE-1){
        exit(0);
    }
    symstack[++top].sym=sym;
    symstack[top].line=line;
}

void pop(){
    if(top==-1){
        exit(0);
    }
    top--;
}
int main(){
    FILE *in;
    char input[1000],previous[1000];
    char c='-';
    int n=0;
    int i,j,line=0;
    int ret=0,ret2=0;//没有越行的注释
    
//    in=fopen("example.txt","r");
    in=fopen("example.c","r");
    if(in==NULL){
        printf("fail to open\n");
        return(EXIT_FAILURE);
    }
    
    while(!feof(in)){
        fgets(input,1000,in);
        line++;

        if(strcmp(previous,input)==0 && feof(in)) break;
        strcpy(previous,input);
        
        for(i=0;input[i]!='\0';i++){
            if((input[i]=='/'&&input[i+1]=='/')&&ret==0&&ret2==0){
                break;
            }else if((input[i]=='"'&&ret==0)||ret2==1){
                if(ret2==1) j=i;
                else j=i+1;
                for(;input[j]!='\0';j++){
                    if(input[j]=='"'){
                        i=j;
                        ret2=0;
                        break;
                    }
                    if(input[j+1]=='\0'){
                        ret2=1;
                        i=j;
                    }
                }
            }else if((input[i]=='/'&&input[i+1]=='*')||ret==1){
                if(ret==1)j=i;
                else j=i+2;
                for(;input[j]!='\0';j++){
                    if(input[j]=='*'&&input[j+1]=='/'){
                        i=j+1;
                        ret=0;
                        break;
                    }
                    if(input[j+1]=='\0'){
                        ret=1;
                        i=j;
                    }
                }
            }else if(input[i]=='('||input[i]==')'||input[i]=='{'||input[i]=='}'){
                enter(input[i],line);
            }
        }
    }
    
    for(i=front;i<rear;i++){
        c=allsym[i].sym;
        n=allsym[i].line;
        if(c=='('||c=='{'){
            if(c=='{'&&symstack[top].sym=='('){
                c=symstack[top].sym;
                n=symstack[top].line;
                break;
            }
            push(c,n);
        }else if(c==')'||c=='}'){
            if(c==')'&&symstack[top].sym=='('){
                pop();
            }else if(c=='}' && symstack[top].sym=='{'){
                pop();
            }else{
                break;
            }
        }
    }
    
    if(i!=rear){
        printf("without maching '%c' at line %d\n",c,n);
    }else if(i==rear&&top!=-1){
        printf("without maching '%c' at line %d\n",symstack[top].sym,symstack[top].line);
    }else if(i==rear&&top==-1){
        for(i=front;i<rear;i++){
            printf("%c",allsym[i].sym);
        }
        printf("\n");
    }
    return 0;
}
