#include<stdio.h>

int ara[300];
char mat[300][301];
int col[300];
int tempara[300];
int idxara[300];
int start;
int end;


void Quick_sort(int *ara,int ini_indx,int fin_indx)
{
    if(ini_indx>fin_indx) return;
    int l1=ini_indx-1,l,tmp;

    for(l=ini_indx;l<fin_indx;l++)
    {
        if(ara[l]<ara[fin_indx]){
            l1++;
            tmp=ara[l];
            ara[l]=ara[l1];
            ara[l1]=tmp;
        }
    }
    l1++;
    tmp=ara[l];
    ara[l]=ara[l1];
    ara[l1]=tmp;

    Quick_sort(ara,ini_indx,l1-1);
    Quick_sort(ara,l1+1,fin_indx);

}

void dfs(int root,int n)
{
    int l,tmp;
    col[root]=1;
    idxara[end]=root;
    tempara[end]=ara[root];
    end++;
    for(l=0;l<n;l++)
    {
        if(mat[root][l]=='1' && col[l]==0){
            dfs(l,n);
        }
    }
}

int main()
{

    int n;
    int l,l1;

    while(1==scanf("%d",&n))
    {
        for(l=0;l<n;scanf("%d",&ara[l]),col[l]=0,l++);
        for(l=0;l<n;scanf("%s",mat[l]),l++);

        for(l=0,start=0,end=0;start<n;l++){
            if(!col[l]) dfs(l,n);
            Quick_sort(tempara,start,end-1);
            Quick_sort(idxara,start,end-1);
            for(l1=start;l1<end;ara[idxara[l1]]=tempara[l1],l1++);
            start=end;
        }

        for(l=0;l<n;l++) printf("%d ",ara[l]);
        putchar('\n');
    }
    return 0;
}
