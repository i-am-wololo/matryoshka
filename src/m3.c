#include <stdlib.h>
#include <stdio.h>
#include "chainloader.h"

// final layer

int main(int argc, char* argv[]) {
    if (atoi(argv[1]) == 9) {
	printf("u win good job!!!!\n");
    }
    else {
	wrong();
    }
    return 0;

}
