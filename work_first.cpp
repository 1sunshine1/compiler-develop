#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>

int main() {
    char *data = (char *)malloc(sizeof(char) * 900000);
    FILE *fp = fopen("./hello.out", "rb");
    struct stat buf;
    char *str = (char *)0x0000000000400000;
    char *str1 = (char *)0x0000000000600000;
    stat("./hello.out", &buf);
    int num = buf.st_size;
    printf("size num = %d\n", num);
    size_t test_num = fread(data, 1, num, fp);
    printf("test_num = %d\n", test_num);
    char *p = (char *)mmap(str, 1000000, PROT_READ|PROT_WRITE|PROT_EXEC, MAP_FIXED|MAP_ANON|MAP_PRIVATE, -1, 0); //open up a reserved place to use.
    printf("mmap1 test\n");
    char *q = (char *)mmap(str1, 1000000, PROT_READ|PROT_WRITE|PROT_EXEC, MAP_FIXED|MAP_ANON|MAP_PRIVATE, -1, 0); //open up a reserved place to use.
    printf("mmap test\n");
//    printf("realloc new test: 1:%p , 2:%p", p, q);
    char *str2 = (char *)memcpy((char *)0x0000000000400000, data, 782497);//put .text(a00e10 + 440) to execute address
    char *str3 = (char *)memcpy((char *)0x00000000006bfeb0, data + 786096, 7552);//put .data(a00e10 + 1030) to execute address
//    printf("str3:%p", str3);
    printf("memcpy test\n");
    printf("hello dipingxian\n");

    __asm__ (
        "CALL 0x040105e"
    );
//    printf("errno = %d", errno);
    return 0;
}
