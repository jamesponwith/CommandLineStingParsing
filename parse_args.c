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

// for parseArguments: a copy of the command line to make argv parm point to
// a static global variable means private to code in this file
static char cmdline_copy[MAXLINE];

int parseArguments(const char *cmdline, char **argv) {
	// TODO: implement this function
	return 0;
}

// TODO: implement the parseArgumentsDynamicFunction here
