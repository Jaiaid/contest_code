#include<stdio.h>

struct node{
    int coin;
    int max_coin_from_lower_floor;
};

struct node tree[5051];
int total_cell;

int max_coin(int cell,int floor)
{
    if(cell+floor>total_cell){
        return tree[cell].coin;
    }

    int tmp;
    if(tree[cell].max_coin_from_lower_floor==-1){
        tree[cell].max_coin_from_lower_floor=max_coin(cell+floor,floor+1);
        tmp=max_coin(cell+floor+1,floor+1);
        if(tmp>tree[cell].max_coin_from_lower_floor) tree[cell].max_coin_from_lower_floor=tmp;
    }
    return tree[cell].max_coin_from_lower_floor+tree[cell].coin;
}

int main()
{
    int floor;
    int l;

    while(1==scanf("%d",&floor))
    {
        total_cell=(((floor)*(floor+1))>>1);
        for(l=1;l<=total_cell;l++)
        {
            scanf("%d",&tree[l].coin);
            tree[l].max_coin_from_lower_floor=-1;
        }
        printf("Output: %d\n",max_coin(1,1));
    }
    return 0;
}
