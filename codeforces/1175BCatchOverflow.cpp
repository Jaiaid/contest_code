#include <iostream>
#include <string>

#define LOOP "for"
#define ADD "add"
#define END "end"
#define OVERFLOW_VAL 0x100000000ULL

// this one is used because calculation may be overflowed then comes to normal range again for the given problem
// so final check is not adequate, we have to set a flag as soon as overflow happens
bool of=false;

unsigned long long int parser()
{
	unsigned long long int ret=0, iteration;
	
	std::string cmd;
	while(std::cin>>cmd)
	{
		if(cmd==LOOP){
			std::cin>>iteration;
			ret+=iteration*parser();
		}
		else if(cmd==ADD){
			ret++;
		}
		else if(cmd==END){
			break;
		}
	}
	if(ret>=OVERFLOW_VAL) of=true;
	return ret;
}

int main()
{
	int l;
	unsigned long long int x;
	std::cin>>l;
	
	of=false;
	x=parser();
	
	if(!of){
		std::cout<<x<<std::endl;
	}
	else{
		std::cout<<"OVERFLOW!!!"<<std::endl;
	}

	return 0;
}
