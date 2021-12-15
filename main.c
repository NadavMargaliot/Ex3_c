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
    char *t = text;
    char *r = res;
    int maybeEven = 0;
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


// char switchAtBash(char c) {
//     if (c >= 97 && c <= 122) {
//         //97    100                                   119   122
//         // a b c d e f g h i j k l m n o p q r s t u v w x y z
//         // z y x w v u t s r q p o n m l k j i h g f e d c b a
//         return (97 + (122 - c));
//     } else if (c >= 65 && c <= 90) {
//         return (65 + (90 - c));
//     }
//     return c;
// }

void makeAtbashFromWord(char arr[]){
    char *ptr=arr;
    char curr;
    while (*ptr){
        if(*ptr >= 65 && *ptr <= 90){
            curr = (65 + (90 - *ptr));
        }else{
            curr = (97 + (122 - *ptr));
        }
        *ptr = (curr);
        ptr++;
    }
}

void reverseStr(char str[]) {
    int n = strlen(str);

    for (int i = 0; i < n / 2; i++) {
        char ch = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = ch;
    }
}


void atbash(char word[], char text[]) {
    word[strlen(word) - 1] = '\0';
    char atbshWord[strlen(word)];
    makeAtbashFromWord(word);
    strcpy(atbshWord, word);
    char copyAtbshWord[strlen(atbshWord)];
    strcpy(copyAtbshWord, atbshWord);
    char reverseAtbshWord[strlen(word)];
    reverseStr(copyAtbshWord);
    strcpy(reverseAtbshWord, copyAtbshWord);
    char result[TXT] = "";
    char *w = atbshWord;
    char *rev = reverseAtbshWord;
    char *t = text;
    char *pr = result;

    for (int i = 0; i < strlen(text); i++) {
        for (int j = i; j < strlen(text); j++) {
            if ((*(t + j) != *(w)) && (*(t + j) != *(rev))) {
                break;
            } else if (*(t + j) == *(w)) {
                for (int k = 0; k < strlen(atbshWord); k++) {
                    if (*(t + j + k) != *(w + k)) {
                        break;
                    } else {
                        if (k == strlen(atbshWord) - 1) {
                            int count = 0;
                            while (count < strlen(atbshWord)) {
                                *pr = *(t + j + count);
                                pr++;
                                count++;
                            }
                            *pr = '~';
                            pr++;
                            i = i + 1;
                        }
                    }
                }
            } else if (*(t + j) == *(rev)) {
                for (int k = 0; k < strlen(reverseAtbshWord); k++) {
                    if (*(t + j + k) != *(rev + k)) {
                        break;
                    } else {
                        if (k == strlen(reverseAtbshWord) - 1) {
                            int count = 0;
                            while (count < strlen(reverseAtbshWord)) {
                                *pr = *(t + j + count);
                                pr++;
                                count++;
                            }
                            *pr = '~';
                            pr++;
                            i = i + 1;
                        }
                    }
                }
            }
        }
    }
    result[strlen(result) - 1] = '\0';
    printf("Atbash Sequences: %s\n", result);
}


int main() {
    char word[WORD];
    char text[TXT];
    makeWord(word);
    makeText(text);
    gematria(word,text);
    atbash(word,text);
    
     


    return 0;
}