#include<stdio.h>
#include<stdlib.h>
#define INF_DIS 1000001

struct node
{
    int name;
    int dist;
    int parent;
};

struct queue_node{
    struct node vertex;
    struct queue_node *next;
};

void shortest_dist_label(int **graph,int num_vertex,struct node *vertices,int start_idx,int final_idx)
{
    struct queue_node *head=(struct queue_node *)malloc(sizeof(struct queue_node));
    struct queue_node *tail=head;
    struct queue_node *tmp,*tmp1;
    int l,l1;

    for(l=0;l<num_vertex;vertices[l].dist=INF_DIS,l++);
    start_idx--,final_idx--;

    vertices[start_idx].dist=0;
    head->vertex=vertices[start_idx];
    head->next=NULL;

    while(head)
    {
        start_idx=head->vertex.name-1;
        for(l=start_idx,l1=0;l1<num_vertex;l1++)
        {

            if(graph[l][l1] && vertices[l].dist+graph[l][l1]<vertices[l1].dist){
                vertices[l1].dist=vertices[l].dist+graph[l][l1];
                vertices[l1].parent=l+1;

                if(head->vertex.dist>=vertices[l1].dist){
                    tmp=(struct queue_node *)malloc(sizeof(struct queue_node));
                    tmp->vertex=vertices[l1];
                    tmp->next=head;
                    head=tmp;
                }
                else if(tail->vertex.dist<=vertices[l1].dist){
                    tail->next=(struct queue_node *)malloc(sizeof(struct queue_node));
                    tail=tail->next;
                    tail->vertex=vertices[l1];
                    tail->next=NULL;
                }
                else{
                    tmp1=head;
                    for(tmp1=head;tmp1->next->vertex.dist<vertices[l1].dist;tmp1=tmp1->next);
                    tmp=tmp1->next;
                    tmp1->next=(struct queue_node *)malloc(sizeof(struct queue_node));
                    tmp1=tmp1->next;
                    tmp1->vertex=vertices[l1];
                    tmp1->next=tmp;
                }
            }

        }

        tmp=head;
        head=head->next;
        free(tmp);
    }

}

void shortest_path_show(struct node *vertices,int num_vertex,int start_idx,int final_idx)
{
    int top;
    int *stack=(int *)malloc(sizeof(int)*num_vertex);

    if(vertices[final_idx-1].dist!=INF_DIS){
        for(top=-1;final_idx;top++,stack[top]=final_idx,final_idx--,final_idx=vertices[final_idx].parent);
        for(printf("%d",stack[top]);top>0;top--,printf(" %d",stack[top]));
        putchar('\n');
    }
    else puts("-1");
}

int main()
{

    struct node *vertices;
    int **graph;
    int l,l1;
    int a,b,w;
    int n,m;

    while(2==scanf("%d%d",&n,&m))
    {
        vertices=(struct node *)malloc(sizeof(struct node)*n);
        graph=(int **)malloc(sizeof(int *)*n);
        for(l=0;l<n;l++)
        {
            graph[l]=(int *)malloc(sizeof(int)*n);
            for(l1=0;l1<n;l1++)
            {
                if(l==l1) graph[l][l1]=0;
                else graph[l][l1]=INF_DIS;
            }
        }

        for(l=0;l<m;l++)
        {
            scanf("%d%d%d",&a,&b,&w);
            graph[a-1][b-1]=w,graph[b-1][a-1]=w;
        }

        for(l=0;l<n;vertices[l].name=l+1,vertices[l].parent=0,l++);

        shortest_dist_label(graph,n,vertices,1,n);
        shortest_path_show(vertices,n,1,n);
        free(vertices);
        free(graph);
    }
	return 0;
}
