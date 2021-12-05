#include <iostream>

int main()
{
	int n;
	int total_num_of_gray;
	
	std::cin>>n;
	
	/*
	 * following strategy is done, with increasing n, ^ chain is increased diagonally
	 *  
	 *  **     **
	 *  *^*    *^*
	 *   *^*    *^* 
	 *    **     *^*
	 *            *^*
	 *             **
	 */
	total_num_of_gray=3*n+4;
	std::cout<<total_num_of_gray<<std::endl;
	
	
	std::cout<<"1 1"<<std::endl<<"2 1"<<std::endl;
	for(int y=2,x=1;y<n+2;y++,x++)
	{
		std::cout<<x<<' '<<y<<std::endl<<x+1<<' '<<y<<std::endl<<x+2<<' '<<y<<std::endl;
	}
	std::cout<<n+1<<' '<<n+2<<std::endl<<n+2<<' '<<n+2<<std::endl;

	return 0;
}
