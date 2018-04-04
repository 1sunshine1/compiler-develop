#include <stdio.h>
#include <string.h>
int main() {
    FILE *fp1 = fopen("2.text", "w");
    int len;
    FILE *fp = fopen("1.text", "w");
    if (fp == 0) {
        printf("can't open 1.text\n");
        return 0;
    }
    if (fp1 == 0) {
        printf("can't open 2.text\n");
        return 0;
    }
    fseek(fp, 0, SEEK_END);
    len = ftell(fp);
    fseek(fp1, 0, SEEK_SET);
    fwrite(fp, len, 1, fp1);
    fclose(fp);
    fclose(fp1);
    return 0;
}
