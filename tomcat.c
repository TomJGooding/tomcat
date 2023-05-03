#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("tomcat: %s: No such file\n", argv[1]);
    } else {
        printf("Success! %s is a file!\n", argv[1]);
    }
    return EXIT_SUCCESS;
}
