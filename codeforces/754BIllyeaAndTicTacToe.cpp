#include<iostream>

using namespace std;

char board[5][5];

bool resolve1(int i,int j)
{
	if(i<2 && j<2){
		if((board[i][j+1]=='x' && board[i][j+2]=='.') || (board[i][j+1]=='.' && board[i][j+2]=='x')) return true;
		else if((board[i+1][j]=='x' && board[i+2][j]=='.') || (board[i+1][j]=='.' && board[i+2][j]=='x')) return true;
		else if((board[i+1][j+1]=='x' && board[i+2][j+2]=='.') || (board[i+1][j+1]=='.' && board[i+2][j+2]=='x')) return true;
		
		return false;
	}
	else if(i<2){
		if((board[i+1][j]=='x' && board[i+2][j]=='.') || (board[i+1][j]=='.' && board[i+2][j]=='x')) return true;
		else if((board[i+1][j-1]=='x' && board[i+2][j-2]=='.') || (board[i+1][j-1]=='.' && board[i+2][j-2]=='x')) return true;
	}
	else if(j<2 && ((board[i][j+1]=='x' && board[i][j+2]=='.') || (board[i][j+1]=='.' && board[i][j+2]=='x'))){
		return true;
	}
	return false;
}

bool resolve2(int i,int j)
{
	if(i<2 && j<2){
		if((board[i][j+1]=='x' && board[i][j+2]=='x') || (board[i][j+1]=='x' && board[i][j+2]=='x')) return true;
		else if((board[i+1][j]=='x' && board[i+2][j]=='x') || (board[i+1][j]=='x' && board[i+2][j]=='x')) return true;
		else if((board[i+1][j+1]=='x' && board[i+2][j+2]=='x') || (board[i+1][j+1]=='x' && board[i+2][j+2]=='x')) return true;
		
		return false;
	}
	else if(i<2){
		if((board[i+1][j]=='x' && board[i+2][j]=='x') || (board[i+1][j]=='x' && board[i+2][j]=='x')) return true;
		else if((board[i+1][j-1]=='x' && board[i+2][j-2]=='x') || (board[i+1][j-1]=='x' && board[i+2][j-2]=='x')) return true;
	}
	else if(j<2 && ((board[i][j+1]=='x' && board[i][j+2]=='x') || (board[i][j+1]=='x' && board[i][j+2]=='x'))){
		return true;
	}
	
	return false;
}

int main()
{
	bool possible;
	
	for(int l=0;l<4;l++) cin>>board[l];
	
	possible=false;
	for(int l=0;l<4;l++)
	{
		for(int l1=0;l1<4;l1++)
		{
			if(board[l][l1]=='x'){
				possible=resolve1(l,l1);
			}
			else if(board[l][l1]=='.'){
				possible=resolve2(l,l1);
			}
			if(possible){
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}
	
	cout<<"NO"<<endl;
	return 0;
}
