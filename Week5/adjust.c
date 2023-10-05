#include<stdio.h>
#include<stdlib.h>
struct Node{
    int id;
    struct Node *child[3];
}node[500];
typedef struct Node* treenodeptr;
struct Airport{
    int id;
    int people;
}airport[100];
int compare(const void *a, const void *b){
    struct Airport *A=(struct Airport *)a;
    struct Airport *B=(struct Airport *)b;
    if(A->people==B->people){
        return (A->id-B->id);  //编号小到大
    }else{
        return (B->people-A->people); //人流大到小
    }
}
int portlist[500],portlisttop=0; //更换前层次遍历存储
void layerorder(treenodeptr ptr)
{
    treenodeptr queue[500],current;
    int front=-1,rear=0;
    int i;
    if(ptr!=NULL){
        queue[0]=ptr;
        while(rear>front){
            current=queue[++front];
            if(current->child[0]==NULL&&current->child[1]==NULL&&current->child[2]==NULL){
                portlist[portlisttop++]=current->id;
            }else{
                for(i=0;i<3;i++){
                    if(current->child[i]!=NULL){
                        queue[++rear]=current->child[i];
                    }
                }
            }
        }
    }
}
int main()
{
    int i,j;
    int root,child;
    for(i=0;;i++){
        scanf("%d",&root);
        if(root==-1)break;
        node[root].id=root;
        for(j=0;;j++){
            scanf("%d",&child);
            if(child==-1)break;
            else{
                node[child].id=child;
                node[root].child[j]=&node[child];
            }
        }
    }
    layerorder(&node[100]);
    for(i=0;i<portlisttop;i++){
        scanf("%d %d",&airport[i].id,&airport[i].people);
    }
    qsort(airport,portlisttop,sizeof(struct Airport),compare);
    for(i=0;i<portlisttop;i++){
        printf("%d->%d\n",airport[i].id,portlist[i]);
    }
    return 0;
}