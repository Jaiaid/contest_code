#include<stdio.h>

char n[10];

int position(int l,int lwbound)
{
    if(n[l+1]=='\0'){
        if(n[l]=='7') return 2;
        else return 1;
    }

    if(n[l]=='7') return (lwbound<<1)+position(l+1,(lwbound>>1));
    return lwbound+position(l+1,(lwbound>>1));
}

int main()
{
    int l;
    int ans;

    while(1==scanf("%s",n))
    {
        for(l=0;n[l];l++);
        printf("%d\n",position(0,(2<<(l-2))));
    }

    return 0;
}


