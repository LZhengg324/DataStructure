#include<stdio.h>
#include<stdlib.h>
struct Binarytree
{
    int data;
    int depth;
    struct Binarytree *left;
    struct Binarytree *right;
};
typedef struct Binarytree* bst;
int n,n1,k;
bst root;
void findleaf(bst ptr)
{
    if(ptr){
        findleaf(ptr->left);
        findleaf(ptr->right);
        if(!ptr->left&&!ptr->right){
            printf("%d %d\n",ptr->data,ptr->depth);
        }
    }
}
bst insert(int x, int k, bst ptr)
{
    if(!ptr){
        ptr=(bst)malloc(sizeof(struct Binarytree));
        ptr->data=x;
        ptr->depth=k;
        ptr->left=ptr->right=NULL;
        if(n==n1-1)root=ptr;
    }else{
        k++;
        if(ptr->data>x)ptr->left=insert(x,k,ptr->left);
        else if(ptr->data<=x)ptr->right=insert(x,k,ptr->right);
    }
    return ptr;
}
int main()
{
    int x;
    root=NULL;
    scanf("%d",&n1);
    n=n1;
    while(n--){
        scanf("%d",&x);
        k=1;
        insert(x,k,root);
    }
    findleaf(root);
    return 0;
}