#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 1024 
int main()
{
    FILE *fp1;
    FILE *fp2;
    char s1[MAX],s2[MAX],str[MAX],t[MAX];
    int i,j,k;
    int ret=1;
    scanf("%s\n%s",s1,s2);
    if((fp1=fopen("filein.txt","r"))==NULL){
        printf("-1\n");
        exit(EXIT_FAILURE);
    }
    if((fp2=fopen("fileout.txt","w"))==NULL){
        printf("-1\n");
        exit(EXIT_FAILURE);
    }
    fgets(str, MAX, fp1);
    while(!feof(fp1)){
        for(i=0; i<strlen(str); i++){
            if(str[i]==tolower(s1[0])||str[i]==toupper(s1[0])){
                ret=1;
                for(j=i,k=0;s1[k]!='\0';j++,k++){
                    if(str[j]!=toupper(s1[k])&&str[j]!=tolower(s1[k])){
                        ret=0;
                        break;
                    }
                }
                if(ret!=0){
                    strcpy(t,&str[i+strlen(s1)]);
                    str[i]='\0';
                    strcat(str,s2);
                    strcat(str,t);
                    i=i+strlen(s2)-1;
                }
            }
        }
        fputs(str,fp2);
        fgets(str, MAX, fp1);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}