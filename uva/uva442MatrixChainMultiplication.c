#include<stdio.h>
#define MATNUM 26
#define MAXEXPRLEN 512

int matrow[MATNUM];
int matcol[MATNUM];
int ans;
int valid;

struct multiplied_mat
{
    int row;
    int col;
    int indx_inc;
};

struct multiplied_mat expr_evaluate(char *expression);

int main()
{
    freopen("E:\\input.txt","r",stdin);
    freopen("E:\\output.txt","w",stdout);

    char name;
    char expression[MAXEXPRLEN];
    int n;
    int l,l1;

    scanf("%d",&n);
    getchar();
    for(l=0;l<n;l++)
    {
        name=getchar();
        name-='A';
        scanf("%d%d",&matrow[name],&matcol[name]);
        getchar();
    }

    while(1==scanf("%s",expression))
    {
        ans=0;
        valid=1;
        expr_evaluate(expression);
        if(valid) printf("%d\n",ans);
        else puts("error");
    }

    return 0;
}

struct multiplied_mat expr_evaluate(char *expression)
{
    if(!valid) return;

    struct multiplied_mat result,tmp;
    int indx=0;

    if(expression[0]=='(') result=expr_evaluate(&expression[1]);
    else{
        result.row=matrow[expression[0]-'A'];
        result.col=matcol[expression[0]-'A'];
        result.indx_inc=2;

        if(expression[1]>='A' && expression[1]<='Z'){
            if(result.col==matrow[expression[1]-'A']){
                ans+=result.row*result.col*matcol[expression[1]-'A'];
                result.col=matcol[expression[1]-'A'];
                result.indx_inc=3;
            }
            else valid=0;
        }
        return result;
    }

    if(valid){
        indx=result.indx_inc;
        if(expression[indx]==')' || expression[indx]=='\0'){
            result.indx_inc+=2;
            return result;
        }

        tmp=expr_evaluate(&expression[indx]);

        if(valid){
            ans+=result.row*result.col*tmp.col;
            result.col=tmp.col;
            result.indx_inc=indx+tmp.indx_inc+1;
        }

    }

    return result;
}
