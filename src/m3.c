#include <stdlib.h>
#include <stdio.h>
#include "chainloader.h"

int main(int argc, char* argv[]) {
	   if (debug() == 1) {
	return 0;
	   }
    if (atoi(argv[1]) == 9) {
	printf("u win good job!!!!\n");
    }
    else {
	wrong();
    }
    return 0;

}
