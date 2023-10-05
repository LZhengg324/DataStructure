#include<stdio.h>
int main()
{
    int chess[19][19];
    int i,j;
    int ret=1;
    for(i=0; i<19; i++){
        for(j=0; j<19; j++){
            scanf("%d",&chess[i][j]);
        }
    }
    for(i=0;i<19;i++){
        for(j=0; j<19; j++){
            if(chess[i][j]==1){
                if((chess[i][j+1]==1&&chess[i][j+2]==1&&chess[i][j+3]==1)&&(chess[i][j-1]==0||chess[i][j+4]==0)){
                    printf("1:%d,%d\n",i+1,j+1);
                    ret=0;
                }else if ((chess[i+1][j]==1&&chess[i+2][j]==1&&chess[i+3][j]==1)&&(chess[i-1][j]==0||chess[i+4][j]==0)){
                    printf("1:%d,%d\n",i+1,j+1);
                    ret=0;
                }else if ((chess[i+1][j+1]==1&&chess[i+2][j+2]==1&&chess[i+3][j+3]==1)&&(chess[i-1][j-1]==0||chess[i+4][j+4]==0)){
                    printf("1:%d,%d\n",i+1,j+1);
                    ret=0;
                }else if ((chess[i+1][j-1]==1&&chess[i+2][j-2]==1&&chess[i+3][j-3]==1)&&(chess[i-1][j+1]==0||chess[i+4][j-4]==0)){
                    printf("1:%d,%d\n",i+1,j+1);
                    ret=0;
                }
            }else if(chess[i][j]==2){
                if((chess[i][j+1]==2&&chess[i][j+2]==2&&chess[i][j+3]==2)&&(chess[i][j-1]==0||chess[i][j+4]==0)){
                    printf("2:%d,%d",i+1,j+1);
                    ret=0;
                }else if ((chess[i+1][j]==2&&chess[i+2][j]==2&&chess[i+3][j]==2)&&(chess[i-1][j]==0||chess[i+4][j]==0)){
                    printf("2:%d,%d",i+1,j+1);
                    ret=0;
                }else if ((chess[i+1][j+1]==2&&chess[i+2][j+2]==2&&chess[i+3][j+3]==2)&&(chess[i-1][j-1]==0||chess[i+4][j+4]==0)){
                    printf("2:%d,%d",i+1,j+1);
                    ret=0;
                }else if ((chess[i+1][j-1]==2&&chess[i+2][j-2]==2&&chess[i+3][j-3]==2)&&(chess[i-1][j+1]==0||chess[i+4][j-4]==0)){
                    printf("2:%d,%d",i+1,j+1);
                    ret=0;
                }
            }
        } 
        if (ret==0){
            break;
        }
    }
    if(ret==1){
        printf("No\n");
    }
    return 0;
}