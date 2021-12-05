#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node *l;
    struct node *r;
};

void postorder(struct node *headaddrs)
{
    if(headaddrs->l) postorder(headaddrs->l);
    if(headaddrs->r) postorder(headaddrs->r);
    printf("%d\n",headaddrs->key);
}

int main()
{
    struct node head,*par;
    int key;
    scanf("%d",&key);
    head.key=key;
    head.l=NULL;
    head.r=NULL;
    while(1==scanf("%d",&key))
    {
        par=&head;
        int flag=2;
        while(flag==2)
        {
            if(key<par->key)
            {
                if(par->l) par=par->l;
                else{
                    flag=0;
                    break;
                }
            }
            else{
                if(par->r) par=par->r;
                else{
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0){
            par->l=(struct node *)malloc(sizeof(struct node));
            par=par->l;
            par->key=key;
            par->l=NULL;
            par->r=NULL;
        }
        else{
            par->r=(struct node *)malloc(sizeof(struct node));
            par=par->r;
            par->key=key;
            par->l=NULL;
            par->r=NULL;
        }
    }

    postorder(&head);
    return 0;
}
