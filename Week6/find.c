#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define NHASH 3001
#define MULT 37
typedef struct Node
{
    char *word;
    struct Node *next;
}node;
node *hashtable[NHASH];
char s[3500][21];
int N,indextable[26][2];
void linear_search(char *target)
{
    int i,cnt=0;
    char *p;
    for(p=target;*p;p++){
        if(!isalpha(*p)){
            printf("0 0\n");
            return;
        }
    }
    for(i=0;s[i];i++){
        cnt++;
        if(strcmp(s[i],target)==0){
            printf("1 %d\n",cnt);
            return;
        }else if(strcmp(s[i],target)>0){
            printf("0 %d\n",cnt);
            return;
        }
    }
}
void binary_search(char *target)
{
    int low=0,high=N,mid,cnt=0;
    char *p;
    for(p=target;*p;p++){
        if(!isalpha(*p)){
            printf("0 0\n");
            return;
        }
    }
    while(low<=high){
        mid=(low+high)/2;
        cnt++;
        if(strcmp(s[mid],target)==0){
            printf("1 %d\n",cnt);
            return;
        }else if(strcmp(s[mid],target)<0){
            low=mid+1;
        }else if(strcmp(s[mid],target)>0){
            high=mid-1;
        }
    }
    printf("0 %d\n",cnt);
    return;
}
void index_search(char *target)
{
    int high,low,mid,cnt=0;
    char *p;
    for(p=target;*p;p++){
        if(!isalpha(*p)){
            printf("0 0\n");
            return;
        }
    }
    low=indextable[target[0]-'a'][0];
    high=indextable[target[0]-'a'][1];
    if(high!=low){
        while(low<=high){
            mid=(low+high)/2;
            cnt++;
            if(strcmp(s[mid],target)==0){
                printf("1 %d\n",cnt);
                return;
            }else if(strcmp(s[mid],target)<0){
                low=mid+1;
            }else if(strcmp(s[mid],target)>0){
                high=mid-1;
            }
        }
    }
    printf("0 %d\n",cnt);
    return;
}
unsigned int hash(char *target)
{
       unsigned int h=0;
       char *p;
       for(p=target; *p!='\0'; p++)h = MULT*h + *p;
       return h % NHASH;
}
void insert_hash(char *target)
{
    unsigned int code;
    node *new,*p;
    new=(node*)malloc(sizeof(struct Node));
    new->word=(char*)malloc(sizeof(char)*strlen(target)+1);
    strcpy(new->word,target);
    new->next=NULL;
    code=hash(target);
    if(hashtable[code]==NULL){
        hashtable[code]=new;
    }else{
        for(p=hashtable[code];p->next;p=p->next);
        p->next=new;
    }
}
void hash_search(char *target)
{
    unsigned int code;
    int cnt=0;
    node *search;
    code=hash(target);
    char *p;
    for(p=target;*p;p++){
        if(!isalpha(*p)){
            printf("0 0\n");
            return;
        }
    }
    for(search=hashtable[code];search!=NULL;search=search->next){
        cnt++;
        if(strcmp(target,search->word)==0){
            printf("1 %d\n",cnt);
            return;
        }else if(strcmp(target,search->word)<0){
            printf("0 %d\n",cnt);
            return;
        }
    }
    printf("0 %d\n",cnt);
    return;
}
int main()
{
    int n=0,op,indexstart=0;
    char t[50];
    FILE *fp;
    if((fp=fopen("dictionary3000.txt","r"))==NULL){
        printf("-1");
        exit(EXIT_FAILURE);
    }
    while(fscanf(fp,"%s",t)!=EOF){
        if(s[n-1][0]!=t[0]){
            indextable[s[n-1][0]-'a'][0]=indexstart;
            indextable[s[n-1][0]-'a'][1]=n-1;
            indexstart=n;
        }
        strcpy(s[n++],t);
        insert_hash(t);
    }
    indextable[s[n-1][0]-'a'][0]=indexstart;
    indextable[s[n-1][0]-'a'][1]=n-1;
    N=n-1;
    /*for(i=0;i<26;i++){
        printf("%c:%d %d\n",i+'a',indextable[i][0],indextable[i][1]);
    }*/
    scanf("%s%d",t,&op);
    switch(op)
    {
        case 1:
        linear_search(t);
        break;
        case 2:
        binary_search(t);
        break;
        case 3:
        index_search(t);
        break;
        case 4:
        hash_search(t);
        break;
    }
    fclose(fp);
    return 0;
}
