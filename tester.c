/**
 * Tester program for COMP 280 Project08 (argument parsing library)
 *
 * Add your top-level comment here.
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> 
#include "parse_args.h"

// static methods are local to this module
static void printCommandArgs(char *cmdline, char **argv );
static void printBG(int bg) ;

int main() { 

	while(1) {
		// (1) print the shell prompt
		printf("Enter a line to parse, or enter \"quit\" to stop: ");
		fflush(stdout);

		// (2) read in the next command
		char cmdline[MAXLINE];
		if ((fgets(cmdline, MAXLINE, stdin) == NULL) && ferror(stdin))
			perror("fgets error");

		if (feof(stdin)) { /* End of file (ctrl-d) */
			fflush(stdout);
			exit(0);
		}

		char *argv[MAXARGS];
		int bg = parseArguments(cmdline, argv);

		if((argv[0] != NULL) && (strcmp(argv[0], "quit") == 0) ){
			break;
		}
		printCommandArgs(cmdline, argv);
		printBG(bg);


		char **args = NULL;
		bg = 0; // clear bg flag

		// TODO: Uncomment this call to test parseArgsDynamic after you have it
		// implemented.
		 args = parseArgumentsDynamic(cmdline, &bg);
		if(args) {
			printCommandArgs(cmdline, args);
			printBG(bg);
			// TODO: add code to free all malloc'ed state associated  
			//       with the call to parse_cmd_dynamic
		}
	}
	return 0;
}

/**
 * This function prints out a message based on the value of bg
 * indicating if the command is run in the background or not
 */
void printBG(int bg) {
	if(bg) { 
		printf("run in the background is true\n");
	} else { 
		printf("run in the background is false\n");
	}
}

/**
 * This function prints out the cmdline and argv list
 * @param cmdline The command line string
 * @param argv The argv list of command line argumetns string
 */
void printCommandArgs(char *cmdline, char **argv ) {
	printf("\nCommand line: %s\n", cmdline);

	unsigned i=0;
	while (argv[i] != NULL) {
		// note: I'm printing out each argv string between # chars
		//       so that I can see if I have left any space or other 
		//       invisible characters in an argv[i] string (I shouldn't)
		printf("%3d  #%s#\n", i, argv[i]);
		i++;
	}
}
