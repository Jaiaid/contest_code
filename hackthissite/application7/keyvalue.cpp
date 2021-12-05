#include<stdio.h>

int main()
{
	char buf[6];
	unsigned int a,b,c,d;
	int l,l1;
	FILE *fp=fopen("encrypted.enc","rb");

	fread(buf,6,1,fp);

	for(a=0;a<2000;a++)
	{
		b=0,c=0,d=0;
		b=(a^(buf[0]&0xff))+(a^(buf[1]&0xff))+(a^(buf[2]&0xff))+(a^(buf[3]&0xff))+(a^(buf[4]&0xff));
		if(b==0xdca){
			printf("%d\n",a);
		}
	}
	fclose(fp);
	return 0;
}
