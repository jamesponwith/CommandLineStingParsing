/*
 * Implementation file for parse_args library.
 *
 * Add your top-level comments here.
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

// Note: you should NOT declare any other global variables.

int parseArguments(const char *cmdline, char **argv) {
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

		

/*
		int index = sizeof(token) - 1;
		if(strcmp(token[index], "\n") == 0) {
			token[sizeof(token) - 1] = 0;
		}
	*/	
			strcat(token, "\0");
			printf(" %d: %s\n", i, token);
			argv[i] = token; 
			i++;
	}

//	printf("%s\n", *argv); 	
	// if "&" then set bg to 1 
	
	return ret;
}

// TODO: implement the parseArgumentsDynamicFunction here

/*
char **parseArguementsDynamic(const char *cmdline, int *bg) {
	printf("Parsing**\n");
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
