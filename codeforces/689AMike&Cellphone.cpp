#include<cstdio>

using namespace std;

char numpad[4][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}};

void getxy(char ch,int *x,int *y);//function to get x(row) andd y(col) of a number ch in numpad

int main()
{
	char num[10];
	int n;
	int x,y,tmpx,tmpy,l,l1,xdiff[10],ydiff[10];
	
	while(scanf("%d",&n)==1)	
	{
		scanf("%s",num);
			
		getxy(num[0],&x,&y);	//get first digit (x,y)
		
		for(l=1;l<n;l++)		//this loop stores diff of consecutive digits x's and y's in xdiff and ydiff
		{
			getxy(num[l],&tmpx,&tmpy);
			xdiff[l]=tmpx-x;
			ydiff[l]=tmpy-y;
			x=tmpx,y=tmpy;
		}
		//now see if starting from any digit of numpad following the difference leads to valid numpad position
		//if for any digit except num[0] there is a valid numpad sequence l will be <10
		//in case number is of single digit the check won't work. So, while outputting n>1 is checked 
		for(l=0;l<10;l++)
		{
			if(l+'0'==num[0]){
				continue;
			}
			getxy(l+'0',&x,&y);

			for(l1=1;l1<n;l1++)
			{
				x+=xdiff[l1];
				y+=ydiff[l1];
				
				if(x<0 || x>3 || y<0 || y>2 || (x==3 && (y==0||y==2)) ){
					break;
				}
			}

			if(l1==n){
				break;
			}
		}
		
		if(l==10 && n>1) puts("YES");
		else puts("NO");
	}
	
	return 0;
}

void getxy(char ch,int *x,int *y)
{
	int l,l1;
	for(l=0;l<4;l++)
	{
		for(l1=0;l1<3;l1++)
		{
			if(numpad[l][l1]==ch){
				*x=l,*y=l1;
			}
		}
	}
}
