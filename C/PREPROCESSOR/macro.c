#include "header.h"

void macro(FILE *f1, FILE *f2)
{
	int count=0, c=0, l=0, i=0, j=0, line=0;
	int ch, s=0, l1=0;

	// First pass: count lines, longest line, etc.
	while((ch=fgetc(f1))!=EOF)
	{
		if(ch=='\n') line++;
		if(ch!='\n') l1++;
		else { if(l<l1) l=l1; l1=0; }

		if(ch!=' ' && ch!='\n') s++;
		else { if(c<s) c=s; s=0; }
	}

	rewind(f1);

	// Allocate space for each line
	char **new = malloc(sizeof(char*) * line);
	for(i=0;i<line;i++)
		new[i] = malloc(l+10);

	i=0;
	while(i<line && fgets(new[i], l+10, f1)!=NULL)
		i++;

	rewind(f1);

	char old[l+20], s1[50], s2[100];

	while(fgets(old,sizeof(old),f1)!=NULL)
	{
		i=0; j=0; count=0;
		s1[0]='\0'; s2[0]='\0';

		if (strncmp(old, "#define", 7) == 0)
		{
			i=7;
			while(old[i]==' '||old[i]=='\t') i++;
			count=1;

			while(old[i]!='\n' && old[i]!='\0')
			{
				if(old[i]==' ' || old[i]=='\t')
				{
					if(count==1) { s1[j]='\0'; j=0; count=2; }
					else if(count==2) { s2[j]='\0'; break; }
				}
				else
				{
					if(count==1) s1[j++]=old[i];
					else if(count==2) s2[j++]=old[i];
				}
				i++;
			}
			if(count==1) s1[j]='\0';
			else if(count==2) s2[j]='\0';

			// Now search through stored lines
			for (i = 0; i < line; i++)
			{
				if (strncmp(new[i], "#define", 7) == 0)
					continue;

				char temp[500];
				int k = 0, p = 0;

				while (new[i][p] != '\0')
				{
					// if macro name matches at this position
					if (strncmp(&new[i][p], s1, strlen(s1)) == 0)
					{
						strcpy(&temp[k], s2);           // copy macro body
						k += strlen(s2);
						p += strlen(s1);                // skip macro name
					}
					else
					{
						temp[k++] = new[i][p++];        // copy normal char
					}
				}

				temp[k] = '\0';
				strcpy(new[i], temp);                   // update line
			}

		}
	}

	for(i=0;i<line;i++)
		fputs(new[i],f2);
	return ;
}
