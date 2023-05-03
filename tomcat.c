#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; ++i) {
        int c;
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("tomcat: %s: No such file\n", argv[i]);
            continue;
        }
        while ((c = getc(fp)) != EOF) {
            putchar(c);
        }
        fclose(fp);
    }
    return EXIT_SUCCESS;
}
