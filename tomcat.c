#include <stdio.h>
#include <stdlib.h>

#define PROGRAM_NAME "tomcat"

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; ++i) {
        int c;
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("%s: %s: No such file\n", PROGRAM_NAME, argv[i]);
            continue;
        }
        while ((c = getc(fp)) != EOF) {
            putchar(c);
        }
        fclose(fp);
    }
    return EXIT_SUCCESS;
}
