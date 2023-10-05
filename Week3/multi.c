#include<stdio.h>
#include<stdlib.h>
struct node
{
    long long coefficient;
    long long index;
    struct node *next;
};
typedef struct node* Node;
int main()
{
    Node heada,headb,newnode,current,previous,answer,arrange,pa,pb;
    char character;
    long long tcoefficent,tindex;
    newnode=(Node)malloc(sizeof(struct node));
    heada=newnode;
    current=newnode;
    do
    {
        scanf("%lld%lld",&current->coefficient,&current->index);
        character=getchar();
        newnode=(Node)malloc(sizeof(struct node));
        current->next=newnode;
        current=current->next;
        current->next=NULL;
    } while (character!='\n');
    newnode=(Node)malloc(sizeof(struct node));
    headb=newnode;
    current=newnode;
    do
    {
        scanf("%lld%lld",&current->coefficient,&current->index);
        character=getchar();
        newnode=(Node)malloc(sizeof(struct node));
        current->next=newnode;
        current=current->next;
        current->next=NULL;
    } while (character!='\n');
    newnode=(Node)malloc(sizeof(struct node));
    answer=newnode;
    current=newnode;
    for(pa=heada;pa->next!=NULL;pa=pa->next){
        for(pb=headb;pb->next!=NULL;pb=pb->next){
            current->coefficient=pa->coefficient*pb->coefficient;
            current->index=pa->index+pb->index;
            newnode=(Node)malloc(sizeof(struct node));
            current->next=newnode;
            current=current->next;
            current->next=NULL;
        }
    }
    for(previous=answer;previous->next!=NULL;previous=previous->next){
        for(arrange=previous->next;arrange->next!=NULL;arrange=arrange->next){
            if((previous->index)>=(arrange->index)){
                continue;
            }else if((previous->index)<(arrange->index)){
                tcoefficent=previous->coefficient;
                previous->coefficient=arrange->coefficient;
                arrange->coefficient=tcoefficent;
                tindex=previous->index;
                previous->index=arrange->index;
                arrange->index=tindex;
            }
        }
    }
    for(previous=answer,current=answer->next;current->next!=NULL;current=current->next,previous=previous->next){
        /*if(previous->index==current->index){
            do
            {
            previous->coefficient=previous->coefficient+current->coefficient;
            previous->next=current->next;
            free(current);
            current=previous->next;
            }while(previous->index==current->index);
        }*/
        printf("1\n");
    }
    for(current=answer;current->next!=NULL;current=current->next){
        if(current->coefficient!=0){
            printf("%lld %lld ",current->coefficient,current->index);
        }
    }
    return 0;
}