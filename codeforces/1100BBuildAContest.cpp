#include <iostream>
#include <map>
#include <set>
#include <string>

#define MAXPROBLEM 100000

using namespace std;

int main()
{
	int n,m;
	string ans;

	while(cin>>n>>m)
	{
		ans=string(m,'0');
		map<int,int> problem_pool;
		set<int> problem_set;

		for(int l=0;l<m;l++)
		{
			int tmp,prev_size;
			cin>>tmp;

			if(problem_pool.find(tmp)==problem_pool.end()){
				problem_pool[tmp]=1;
			}
			else{
				problem_pool[tmp]++;
			}
			
			prev_size=problem_set.size();
			problem_set.insert(tmp);
			
			if(prev_size<problem_set.size()){
				problem_pool[tmp]--;
			}

			if(problem_set.size()==n){
				ans[l]='1';
				problem_set.clear();
				for(int l1=1;l1<=n;l1++)
				{
					if(problem_pool.find(l1)!=problem_pool.end()&&problem_pool[l1]!=0){
						problem_set.insert(l1);
						problem_pool[l1]--;
					}
				}
			}
			//cout<<problem_set.size()<<' '<<problem_pool[1]<<' '<<problem_pool[2]<<' '<<problem_pool[3]<<endl;
		}

		cout<<ans<<endl;
	}

	return 0;
}
