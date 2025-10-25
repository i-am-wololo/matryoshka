#include "chainloader.h"
#include "m3.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
    if (debug() == 1) return 0;
    char* string = argv[1];
    if (string[0] == '1') {
	printf("correct!");
	string++;
	char* args[] = {"test", string};
	decrypt_run(m3, m3_len, 2, args);
    } else {
	wrong();
    }
}

