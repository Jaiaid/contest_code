#include<cstdio>
#define INF_DIS 100000000001

struct node
{
    int name;
    long long int dist;
    int parent;
    struct node *next;
};

struct queue_node{
    struct node vertex;
    struct queue_node *next;
};

void shortest_dist_label(struct node **graph,int num_vertex,struct node *vertices,int start_idx,int final_idx)
{
    struct node *tmp2;
    struct queue_node *head=new struct queue_node;
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
        for(tmp2=graph[start_idx];tmp2;tmp2=tmp2->next)
        {

            if(vertices[start_idx].dist+tmp2->dist<vertices[tmp2->name-1].dist){
                l1=tmp2->name-1;
                vertices[l1].dist=vertices[start_idx].dist+tmp2->dist;
                vertices[l1].parent=start_idx+1;

                if(head->vertex.dist>=vertices[l1].dist){
                    tmp=new struct queue_node;
                    tmp->vertex=vertices[l1];
                    tmp->next=head;
                    head=tmp;
                }
                else if(tail->vertex.dist<=vertices[l1].dist){
                    tail->next=new struct queue_node;
                    tail=tail->next;
                    tail->vertex=vertices[l1];
                    tail->next=NULL;
                }
                else{
                    tmp1=head;
                    for(tmp1=head;tmp1->next->vertex.dist<vertices[l1].dist;tmp1=tmp1->next);
                    tmp=tmp1->next;
                    tmp1->next=new struct queue_node;
                    tmp1=tmp1->next;
                    tmp1->vertex=vertices[l1];
                    tmp1->next=tmp;
                }
            }

        }

        tmp=head;
        head=head->next;
        delete tmp;
    }

}

void shortest_path_show(struct node *vertices,int num_vertex,int start_idx,int final_idx)
{
    int top;
    int *stack=new int[num_vertex];

    if(vertices[final_idx-1].dist!=INF_DIS){
        for(top=-1;final_idx;top++,stack[top]=final_idx,final_idx--,final_idx=vertices[final_idx].parent);
        for(printf("%d",stack[top]);top>0;top--,printf(" %d",stack[top]));
        putchar('\n');
    }
    else puts("-1");
    delete[] stack;
}

int main()
{

    struct node *vertices;
    struct node **graph,*tmp,*tmp1;
    int l,l1;
    int a,b;
    long long int w;
    int n,m;

    while(2==scanf("%d%d",&n,&m))
    {
        vertices=new struct node[n];
        graph=new struct node*[n];

        for(l=0;l<n;graph[l]=NULL,vertices[l].name=l+1,vertices[l].parent=0,l++);

        for(l=0;l<m;l++)
        {
            scanf("%d%d%lld",&a,&b,&w);
            a--;

            tmp1=graph[a];
            tmp=new node;
            tmp->name=b;
            tmp->dist=w;
            tmp->parent=0;
            tmp->next=tmp1;
            graph[a]=tmp;
            b--;

            tmp1=graph[b];
            tmp=new node;
            tmp->name=a+1;
            tmp->dist=w;
            tmp->parent=0;
            tmp->next=tmp1;
            graph[b]=tmp;

        }

        shortest_dist_label(graph,n,vertices,1,n);
        shortest_path_show(vertices,n,1,n);
        delete[] vertices;
        for(l=0;l<n;delete[] graph[l],l++);
        delete[] graph;
    }
	return 0;
}
