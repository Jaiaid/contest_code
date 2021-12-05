#include<stdio.h>
#define MAXSOLDIER 1000

struct commando{
    int B;
    int T;
};

void Quick_sort(struct commando *ara,int ini_indx,int fin_indx)
{
    if(ini_indx>fin_indx) return;

    struct commando tmp;
    int l1=ini_indx-1,l;

    for(l=ini_indx;l<fin_indx;l++)
    {
        if(ara[l].T>ara[fin_indx].T){
            l1++;
            tmp=ara[l];
            ara[l]=ara[l1];
            ara[l1]=tmp;
        }
        else if(ara[l].T==ara[fin_indx].T && ara[l].B<ara[fin_indx].B){
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
    struct commando team[MAXSOLDIER];
    int N;
    int case_no=0;
    int ans;
    int l,tmp_max;

    while(1==scanf("%d",&N))
    {
        if(!N) break;

        for(l=0;l<N;l++)
        {
            scanf("%d%d",&team[l].B,&team[l].T);
        }
        Quick_sort(team,0,N-1);

        for(ans=team[0].T+team[0].B,tmp_max=team[0].B,l=1;l<N;l++)
        {
            tmp_max+=team[l].B;
            if(tmp_max+team[l].T>ans){
                ans=tmp_max+team[l].T;
            }
        }

        printf("Case %d: %d\n",++case_no,ans);
    }
    return 0;
}

