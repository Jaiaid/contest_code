#include <stdio.h>
#include <math.h>
#include <float.h>
#include <limits.h>

// problem link https://codeforces.com/problemset/problem/1485/A

// don't pass num=0 and/or base=0
int how_many_digit(int num,int base)
{
	int n=0;
	// base maybe 1
	if(base==1){
		return INT_MAX;
	}
	while(num!=0)
	{
		num/=base;
		n++;
	}
	return n;
}

int main()
{
	int t;
	int a,b;
	
	scanf("%d",&t);
	while(t>0)
	{
		scanf("%d%d",&a,&b);
		int ans=1;
		
		// first two block will also handle case where a==1
		
		// first let's handle simple cases
		// if a==b answer will be 2
		// b=b+1 and a=floor(a/b) to make a==0
		if(a==b){
			ans=2;
		}
		// if a<b, a=floor(a/b) will make a==0
		else if(a<b){
			ans=1;
		}
		else{
			// assuming first b will needs to be incremented then it will be used to divide a
			// so, # of operation, y = increament of b (b_inc-b) + (# of digit in a at base b_inc)
			// differentiating y w.r.t b_inc and solving for condition of y'=0
			// b_inc = pow(a,sqrt(1/(b_inc*ln(a))))
			// so, we will start from b and increase b 
			// until distance between left side and right side starts to increase
			// if starts to increase stop iterating and calculate # of operation, y
			
			int b_inc=0;
			double abs_difference=DBL_MAX;
			for(b_inc=b;b_inc<=a;b_inc++)
			{
				double tmp_abs_difference = b_inc-pow(a, pow(b_inc*log(a),-0.5));
				tmp_abs_difference = (tmp_abs_difference>=0)?tmp_abs_difference:-tmp_abs_difference;
				
				// printf("%lf %d %d %d\n",tmp_abs_difference,b_inc,how_many_digit(a,b_inc),ans);
				if(tmp_abs_difference>abs_difference){
					break;
				}
				ans=(b_inc-b)+how_many_digit(a,b_inc);
				abs_difference = tmp_abs_difference;
			}
		}
		
		printf("%d\n",ans);
		t--;
	}
	
	return 0;
}
