#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Exersize1.h"
#include "Exersize2.h"
#include "Exersize3.h"
#include "Exersize4.h"

int main() {
    FILE* readid, * writeid;
    readid = fopen("G:\\Text\\Text.txt", "r");
    writeid = fopen("G:\\Text\\NewText.txt", "w");
    if (readid != NULL && writeid != NULL) {
        PrintBigWords(readid, writeid);
        fclose(readid);
        fclose(writeid);
    }
    
    readid = fopen("G:\\Text\\Text.txt", "r");
    writeid = fopen("G:\\Text\\TextCopy.txt", "w");
    if (readid != NULL && writeid != NULL) {
        CopyText(readid, writeid);
        fclose(readid);
        fclose(writeid);
    }
    
    readid = fopen("G:\\Text\\Text.txt", "r");
    writeid = fopen("G:\\Text\\TextReflect.txt", "w");
    if (readid != NULL && writeid != NULL) {
        ReflectText(readid, writeid);
        fclose(readid);
        fclose(writeid);
    }
    
    readid = fopen("G:\\Text\\Text.txt", "r");
    writeid = fopen("G:\\Text\\LineText.txt", "w");
    if (readid != NULL && writeid != NULL) {
        PrintTextWithLine(readid, writeid);
        fclose(readid);
        fclose(writeid);
    }
}