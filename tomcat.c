#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

#define PROGRAM_NAME "tomcat"

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; ++i) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf(
                "%s: %s: No such file or directory\n", PROGRAM_NAME, argv[i]
            );
            continue;
        }
        DIR *dp = opendir(argv[i]);
        if (dp != NULL) {
            printf("%s: %s: Is a directory\n", PROGRAM_NAME, argv[i]);
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
