#include<stdio.h>
#define MAXLEN 52

int cycle(char grid[][MAXLEN],char visited[][MAXLEN],int row,int col)
{
    visited[row][col]=1;
    if(grid[row+1][col]==grid[row][col]){
        if(visited[row+1][col]==2) return 1;
        if(!visited[row+1][col] && cycle(grid,visited,row+1,col)) return 1;
    }

    if(grid[row][col+1]==grid[row][col]){
        if(visited[row][col+1]==2) return 1;
        if(!visited[row][col+1] && cycle(grid,visited,row,col+1)) return 1;
    }

    if(grid[row-1][col]==grid[row][col]){
        if(visited[row-1][col]==2) return 1;
        if(!visited[row-1][col] && cycle(grid,visited,row-1,col)) return 1;
    }

    if(grid[row][col-1]==grid[row][col]){
        if(visited[row][col-1]==2) return 1;
        if(!visited[row][col-1] && cycle(grid,visited,row,col-1)) return 1;
    }
    visited[row][col]=2;
    return 0;
}

int main()
{
    char grid[MAXLEN][MAXLEN];
    char visited[MAXLEN][MAXLEN];
    int r,c;
    int l,l1,l2,flag;

    while(2==scanf("%d%d",&r,&c))
    {
        for(l=0;l<MAXLEN;l++)
        {
            for(l1=0;l1<MAXLEN;grid[l][l1]='\0',l1++);
        }
        for(l=1;l<=r;l++)
        {
            scanf("%s",&grid[l][1]);
        }

        for(l=0;l<MAXLEN;l++)
        {
            for(l1=0;l1<MAXLEN;visited[l][l1]='\0',l1++);
        }
        for(l=1,flag=1;l<=r && flag;l++)
        {
            for(l1=1;l1<=c;l1++)
            {
                if(visited[l][l1]=='\0' && cycle(grid,visited,l,l1)){
                    flag=0;
                    break;
                }
            }
        }

        if(flag) puts("No");
        else puts("Yes");

    }
    return 0;
}
