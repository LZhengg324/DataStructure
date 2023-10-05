#include<stdio.h>
int min(int x,int y){
    return x>y?y:x;
}
int main()
{
    int n,i,j,customer;
    int head=0,tail=0;
    int counter=3;
    int queue[1000]={0};
    scanf("%d",&n);
    for(j=0;j<n;j++){
        scanf("%d",&customer);
        tail=tail+customer;
        if((tail-head)<21)counter=3;
        else if((tail-head)>=21&&(tail-head)<28)counter=4;
        else if((tail-head)>=28)counter=5;
        for(i=head;i<min(head+counter,tail);i++){
            printf("%d : %d\n",i+1,queue[i]);
        }
        for(i=head+counter;i<tail;i++){
            queue[i]++;
        }
        head=head+counter;
        if(head>tail){
            head=tail;
        }
    }
    while(tail>head){
        if((tail-head)<counter*7&&counter==5)counter--;
        else if((tail-head)<counter*7&&counter==4)counter--;
        for(i=head;i<min(head+counter,tail);i++){
            printf("%d : %d\n",i+1,queue[i]);
        }
        for(i=head+counter;i<tail;i++){
            queue[i]++;
        }
        head=head+counter;
        if(head>tail){
            head=tail;
        }
    }
    return 0;
}
