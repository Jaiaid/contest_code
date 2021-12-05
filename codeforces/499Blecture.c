#include<stdio.h>
#include<stdlib.h>

typedef struct dictionary{
    char wrd1[11];
    char wrd2[11];
    struct dictionary *next;
} container;


container *heads[26];

int len(char *wrd)
{
    int l;
    for(l=0;*wrd;wrd++,l++);
    return l;
}

container* insert(int indx,char *wrd1,char *wrd2)
{
    int l;
    container* temp;

    if(heads[indx]==NULL){
        heads[indx]=(container *)malloc(sizeof(container));
        temp=heads[indx];
    }
    else{
        for(temp=heads[indx];temp->next!=NULL;temp=temp->next);
        temp->next=(container *)malloc(sizeof(container));
        temp=temp->next;
    }

    for(l=0;*wrd1;temp->wrd1[l]=*wrd1,l++,wrd1++);
    temp->wrd1[l]='\0';
    for(l=0;*wrd2;temp->wrd2[l]=*wrd2,l++,wrd2++);
    temp->wrd2[l]='\0';
    temp->next=NULL;

    return temp;
}

container* find(container* head,char *wrd1)
{
    container *temp;

    for(temp=head;temp!=NULL;temp=temp->next)
    {
        int l;
        for(l=0;wrd1[l] && temp->wrd1[l] && temp->wrd1[l]==wrd1[l];l++);
        if(wrd1[l]==temp->wrd1[l]) break;
    }

    return temp;
}


int main()
{
    int n,m,l;

    while(2==scanf("%d%d",&n,&m))
    {
        char tmp[11],tmp1[11];
        int l1,l2,indx;
        container *temp;

        for(l=0;l<26;heads[l]=NULL,l++);

        for(l=0;l<m;l++)
        {
            scanf("%s%s",tmp,tmp1);

            insert(tmp[0]-'a',tmp,tmp1);
            insert(tmp1[0]-'a',tmp1,tmp);
        }

        for(l=0;l<n;l++)
        {
            scanf("%s",tmp);
            temp=find(heads[tmp[0]-'a'],tmp);

            if(len(tmp)>len(temp->wrd2)) printf("%s ",temp->wrd2);
            else printf("%s ",tmp);
        }
        putchar('\n');
    }
    return 0;
}
