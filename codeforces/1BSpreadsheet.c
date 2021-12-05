#include<stdio.h>
#include<stdlib.h>

int main()
{
    char str[100];
    int n;
    char stck[50];
    int task,mlt;
    int l,tmp;

    while(1==scanf("%d",&n))
    {
        while(n)
        {
            scanf("%s",str);
            if(str[0]=='R' && str[1]<='9'){
                for(l=2;str[l] &&str[l]<='9';l++);
                if(!str[l]) task=2;
                else task=1;
            }
            else task=2;

            if(task==1){
                for(l=0;str[l]!='C';l++);
                tmp=atoi(&str[l+1]);
                for(l=0;tmp;)
                {
                    tmp--,stck[l]='A'+(char)(tmp%26),l++,tmp/=26;
                }
                for(l--;l>=0;putchar(stck[l]),l--);
                printf("%d\n",atoi(&str[1]));
            }
            else{
                for(l=0;str[l]>'9';l++);
                printf("R%dC",atoi(&str[l]));
                for(l--,tmp=0,mlt=1;l>=0;tmp+=(str[l]-'A'+1)*mlt,mlt*=26,l--);
                printf("%d\n",tmp);
            }
            n--;
        }
    }
    return 0;
}
