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
	// TODO: implement this function
	return 0;
}

// TODO: implement the parseArgumentsDynamicFunction here


char **parseArguementsDynamic(const char *cmdlinem int *bg) {
	printf("Parsing**\n");
	unsigned int i = 0;
	char cmdline_copy[strlen(cmdline)];
	for(i = 0; i < strlen(cmdline); ++i) {
		cmdline_copy[i] = cmdline[i];
		if(cmdline[i] == "&") {
			
		}
	}
}
