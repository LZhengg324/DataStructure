#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define N 20000
char page[N][100];
int visited[N];
double sim[N][2],tmp;
int keywordappears[N];
int currentpage;
FILE *fp;
struct Tree  //字典树结点
{
    char letter;
    int flag; //当该结点为最后一个字时，flag=1
    struct Tree *next[26];
};
typedef struct Tree tree;
struct Keyword
{
    char word[81];
    double freq[N], inverse;
    double times;
};
typedef struct Keyword keyword;
keyword list[200];
tree *dictionaryroot;
int scanpages,totalkeywords,outputsim;
tree* createdictionarytree(tree *root)
{
    int i,c=0;
    root=(tree*)malloc(sizeof(tree));
    root->letter=c,root->flag=0;
    for(i=0;i<26;i++)root->next[i]=NULL;
    tree *ptr=root;
    while(c=fgetc(fp),c!=EOF){
        if(c=='\n'||c=='\r'){
            ptr->flag=1;
            ptr=root;
            continue;
        }
        if(!ptr->next[c-97]){
            ptr->next[c-97]=(tree*)malloc(sizeof(tree));
            ptr->next[c-97]->letter=c,ptr->next[c-97]->flag=0;
            for(i=0;i<26;i++)ptr->next[c-97]->next[i]=NULL;
        }
        ptr=ptr->next[c-97];
    }
    ptr->flag=1;
    //printf("dictionarytreedone\n");
    return root;
}
void deletestopwords(tree* root)
{
    char stopword[13];
    int c;
    int k=0,i;
    tree *ptr=dictionaryroot;
    while(c=fgetc(fp),c!=EOF){
        if(c!='\n'&&c!='\r'){
           stopword[k++]=c; 
        }else{
            if(k>0){
                stopword[k]='\0';
                //printf("%s\n",stopword);
                for(i=0;stopword[i]!='\0';i++){
                    if(!ptr)break;
                    ptr=ptr->next[stopword[i]-97];
                }
                if(ptr)ptr->flag=0;
                ptr=root;
            }
            k=0;
        }
    }
    stopword[k]='\0';
    //printf("%s\n",stopword);
    for(i=0;stopword[i]!='\0';i++){
        if(!ptr)break;
        ptr=ptr->next[stopword[i]-97];
    }
    if(ptr)ptr->flag=0;
    ptr=root;
    //printf("deletedone\n");
}
void iskeywords(int numofkeywords, char *argv[])
{
    tree *ptr=dictionaryroot;
    int i,j,k,flag;
    char t[100];
    scanpages=atoi(argv[1]);
    for(i=2;i<numofkeywords;i++){
        for(j=0;argv[i][j]!='\0';j++){
            if(!ptr)break;
            ptr=ptr->next[argv[i][j]-97];
        }
        if(ptr&&ptr->flag==1){
            strcpy(list[totalkeywords++].word,argv[i]);
            list[totalkeywords-1].inverse=list[totalkeywords-1].times=0;
            for(k=0;k<N;k++)list[totalkeywords-1].freq[k]=0;
        }
        ptr=dictionaryroot;
    }
    for(i=0;i<totalkeywords;i++){
        flag=1;
        for(j=1;j<totalkeywords-i;j++){
            if(strcmp(list[j-1].word,list[j].word)>0){
                flag=0;
                strcpy(t,list[j-1].word);
                strcpy(list[j-1].word,list[j].word);
                strcpy(list[j].word,t);
            }
        }
        if(flag)break;
    }
    //printf("managekeyworddone\n");
}
int binarysearchkeywords(char c[100])
{
    int low=0,high=totalkeywords-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(strcmp(c,list[mid].word)==0)return mid;
        else if(strcmp(c,list[mid].word)>0)low=mid+1;
        else if(strcmp(c,list[mid].word)<0)high=mid-1;
    }
    return -1;
}
void articlein()
{
    int c;
    char s[100];
    int i=0,k,j;
    tree *ptr=dictionaryroot;
    fscanf(fp,"%s",page[currentpage]);
    while(c=fgetc(fp),c>EOF){
        if(isalpha(c))s[i++]=tolower(c);
        else{
            if(i>0){
                s[i]='\0';
                //printf("%s\n",s);
                k=binarysearchkeywords(s);
                if(k!=-1){
                    list[k].freq[currentpage]++;
                    keywordappears[currentpage]++;
                    if(visited[k]==0){
                        list[k].times++,visited[k]=1;
                    }
                }else{
                    for(j=0;s[j]!='\0';j++){
                        if(!ptr)break;
                        ptr=ptr->next[s[j]-97];
                    }
                    if(ptr&&ptr->flag)keywordappears[currentpage]++;
                    ptr=dictionaryroot;
                }
                i=0;
            }
            if(c=='\f'){
                fscanf(fp,"%s",page[++currentpage]);
                i=0;
                for(j=0;j<totalkeywords;j++)visited[j]=0;
            }
        }
    }
    //printf("articleindone\n");
}
void cal_sim()
{
    int i,j,flag;
    double f;
    for(i=0;i<currentpage;i++)sim[i][1]=i;
    for(i=0;i<totalkeywords;i++){
        if(list[i].times!=0)list[i].inverse=log10((currentpage+1)/list[i].times);
        for(j=0;j<currentpage;j++){
            f=(list[i].freq[j]/keywordappears[j]*1.0)*list[i].inverse*100;
            list[i].freq[j]=f;
            sim[j][0]=sim[j][0]+f;
        }
    }
    for(i=0;i<=currentpage;i++){
        flag=1;
        for(j=1;j<=currentpage-i;j++){
            if(sim[j-1][0]<sim[j][0]){
                flag=0;
                tmp=sim[j-1][0];
                sim[j-1][0]=sim[j][0];
                sim[j][0]=tmp;
                tmp=sim[j-1][1];
                sim[j-1][1]=sim[j][1];
                sim[j][1]=tmp;
            }
        }
        if(flag)break;
    }
    for(i=0;i<=currentpage;i++)if(sim[i][0]==0)break;
    if(i>=5)outputsim=5;
    else outputsim=i;
    if(scanpages>=i)scanpages=i;
    //printf("calsimdone\n");
}
int main(int argc, char *argv[])
{
    int i=0;
    if((fp=fopen("dictionary.txt","r"))==NULL)exit(EXIT_FAILURE);
    dictionaryroot=createdictionarytree(dictionaryroot);
    fclose(fp);
    if((fp=fopen("stopwords.txt","r"))==NULL)exit(EXIT_FAILURE);
    deletestopwords(dictionaryroot);
    fclose(fp);
    iskeywords(argc,argv);
    if((fp=fopen("article.txt","r"))==NULL)exit(EXIT_FAILURE);
    articlein();
    fclose(fp);
    cal_sim();
    if((fp=fopen("results.txt","w"))==NULL)exit(EXIT_FAILURE);
    while(i<outputsim){
        printf("%.6f %d %s\n",sim[i][0],(int)sim[i][1]+1,page[(int)sim[i][1]]);
        i++;
    }
    i=0;
    while(i<scanpages){
        fprintf(fp,"%.6f %d %s\n",sim[i][0],(int)sim[i][1]+1,page[(int)sim[i][1]]);
        i++;
    }
    fclose(fp);
    return 0;
}