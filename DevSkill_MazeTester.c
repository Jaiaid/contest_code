#include<stdio.h>

char maze[30][31];

int dfs(int row,int col)
{
    if(maze[row][col]=='G') return 1;
    int result=0;
    maze[row][col]='X';

    if(row+1<30 && (maze[row+1][col]=='.' ||  maze[row+1][col]=='G') && !result){
        result=dfs(row+1,col);
    }

    if(col+1<30 && (maze[row][col+1]=='.' ||  maze[row][col+1]=='G') && !result){
        result=dfs(row,col+1);
    }

    if(col-1>=0 && (maze[row][col-1]=='.' ||  maze[row][col-1]=='G') && !result){
        result=dfs(row,col-1);
    }

    if(row-1>=0 && (maze[row-1][col]=='.' ||  maze[row-1][col]=='G') && !result){
        result=dfs(row-1,col);
    }

    return result;
}

int main()
{
    int row,col;
    int l,l1,flag;

    while(1==scanf("%s",maze[0]))
    {
        for(l=1,flag=1;l<30;l++)
        {
            scanf("%s",maze[l]);
            for(l1=0;flag && l1<30;l1++)
            {
                if(maze[l][l1]=='P') row=l,col=l1,flag=0;
            }
        }

        if(dfs(row,col)) puts("Possible");
        else puts("Impossible");
    }
    return 0;
}
