
#define _GNU_SOURCE
#include <stdio.h>
#include "chainloader.h"



int main() {
    char* string = "hello world";
    printf("%s\n", string);
    string++;
    printf("%s", string++);
    return 0;    
}

