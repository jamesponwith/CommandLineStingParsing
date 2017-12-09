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
	char *cmdline_cp = strdup(cmdline);
	char *cmdline_args = strdup(cmdline);
	*bg = 0;
	unsigned int i = 0;
	
	char *token = strtok(cmdline_cp, " \n");
	while(token != NULL) {
		if(strcmp(token, "&") == 0) {
			*bg = 1;
			i--;
		}
		//cmdline_cp[i] = *token;
		i++;
		token = strtok(NULL, " \n");	
	}

	i += 1;
	char **argv = calloc(i, sizeof(char **));
	unsigned int z = 0;
	char *token2 = strtok(cmdline_args, " \n");
	while(token2 != NULL) {
		if(strcmp(token2, "&") == 0) {
			*bg = 1;
			z++;
			break;
		}	
		int size = strlen(token2);
		argv[z] = calloc(size, sizeof(char));
		strcpy(argv[z], token2);
		z++;
		token2 = strtok(NULL, " \n");
	}

	free(cmdline_cp);
	free(cmdline_args);
	
	argv[z] = NULL;
	return argv;
}
	
// TODO: implement the parseArgumentsDynamicFunction here
