#include<stdio.h>
#include<string.h>
#define WORDS 100
#define LEN 30

char text1[WORDS+1][LEN],text2[WORDS+1][LEN];
int sub_soln[WORDS+1][WORDS+1];
int back_track[WORDS+1][WORDS+1];
int tos;
int stack[WORDS];

void printLCS(int l,int l1)
{
    if(!l || !l1) return;

    if(back_track[l][l1]==2){
        stack[tos++]=l;
        printLCS(l-1,l1-1);
    }
    else{
        if(back_track[l][l1]==1) printLCS(l-1,l1);
        else printLCS(l,l1-1);
    }
}

int main()
{
    int text1_len,text2_len;
    int l,l1;

    while(1==scanf("%s",text1[1]))
    {

        for(l=1;text1[l][0]!='#';l++,scanf("%s",text1[l]));
        text1_len=l;
        for(l=1,scanf("%s",text2[1]);text2[l][0]!='#';l++,scanf("%s",text2[l]));
        text2_len=l;

        for(l=0;l<=WORDS;sub_soln[0][l]=0,sub_soln[l][0]=0,l++);
        for(l=0;l<text1_len;l++)
        {
            for(l1=0;l1<text2_len;l1++) back_track[l][l1]=0;
        }

        for(l=1;l<text1_len;l++)
        {
            for(l1=1;l1<text2_len;l1++)
            {
                if(strcmp(text1[l],text2[l1])){
                    if(sub_soln[l-1][l1]>sub_soln[l][l1-1]){
                        sub_soln[l][l1]=sub_soln[l-1][l1];
                        back_track[l][l1]=1;
                    }
                    else{
                        sub_soln[l][l1]=sub_soln[l][l1-1];
                        back_track[l][l1]=0;
                    }
                }
                else{
                    sub_soln[l][l1]=sub_soln[l-1][l1-1]+1;
                    back_track[l][l1]=2;
                }
            }
        }

        if(!sub_soln[l-1][l1-1]) continue;

        tos=0;
        printLCS(l-1,l1-1);
        for(l=tos-1;l>=0;l--)
        {
            printf("%s",text1[stack[l]]);
            if(l) putchar(' ');
        }
        putchar('\n');
    }
    return 0;
}
