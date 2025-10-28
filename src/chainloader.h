#ifndef CHAINLOADER_H
#define CHAINLOADER_H
#endif

#include <stdio.h>
#include <unistd.h>


void decrypt_buffer(char buf[], unsigned int lenbuf, unsigned char key);

int decrypt_run(char buffer[], unsigned int lenbuffer, unsigned char key, char* argv[]);

FILE* create_file(char buffer[],
		  unsigned int lenbuffer,
		  unsigned int flags);


int run(FILE* fp, char* name, char* argv[]);


void wrong();
