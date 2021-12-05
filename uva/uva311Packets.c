#include<stdio.h>

int main()
{
    int box[8],ans;
    int l,area;
    box[7]=1;
    while(6==scanf("%d%d%d%d%d%d",&box[1],&box[2],&box[3],&box[4],&box[5],&box[6]))
    {
        for(l=1;!box[l];l++);
        if(l==7) break;

        ans=box[6];
        ans+=(box[3]>>2);
        box[3]&=3;

        if(box[5]){
            ans+=box[5];
            if(box[1]>=11*box[5]) box[1]-=11*box[5];
            else box[1]=0;
        }

        if(box[4]){
            ans+=box[4];
            area=20*box[4];
            if(box[2]>=5*box[4]){
                box[2]-=5*box[4];
                area=0;
            }
            else{
                area-=(box[2]<<2);
                box[2]=0;
            }
            if(box[1]>area) box[1]-=area;
            else box[1]=0;
        }

        if(box[3]){
            ans++;
            if(box[3]==3){
                area=9;
                if(box[2]){
                    box[2]--;
                    area=5;
                }
            }
            else if(box[3]==2){
                area=18;
                if(box[2]>3){
                    box[2]-=3;
                    area=6;
                }
                else{
                    area-=(box[2]<<2);
                    box[2]=0;
                }
            }
            else{
                area=27;
                if(box[2]>5) box[2]-=5,area=7;
                else area-=(box[2]<<2),box[2]=0;
            }

            if(box[1]>area) box[1]-=area;
            else box[1]=0;
        }

        if(box[2]){
            ans+=box[2]/9;
            box[2]%=9;
            area=36;
            if(box[2]){
                ans++;
                area=36-(box[2]<<2);
            }
            if(box[1]>area) box[1]-=area;
            else box[1]=0;
        }

        if(box[1]){
            ans+=box[1]/36;
            box[1]%=36;
            if(box[1]) ans++;
        }

        printf("%d\n",ans);
    }
    return 0;
}

