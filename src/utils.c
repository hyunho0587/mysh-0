#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
	char *token;
	int i=0;

	char ptr[8096];

	strcpy(ptr, command);

	argv[0] = (char**)malloc(sizeof(char*)*6);
	//argv[0][0]= (char*)malloc(sizeof(char)*40*3);
	//memset(*argv[0], 0, sizeof(*argv));
	for(int a =0; a<6; a++)
	{
		argv[0][a]= (char*)malloc(sizeof(char)*40);
	}
	token = strtok(ptr, " \n\t");
	if(token == NULL){
		i=1;
		strcpy(argv[0][0],"");
	}
	while(token != NULL)
	{	
		
		strcpy(argv[0][i], token);
		//printf("%s\n", *argv[i]);
		i++;
		token = strtok(NULL, " \t\n");
	}
	*argc=i; 

}
