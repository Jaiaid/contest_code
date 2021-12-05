#include<stdio.h>

int main()
{
    int ara[3];
    int table;
    int l,l1,tmp;

    while(3==scanf("%d%d%d",&ara[0],&ara[1],&ara[2]))
    {
        table=0;

        if(ara[0]==ara[1] && ara[1]==ara[2]){
            table+=ara[0];
            ara[0]=0,ara[1]=0,ara[2]=0;
        }
        else{
            do
            {
                for(l=0;l<3;l++)
                {
                    for(l1=1;l1<3-l;l1++)
                    {
                        if(ara[l1]<ara[l1-1]){
                            tmp=ara[l1];
                            ara[l1]=ara[l1-1];
                            ara[l1-1]=tmp;
                        }
                    }
                }

                if(ara[1]+ara[0]<=(ara[2]>>1)){
                    table+=ara[1]+ara[0];
                }
                else  if(ara[1]>=3){
                    table+=((ara[1]/3)<<1);
                    ara[2]-=(ara[1]/3)*3;
                    ara[1]-=((ara[1]/3)<<1);
                }
                else if(ara[1]<3){
                    table++;
                    ara[1]--;
                    ara[2]-=2;
                }
                else{
                    break;
                }

            }while(1);

        }
        printf("%d\n",table);
    }

    return 0;
}
