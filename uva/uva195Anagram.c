#include<stdio.h>
#define MAXLEN 501

char str[MAXLEN];
char color[MAXLEN];
int len;


void anagram(char word[],char graph[][MAXLEN],int prsntrow,int depth)
{
    int l;
    char char_visited[52];
    if(depth+1==len){
        str[depth+1]='\0';
        puts(str);
        return;
    }

    for(l=0;l<52;l++) char_visited[l]='\0';

    for(l=0;l<len;l++)
    {
        if(color[l]) continue;
        else if(word[l]<='Z' && word[l]>='A' && char_visited[word[l]-'A']){
            continue;
        }
        else if(word[l]<='z' && word[l]>='a' && char_visited[word[l]-'a'+26]){
            continue;
        }
        else if(word[l]<='Z' && word[l]>='A' && graph[prsntrow][l]){
            char_visited[word[l]-'A']=1;
        }
        else if(word[l]<='z' && word[l]>='a' && graph[prsntrow][l]){
            char_visited[word[l]-'a'+26]=1;
        }

        if(graph[prsntrow][l]){
            color[l]=(char)(1);
            str[depth+1]=word[l];
            anagram(word,graph,l,depth+1);
            color[l]='\0';
        }
    }
    return ;
}

int main()
{
    char word[MAXLEN];
    char graph[MAXLEN][MAXLEN];
    int n;
    int l,l1,l2,tmpi;
    char tmpc;

    while(1==scanf("%d",&n))
    {
        for(l=0;l<n;l++)
        {
            scanf("%s",word);
            for(len=0;word[len];len++);

            for(l1=0;l1<len;l1++)
            {
                tmpi=len-l1;
                for(l2=1;l2<tmpi;l2++)
                {
                    if((word[l2]<='z' && word[l2]>='a') && (word[l2-1]<='z' && word[l2-1]>='a')){
                        if(word[l2]<word[l2-1]){
                            tmpc=word[l2-1];
                            word[l2-1]=word[l2];
                            word[l2]=tmpc;
                        }
                    }
                    else if((word[l2]<='Z' && word[l2]>='A') && (word[l2-1]<='Z' && word[l2-1]>='A')){
                        if(word[l2]<word[l2-1]){
                            tmpc=word[l2-1];
                            word[l2-1]=word[l2];
                            word[l2]=tmpc;
                        }
                    }
                    else if((word[l2]<='z' && word[l2]>='a') && (word[l2-1]<='Z' && word[l2-1]>='A')){
                        tmpc =word[l2]-'a'+'A';
                        if(tmpc<word[l2-1]){
                            tmpc=word[l2-1];
                            word[l2-1]=word[l2];
                            word[l2]=tmpc;
                        }
                    }
                    else if((word[l2]<='Z' && word[l2]>='A') && (word[l2-1]<='z' && word[l2-1]>='a')){
                        tmpc =word[l2]-'A'+'a';
                        if(tmpc<=word[l2-1]){
                            tmpc=word[l2-1];
                            word[l2-1]=word[l2];
                            word[l2]=tmpc;
                        }
                    }
                }
            }

            for(l1=0;l1<len;l1++)
            {
                color[l1]='\0';
                for(l2=0;l2<len;l2++)
                {
                    if(l2!=l1) graph[l1][l2]=(char)(1);
                    else graph[l1][l2]='\0';
                }
            }

            for(l1=0;l1<len;l1++)
            {
                for(l2=0;l2<l1 && word[l1]!=word[l2];l2++);
                if(l2==l1){
                    color[l1]=(char)(1);
                    str[0]=word[l1];
                    anagram(word,graph,l1,0);
                    color[l1]='\0';
                }
            }
        }
    }
    return 0;
}
