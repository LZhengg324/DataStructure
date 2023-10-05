#include<stdio.h>
#include<stdlib.h>
int total,start,quit;
struct node
{
    int num;
    struct node *next;
};
typedef struct node* Node;
int king(int total,int quit,int start)
{
    Node head,current,r;//*head为记录头结点、*current为当前结点、*r为过渡结点
    int i,j=1;
    int King;
    r=(Node)malloc(sizeof(struct node));
    r->num=j++;
    head=r;
    current=r;
    for(i=0;i<total-1;i++){
        r=(Node)malloc(sizeof(struct node));
        r->num=j++;
        current->next=r;
        current=current->next;
    }
    current->next=head;
    for(i=1,current=head ; i<start ; i++){
        current=current->next;
    }
    while(current->next!=current){
        for(i=1;i<quit;i++){
            r=current;
            current=current->next;
        }
        r->next=current->next;
        free(current);
        current=r->next;
    }
    King=current->num;
    return King;
} 
int main()
{
    scanf("%d%d%d",&total,&quit,&start);
    printf("%d",king(total,quit,start));
    return 0;
}