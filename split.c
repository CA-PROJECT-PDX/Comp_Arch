#include <stdlib.h>
#include <stdio.h>
#include<string.h>

char *remove_white_spaces(char *str)
{
	int i = 0, j = 0;
	while (str[i])
	{
		if (str[i] != ' ')
          str[j++] = str[i];
		i++;
	}
	str[j] = '\0';
	return str;
}

int main(int argc, char *argv[])
{
	char* fname;
	fname=argv[1];
	FILE *fp = fopen(fname, "r");
	char cr;
	size_t lines = 0;
	
	while( cr != EOF ) {
	if ( cr == '\n' ) {
		lines++;
	}
	cr = getc(fp);
	}
	rewind(fp);
	
	{
    char *data[lines];
    size_t n;
    char* addr[lines];
    char* inst[lines];
    char* token;
    for (size_t i = 0; i < lines; i++) {
      data[i] = NULL;
      size_t n = 0;

      getline(&data[i], &n, fp);
    }

    for (size_t i = 0; i < lines; i++) {
	remove_white_spaces(data[i]);
	 //printf("%s", data[i]);
    	addr[i] = strtok(data[i],":");
	
	inst[i] = strtok(NULL,":"); 
	
	printf("addr=%s,inst=%s",addr[i],inst[i]);
    }
	}
	
	fclose(fp);
	
	return 0;

}
