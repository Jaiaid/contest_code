#include<stdio.h>

int main()
{
    int n,lexicalflg,len1,len2;
    int ara1[200000],ara2[200000];
    double sum1,sum2;
    while(1==scanf("%d",&n))
    {
        int l,tmp,lstmov,score;
        for(l=0,len1=0,len2=0,sum1=0,sum2=0,lexicalflg=0;l<n;l++)
        {
            scanf("%d",&score);

            if(score<0){
                ara2[len2]=score;
                len2++;
                sum2+=score;
            }
            else{
                ara1[len1]=score;
                len1++;
                sum1+=score;
            }

        }
        lstmov=score;

        tmp=(len1<=len2)?len1:len2;
        for(l=0;l<tmp;l++)
        {
            if(ara1[l]>-ara2[l]){
                lexicalflg=1;
                break;
            }
            else if(ara1[l]<-ara2[l]){
                lexicalflg=2;
                break;
            }
        }

        if(sum1>-sum2) puts("first");
        else if(sum1<-sum2) puts("second");
        else{
            if(!lexicalflg){
                if(len1>len2) puts("first");
                else if(len1<len2) puts("second");
                else{
                    if(lstmov>0) puts("first");
                    else puts("second");
                }
            }
            else if(lexicalflg==1) puts("first");
            else puts("second");
        }
    }

    return 0;
}
