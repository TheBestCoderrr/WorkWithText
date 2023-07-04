#include <iostream>
#include <string.h>
#include "Sizes.h"
#include "FindCountStr.h"

void PrintTextWithLine(FILE* readid, FILE* writeid) {
	int countstr = FindCountStr(readid), integer = 0;
	bool endsymbol = true, space = false, isspace = true;
	char str[TEXTSIZE];
	fseek(readid, 0, SEEK_SET);
	while (integer < countstr) {
		fgets(str, TEXTSIZE, readid);
		for (int i = 0; i < strlen(str); i++) {
			if (str[i] == ' ') {
				space = true;
				isspace = false;
			}
		}
		fprintf(writeid, "%s", str);
		if (space) {
			fprintf(writeid, "------------\n");
			space = false;
		}
		integer++;
	}
	if(isspace)
		fprintf(writeid, "\n------------");
}