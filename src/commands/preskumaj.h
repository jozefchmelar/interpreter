#include <stdio.h>
#include <stdlib.h>

static inline int preskumaj(const  char *predmet)
{
	printf("\n------------\n");
	FILE *f;
	char c;
	f = fopen(predmet, "rt");

	while ((c = fgetc(f)) != EOF) {
		printf("%c", c);
	}
	printf("------------\n");
	return 0;
}
