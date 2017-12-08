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
