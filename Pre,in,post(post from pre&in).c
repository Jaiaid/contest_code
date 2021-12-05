#include<stdio.h>
#include<stdlib.h>

char pre[53],in[53];

void getpostorder(int ini_indx,int fin_indx,int pre_ini_indx,int pre_fin_indx)
{
    if(pre_ini_indx>pre_fin_indx){
        return;
    }
    int l;
    for(l=ini_indx;in[l]!=pre[pre_ini_indx];l++);

    getpostorder(ini_indx,l-1,pre_ini_indx+1,pre_ini_indx+l-ini_indx);
    getpostorder(l+1,fin_indx,pre_ini_indx+l-ini_indx+1,pre_fin_indx);
    putchar(in[l]);
}

int main()
{
    int tc;
    while(1==scanf("%d",&tc))
    {
        int n,l;
        for(l=0;l<tc;l++)
        {
            scanf("%d%s%s",&n,pre,in);
            getpostorder(0,n-1,0,n-1);
            putchar('\n');
        }
    }

    return 0;
}
