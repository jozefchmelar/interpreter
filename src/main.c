#include <stdio.h> 
#include <string.h>
#include "commands/chod.h"
#include "commands/prezri.h"
#include "commands/cesty.h"
#include "commands/klonuj.h"
#include "commands/zahod.h"
#include "commands/znic.h"
#include "commands/preskumaj.h"
#include "commands/obsahvaku.h"

int main(int argc , const char* argv[] )
{ 
	 
	//	while(i != argc)
	//	{		    
        cesty();
        prezri();
        preskumaj("kamen");
        obsahvaku();
        prezri();


		//	printf("%s \n",cesty());	
			//obsah();
			      
//            ++i;
  //      }
 
    
	return 0;
}

