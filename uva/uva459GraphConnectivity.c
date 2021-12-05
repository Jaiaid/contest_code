#include<stdio.h>
#define MAXNODE 26

int node_par[MAXNODE];

int find_par(int u)
{
    node_par[u]=(node_par[u]==u)?u:find_par(node_par[u]);
    return node_par[u];
}

int main()
{
    char edge[3];
    char node_max_name;
    int tc;
    int l,u,v,case_no=0;

    scanf("%d",&tc);
    getchar();
    getchar();

    while(case_no<tc)
    {
        node_max_name=getchar();
        getchar();

        for(l=0,node_max_name-='A'-1;l<node_max_name;node_par[l]=l,l++);

        for(l=0;gets(edge) && edge[0];)
        {
            u=find_par(edge[0]-'A');
            v=find_par(edge[1]-'A');
            if(u!=v){
                node_par[u]=v;
                l++;
            }
        }

        printf("%d\n",node_max_name-l);
        case_no++;
        if(case_no<tc) putchar('\n');
    }

    return 0;
}

