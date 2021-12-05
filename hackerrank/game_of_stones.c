/*
Problem:
Two players (numbered and ) are playing a game with stones. Player always plays first, and the two players move in alternating turns. The game's rules are as follows:

    In a single move, a player can remove either , , or stones from the game board.
    If a player is unable to make a move, that player loses the game.

Given the number of stones, find and print the name of the winner (i.e., or ) on a new line. Each player plays optimally, meaning they will not make a move that causes them to lose the game if some better, winning move exists.

Input Format:
The first line contains an integer, , denoting the number of test cases.
Each of the subsequent lines contains a single integer, , denoting the number of stones in a test case.

Constraints
1<=tc<=100
1<=n<=100

Output Format:
On a new line for each test case, print "First" if the first player is the winner; otherwise, print "Second".
*/

#include <stdio.h>

int winner_if_stone_num[101];//store the winner index(1 or 2) depending on given stone(s)

void det_winner();//fill the solution array

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int tc;
    int n;
    
    scanf("%d",&tc);
    
    det_winner();
    
    while(tc)
    {
        scanf("%d",&n);
        
        if(winner_if_stone_num[n]==1) puts("First");
        else puts("Second");
        
        tc--;
    }
    
    return 0;
}

void det_winner()
{
    int l;
    winner_if_stone_num[1]=2;
    
    for(l=2;l<6;l++)
    {
        winner_if_stone_num[l]=1;
    }
    
    for(;l<101;l++)
    {
        if(winner_if_stone_num[l-2]==1 && winner_if_stone_num[l-3]==1 && winner_if_stone_num[l-5]==1){
            winner_if_stone_num[l]=2;
        }
        else{
            winner_if_stone_num[l]=1;
        }
    }
}
