#include<stdio.h>
#define MAXEVENT 20

short int dp[MAXEVENT];
short int correct_event_idx[MAXEVENT];
short int event_idx[MAXEVENT];

short int max_subsquence_len(short int first_event,short int len)
{
    short int max,score,l;

    for(l=0,max=1,score=0;l<len;l++)
    {
        if(correct_event_idx[l]>correct_event_idx[first_event] && event_idx[l]>event_idx[first_event]){
            if(dp[l]) score=1+dp[l];
            else{
                score=1+max_subsquence_len(l,len);
            }
        }
        if(score>max) max=score;
    }
    dp[first_event]=max;
    return dp[first_event];
}

int main()
{
    short int score;
    short int n;
    short int l,tmp;

    scanf("%hd",&n);

    for(l=0;l<n;scanf("%hd",&correct_event_idx[l]),l++);

    while(1==scanf("%hd",&event_idx[0]))
    {
        dp[0]=0;
        for(l=1;l<n;dp[l]=0,scanf("%hd",&event_idx[l]),l++);

        for(l=0,tmp=0;l<n;l++)
        {
            if(tmp<max_subsquence_len(l,n)){
                tmp=max_subsquence_len(l,n);
            }
        }
        printf("%hd\n",tmp);
    }
    return 0;
}
