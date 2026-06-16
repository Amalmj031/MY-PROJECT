#include "header.h"

int main(int argc , char **argv)
{
	if(argc != 2)
	{
		printf("\n ./a.out file name \n");
		return 0;
	}

	FILE *f1=fopen(argv[1],"r");
	FILE *f2=fopen("file1.c","w");
	cmd_rmv(f1 ,f2);
	fclose(f2);
	fclose(f1);

	f1=fopen(argv[1],"r");
	f2=fopen("file2.c","w");
	macro(f1,f2);
	fclose(f1);
	fclose(f2);

	f1=fopen(argv[1],"r");
	f2=fopen("file3.c","w");
	header_include(f1,f2);
	fclose(f1);
	fclose(f2);

	printf("\ncmt remover \n");

	return 0;
}
