#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    FILE *fp1;
    FILE *fp2;
    char key[51],keypro[78];
    char en[100001],op[100001]={'0'};
    char alphabet[27],s[27];
    int i, j, k, m, n;
    if((fp1=fopen("encrypt.txt","r"))==NULL){
        printf("-1\n");
        exit(EXIT_FAILURE);
    }
    if((fp2=fopen("output.txt","w"))==NULL){
        printf("-1\n");
       exit(EXIT_FAILURE);
    }
    for(i=0; i<26; i++){
        alphabet[i]=97+i;
    }
    alphabet[26]='\0';
    strcpy(s,alphabet);
    scanf("%s",key);
    for(i=0,k=0; i<strlen(key); i++){
        if(alphabet[key[i]-97]!='0'){
            keypro[k++]=key[i];
            alphabet[key[i]-97]='0';
        }
    }
    for(m=strlen(keypro),n=25,k=0; n>-1; n--){
        if(alphabet[n]!='0'){
            keypro[m+k++]=alphabet[n];
        }
    }
    keypro[m+k]='\0';
    fgets(en, 100001, fp1);
    for(i=0; en[i]!='\0'; i++){
        if(en[i]>='a'&&en[i]<='z'){
            for(j=0;j<27;j++){
                if(s[j]==en[i]){
                    op[i]=keypro[j];
                    op[i+1]='\0';
                    break;
                }
            }
        }else{
            op[i]=en[i];
            op[i+1]='\0';
        }
    }
    fputs(op,fp2);
    fclose(fp1);
    fclose(fp2);
    return 0;
}