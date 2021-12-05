#include <iostream>
#include <vector>
#include <string>

/*
 * Here problem is to rearrange the array so that, 
 * f(...f(f(f(a1,a2),a3),a4)...) is max
 * f(x,y)=(x|y)-y which is equivalent to x&(~y). 
 * So, closed form of operation is a_1&(~a_2)...(~a_n)
 * and we have to maximize it's value by rearranging array
 * As a1 we have to choose such number that it has a bit position 
 * which is 1 only for that number and the position is maximum 
 */

// gives 32 length string with 31th bit in index zero
std::string find_bitstring(int n);

int main()
{
	/*
	 * algo. is fund all the bitstring than find such a number that, 
	 * one of it's bit position is 1 only in it. Position wise search is done 
	 * from bit position 30(in string 1). So, first such position will be 
	 * of maximum place value and will give possible maximum number as a1
	 * 
	 * The algorithm's time complexity is O(n) where n is length of ara
	 */
	int n;
	std::vector<int> ara;
	std::vector<std::string> bitstring_ara;
	
	std::cin>>n;
	for(int i=0;i<n;i++)
	{
		int tmp;
		std::cin>>tmp;
		
		ara.push_back(tmp);
		bitstring_ara.push_back(find_bitstring(tmp));
	}

	/*
	 * kind of column major traversal
	 */
	for(int i=1;i<32;i++)
	{
		int count=0;
		int swap_idx;
		for(int j=0;j<n;j++)
		{
			if(bitstring_ara[j][i]=='1'){
				swap_idx=j;
				count++;
			}
		}
		if(count==1){
			int tmp=ara[swap_idx];
			ara[swap_idx]=ara[0];
			ara[0]=tmp;
			break;
		}
	}
	for(int i=0;i<n;i++)
	{
		std::cout<<ara[i]<<' ';
	}

	return 0;
}

std::string find_bitstring(int n)
{
	std::string bitstring(32,'0');
	int pos=31;
	while(n)
	{
		if(n&1){
			bitstring[pos]='1';
		}
		pos--;
		n>>=1;
	}
	
	return bitstring;
}
