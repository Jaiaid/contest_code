#include<stdio.h>

int main()
{
    int tc,rnum;
    while(1==scanf("%d",&tc))
    {
        int l,l1,numpos[100],ansara[1000],gi;
        int rpos[100][2],rad[100];

        for(l=0,gi=0;l<tc;l++)
        {
            scanf("%d%d",&rnum,&numpos[l]);

            for(l1=0;l1<rnum;l1++)
            {
                scanf("%d%d%d",&rpos[l1][0],&rpos[l1][1],&rad[l1]);
            }
            for(l1=0;l1<numpos[l];l1++)
            {
                int myposx,myposy,l2;
                scanf("%d%d",&myposx,&myposy);
                ansara[gi]=0;
                for(l2=0;l2<rnum;l2++)
                {
                    if((myposx-rpos[l2][0])*(myposx-rpos[l2][0])+(myposy-rpos[l2][1])*(myposy-rpos[l2][1])<=rad[l2]*rad[l2]){
                        ansara[gi]=1;
                        break;
                    }
                }
                gi++;
            }
        }

        for(l=0,gi=0;l<tc;l++)
        {
            printf("Case %d:\n",l+1);
            for(l1=0;l1<numpos[l];l1++,gi++)
            {
                if(ansara[gi]) puts("Yes");
                else puts("No");
            }
        }
    }
	
    return 0;
}
