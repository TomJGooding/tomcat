#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

#define PROGRAM_NAME "tomcat"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [FILE]...\n", PROGRAM_NAME);
        fprintf(stderr, "Concatenate FILE(s) to standard output.\n");
        return EXIT_FAILURE;
    }
    for (int i = 1; i < argc; ++i) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            fprintf(
                stderr,
                "%s: %s: No such file or directory\n",
                PROGRAM_NAME,
                argv[i]
            );
            continue;
        }
        DIR *dp = opendir(argv[i]);
        if (dp != NULL) {
            fprintf(stderr, "%s: %s: Is a directory\n", PROGRAM_NAME, argv[i]);
            closedir(dp);
            continue;
        }
        int c;
        while ((c = getc(fp)) != EOF) {
            putchar(c);
        }
        fclose(fp);
    }
    return EXIT_SUCCESS;
}
