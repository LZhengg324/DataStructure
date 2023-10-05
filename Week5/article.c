#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct Binarytree* bst;
struct Binarytree
{
    char word[10000];
    int appear;
    bst left,right;
}tree;
bst insert(bst ptr,char s[10000])
{
    if(ptr==NULL){
        ptr=(bst)malloc(sizeof(struct Binarytree));
        ptr->appear=1;
        strcpy(ptr->word,s);
        ptr->left=ptr->right=NULL;
    }else{
        if(strcmp(s,ptr->word)>0)ptr->right=insert(ptr->right,s);
        else if(strcmp(s,ptr->word)<0)ptr->left=insert(ptr->left,s);
        else if(strcmp(s,ptr->word)==0)ptr->appear++;
    }
    return ptr;
}
void print(bst ptr){
    if(ptr){
        print(ptr->left);
        printf("%s %d\n",ptr->word,ptr->appear);
        print(ptr->right);
    }
}
int main()
{
    FILE *fp;
    bst root=NULL,p;
    char s[10000],t[10000];
    int i,j;
    if((fp=fopen("article.txt","r"))==NULL){
        exit(EXIT_FAILURE);
    }
    while(fgets(s,10000,fp)){
        for(i=0;s[i]!='\0';i++){
            if(isalpha(s[i]))s[i]=tolower(s[i]);
            else s[i]=' ';
        }
        for(i=0;s[i]!='\0';i++){
            strcpy(t,"\0");
            for(j=0;isalpha(s[i]);i++){
                t[j++]=s[i];
            }
            t[j]='\0';
            if(t[0]=='\0')continue;
            root=insert(root,t);
        }
    }
    p=root;
    for(i=0;i<3&&p;i++){
        printf("%s ",p->word);
        p=p->right;
    }
    printf("\n");
    print(root);
    fclose(fp);
    return 0;
}