#include <iostream>
#include <string.h>

void PrintBigWords(FILE* readid, FILE* writeid) {
    int countletters = 0;
    char letter, pattern[] = { " \n.,!?[]{}()@$%^&*<>\\|/;:\'\"`=+_"};
    bool syntaxis = true;
    do
    {
        do {
            letter = fgetc(readid);
            for (int i = 0; i < strlen(pattern); i++) {
                if (letter == pattern[i] || letter == EOF) {
                    syntaxis = false;
                    break;
                }
            }
            countletters++;
        } while (syntaxis);
        syntaxis = true;
        if (countletters - 1 >= 7) {
            fseek(readid, -countletters, SEEK_CUR);
            if(letter == '\n')
                fseek(readid, -1, SEEK_CUR);

            do {
                letter = fgetc(readid);
                for (int i = 0; i < strlen(pattern); i++) {
                    if (letter == pattern[i] || letter == EOF) {
                        syntaxis = false;
                        break;
                    }
                }
                if(syntaxis)
                    fprintf(writeid, "%c", letter);
            } while (syntaxis);
            syntaxis = true;
        }
        for (int i = 0; i < strlen(pattern); i++) {
            if (letter == pattern[i])
                fprintf(writeid, "%c", letter);
        }
        countletters = 0;
    } while (letter != EOF);
}