#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "commands.h"

int do_cd(int argc, char** argv) {
  
  if (!validate_cd_argv(argc, argv))
    return -1;
  
  else if(argc==2){
     if(chdir(argv[1])){
        printf("Can not such directory\n");
     }

   }
 
  return 0;
}

int do_pwd(int argc, char** argv) {
	char buf[50];
  if (!validate_pwd_argv(argc, argv))
    return -1;
	
	getcwd(buf,50);
        printf("%s\n",buf);
  

  return 0;
}

int validate_cd_argv(int argc, char** argv) {
	if(strcmp(argv[0],"cd"))
		return 0;
	if(argc==1){
   // chdir(getenv("HOME"));
	return 0;
 	}
	else if(argc > 2){
		return 0;
	}
	

  // TODO: Fill it!
  return 1;
}

int validate_pwd_argv(int argc, char** argv) {
	if (!strcmp(argv[0], "cd")) return 0;
	
	if (strcmp(argv[0], "pwd")){
		if(argc==1) 	return 1;
		else 		return 0;
		}		
	else{ if(argc == 1) return 1; 
		else return 0;
		}

	

  // TODO: Fill it!
  return 1;

}
