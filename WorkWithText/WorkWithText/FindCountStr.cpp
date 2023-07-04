#include <iostream>
int FindCountStr(FILE* text) {
	char letter;
	int countstr = 1;
	do {
		letter = fgetc(text);
		if (letter == '\n')
			countstr++;
	} while (letter != EOF);
	return countstr;
}