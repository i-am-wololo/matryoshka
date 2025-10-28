#include "chainloader.h"
#include "m3.h"

// 3rd layer

int main(int argc, char* argv[]) {
    char key = argv[1][0] - '0';
    char* args[] = {"", argv[1]+1 };
    if (decrypt_run(m3, m3_len, key, args) == -1) {
	wrong();
    }
    return 0;
    

}

