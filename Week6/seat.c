#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Info
{
    char no[9];
    char name[21];
    int seat;
}info[100];
void bubblesort_seat(int n)
{
    int i,j,t,flag;
    char tmp[21];
    for(i=0;i<n;i++){
        flag=1;
        for(j=1;j<n;j++){
            if(info[j-1].seat>info[j].seat){
                flag=0;
                strcpy(tmp,info[j-1].no);
                strcpy(info[j-1].no,info[j].no);
                strcpy(info[j].no,tmp);
                strcpy(tmp,info[j-1].name);
                strcpy(info[j-1].name,info[j].name);
                strcpy(info[j].name,tmp);
                t=info[j-1].seat;
                info[j-1].seat=info[j].seat;
                info[j].seat=t;
            }else if(info[j-1].seat==info[j].seat&&(strcmp(info[j-1].no,info[j].no)>0)){
                flag=0;
                strcpy(tmp,info[j-1].no);
                strcpy(info[j-1].no,info[j].no);
                strcpy(info[j].no,tmp);
                strcpy(tmp,info[j-1].name);
                strcpy(info[j-1].name,info[j].name);
                strcpy(info[j].name,tmp);
            }
        }
        if(flag==1)break;
    }
    return;
}
void bubblesort_no(int n)
{
    int i,j,t,flag;
    char tmp[21];
    for(i=0;i<n;i++){
        flag=1;
        for(j=1;j<n;j++){
            if(strcmp(info[j-1].no,info[j].no)>0){
                flag=0;
                strcpy(tmp,info[j-1].no);
                strcpy(info[j-1].no,info[j].no);
                strcpy(info[j].no,tmp);
                strcpy(tmp,info[j-1].name);
                strcpy(info[j-1].name,info[j].name);
                strcpy(info[j].name,tmp);
                t=info[j-1].seat;
                info[j-1].seat=info[j].seat;
                info[j].seat=t;
            }
        }
        if(flag==1)break;
    }
    return;
}
int main()
{
    int N,M=0,Q,i,j,tmp[100]={0},flag=0;
    FILE *fp;
    if((fp=fopen("in.txt","r"))==NULL){
        printf("FAIL");
        exit(EXIT_FAILURE);
    }
    scanf("%d",&N);
    for(i=0;i<N;i++){
        fscanf(fp,"%s",info[i].no);
        fscanf(fp,"%s",info[i].name);
        fscanf(fp,"%d",&info[i].seat);
    }
    fclose(fp);
    bubblesort_seat(N);
    for(i=0;i<N;i++){
        tmp[info[i].seat]++;
    }
    M=info[N-1].seat;
    Q=M>N?N:M;
    for(j=1;j<=Q;j++){
        if(tmp[j]==0){
            tmp[info[N-1].seat]--;
            if(tmp[info[N-1].seat]<0)tmp[info[N-1].seat]=0;
            info[N-1].seat=j;
            tmp[j]++;
            bubblesort_seat(N);
        }
        M=info[N-1].seat;
        Q=M>N?N:M;
    }
    for(flag=1;tmp[flag]!=0;flag++);
    for(j=1;j<N;j++){
        if(info[j].seat==info[j-1].seat){
            info[j].seat=flag++;
        }
    }
    bubblesort_no(N);
    if((fp=fopen("out.txt","w"))==NULL){
        printf("FAIL");
        exit(EXIT_FAILURE);
    }
    for(i=0;i<N;i++){
        fprintf(fp,"%s ",info[i].no);
        fprintf(fp,"%s ",info[i].name);
        fprintf(fp,"%d\n",info[i].seat);
    }
    return 0;
}