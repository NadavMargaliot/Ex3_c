#include <stdio.h>
#include "MyFuncs.h"
#include <string.h>
#define WORD 30
#define TXT 1024


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

int gematriaValue(char c){
    if(c >= 97 && c <= 122){
        return (c - 'a') + 1;
    }else if(c >= 65 && c <= 90){
        return (c - 'A') + 1;
    }
    return 0;
}
int gematriaFromWord(char word[]){
    int result = 0;
    for(int i = 0; i < strlen(word); i++){
        result += gematriaValue(word[i]);
    }
    return result;
}


// Gematria Sequences: a-bc,d~dbca~dcba
// a-bc,dbca-zwxyzabzyxw0dcba~





void gematria(char word[] , char text[]){
    char res[TXT];
    char *w = word;
    char *t = text;
    char *r = res;
    int maybeEven = 0;
    int count = 0;
    int expectedWordGematria = gematriaFromWord(word);
    for(int i = 0; i < strlen(text); i++){
        for(int j = i; j < strlen(text); j++){
            if(maybeEven < expectedWordGematria){
                maybeEven += gematriaValue(*(t + j));
                if (maybeEven == 0){
                    break;
                }
                if(maybeEven == expectedWordGematria){
                    for(int k = i; k <= j ; k++){
                        *r = *(t+k);
                        r++;
                    }
                        *r = '~';
                        r++;
                        maybeEven = 0;
                        break;
                }
            }else{
                maybeEven = 0;
                break;
            }
        }
        maybeEven = 0;
    }
    res[strlen(res) - 1] = '\0';
    printf("Gematria Sequences: %s\n" , res);
}

int main() {
    char word[WORD];
    char text[TXT];
    // printf("Please enter a word:");
    makeWord(word);
    // printf("Please enter a text:");
    makeText(text);
    gematria(word,text);
    return 0;
}