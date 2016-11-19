#include <stdio.h>
#include <stdlib.h>

int preskumaj(char *predmet) {
    printf("skumaj:\t%s\n\t", predmet );
    FILE *f;
    char c;
    f = fopen(predmet, "rt");

    while ((c = fgetc(f)) != EOF) {
        printf("%c", c);
    }
}
