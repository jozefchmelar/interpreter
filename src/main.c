#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "commands/chod.h"
#include "commands/prezri.h"
#include "commands/cesty.h"
#include "commands/klonuj.h"
#include "commands/zahod.h"
#include "commands/znic.h"
#include "commands/preskumaj.h"
#include "commands/obsahvaku.h"
#include "commands/zober.h"

int main(int argc , const char* argv[] )
{

	//	while(i != argc)
	//	{
	// mode r w execute user.
	mkdir("/tmp/VAK/", S_IRWXU );
	cesty();
	prezri();

	klonuj("znacka");
	obsahvaku();


	return 0;
}

