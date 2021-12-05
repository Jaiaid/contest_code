#include<iostream>
#include<cstdio>

using namespace std;

class player{
    char team;
    int num;
    char outfl;
    int time;
public:
    player(){ num=0,outfl='\0'; };
    void setteam(char t){ team=t; };
    void setnum(int n){ num=n; };
    void settime(int t){ time=t; };
    void setoutfl(char t){ outfl=t; };
    int gettime(){ return time; };
    int getnum(){ return num; };
    char getoutfl(){ return outfl; };
    char getteam(){ return team; };
};

int main()
{
    int plyrnum,aralen=0;
    player ara[90];
    char home[21],away[21];

    while(2==scanf("%s%s",home,away))
    {
        cin>>plyrnum;

        for(int l=0;l<plyrnum;l++)
        {
            int t,m,l1;
            char tl,cl;

            cin>>t>>tl>>m>>cl;

            for(l1=0;l1<aralen;l1++) if(m==ara[l1].getnum() && tl==ara[l1].getteam()) break;
            if(l1==aralen){
                ara[l1].setoutfl(cl);
                ara[l1].setteam(tl);
                ara[l1].settime(t);
                ara[l1].setnum(m);
                aralen++;
            }
            else if(ara[l1].getoutfl()!='r'){
                ara[l1].settime(t);
                if(ara[l1].getoutfl()=='y' && cl=='y') ara[l1].setoutfl('r');
                else ara[l1].setoutfl('r');
            }
        }

        for(int l=0;l<aralen;l++)
        {
            int l2=aralen-l-1;
            for(int l1=0;l1<l2;l1++)
            {
                player temp;
                if(ara[l1].gettime()>ara[l1+1].gettime()){
                    temp=ara[l1];
                    ara[l1]=ara[l1+1];
                    ara[l1+1]=temp;
                }
            }
        }

        for(int l=0;l<aralen;l++)
        {
            if(ara[l].getoutfl()=='r'){
                if(ara[l].getteam()=='a') cout<<away;
                else cout<<home;
                cout<<' '<<ara[l].getnum()<<' '<<ara[l].gettime()<<'\n';
            }
        }
    }
    return 0;
}
