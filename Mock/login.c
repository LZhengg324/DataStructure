#include<stdio.h>
#include<string.h>
struct Login
{
    int id;
    char name[16];
    int cpu;
    char time[7];
    int flag;
}login[200],warning[200],tmp;
int main()
{
    int N;
    int i,j,k=0,f,m;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d%s%d%s",&login[i].id,login[i].name,&login[i].cpu,login[i].time);
        login[i].flag=1;
    }
    for(i=0;i<N;i++){
        if(!login[i].flag)continue;
        for(j=0;j<N;j++){
            if(i==j)continue;
            if(!login[j].flag)continue;
            if(login[i].id==login[j].id&&login[i].flag&&login[j].flag){
                if(login[i].cpu!=login[j].cpu){
                    warning[k++]=login[j];
                    login[i].flag=login[j].flag=0;
                    for(m=0;m<N;m++)if(login[m].id==login[j].id)login[m].flag=0;
                }
            }
        }
    }
    for(i=0;i<k;i++){
        f=1;
        for(j=1;j<k-i;j++){
            if(warning[j-1].id>warning[j].id){
                f=0;
                tmp=warning[j];
                warning[j]=warning[j-1];
                warning[j-1]=tmp;
            }
        }
        if(f)break;
    }
    for(i=0;i<k;i++){
        printf("%d %s\n",warning[i].id,warning[i].name);
    }
    return 0;
}