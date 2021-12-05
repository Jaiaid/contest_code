#include<stdio.h>

int main()
{
    int tc,D,N,ans[100],h[41],c[41],a[41],ac[41];
    while(1==scanf("%d",&tc))
    {
        int l;
        for(l=0;l<tc;l++) ans[l]=0;
        for(l=0;l<tc;l++)
        {
            int l1,l2,l3,l4,hi=0,ci=0,ai=0,aci=0;
            char genre[10];
            scanf("%d%d",&D,&N);
            for(l1=0;l1<N;l1++)
            {
                int temp;
                char name[41];
                scanf("%s%s%d",name,genre,&temp);
                if(genre[0]=='C'){
                    c[ci]=temp;
                    ci++;
                }
                else if(genre[0]=='H'){
                    h[hi]=temp;
                    hi++;
                }
                else if(genre[1]=='c'){
                    ac[aci]=temp;
                    aci++;
                }
                else{
                    a[ai]=temp;
                    ai++;
                }

            }
            if(!ai || !aci || !hi || !ci) continue;

            for(l1=0;l1<aci;l1++){
                int temp=ac[l1];
                if(temp>D) continue;
                for(l2=0;l2<ai;temp-=a[l2],l2++){
                    temp+=a[l2];
                    if(temp>D) continue;
                    for(l3=0;l3<ci;temp-=c[l3],l3++){
                        temp+=c[l3];
                        if(temp>D) continue;
                        for(l4=0;l4<hi;temp-=h[l4],l4++){
                            temp+=h[l4];
                            if(temp>ans[l] && temp<=D){
                                ans[l]=temp;
                            }
                        }

                    }
                }
            }

        }

        for(l=0;l<tc;l++)
        {
            if(ans[l]) printf("Case %d: %d\n",l+1,ans[l]);
            else printf("Case %d: Movie show canceled!\n",l+1);
        }
    }
    return 0;
}
