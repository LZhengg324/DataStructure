#include<stdio.h>
int graph[1000][1000];
int queue[1000];
int front,rear;
int visited[1000];
void DFS(int vex, int graph[1000][1000])
{
    int i;
    if(visited[vex]==0){
        printf("%d ",vex);
        visited[vex]=1;
    }
    for(i=0;i<1000;i++){
        if(graph[i][vex]&&!visited[i])DFS(i,graph);
    }
}
void BFS(int vex, int graph[1000][1000])
{
    int i;
    if(visited[vex]==0){
        printf("%d ",vex);
        visited[vex]=1;
    }
    for(i=0;i<1000;i++){
        if(!visited[i]&&graph[i][vex]){
            queue[rear++]=i;
        }
    }
    while(front<rear){
        BFS(queue[front++],graph);
    }
}
int main()
{
    int v,e,a,b,i;
    scanf("%d%d",&v,&e);
    while((e--)>0){
        scanf("%d%d",&a,&b);
        graph[a][b]=1;
        graph[b][a]=1;
    }
    DFS(0,graph);
    printf("\n");
    for(i=0;i<1000;i++)visited[i]=0;
    BFS(0,graph);
    printf("\n");
    scanf("%d",&a);
    for(i=0;i<1000;i++){
        graph[a][i]=0;
        graph[i][a]=0;
    }
    for(i=0;i<1000;i++)visited[i]=0;
    DFS(0,graph);
    printf("\n");
    for(i=0;i<1000;i++)visited[i]=0;
    BFS(0,graph);
    printf("\n");
    return 0;
}