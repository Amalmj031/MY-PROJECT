#include "header.h"

void cmd_rmv(FILE *f1 , FILE *f2)
{
	char c, s;

	while ((c = fgetc(f1)) != EOF)
	{
		if (c == '/')
		{
			s = fgetc(f1);

			// single line comment
			if (s == '/')
			{
				while ((c = fgetc(f1)) != '\n' && c != EOF);
				if (c == '\n') fputc('\n', f2);   // preserve newline
			}
			// multi line comment
			else if (s == '*')
			{
				while ((c = fgetc(f1)) != EOF)
				{
					if (c == '*' && (s = fgetc(f1)) == '/')
						break;   // end of comment
				}
			}
			// Not a comment - output both chars
			else
			{
				fputc('/', f2);
				fputc(s, f2);
			}
		}
		else
		{
			fputc(c, f2);  // normal char
		}
	}
}
