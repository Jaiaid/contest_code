#include<stdio.h>
#define MAXLEN 200000

int main()
{
    char str[MAXLEN];
    int key[26];
    int n;
    int ans;
    int l;

    while(2==scanf("%d%s",&n,str))
    {
        for(l=0;l<26;key[l]=0,l++);
        for(l=0,ans=0;str[l];l++)
        {
            key[str[l]-'a']++;
            l++;

            if(key[str[l]-'A']){
               key[str[l]-'A']--;
            }
            else{
                ans++;
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}

