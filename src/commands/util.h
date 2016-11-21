#include <string.h>


int isCommand(const char* totest) {
	char *commands[] = {"cesty", "chod", "hmotnostvaku", "klonuj", "koniec", "obsahvaku", "poloz", "preskumaj", "prezri", "zahod", "znic", "zober"};
	int count  = sizeof(commands) / sizeof(commands[0]);

	for (int i = 0; i < count; ++i)
	{
		if (strcmp(commands[i], totest) == 0) return 0;
	}
	return 1;
}

int hasParameter(const char* totest) {
	char *commands[] = {"chod", "klonuj", "poloz", "preskumaj", "zahod", "znic", "zober"};
	int count  = sizeof(commands) / sizeof(commands[0]);

	for (int i = 0; i < count; ++i)
	{
		if (strcmp(commands[i], totest) == 0) return 0;
	}
	return 1;
}