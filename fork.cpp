#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main() {
|   pid_t pid;
    pid = fork();
    char *argc[] = {NULL};
    if (pid == 0) {
        printf("it is children\n");
        execve("./hello.out", argc, NULL);
        printf("errno ： %d", errno);
    } else if (pid < 0) {
        printf("it is wrong\n");
    } else {
        execve("./hello_1.out", argc, NULL);
        printf("it is father\n");
    }
    sleep(5);
    printf("progrem 1 success\n");
    return 0;
}
