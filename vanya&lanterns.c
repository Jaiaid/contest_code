#include<stdio.h>

void Quick_sort(double *ara,int ini_indx,int fin_indx)
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

int main()
{
    int n,len;
    double ara[1000];
    while(2==scanf("%d%d",&n,&len))
    {
        short int l;
        double min_dist=0;
        for(l=0;l<n;l++) scanf("%lf",ara+l);
        Quick_sort(&ara[0],0,l-1);

        for(l=1;l<n;l++) if(ara[l]-ara[l-1]>min_dist) min_dist=ara[l]-ara[l-1];

        if(len-ara[n-1]>min_dist/2 || min_dist/2<ara[0]){
            if(len-ara[n-1]>ara[0]) printf("%.10lf\n",len-ara[n-1]);
            else printf("%.10lf\n",ara[0]);
        }
        else printf("%.10lf\n",min_dist/2);
    }
    return 0;
}
