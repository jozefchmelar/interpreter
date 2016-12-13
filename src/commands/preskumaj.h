/*! \file  preskumaj.h
\brief  popise daný predmet
\author Jozef Chmelar
*/
#include <stdio.h>
#include <stdlib.h>
/*! \brief prints content of file
  
*/ 
static inline int preskumaj(const  char *predmet)
{	
		FILE *f;
		char c;
		// This function returns a FILE pointer. 
		// Otherwise, NULL is returned and the global variable errno is 
		// set to indicate the error.	
		f = fopen(predmet, "r");
		if(f){

			while ((c = fgetc(f)) != EOF) {
				printf("%c", c);
			}
		fclose(f);

		}else{
			printf("No such file\n");
		}
	
	return 0;
}
