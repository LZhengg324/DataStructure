#include<stdio.h>
#include<string.h>
struct Tel
{
    char name[21];
    char telnum[12];
    char rep[3];
}tel[100], t;
int main()
{
    int ppl;
    int i, j, cname, cnum;
    scanf("%d",&ppl);
    for(i=0;i<ppl;i++){
        scanf("%s",tel[i].name);
        scanf("%s", tel[i].telnum);
        strcpy(tel[i].rep,"_0");
    }
    for(i=0;i<ppl;i++){
        for(j=i+1; j<ppl; j++){
            cname=strcmp(tel[i].name, tel[j].name);
            cnum=strcmp(tel[i].telnum, tel[j].telnum);
            if (cname==0&&cnum!=0){
                tel[j].rep[1]++;
            }else if (cname==0&&cnum==0){
                strcpy(tel[j].name, "\0");
                strcpy(tel[j].telnum,"\0");
                strcpy(tel[j].rep,"\0");
            }
        }
    }
    for(i=0;i<ppl;i++){
        for(j=i+1; j<ppl; j++){
            if (strcmp(tel[i].name,tel[j].name)>0){
                t=tel[i];
                tel[i]=tel[j];
                tel[j]=t;
            }else if(strcmp(tel[i].name, tel[j].name)==0){
                if (strcmp(tel[i].rep,tel[j].rep)>0){
                    t=tel[i];
                    tel[i]=tel[j];
                    tel[j]=t;
                }
            }
        }
    }
    for(i=0;i<ppl;i++){
        if (tel[i].rep[1]=='0'){
            printf("%s %s\n",tel[i].name, tel[i].telnum);
        }else{
            printf("%s%s %s\n",tel[i].name,tel[i].rep,tel[i].telnum);
        }
    }
    return 0;   
}