#include<stdio.h>
#include<string.h>

void header_include(FILE *tp1, FILE *tp2)
{
	int i;
	char *p;
	char s[200], header[100], line[200];

	while(fgets(s, 199, tp1))
	{
		p = 0;
		if(p = strstr(s, "#include"))
		{
			if(s[8] == '<')
			{
				strcpy(header, "/usr/include/");
				i = 13;
			}
			else if(s[8] == '"')
			{
				i = 0;
			}

			p += 9;
			while(!(*p == '>' || *p == '"'))
			{
				header[i] = *p;
				p++;
				i++;
			}
			header[i] = '\0';

			FILE *hp = fopen(header, "r");
			if(hp == 0)
			{
				printf("header file not found\n");
				return;
			}

			while(fgets(line, 199, hp))
				fputs(line, tp2);
			fputc('\n', tp2);
		}
		else
			fputs(s, tp2);
	}
}
