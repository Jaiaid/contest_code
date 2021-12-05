#include<iostream>

#define MAXROW 500
#define MAXCOL 500

using namespace std;

int main()
{
	int n;
	long long int square[MAXROW][MAXCOL];
	
	while(cin>>n)
	{
		int l,emprow,empcol,refrow;
		long long int refsum=0,rowsum[MAXROW],colsum[MAXCOL],diagonalsum[2]={0,0};

		for(l=0;l<n;l++)
		{
			int rowhaszero=-1;
			for(int l1=0;l1<n;l1++)
			{
				cin>>square[l][l1];
				
				if(square[l][l1]==0){
					emprow=l;
					empcol=l1;
					rowhaszero=l;
				}
			}
			if(rowhaszero==-1){
				refrow=l;
			}
			/*
			 * this if block above was initially inside of above for loop
			 * So if there was 0 in the last row of square it would assign a
			 * wrong value in refrow variable. WA at test case 101 -_-
			*/
		}
		
		rowsum[emprow]=0,colsum[empcol]=0;
		for(l=0;l<n;l++)
		{
			rowsum[emprow]+=square[emprow][l];
			colsum[empcol]+=square[l][empcol];
			refsum+=square[refrow][l];
		}
		
		if(rowsum[emprow]==colsum[empcol]){
			square[emprow][empcol]=refsum-rowsum[emprow];

			for(l=0;l<n;l++)
			{
				rowsum[l]=0,colsum[l]=0;
				for(int l1=0;l1<n;l1++)
				{
					rowsum[l]+=square[l][l1];
					colsum[l]+=square[l1][l];
				}
				diagonalsum[0]+=square[l][l];
				diagonalsum[1]+=square[l][n-l-1];
			}
			
			if(rowsum[0]==colsum[0] && rowsum[0]==diagonalsum[0] && diagonalsum[0]==diagonalsum[1]){	
				for(l=1;l<n;l++)
				{
					if(rowsum[l]!=rowsum[l-1] || colsum[l]!=colsum[l-1]){
						break;
					}
				}
				if(l<n){
					square[emprow][empcol]=-1;
				}
			}
			else{
				square[emprow][empcol]=-1;
			}
		}
		else{
			square[emprow][empcol]=-1;
		}
		
		if(n==1){
			square[emprow][empcol]=1;
		}	
		if(square[emprow][empcol]<=0){
			square[emprow][empcol]=-1;
		}
		cout<<square[emprow][empcol]<<endl;
	}
	
	return 0;
}
