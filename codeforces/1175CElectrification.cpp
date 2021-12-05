#include <iostream>
#include <vector>
#include <algorithm>

#define MAXSEQUENCELEN 200000

using namespace std;

// trying to find the most closely packed consecutive k+1 number
// the answer is the mid point of those numbers which will give the smallest 
// distance from two extreme points of the k numbers

int solution(const vector<int> &ara,int n,int k)
{
	int ans=ara[n-1];
	int min_d=ara[n-1];
	int first,last,mid;
	
	for(int l=k,l1=0;l<n;l++,l1++)
	{
		first=ara[l1];
		last=ara[l];
		mid=(first+last)/2;
		
		int l_d=mid-first;
		int r_d=last-mid;
		int tmp_d=(r_d>l_d)?r_d:l_d;
		
		if(tmp_d<min_d){
			ans=mid;
			min_d=tmp_d;
		}
	}
	
	return ans;
}

int main()
{
	int tc;
	int n,k;
	vector<int> ara(MAXSEQUENCELEN,0);
	
	// not necessary
	ios_base::sync_with_stdio(false);
	
	cin>>tc;
	while(tc)
	{
		cin>>n>>k;
		for(int l=0;l<n;l++)
		{
			cin>>ara[l];
		}
		
		cout<<solution(ara,n,k)<<endl;
		tc--;
	}

	return 0;
}
