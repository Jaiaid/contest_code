#include<stdio.h>
#define MAXLEN 52

int prevr,prevc;

int cycle(char grid[][MAXLEN],char visited[][MAXLEN],int row,int col)
{
    if(visited[row][col]==1) return 1;
    int tmp1,tmp2;

    if((row+1!=prevr || col!=prevc) && grid[row+1][col]==grid[row][col]){
        tmp1=prevr,tmp2=prevc;
        prevr=row,prevc=col;
        visited[row][col]=1;
        if(cycle(grid,visited,row+1,col)) return 1;
        prevr=tmp1,prevc=tmp2;
    }

    if((row!=prevr || col+1!=prevc) && grid[row][col+1]==grid[row][col]){
        tmp1=prevr,tmp2=prevc;
        prevr=row,prevc=col;
        visited[row][col]=1;
        if(cycle(grid,visited,row,col+1)) return 1;
        prevr=tmp1,prevc=tmp2;
    }

    if((row-1!=prevr || col!=prevc) && grid[row-1][col]==grid[row][col]){
        tmp1=prevr,tmp2=prevc;
        prevr=row,prevc=col;
        visited[row][col]=1;
        if(cycle(grid,visited,row-1,col)) return 1;
        prevr=tmp1,prevc=tmp2;
    }

    if((row!=prevr || col-1!=prevc) && grid[row][col-1]==grid[row][col]){
        tmp1=prevr,tmp2=prevc;
        prevr=row,prevc=col;
        visited[row][col]=1;
        if(cycle(grid,visited,row,col-1)) return 1;
        prevr=tmp1,prevc=tmp2;
    }
    visited[row][col]=1;
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
                prevr=0,prevc=0;
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
