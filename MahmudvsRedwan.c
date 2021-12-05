#include<stdio.h>

long long int gcd(long long int a,long long int b)
{
    long long int k;
    while(a%b){
        k=b;
        b=a%b;
        a=k;
    }
    return b;
}

int main()
{
    int N,tc;
    long long int D,x[10],y[10];
    int l,l1,l2,l3,end;
    long long int d[45],n[45],tmp1,tmp2,tmp3;
    int count;

    scanf("%d",&tc);
    for(l=0;l<tc;)
    {
        scanf("%d%lld",&N,&D);

        for(l1=0;l1<N;l1++)
        {
            scanf("%lld%lld",&x[l1],&y[l1]);
        }

        for(l1=0,end=0,count=0;l1<N;l1++)
        {
            for(l2=l1+1;l2<N;l2++)
            {
                tmp1=y[l1]-y[l2];
                tmp2=x[l1]-x[l2];

                if((tmp1<0 && tmp2<0) || (tmp1>0 && tmp2<0)) tmp1=-tmp1,tmp2=-tmp2;

                if(tmp1 && tmp2) tmp3=gcd((tmp1>0)?tmp1:-tmp1,(tmp2>0)?tmp2:-tmp2),tmp1/=tmp3,tmp2/=tmp3;

                for(l3=0;l3<end;l3++)
                {
                    if((!d[l3] && !tmp1) || (d[l3]==tmp1 && n[l3]==tmp2) || (!n[l3] && !tmp2)) break;
                }

                if(l3==end){
                    d[l3]=tmp1,n[l3]=tmp2;
                    count++,end++;
                }
            }
        }

        printf("Case %d: %lld\n",++l,D*count);
    }
    return 0;
}

