#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; ++i) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("tomcat: %s: No such file\n", argv[i]);
            continue;
        }
        printf("Success! %s is a file!\n", argv[i]);
        fclose(fp);
    }
    return EXIT_SUCCESS;
}
