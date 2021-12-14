#include <stdio.h>
#include "MyFuncs.h"
#define TXT 1024;
#define WORD 30;


void makeWord(char word[30]){
    char curr;
    int counter = 0;
    while(curr != ' ' && curr != '\t' && curr != '\n' && counter < 30){
        scanf("%c" , &curr);
        counter++;
    }
}

void makeText(char word[1024]){
    char curr;
    int counter = 0;
    while(curr != '~' && counter < 1024){
        scanf("%c" , &curr);
        counter++;
    }
}


