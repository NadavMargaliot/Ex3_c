#include <stdio.h>
#include "MyFuncs.h"
#include <string.h>
#define WORD 30
#define TXT 1024

int main() {
    char word[WORD];
    char text[TXT];
    makeWord(word);
    makeText(text);
    char tmpWord[strlen(word)];
    strcpy(tmpWord,word);
    gematria(word,text);
    atbash(word,text);
    anagram(tmpWord,text);
    return 0;
}