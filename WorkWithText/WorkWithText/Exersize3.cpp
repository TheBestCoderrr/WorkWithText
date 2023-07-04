#include <iostream>
#include "Sizes.h"
#include "FindCountStr.h"

void ReflectText(FILE* readid, FILE* writeid) {
	char str[TEXTSIZE], letter;
	fseek(readid, 0, SEEK_SET);
	int countstr = FindCountStr(readid);
	int counter = 0;
	fseek(readid, 0, SEEK_END);
	do {
		letter = fgetc(readid);
		fseek(readid, -2, SEEK_CUR);
		counter++;
	} while (letter != '\n');
	fseek(readid, 2, SEEK_CUR);
	fgets(str, TEXTSIZE, readid);
	fprintf(writeid, "%s\n", str);
	fseek(readid, -counter - 2, SEEK_CUR);
	counter = 0;

	for (int i = 0; i < countstr - 2; i++) {
		do {
			letter = fgetc(readid);
			fseek(readid, -2, SEEK_CUR);
			counter++;
		} while (letter != '\n');
		fseek(readid, 2, SEEK_CUR);
		fgets(str, TEXTSIZE, readid);
		fprintf(writeid, "%s", str);

		fseek(readid, -counter-4, SEEK_CUR);
		counter = 0;
	}
	fseek(readid, 0, SEEK_SET);
	fgets(str, TEXTSIZE, readid);
	fprintf(writeid, "%s", str);
}