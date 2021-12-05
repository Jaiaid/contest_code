#include<stdio.h>

struct stormtroopers
{
    double slope;
    int flag;
};

int main()
{
    int n,xg,yg,shoot;
    int x,y;
    int l,l1;
    struct stormtroopers team[1000];

    while(3==scanf("%d%d%d",&n,&xg,&yg))
    {
        for(l=0;l<n;l++)
        {
            scanf("%d%d",&x,&y);
            team[l].slope=(y-yg)*1.0/(x-xg);
            if(!(x-xg) && (y-yg)<0) team[l].slope=-team[l].slope;
            team[l].flag=1;
        }

        for(l=0,shoot=0;l<n;l++)
        {
            if(team[l].flag){
                shoot++;
                for(l1=l;l1<n;l1++)
                {
                    if(team[l1].flag){
                        if(team[l].slope==team[l1].slope) team[l1].flag=0;
                    }
                }
            }
        }
        printf("%d\n",shoot);
    }
    return 0;
}
