#define MAXLEN 100000
#include<iostream>
#include<algorithm>

using namespace std;

struct person{
    long long int m;
    long long int s;
} friends[MAXLEN];

bool comp(person arg1,person arg2)
{
    return arg1.m<arg2.m;
}

int main()
{
    int n;
    unsigned long long int d;
    int l,ini;
    long long int tmp;
    long long int maxff;

    while(cin>>n>>d)
    {
        for(l=0;l<n;l++) cin>>friends[l].m>>friends[l].s;

        sort(friends,friends+n,comp);

        for(l=0;l<n;l++) cout<<friends[l].s<<'\n';

        for(l=1,tmp=friends[0].s,ini=0,maxff=0;l<n;l++)
        {
            if(friends[l].m<friends[ini].m+d) tmp+=friends[l].s;
            else{
                if(tmp>maxff) maxff=tmp;
                while(friends[l].m>=friends[ini].m+d) tmp-=friends[ini].s,ini++;
                tmp+=friends[l].s;
            }
        }
        if(tmp>maxff) maxff=tmp;
        cout<<maxff<<'\n';
    }
    return 0;
}
