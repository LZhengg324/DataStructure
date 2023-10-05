#include<stdio.h>
int s[10]={1,2,3,4,5,6,7,8,9,10};
int output[10], mark[10];
int n;
void recursion(int k,int n)
{
	int i,j;
	if (k==n){
		for (i=0; i<n; i++){
			printf("%d ",output[i]);
		}
		printf("\n");
	}else{
		for (j=0; j<n; j++){
			if (mark[j]==0){
				output[k]=s[j];
				mark[j]=1;
				recursion(k+1,n);
				mark[j]=0;
			}
		}
	}
}
int main()
{
	int k=0;
	scanf("%d",&n);
	recursion(k,n);
	return 0;
 } 
