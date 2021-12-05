#include<iostream>
#include<cstdio>

using namespace std;

class ant{
    int L;
    int W;
public:
    int H;
    int Vol;

    void set(int L,int W,int H)
    {
        this->L=L,this->W=W,this->H=H;
        Vol=L*H*W;
    }
};

int main()
{
    int tc;
    ant *arabase;
    while(1==scanf("%d",&tc))
    {
        if(!tc) break;
        arabase=new ant[tc];

        for(int l=0;l<tc;l++)
        {
            int i,j,k;
            cin>>i>>j>>k;
            arabase[l].set(i,j,k);
        }

        for(int l=tc;l>0;l--)
        {
            for(int l1=1;l1<l;l1++)
            {
                if(arabase[l1-1].H>arabase[l1].H)
                {
                    ant tmpcls=arabase[l];
                    arabase[l1]=arabase[l1-1];
                    arabase[l1-1]=tmpcls;
                }
                else if(arabase[l1-1].H==arabase[l1].H)
                {
                    if(arabase[l1-1].Vol>arabase[l1].Vol)
                    {
                        ant tmpcls=arabase[l];
                        arabase[l1]=arabase[l1-1];
                        arabase[l1-1]=tmpcls;
                    }
                }
            }
        }
        cout<<arabase[tc-1].Vol<<'\n';
        delete[] arabase;
    }
    return 0;
}
