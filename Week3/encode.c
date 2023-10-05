#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char ch;
    struct node *next;
};
typedef struct node* nodeptr;
int main()
{
    char s[33],t[33],key[95];
    char filec;
    char firstch;
    int i,j, n,word;
    int k=32,left=95;
    FILE *fp1,*fp2;
    nodeptr current,newnode,previous,head,keyhead,last;
    if((fp1=fopen("in.txt","r"))==NULL){
        printf("-1");
        exit(EXIT_FAILURE);
    }
    if((fp2=fopen("in_crpyt.txt","w"))==NULL){
        printf("-1");
        exit(EXIT_FAILURE);
    }
    gets(s);
    for(i=0;s[i]!='\0';i++){
        for(j=i+1;s[j]!='\0';j++){
            if(s[i]==s[j]){
                strcpy(t,&s[j+1]);
                s[j]='\0';
                strcat(s,t);
            }
        }
    }
    newnode=(nodeptr)malloc(sizeof(struct node));
    head=newnode;
    current=newnode;
    for(i=0;i<95;i++){     
        current->ch=k++;
        newnode=(nodeptr)malloc(sizeof(struct node));
        current->next=newnode;
        current=current->next;
    }
    last=current;
    current->next=head;
    for(current=head;current->next!=head;current=current->next);
    previous=current;
    for(i=0;s[i]!='\0';i++){
        for(current=head,previous=last;current->next!=head;current=current->next,previous=previous->next){
            if(current->ch==s[i]){
                if(current==head){
                    head=head->next;
                    previous->next=current->next;
                    free(current);
                    current=previous->next;
                }else{
                previous->next=current->next;
                free(current);
                current=previous->next;
                }
            }
        }
    }
    newnode=(nodeptr)malloc(sizeof(struct node));
    keyhead=newnode;
    current=newnode;
    for(i=0;s[i]!='\0';i++){
        current->ch=s[i];
        if(s[i+1]=='\0')break;
        newnode=(nodeptr)malloc(sizeof(struct node));
        current->next=newnode;
        current=current->next;
    }
    current->next=head;
    for(current=keyhead;current->next!=last;current=current->next);
    current->next=keyhead;
    free(last);
    last=current;
    firstch=keyhead->ch;
    current=keyhead;
    previous=last;
    while(left>1){
        word=current->ch;
        n=word-1;
        previous->next=current->next;
        free(current);
        current=previous->next;
        while(n-->0){
            current=current->next;
            previous=previous->next;
        }
        key[word-32]=current->ch;
        left--;
    }
    key[previous->ch-32]=firstch;
//    printf("%s",key);
      while((filec=fgetc(fp1))!=EOF){
        if(filec>=32&&filec<=126){
            fputc(key[filec-32],fp2);
        }else{
            fputc(filec,fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}