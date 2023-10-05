#include<stdio.h>
#include<stdlib.h>
struct Treenode
{
    int n;
    int flag;
    struct Treenode *left,*right;
};
typedef struct Treenode treenode;
int cnt,max,mark;
void Createbst(treenode *ptr, int num)
{
    treenode *new;
    if(ptr->n>num){
        cnt++;
        if(ptr->left)Createbst(ptr->left,num);
        else{
            new=(treenode*)malloc(sizeof(treenode));
            new->n=num,new->flag=1;
            new->left=new->right=NULL;
            ptr->left=new;
        }
    }else if(ptr->n<num){
        cnt++;
        if(ptr->right)Createbst(ptr->right,num);
        else{
            new=(treenode*)malloc(sizeof(treenode));
            new->n=num,new->flag=1;
            new->left=new->right=NULL;
            ptr->right=new;
        }
    }else if(ptr->n==num){
        cnt++,ptr->flag++;
        if(ptr->flag>max)max=ptr->flag;
    }
}
void travelDFS(treenode *ptr)
{
    if(ptr){
        if(!mark)travelDFS(ptr->left);
        if(!mark)travelDFS(ptr->right);
        if(ptr->flag==max&&!mark)mark=ptr->n;
    }
}
int main()
{
    treenode *root,*ptr;
    int N,x;
    scanf("%d",&N);
    scanf("%d",&x);
    root=(treenode*)malloc(sizeof(treenode));
    root->n=x,root->flag=1;
    root->left=root->right=NULL;
    N--;
    while(N--){
        scanf("%d",&x);
        Createbst(root,x);
    }
    travelDFS(root);
    printf("%d\n",cnt);
    for(ptr=root;ptr;){
        if(ptr->n<mark){
            printf("%d ",ptr->n);
            ptr=ptr->right;
        }else if(ptr->n>mark){
            printf("%d ",ptr->n);
            ptr=ptr->left;
        }else if(ptr->n==mark){
            printf("%d",ptr->n);
            break;
        }
    }
    return 0;
}