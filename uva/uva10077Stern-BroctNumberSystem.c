#include<stdio.h>
#define MAXPATHLENGTH 10001

int main()
{
    char path[MAXPATHLENGTH];
    int m,n;
    int Lnum,Rnum,Lden,Rden;
    int l,tmpden,tmpnum;

    while(2==scanf("%d%d",&m,&n))
    {
        if(m==1 && n==1) break;

        l=0;
        Lnum=0,Rnum=1,Lden=1,Rden=0;
        tmpden=1,tmpnum=1;
        while(tmpden!=n || tmpnum!=m)
        {
            if((1.0*tmpnum/tmpden)>(1.0*m/n)){
                Rnum=tmpnum,Rden=tmpden;
                tmpnum=Lnum+Rnum,tmpden=Lden+Rden;
                path[l]='L';
            }
            else{
                Lnum=tmpnum,Lden=tmpden;
                tmpnum=Lnum+Rnum,tmpden=Lden+Rden;
                path[l]='R';
            }

            l++;
        }
        path[l]='\0';
        puts(path);
    }
    return 0;
}

