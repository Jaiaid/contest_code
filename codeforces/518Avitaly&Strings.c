#include<stdio.h>

int main()
{
    char str1[101],str2[101],carry;
    int l,flag;

    while(2==scanf("%s%s",str1,str2))
    {
        for(l=0;str1[l];l++);
        for(carry=1,flag=0,l--;l>=0;l--)
        {
            if(str1[l]!='z') str1[l]+=carry,carry='\0';
            else if(carry) str1[l]='a',carry=1;

            if(str1[l]!=str2[l]) flag=1;
        }

        if(flag) puts(str1);
        else puts("No such string");
    }
    return 0;
}

