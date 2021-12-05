#include<stdio.h>

int main()
{
    int tc,term_no;
    int case_no=0,l;

    scanf("%d",&tc);
    while(case_no<tc)
    {
        scanf("%d",&term_no);
        if(term_no%7){
            term_no--;
            printf("Case %d: %d\n",++case_no,-2+(term_no*term_no));
        }
        else{
            printf("Case %d: %d\n",++case_no,33+(term_no/7)*11);
        }
    }
    return 0;
}

