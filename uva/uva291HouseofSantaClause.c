#define PATHLENGTH 7
#include<stdio.h>

int graph[5][5]={{0,1,1,0,1},{1,0,1,0,1},{1,1,0,1,1},{0,0,1,0,1},{1,1,1,1,0}};
int maxcolor[5]={2,2,2,1,2};
int color[5]={0,0,0,0,0};
char str[9];


void dfs(int node,int depth)
{
    int l;
    str[depth]=(char)(49+node);
    color[node]++;
    if(depth==8){
        str[9]='\0';
        puts(str);
        return;
    }
    for(l=0;l<5;l++)
    {
        if(graph[node][l] && color[l]<maxcolor[l]){
            graph[node][l]=0;
            graph[l][node]=0;
            dfs(l,depth+1);
            graph[node][l]=1;
            graph[l][node]=1;
            color[l]--;
        }
    }
}

int main()
{
    dfs(0,0);
    return 0;
}
