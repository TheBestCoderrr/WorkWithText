#include <iostream>

void CopyText(FILE* readid, FILE* writeid) {
	char letter;
	while (true) {
		letter = fgetc(readid);
		if (letter == EOF)
			break;
		fprintf(writeid, "%c", letter);
	} 
}