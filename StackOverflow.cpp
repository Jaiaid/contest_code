#include<iostream>

using namespace std;

class stck{
    int *ara;
    int top;
public:
    stck(){ top=0,ara=new int[10000]; };

    void push(int x){ ara[top++]=x; };

    void pop(){
        if(top) top--;
    };

    void topf(){
        if(!top) cout<<"Empty!\n";
        else cout<<ara[top-1]<<'\n';
    };

    ~stck(){ delete[] ara; }

    friend void put(stck &i,stck &j);
};

void put(stck &i,stck &j){
    for(int l=0;l<j.top;i.ara[i.top]=j.ara[l],i.top++,l++);
    j.top=0;
};

int main()
{
    stck *ara;
    int T,N,Q;
    char cmd[5];
    int i,j;

    cin>>T;

    for(int l=0;l<T;l++)
    {
        cin>>N>>Q;
        ara = new stck[N];

        cout<<"Case "<<l+1<<":\n";
        for(int l1=0;l1<Q;l1++)
        {
            cin>>cmd;
            if(cmd[0]=='t'){
                cin>>i;
                i--;
                ara[i].topf();
            }
            else if(cmd[1]=='o'){
                cin>>i;
                i--;
                ara[i].pop();
            }
            else{
                cin>>i>>j;
                i--;
                if(cmd[2]=='s'){
                    ara[i].push(j);
                }
                else{
                    j--;
                    put(ara[i],ara[j]);
                }
            }
        }
        delete[] ara;
    }
    return 0;
}
