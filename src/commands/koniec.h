/*! \file  koniec.h
\brief  ukončí činnosť interpretra príkazov
\author Jozef Chmelar
*/
#include <stdio.h>
#include <stdlib.h>
/*! \brief exits interpreter
	exit.
*/ 
static inline int koniec()
{
	exit(EXIT_SUCCESS);
}