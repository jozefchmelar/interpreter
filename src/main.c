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
#include "commands/koniec.h"
#include "commands/hmotnostvaku.h"

int main(int argc , const char* argv[] )
{
	printf("\n----\nSTART\n----\n\n");

	//	while(i != argc)
	//	{
	// mode r w execute user.
	mkdir("/tmp/VAK/", S_IRWXU );
	chod("nemocnica");
	prezri();
	klonuj("liek");
	hmotnostvaku();
	zahod("liek");
	hmotnostvaku();
	prezri();
	znic("liek");
	prezri();
	

	koniec();
	//TODO make every command execute in separate thread
	return 0;
}

