#include<stdio.h>
struct Line{
    int id;
    int start,end;
    int weight;
};
typedef struct Line line;
line a[100],b[100];
void swap(int *a, int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
int parent[100],top,sum;
int find(int x)
{
    if(parent[x]!=x)parent[x]=find(parent[x]);
    return parent[x];
}
void  attach(line k)
{
    int x,y;
    x=find(k.start);
    y=find(k.end);
    if(x!=y){
        parent[x]=y;
        b[top++]=k;
        sum=sum+b[top-1].weight;
    }
}
int main()
{
    int vex,edge;
    int i,j,flag;
    line t;
    scanf("%d%d",&vex,&edge);
    for(i=0;i<vex;i++){
        parent[i]=i;
    }
    for(i=0;i<edge;i++){
        scanf("%d%d%d%d",&a[i].id,&a[i].start,&a[i].end,&a[i].weight);
    }
    for(i=0;i<edge;i++){
        flag=1;
        for(j=1;j<edge-i;j++){
            if(a[j-1].weight>a[j].weight){
                flag=0;
                t=a[j-1];
                a[j-1]=a[j];
                a[j]=t;
            }
        }
        if(flag==1)break;
    }
    for(i=0;i<edge;i++){
        attach(a[i]);
    }
    for(i=0;i<top;i++){
        flag=1;
        for(j=0;j<top-i;j++){
            if(b[j-1].id>b[j].id){
                t=b[j-1];
                b[j-1]=b[j];
                b[j]=t;
                flag=0;
            }
        }
        if(flag==1)break;
    }
    printf("%d\n",sum);
    for(i=0;i<top;i++){
        printf("%d ",b[i].id);
    }
    return 0;
}