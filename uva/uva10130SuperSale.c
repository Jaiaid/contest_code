#include<stdio.h>
#define MAXNUMOBJ 1000
#define MAXWEIGHT 30
#define MAXGROUPMEMBER 100

struct object{
    int price;
    int weight;
};

int sub_soln[MAXWEIGHT+1][MAXNUMOBJ+1];
struct object market[MAXNUMOBJ+1];
int group[MAXGROUPMEMBER];


void max_value(int N,int maxw)
{
    int l,l1,tmpw,tmpp;

    for(l=0;l<=N;l++) sub_soln[0][l]=0;
    for(l=0;l<=maxw;l++) sub_soln[l][0]=0;

    for(l=1;l<=maxw;l++)
    {
        for(l1=1;l1<=N;l1++)
        {
            tmpw=market[l1].weight,tmpp=market[l1].price;

            if(tmpw>l) sub_soln[l][l1]=sub_soln[l][l1-1];
            else if(sub_soln[l][l1-1]>sub_soln[l-tmpw][l1-1]+tmpp){
                sub_soln[l][l1]=sub_soln[l][l1-1];
            }
            else{
                sub_soln[l][l1]=tmpp+sub_soln[l-tmpw][l1-1];
            }
        }
    }
}

int main()
{
    freopen("E:\\input.txt","r",stdin);
    freopen("E:\\output.txt","w",stdout);

    int tc,G,N;
    int ans;
    int l,l1,case_no=0,maxw;

    scanf("%d",&tc);
    while(case_no<tc)
    {
        scanf("%d",&N);
        for(l=1;l<=N;l++)
        {
            scanf("%d%d",&market[l].price,&market[l].weight);
        }

        scanf("%d",&G);
        for(l=0,maxw=0;l<G;l++)
        {
            scanf("%d",&group[l]);
            if(group[l]>maxw) maxw=group[l];
        }

        max_value(N,maxw);
        for(l=0,ans=0;l<G;l++) ans+=sub_soln[group[l]][N];

        printf("%d\n",ans);

        case_no++;
    }

    return 0;
}
