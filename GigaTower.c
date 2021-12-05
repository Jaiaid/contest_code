#include<stdio.h>

int main()
{
    int n;
    while(1==scanf("%d",&n))
    {
        int l,tmp;
        for(l=1,n++,tmp=n;;n=tmp,l++,n++,tmp=n)
        {
            while(n && n%10!=8 && n%10!=-8){ //negative number%10==unit place of negative number
                n/=10;
            }
            if(n%10==8 || n%10==-8) break;
        }
        printf("%d\n",l);
    }

    return 0;
}
