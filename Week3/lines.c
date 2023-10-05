#include<stdio.h>
int a[500][4]={{0}};
int n, t[4];  //t为过渡数组
void arrangement(int a[500][4],int n,int t[4]){ //将所有线段的起点x坐标进行排列，因为x2>x1.
    int i,j,k;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(a[i][0]>a[j][0]){
                for (k = 0; k < 4; k++){
                    t[k]=a[i][k];
                }
                for (k = 0; k < 4; k++){
                    a[i][k]=a[j][k];
                }
                for (k=0; k<4; k++){
                    a[j][k]=t[k];
                }
            }
        }
    }
}
int main()
{
    int i,j,currentx; //currentx用以记录当前线段终点的x坐标
    int firstx=0, firsty=0;
    int count, maxcount=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
    }
    arrangement(a,n,t);
    for(i=0;i<n;i++){
        count=1;
        currentx=i;
        for(j=i+1;j<n;j++){
            if(a[j][0]==a[currentx][2]&&a[j][1]==a[currentx][3]){
                count++;
                currentx=j;
            }
        }
        if(count>maxcount){
            firstx=a[i][0];
            firsty=a[i][1];
            maxcount=count;
        }
    }
    printf("%d %d %d\n",maxcount,firstx,firsty);
    return 0;
}