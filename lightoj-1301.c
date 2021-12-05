#include<stdio.h>
#define MAXTIMESTAMP 100000

struct time{
    int t;
    int type;
};

void Quick_sort(struct time *ara,int ini_indx,int fin_indx)
{
    if(ini_indx>fin_indx) return;

    struct time tmp;
    int l1=ini_indx-1,l;

    for(l=ini_indx;l<fin_indx;l++)
    {
        if(ara[l].t<ara[fin_indx].t){
            l1++;
            tmp=ara[l];
            ara[l]=ara[l1];
            ara[l1]=tmp;
        }
        else if(ara[l].t==ara[fin_indx].t && ara[l].type<ara[fin_indx].type){
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
    struct time list[MAXTIMESTAMP];
    int tc,N;
    int case_no=0;
    int free,busy,max_busy,si,ti;
    int l,l1;

    scanf("%d",&tc);
    while(case_no<tc)
    {
        scanf("%d",&N);

        for(l=0,l1=0;l<N;l++,l1++)
        {
            scanf("%d%d",&si,&ti);

            list[l1].t=si,list[l1].type=0;
            l1++;
            list[l1].t=ti,list[l1].type=1;
        }

        Quick_sort(list,0,l1-1);

        for(N=l1,free=N,max_busy=busy=0,l=0;l<N;l++)
        {
            if(list[l].type){
                busy--;
                free++;
            }
            else{
                busy++;
                free--;
                if(busy>max_busy) max_busy=busy;
            }
        }

        printf("Case %d: %d\n",++case_no,max_busy);
    }
    return 0;
}

