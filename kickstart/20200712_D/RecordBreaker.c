#include <stdio.h>
#define MAXDAY 200000

int main()
{
    int T, N;
    int case_no;
    int day_visitor[MAXDAY+2];
    
    scanf("%d",&T);
    for(case_no=1;case_no<=T;case_no++)
    {
        scanf("%d",&N);
        
        int i;
        // for logic convenience
        day_visitor[0]=-1;
        for(i=1;i<=N;i++)
        {
            scanf("%d",&day_visitor[i]);
        }
        day_visitor[N+1]=-1;
        
        int num_of_record_break_day=0;
        int current_max_visitor=-1;
        for(i=1;i<=N;i++)
        {
            if(day_visitor[i] > day_visitor[i+1] && day_visitor[i] > current_max_visitor){
                current_max_visitor=day_visitor[i];
                num_of_record_break_day++;
            }
            if(day_visitor[i] > current_max_visitor){
				current_max_visitor=day_visitor[i];
			}
        }
        
        printf("Case #%d: %d\n",case_no,num_of_record_break_day);
    }
    
    return 0;
}
