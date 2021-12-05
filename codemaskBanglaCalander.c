#include<stdio.h>

char bangla_month[13][15]={"","Poush", "Magh", "Falgun", "Chaitra",
				"Baishakh", "Jaishtha", "Ashar", "Sraban", 
				"Bhadra", "Ashwin", "Kartik" ,"Agrahayan" 
			   };

int english_month_day[13]={-1,31,28,31,30,31,30,31,31,30,31,30,31};
int bangla_month_day[13]={-1,30,30,30,30,31,31,31,31,31,30,30,30};

int isLeap(int yyyy)
{
	if(yyyy%4) return 0;
	else{
		if(yyyy%100 || yyyy%400==0) return 1;
	}
	return 0;
}

int main()
{
	int T,DD,MM,YYYY;
	int tc,totalday,l;
	int ansDD,ansMM,ansYYYY;
	
	scanf("%d",&T);
	
	for(tc=1;tc<=T;tc++)
	{
		scanf("%d%d%d",&DD,&MM,&YYYY);
		
		if(isLeap(YYYY)){
			bangla_month_day[3]=31;
			english_month_day[2]=29;
		}
		
		for(l=1,totalday=DD;l<MM;l++)
		{
			totalday+=english_month_day[l];
		}
		
		ansYYYY=1378+(YYYY-1972);
		ansMM=1;
		ansDD=17;
		
		for(l=1;l<=totalday;l++)
		{
			ansDD++;
			
			if(ansDD>bangla_month_day[ansMM]){
				ansMM++;
				ansDD=1;
				
				if(ansMM==5){
					ansYYYY++;
				}
				else if(ansMM>12){
					ansMM=1;
				}
				
			}
		}
		
		printf("Case %d: %d, %s, %d\n",tc,ansDD,bangla_month[ansMM],ansYYYY);
		
		bangla_month_day[3]=30;
		english_month_day[2]=28;
	}
	
	return 0;
}
