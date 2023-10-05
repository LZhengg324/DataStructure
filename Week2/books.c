#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct library
{
    char name[51];
    char author[21];
    char publisher[31];
    char publishdate[11];
}books[500],t;
void arrange(int n, struct library books[500], struct library t)
{
    int i,j;
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(strcmp(books[i].name,books[j].name)>0){
                t=books[i];
                books[i]=books[j];
                books[j]=t;
            }
        }
    }
}
int main()
{
    FILE *fp1;
    FILE *fp2;
    int i=0;
    int action=1;
    int storage;
    char s[10001];
    if((fp1=fopen("books.txt","r"))==NULL){
        printf("-1");
        exit(EXIT_FAILURE);
    }
    if((fp2=fopen("ordered.txt","w"))==NULL){
        printf("-1");
        exit(EXIT_FAILURE);
    }
    while((fscanf(fp1, "%s %s %s %s", books[i].name, books[i].author, books[i].publisher, books[i].publishdate))!=EOF){
        i++;
    }
    storage=i;
    arrange(storage,books,t);
    while(action!=0){
        scanf("%d",&action);
        if(action==1){
            scanf("%s %s %s %s",books[storage].name, books[storage].author, books[storage].publisher, books[storage].publishdate);
            storage++;
        }else if(action==2){
            scanf("%s", s);
            for(i=0; i<storage; i++){
                if(strstr(books[i].name, s)!=NULL){
                    printf("%-50s%-20s%-30s%-10s\n",books[i].name, books[i].author, books[i].publisher, books[i].publishdate);
                }
            }
        }else if(action==3){
            scanf("%s",s);
            for(i=0; i<storage; i++){
                if(strstr(books[i].name,s)!=NULL){
                    strcpy(books[i].name,"\0");
                    strcpy(books[i].author,"\0");
                    strcpy(books[i].publisher,"\0");
                    strcpy(books[i].publishdate,"\0");
                }
            }
        }
        arrange(storage,books,t);
    }
    for(i=0; i<storage; i++){
        if(books[i].name[0]!='\0'){
            fprintf(fp2,"%-50s%-20s%-30s%-10s\n", books[i].name, books[i].author, books[i].publisher, books[i].publishdate);
        }else{
            continue;
        }
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}