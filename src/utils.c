#include <string.h>

int is_elf(char buffer[]) {
    if (strcmp(buffer, "\x7F" "ELF") == 0) {
	return 1;
    }
    return 0;
}
