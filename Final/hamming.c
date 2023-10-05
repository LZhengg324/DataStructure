#include<stdio.h>
#include<string.h>
struct Hamming
{
    char s[17];
    int distance;
}hamming[16],t;
int main()
{
    int N,i,k,cnt=0,flag;
    char c[17];
    scanf("%d",&N);
    scanf("%s",c);
    for(i=0;i<N-1;i++){
        scanf("%s",hamming[i].s);
    }
    for(i=0;i<N-1;i++){
        cnt=0;
        for(k=0;c[k];k++)if(c[k]!=hamming[i].s[k])cnt++;
        hamming[i].distance=cnt;
    }
    for(i=0;i<N-1;i++){
        flag=1;
        for(k=1;k<N-1-i;k++){
            if(hamming[k-1].distance<hamming[k].distance){
                flag=0;
                t=hamming[k-1];
                hamming[k-1]=hamming[k];
                hamming[k]=t;
            }else if(hamming[k].distance==hamming[k-1].distance&&strcmp(hamming[k].s,hamming[k-1].s)<0){
                flag=0;
                t=hamming[k-1];
                hamming[k-1]=hamming[k];
                hamming[k]=t;
            }
        }
        if(flag)break;
    }
    for(i=0;i<N-1;i++){
        printf("%s ",c);
        printf("%s ",hamming[i].s);
        printf("%d\n",hamming[i].distance);
    }
    return 0;
}