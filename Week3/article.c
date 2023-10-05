#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
char vocab[1024][50],t[50];
void arrangement(char vocab[1024][50])
{
    int i,j;
    for(i=0;vocab[i][0]!='\0';i++){
        for(j=i+1;vocab[j][0]!='\0';j++){
            if(strcmp(vocab[i],vocab[j])>0){
                strcpy(t,vocab[i]);
                strcpy(vocab[i],vocab[j]);
                strcpy(vocab[j],t);
            }
        }
    }
}
int main()
{
    char s[50];
    int i=0,k=0,j=0,len;
    int currentvocabline=0;
    int count=1;
    FILE *fp;
    if((fp=fopen("article.txt","r"))==NULL){
        printf("-1");
        exit(EXIT_FAILURE);
    }
    while((fscanf(fp,"%s",s))!=EOF){ 
        len=strlen(s);
        s[len]='\0';
        for(i=0;i<strlen(s);i++){
            if(isupper(s[i]))s[i]=tolower(s[i]);
        }
        for(i=0;i<strlen(s);i++){
            if(s[i]>='a'&&s[i]<='z'){
                for(j=i;s[j]>='a'&&s[j]<='z';j++){
                    vocab[currentvocabline][k++]=s[j];
                }
                currentvocabline++,k=0;
                i=j;
            }
        }
//        printf("---------\n");
    }
    arrangement(vocab);
    for(i=0;vocab[i][0]!='\0';i++){
        if(strcmp(vocab[i],vocab[i+1])==0){
            count++;
        }else{
            printf("%s %d\n",vocab[i],count);
            count=1;
        }
    }
    fclose(fp);
    return 0;
}