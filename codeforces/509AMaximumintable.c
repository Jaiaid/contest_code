#define PATHLENGTH 7
#include<stdio.h>

int rec(int row,int col)
{
    if(row==1 || col==1) return 1;
    else return rec(row,col-1)+rec(row-1,col);
}

int main()
{
    int n;
    while(1==scanf("%d",&n))
    {
        printf("%d\n",rec(n,n));
    }
    return 0;
}
