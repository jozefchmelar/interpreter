#include <string.h>
#include <pwd.h>


static inline int isCommand(const char* totest) {
	char *commands[] = {"cesty", "chod", "hmotnostvaku", "klonuj", "koniec", "obsahvaku", "poloz", "preskumaj", "prezri", "zahod", "znic", "help","zober"};
	int count  = sizeof(commands) / sizeof(commands[0]);

	for (int i = 0; i < count; ++i)
	{
		if (strcmp(commands[i], totest) == 0) return 0;
	}
	return 1;
}

static inline int hasParameter(const char* totest) {
	char *commands[] = {"chod", "klonuj", "poloz", "preskumaj", "zahod", "znic", "zober"};
	int count  = sizeof(commands) / sizeof(commands[0]);

	for (int i = 0; i < count; ++i)
	{
		if (strcmp(commands[i], totest) == 0) return 0;
	}
	return 1;
}


static inline char** split( char *str) {
	char ** res  = NULL;
	char *  p    = strtok (str, " ");
	int n_spaces = 0, i;
	/* split string and append tokens to 'res' */
	while (p) {
		res = realloc (res, sizeof (char*) * ++n_spaces);

		if (res == NULL)
			exit (-1); /* memory allocation failed */

		res[n_spaces - 1] = p;

		p = strtok (NULL, " ");
	}
	/* realloc one extra element for the last NULL */
	res = realloc (res, sizeof (char*) * (n_spaces + 1));
	res[n_spaces] = 0;
	return res;
}

static inline void help() {
	 char *test =
	#include "help.txt"
	 ;
	 printf("%s\n", test);
	// int c;
	// FILE *file;
	// file = fopen("help.txt", "r");
	// if (file) {
	// 	while ((c = getc(file)) != EOF)
	// 		putchar(c);
	// 	fclose(file);
	// }
}

static inline const char *getUserName()
{
  uid_t uid = geteuid();
  struct passwd *pw = getpwuid(uid);
  if (pw)
  {
    return pw->pw_name;
  }

  return "";
}