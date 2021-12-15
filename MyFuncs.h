
#ifndef _MY_FUNCS_H_
#define _MY_FUNCS_H_
#define WORD 30
#define TXT 1024
void makeWord(char[WORD]);
void makeText(char[TXT]);
int gematriaValue(char c);
int gematriaFromWord(char word[]);
char switchAtBash(char c);
void gematria(char word[] , char text[]);
void makeAtbashFromWord(char arr[]);
void reverseStr(char word[]);
void atbash(char word[], char text[]);
int isAnagram(char* a, char* b);
void anagram(char word[] , char text[]);

#endif