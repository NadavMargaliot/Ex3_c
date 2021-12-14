#include <stdio.h>
#include "MyFuncs.h"
#define WORD 30
#define TXT 1024
int main(){
     char word[WORD];
    char text[TXT];
    printf("Please enter a word:");
    makeWord(word);
    printf("%s",word);

    printf("Please enter a text:");
    makeText(text);
    printf("%s",text);

    return 0;

}

void makeWord(char word[30]){
    char curr;
    int counter = 0;
    while(curr != ' ' && curr != '\t' && curr != '\n' && counter < 30){
        scanf("%c" , &curr);
        word[counter] = curr;
        counter++;
    }
}

void makeText(char text[1024]){
    char curr;
    int counter = 0;
    while(curr != '~' && counter < 1024){
        scanf("%c" , &curr);
        text[counter] = curr;
        counter++;
    }
}