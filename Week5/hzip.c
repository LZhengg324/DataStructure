#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
    int i;
    printf("%d\n",argc);
    for(i=0;argv;i++,argv++){
        printf("argv[%d] is %s\n",i,*argv-1);
    }
    return 0;
}
