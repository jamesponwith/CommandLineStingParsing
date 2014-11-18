CC = gcc
CFLAGS = -g -Wall -Werror
TARGETS = tester

all: $(TARGETS) 

tester : tester.c  parse_args.o
	$(CC) $(CFLAGS) -o $@ $^

# this is the command to build the parse_args library as a .o file
parse_args.o: parse_args.c parse_args.h
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(TARGETS) parse_args.o 
