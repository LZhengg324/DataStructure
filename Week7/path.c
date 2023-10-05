#include<stdio.h>
#include<stdlib.h>
typedef struct Node node;
typedef struct Ver ver;
struct Node{
    int weight;
    ver *head; 
    node *next;
};
struct Ver{
    int data;
    int flag;
    node *next;
};
ver* list[1000];
node* Createnode(int vex, int weight)
{
    node* new;
    new=(node*)malloc(sizeof(node));
    new->weight=weight;
    new->head=list[vex];
    new->next=NULL;
    return new;
}
void insertnode(int weight, int data, int vex)
{
    node *new,*p;
    new=Createnode(vex, weight);
    if(!list[data]->next){
        list[data]->next=new;
    }else if(!list[data]->next->next){
        if(new->weight<list[data]->next->weight){
            new->next=list[data]->next;
            list[data]->next=new;
        }else{
            list[data]->next->next=new;
        }
    }else{
        for(p=list[data]->next;p->next;p=p->next)if(new->weight<p->next->weight)break;
        new->next=p->next;
        p->next=new;
    }
}
int path[1000];
int top;//栈
int end;//终点
void DFS(int vex){
    int i;
    node *p;
    if(vex==end){
        for(i=0;i<top;i++){
            printf("%d ",path[i]);
        }
        printf("\n");
    }else{
        for(p=list[vex]->next;p;p=p->next){
            if(!p->head->flag){
                p->head->flag=1;
                path[top++]=p->weight;
                DFS(p->head->data);
                p->head->flag=0;
                top--;
            }
        }
    }
}
int main()
{
    int vex,edge,i;
    int weight,a,b;
    scanf("%d%d",&vex,&edge);
    end=vex-1;
    for(i=0;i<vex;i++){
        list[i]=(ver*)malloc(sizeof(ver));
        list[i]->data=i;
        list[i]->flag=0;
        list[i]->next=NULL;
    }
    for(i=0;i<edge;i++){
        scanf("%d%d%d",&weight,&a,&b);
        insertnode(weight,a,b);
        insertnode(weight,b,a);
    }
    list[0]->flag=1;
    DFS(0);
    return 0;
}