#include <stdio.h>
#include "chainloader.h"
#include "m1.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
	printf("usage: ./matryoshka key\n");
	return 0;
    }
    char key = argv[1][0] - 87;
    char* args[] = {"", argv[1]+1 };
    if (decrypt_run(m1, m1_len, key, args) == -1) {
	wrong();
    }
    return 0;

}

