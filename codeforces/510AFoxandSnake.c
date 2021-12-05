#include<stdio.h>
#define MAXLEN 50

int main()
{
    int grid[MAXLEN][MAXLEN];
    int n,m;
    int r,c;
    int l,l1,l2,flag;

    while(2==scanf("%d%d",&n,&m))
    {
        for(l=0;l<n;l++)
        {
            for(l1=0;l1<m;l1++) grid[l][l1]=0;
        }

        for(l=0,flag=0;l<n;l++)
        {
            if(!(l&1)){
                for(l1=0;l1<m;l1++)
                {
                    grid[l][l1]=1;
                }
            }
            else{
                if(!flag){
                    grid[l][m-1]=1;
                    flag=1;
                }
                else{
                    grid[l][0]=1;
                    flag=0;
                }
            }
        }

        for(l=0;l<n;l++)
        {
            for(l1=0;l1<m;l1++)
            {
                if(grid[l][l1]==1) putchar('#');
                else putchar('.');
            }
            putchar('\n');
        }

    }
    return 0;
}
