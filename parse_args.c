/*
 * Implementation file for parse_args library.
 *
 * This class include two functions that take in command line 
 * arguments and parse them. The first simply tokenizes the 
 * arguments and tracks whether the command should be ran 
 * in the background or not. The second dynamically allocates
 * memory to each individual element of the char array.  
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parse_args.h"

/*
 * A copy of the command line to which you can make your argv array point.
 * 
 * Note: Use this ONLY in the parseArguments function; DO NOT use in the
 * parseArgumentsDynamic function.
 */
static char cmdline_copy[MAXLINE];
// Globals are evil

int parseArguments(const char *cmdline, char **argv) {
	unsigned int j;
	for(j = 0; j < sizeof(argv) - 1; j++) {
		argv[j] = NULL;
	}
	// Create copy of user command line arguments
	strcpy(cmdline_copy, cmdline);	 
	
	int ret = 0;
	char *token;
	char *remainder = cmdline_copy;
	char delim[] = " \n";
	unsigned int i = 0;
	while((token = strtok_r(remainder, delim, &remainder))) {
		if(strcmp(token, "&") == 0) {
			ret = 1;
			return ret;
		}
			//strcat(token, "\0");
			argv[i] = token; 
			i++;
	}
	return ret;
}



char **parseArgumentsDynamic(const char *cmdline, int *bg) {
	char cmdline_cp[strlen(cmdline)];
	strcpy(cmdline_cp, cmdline);	 

	//*bg = 0;	
	char *token;
	char *remainder = cmdline_cp;
	char delim[] = " \n";
	unsigned int i = 0;
	int size = 0;	
	char **argv = malloc(sizeof(char *));
	while((token = strtok_r(remainder, delim, &remainder))) {
		if(strcmp(token, "&") == 0) {
			*bg = 1;
			return argv;
		}	
		size = strlen(token);
			*argv = realloc(*argv, (size + 1));
		//	strcat(token, "\0");

		argv[i] = token;
		printf("%s%d\n", "Strlen =", size );
		//argv[i] = realloc(*argv, size); 	
		i++;
		printf("argv = %s,  Address = %p\n", argv[i-1], &argv);
	}
	//argv[i + 1] = NULL;
	//*argv = realloc(argv, size);
	//size += 1;
	//*argv = realloc(*argv, size + 1);
	//argv[sizeof(*argv) - 1] = NULL;	
	return argv;
}	
	



// TODO: implement the parseArgumentsDynamicFunction here
/*
char **parseArguementsDynamic(const char *cmdline, int *bg) {
	printf("Parsing Dynamically\n");
	unsigned int i = 0;
	char cmdline_cpy[strlen(cmdline)];
	for(i = 0; i < strlen(cmdline); ++i) {
		cmdline_cpy[i] = cmdline[i];
		if(cmdline[i] == '&') {
			cmdline_cpy[i] = '&';
			*bg = 1;
			break;	
		}
		if(cmdline[i] == '\n') {
			cmdline_cpy[i] = '\0';
			break;
		}
	}
	printf("cmdline copy %s\n", cmdline_cpy);
	char *cmdline_args = strtok(cmdline_cpy, " ");
	i = 0;
	char **argv = malloc(sizeof(char *));
	if(cmdline_args != NULL) {
		while(cmdline_args) {
			argv[i] = malloc(sizeof(cmdline_args));
			printf("%s\n", cmdline_args);
			strcpy(argv[i], cmdline_args);
			printf("%s\n", cmdline_args);
			cmdline_args = strtok(NULL, " ");
			printf("%d\n", (int) sizeof(argv));
			i++;
			if(cmdline_args == NULL) {
				break;
			}
			return argv;
		}
	}
	else {
		return NULL;
	}
}
*/
