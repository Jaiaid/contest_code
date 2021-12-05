#include<cstdio>
#define INF_DIS 100000
#define MAXNODE 757

struct node
{
    char name[3];
    int dist;
    int parent;
    struct node *next;
};

struct queue_node{
    struct node vertex;
    struct queue_node *next;
};

void shortest_dist_label(struct node **graph,struct node *vertices,int start_idx,int final_idx)
{
    struct node *tmp2;
    struct queue_node *head=new struct queue_node;
    struct queue_node *tail=head;
    struct queue_node *tmp,*tmp1;
    int l,l1;

    vertices[start_idx].dist=0;
    head->vertex=vertices[start_idx];
    head->next=NULL;

    while(head)
    {
        start_idx=(head->vertex.name[0]-65)*26+(head->vertex.name[1]-65);
        for(tmp2=graph[start_idx];tmp2;tmp2=tmp2->next)
        {
            l1=(tmp2->name[0]-65)*26+(tmp2->name[1]-65);
            if(vertices[start_idx].dist+1<vertices[l1].dist){
                vertices[l1].dist=vertices[start_idx].dist+1;
                vertices[l1].parent=start_idx;

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

void shortest_path_show(struct node *vertices,int final_idx)
{
    if(vertices[final_idx].dist==INF_DIS){
        puts("No route");
    }
    else{
        if(vertices[final_idx].parent!=-1){
            shortest_path_show(vertices,vertices[final_idx].parent);
            printf("%s %s\n",vertices[vertices[final_idx].parent].name,vertices[final_idx].name);
        }
    }
}

int main()
{

    struct node *vertices;
    struct node **graph,*tmp,*tmp1;
    char startnode[3],endnode[3];
    int l,l1,tc=1;
    int key1,key2;
    int edge;
    graph=new struct node*[MAXNODE];
    vertices=new struct node[MAXNODE];

    while(1==scanf("%d",&edge))
    {
        if(tc>1) putchar('\n');
        for(l=0;l<MAXNODE;graph[l]=NULL,l++);
        for(l=0;l<edge;l++)
        {
            scanf("%s%s",startnode,endnode);
            key1=(startnode[0]-65)*26+(startnode[1]-65);
            key2=(endnode[0]-65)*26+(endnode[1]-65);

            tmp1=graph[key1];
            tmp=new node;
            tmp->name[0]=endnode[0],tmp->name[1]=endnode[1],tmp->name[2]='\0';
            tmp->dist=INF_DIS;
            tmp->parent=-1;
            tmp->next=tmp1;
            graph[key1]=tmp;

            tmp1=graph[key2];
            tmp=new node;
            tmp->name[0]=startnode[0],tmp->name[1]=startnode[1],tmp->name[2]='\0';
            tmp->dist=INF_DIS;
            tmp->parent=-1;
            tmp->next=tmp1;
            graph[key2]=tmp;

            vertices[key1].name[0]=startnode[0],vertices[key1].name[1]=startnode[1],vertices[key1].name[2]='\0';
            vertices[key2].name[0]=endnode[0],vertices[key2].name[1]=endnode[1],vertices[key2].name[2]='\0';
            vertices[key1].dist=INF_DIS;
            vertices[key2].dist=INF_DIS;
            vertices[key1].parent=-1;
            vertices[key2].parent=-1;
        }
        scanf("%s%s",startnode,endnode);

        key1=(startnode[0]-65)*26+(startnode[1]-65);
        key2=(endnode[0]-65)*26+(endnode[1]-65);
        vertices[key1].name[0]=startnode[0],vertices[key1].name[1]=startnode[1],vertices[key1].name[2]='\0';
        vertices[key2].name[0]=endnode[0],vertices[key2].name[1]=endnode[1],vertices[key2].name[2]='\0';
        vertices[key1].dist=INF_DIS;
        vertices[key2].dist=INF_DIS;
        vertices[key1].parent=-1;
        vertices[key1].parent=-1;

        shortest_dist_label(graph,vertices,key1,key2);
        shortest_path_show(vertices,key2);
        tc++;
    }
	return 0;
}
