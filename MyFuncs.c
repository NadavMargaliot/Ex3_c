#include <stdio.h>
#include "MyFuncs.h"
#include <string.h>
#define TXT 1024
#define WORD 30

//--initialize the word
void makeWord(char word[WORD]){
    char curr;
    int counter = 0;
    while(curr != ' ' && curr != '\t' && curr != '\n' && counter < WORD){
        scanf("%c" , &curr);
        word[counter] = curr;
        counter++;
    }
}
//--initialize the text
void makeText(char text[TXT]){
    char curr;
    int counter = 0;
    while(curr != '~' && counter < TXT){
        scanf("%c" , &curr);
        text[counter] = curr;
        counter++;
    }
}
//--Q1
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
    if(res[strlen(res) - 1] == '~'){
        res[strlen(res) - 1] = '\0';
    }
    printf("Gematria Sequences: %s\n" , res);
}

//--Q2
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

void reverseStr(char word[]) {
    int n = strlen(word);
    for (int i = 0; i < n / 2; i++) {
        char ch = word[i];
        word[i] = word[n - i - 1];
        word[n - i - 1] = ch;
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

//--Q3
int isAnagram(char* a, char* b) {
    int checkAnagram[177] = {0};
    for(int i = 0 ; a[i] != '\0'; i++){
        if(a[i] != ' '){
            checkAnagram[(int)*(a+i)] += 1;
        }
        if(b[i] != ' ' && strlen(b)>i){
            checkAnagram[(int)*(b+i)] -= 1;
        }
    }
    for(int i = 0; i < 177; i++){
        if(checkAnagram[i] != 0){
            return 0;
        }
    }
    return 1;
}

void anagram(char word[], char text[]){
    word[strlen(word)-1] = '\0';
    char *t, *tf, *w;
    t = text; 
    char ans[TXT] = "";
    while(*t){
        char helper[TXT] = "";
        int counter = 0; 
        tf = t;
        w = word;
        while(counter < strlen(w)){
        if(*tf == 32 && !strlen(helper)){
            break;
        }
        else if (*tf != 32){
            counter ++;
        }
        strncat(helper, tf,1);
        tf++;

        if(strlen(w) == counter){
            if(isAnagram(helper, w)){
                strcat(ans, helper);
                ans[strlen(ans)] = '~';
                counter = 0; 
            }
        }
        }
        t++;
    }
    ans[strlen(ans)-1] = '\0'; 
    printf("Anagram Sequences: %s", ans);
}



