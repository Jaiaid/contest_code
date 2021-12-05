#include<stdio.h>

int main()
{

    char str[100001],c;
    int l,len,flag;

    while(1==scanf("%s",str))
    {
        for(l=0;str[l];l++);
        len=l-1;
        c=str[len];
        flag=0;

        for(l=0;str[l];l++)
        {
            if(!(str[l]&1) && str[l]<c){
                c=str[l];
                str[l]=str[len];
                str[len]=c;
                flag=1;
                break;
            }
        }

        if(!flag){
            for(l=len;l>=0;l--)
            {
                if(!(str[l]&1)){
                    c=str[l];
                    str[l]=str[len];
                    str[len]=c;
                    flag=1;
                    break;
                }
            }
        }

        if(flag) puts(str);
        else puts("-1");
    }
	return 0;
}
