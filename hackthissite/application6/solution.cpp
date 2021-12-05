#include<stdio.h>

int main()
{
	int temp,size=0x33;
	FILE *fin=fopen("app6win.exe","rb");
	FILE *fout=fopen("app6win.exe","rb+");
	fseek(fin,4284+0x17,SEEK_SET);
	fseek(fout,4284+0x17,SEEK_SET);

	while(size)
	{
		fread(&temp,4,1,fin);
		temp^=0xbeefcabe;
		fwrite(&temp,4,1,fout);
		size--;
	}
	return 0;
}
