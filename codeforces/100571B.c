#include<stdio.h>

unsigned int memory[100001];
int a,b;
unsigned int x[100000];

unsigned int troynacci(int n)
{
    if(memory[n]==-1){
        unsigned long long int tmp=a*troynacci(n-2);
        tmp+=b*troynacci(n-1);
        tmp%=1000000007;
        memory[n]=tmp;
    }
    return memory[n];
}

int main(){
	unsigned int n,q,f1,f2,l,l1;
	unsigned int L,R;

	scanf("%u%u",&n,&q);
	scanf("%u%u",&f1,&f2);
	scanf("%u%u",&a,&b);

    for(l=0;l<n;scanf("%u",&x[l]),memory[l]=-1,l++);
    memory[n]=-1;
    memory[0]=f1,memory[1]=f2;

    for(l=0;l<q;l++)
    {
        scanf("%u%u",&L,&R);
        for(l1=L-1,L--;l1<R;l1++) x[l1]=troynacci(l1-L)+x[l1];
    }

    for(l=0;l<n;l++) printf("%u ",x[l]);

	return 0;
}
