#include<stdio.h>

int strcomp(char *str1,char *str2)
{
    for(;*str1;str1++,str2++)
    {
        if(*str1>*str2){
            return 1;
        }
        else if(*str1<*str2){
            return -1;
        }
    }

    return 0;
}

int main()
{
    char str[1001],temp[1001],ans[1001],tmpc;
    int n,l,l1,l2;

    while(1==scanf("%d",&n))
    {
        scanf("%s",str);

        for(l=0,tmpc=10-str[0];l<n;l++) ans[l]=48+(str[l]+tmpc)%10;
        ans[l]='\0';

        for(l=1;l<n;l++)
        {

            l1=0;
            l2=l;
            tmpc=10-str[l2];
            do{

                temp[l1]=48+(str[l2]+tmpc)%10;
                l1++;
                l2++;
                if(l2==n) l2=0;

            }while(l2!=l);
            temp[l1]='\0';

            if(strcomp(ans,temp)>0){
                for(l2=0;l2<n;l2++) ans[l2]=temp[l2];
            }

        }

        puts(ans);

    }
    return 0;
}
