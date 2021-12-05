#include<stdio.h>
#define MAXSTRLEN 101

int main()
{
    char str[MAXSTRLEN];
    char counter[26];
    int n;
    int l;

    while(2==scanf("%d%s",&n,str))
    {
        if(n<26){
            puts("NO");
            continue;
        }

        for(l=0;l<26;counter[l]='\0',l++);
        for(l=0;str[l];l++)
        {
            if(str[l]<'a') counter[str[l]-'A']++;
            else counter[str[l]-'a']++;
        }

        for(l=0;l<26 && counter[l];l++);

        if(l==26) puts("YES");
        else puts("NO");
    }
    return 0;
}

