#include<stdio.h>

int gcd(int a,int b)
{
    if(b%a==0) return a;
    else return gcd(b%a,a);
}

int main()
{
    int a,b,n;
    while(3==scanf("%d%d%d",&a,&b,&n))
    {
        int l,low,high,ans[n];
        int GCD=gcd(a,b);
        for(l=0,ans[0]=-1;l<n;l++,ans[l]=-1)
        {
            int i;
            scanf("%d%d",&low,&high);

            if(low<=GCD && high>=GCD){
                ans[l]=GCD;
                continue;
            }
            else if(low>GCD) continue;
            else{
                int d,temp;
                for(d=2,temp=GCD/d;(GCD%d) && temp>=low;d++,temp=GCD/d);
                if(temp>=low && temp<=high) ans[l]=temp;
            }
        }
        for(l=0;l<n;l++) printf("%d\n",ans[l]);
    }
    return 0;
}
