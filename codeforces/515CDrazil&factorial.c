#include<stdio.h>

int main()
{
    char data[10][10]={"1","1","2","3","322","5","53","7","7222","7332"};
    char num[16];
    char ans[20];
    int n;
    int l,l1,l2,len;
    char tmp;

    while(2==scanf("%d%s",&n,num))
    {
        for(l=0,len=0;num[l];l++)
        {
            if(num[l]>'1'){
                for(l1=len,l2=0;data[num[l]-'0'][l2];ans[l1]=data[num[l]-'0'][l2],l2++,l1++);
                len=l1;
            }
        }

        for(l=0;l<len;l++)
        {
            l2=len-l;
            for(l1=1;l1<l2;l1++)
            {
                if(ans[l1]>ans[l1-1]){
                    tmp=ans[l1];
                    ans[l1]=ans[l1-1];
                    ans[l1-1]=tmp;
                }
            }
        }
        ans[len]='\0';
        puts(ans);
    }

    return 0;
}
