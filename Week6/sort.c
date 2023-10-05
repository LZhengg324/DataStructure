#include<stdio.h>
int cnt;
void swap(int *a,int *b)
{
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}
void selectsort(int num[],int N)
{
    int i,j,min,tmp;
    for(i=0;i<N;i++){
        min=i;
        for(j=i+1;j<N;j++){
            cnt++;
            if(num[j]<num[min])min=j;
        }
        tmp=num[i];
        num[i]=num[min];
        num[min]=tmp;
    }
}
void bubblesort(int num[],int N)
{
    int i,j,tmp,flag;
    for(i=0;i<N;i++){
        flag=1;
        for(j=1;j<N-i;j++){
            cnt++;
            if(num[j]<num[j-1]){
                flag=0;
                tmp=num[j];
                num[j]=num[j-1];
                num[j-1]=tmp;
            }
        }
        if(flag==1)break;
    }
}
void adjust(int k[],int i,int n)
{
    int j,temp;
    temp=k[i];
    j=2*i+1;
    while(j<n){
        if(j<n-1 && k[j]<k[j+1])j++;
        if(cnt++,temp>=k[j])break;
        k[(j-1)/2]=k[j];
        j=2*j+1;
    }
    k[(j-1)/2]=temp;
}
void heapsort(int num[],int N)
{
    int i,tmp;
    for(i=(N-1)/2;i>=0;i--){
        adjust(num,i,N);
    }
    for(i=N-1;i>0;i--){
        tmp=num[i];
        num[i]=num[0];
        num[0]=tmp;
        adjust(num,0,i);
    }
}
void merge(int x[ ],int tmp[ ],int left,int leftend,int rightend)
{     
    int i=left, j=leftend+1, q=left;
    while(i<=leftend && j<=rightend)
    {
        if(cnt++,x[i]<=x[j])tmp[q++]=x[i++];
        else tmp[q++]=x[j++];
    }
    while(i<=leftend)tmp[q++]=x[i++];
    while(j<=rightend)tmp[q++]=x[j++];
    for(i=left; i<=rightend; i++)x[i]=tmp[i];
}
void split(int num[],int t[],int start,int end)
{
    int mid;
    if(start<end){
        mid=(start+end)/2;
        split(num,t,start,mid);
        split(num,t,mid+1,end);
        merge(num,t,start,mid,end);
    }
}
void mergesort(int num[],int N)
{
    int tmp[100];
    split(num,tmp,0,N-1);
}
void quickSort(int k[ ],int left,int right)
{     
    int i, last;
    if(left<right){
        last=left; 
        for(i=left+1;i<=right;i++)if(cnt++,k[i]<k[left])swap(&k[++last],&k[i]); 
        swap(&k[left],&k[last]);
        quickSort(k,left,last-1); 
        quickSort(k,last+1,right);   
    }
}
int main()
{
    int op,i,num[100],N;
    scanf("%d%d",&N,&op);
    for(i=0;i<N;i++){
        scanf("%d",&num[i]);
    }
    switch(op)
    {
        case 1:
        selectsort(num,N);
        break;
        case 2:
        bubblesort(num,N);
        break;
        case 3:
        heapsort(num,N);
        break;
        case 4:
        mergesort(num,N);
        break;
        case 5:
        quickSort(num,0,N-1);
        break;
    }
    for(i=0;i<N;i++){
        printf("%d ",num[i]);
    }
    printf("\n");
    printf("%d",cnt);
    return 0;
}