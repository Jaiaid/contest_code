#include<stdio.h>
#define MAXPATHLENGTH 10001

int main()
{
    char chessboard[8][9];
    int white,black;
    int l,l1;

    while(1==scanf("%s",chessboard[0]))
    {
        for(l=1;l<8;scanf("%s",chessboard[l]),l++);

        for(l=0,white=0,black=0;l<8;l++)
        {
            for(l1=0;chessboard[l][l1];l1++)
            {
                switch(chessboard[l][l1]){
                    case 'Q':
                        white+=9;
                        break;
                    case 'R':
                        white+=5;
                        break;
                    case 'B':
                        white+=3;
                        break;
                    case 'N':
                        white+=3;
                        break;
                    case 'P':
                        white+=1;
                        break;
                    case 'q':
                        black+=9;
                        break;
                    case 'r':
                        black+=5;
                        break;
                    case 'b':
                        black+=3;
                        break;
                    case 'n':
                        black+=3;
                        break;
                    case 'p':
                        black+=1;
                }
            }
        }

        if(black>white) puts("Black");
        else if(black<white) puts("White");
        else puts("Draw");
    }
    return 0;
}

