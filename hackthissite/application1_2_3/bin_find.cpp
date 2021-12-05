#include<stdio.h>
#include<stdlib.h>

int main(int argc ,char **argv)
{
	if(argc<3){
		printf("give file and character count\n");
		return 0;
	}
	FILE *fp=fopen(argv[1],"rb");
	unsigned char buf[4096];
	int l,size,state,tmp,writelen=atoi(argv[2]);

	for(state=0,tmp=0,size=fread(buf,1,4096,fp);!feof(fp);size=fread(buf,1,4096,fp))
	{
		for(l=0;l<size;l++)
		{
			if(buf[l]=='p' && !state) state++;
			else if(buf[l]=='a' && state==1) state++;
			else if(buf[l]=='s' && state==2) state++;
			else if(buf[l]=='s' && state==3) state++;
			else if(buf[l]=='w' && state==4) state++;
			else if(buf[l]=='o' && state==5) state++;
			else if(buf[l]=='r' && state==6) state++;
			else if(buf[l]=='d' && state==7) state++;
			else if(state==8){
				for(;l<size && tmp<writelen;l++)
				{
					tmp++;
					putchar(buf[l]);
				}
				if(tmp==writelen){
					state=0;
					tmp=0;
				}
				puts("\n");
			}
			else state=0;
		}
	}
	return 0;
}
