#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct Node* nodeptr;
struct Node 
{
    int num;
    char op;
    int flag;   //判断该结点为运算符还是操作数
    nodeptr left,right;
}node;
nodeptr stack[10000],root;
int top=-1;
int calculate(nodeptr ptr)
{
    int a,b;
    if(ptr==NULL)return 0;
    if(ptr->flag==1)return ptr->num;
    a=calculate(ptr->left);
    b=calculate(ptr->right);
    if(ptr->op=='+')ptr->num=a+b;
    else if(ptr->op=='-')ptr->num=a-b;
    else if(ptr->op=='*')ptr->num=a*b;
    else if(ptr->op=='/')ptr->num=a/b;
    return ptr->num;
}
void pushstack(nodeptr new)
{
    nodeptr a,b;
    if(new->flag==1){
        stack[++top]=new;
    }else if(new->flag==0){
        b=stack[top--];
        a=stack[top--];
        new->left=a;
        new->right=b;
        stack[++top]=new;
    }
}
void createtree()
{
    char s[10000],op[10000];
    int n,optop=-1;
    int i;
    nodeptr new;
    gets(s);
    for(i=0;s[i]!='=';i++){
        if(isdigit(s[i])){
            n=atoi(&s[i]);
            new=(nodeptr)malloc(sizeof(struct Node));
            new->num=n;
            new->flag=1;
            new->left=new->right=NULL;
            pushstack(new);
            while(isdigit(s[i+1]))i++;
        }else if(s[i]=='+'||s[i]=='-'){
            while(optop>=0&&op[optop]!='('){
                new=(nodeptr)malloc(sizeof(struct Node));
                new->op=op[optop--];
                new->flag=0;
                new->left=new->right=NULL;
                pushstack(new);
            }
            op[++optop]=s[i];
        }else if(s[i]=='*'||s[i]=='/'){
            if(op[optop]=='*'||op[optop]=='/'){
                new=(nodeptr)malloc(sizeof(struct Node));
                new->op=op[optop--];
                new->flag=0;
                new->left=new->right=NULL;
                pushstack(new);
            }
            op[++optop]=s[i];
        }else if(s[i]=='('){
            op[++optop]=s[i];
        }else if(s[i]==')'){
            while(op[optop]!='('){
                new=(nodeptr)malloc(sizeof(struct Node));
                new->op=op[optop--];
                new->flag=0;
                new->left=new->right=NULL;
                pushstack(new);
            }
            optop--;
        }
    }
    while(optop>-1){
        new=(nodeptr)malloc(sizeof(struct Node));
        new->op=op[optop--];
        new->flag=0;
        new->left=new->right=NULL;
        pushstack(new);
    }
    root=stack[0];
}
int main()
{
    int ans;
    createtree();
    if(root->flag==1&&root)printf("%d ",root->num);
    else if(root->flag==0&&root)printf("%c ",root->op);
    if(root->left->flag==1&&root)printf("%d ",root->left->num);
    else if(root->left->flag==0&&root->left)printf("%c ",root->left->op);
    if(root->right->flag==1&&root->right)printf("%d\n",root->right->num);
    else if(root->right->flag==0&&root->right)printf("%c\n",root->right->op);
    ans=calculate(root);
    printf("%d",ans);
    return 0;
}