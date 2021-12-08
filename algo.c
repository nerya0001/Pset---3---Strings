#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define WLEN 30 //word length
#define TLEN 256 //text length

/* all of the minimal sequences with the same numerology as s */
char* numerology(char word[], char text[]) {
  char wordCopy[WLEN], textCopy[TLEN], ans[TLEN];
  strcpy(wordCopy, word);
  strcpy(textCopy, text);
  return ans;
}
/* all of the minimal sequences, such that when ignoring blank characters
they are idrntical to s or the revers of s in atbash */
char* atbash(char word[], char text[]) {
  char wordCopy[WLEN], textCopy[TLEN], ans[TLEN];
  strcpy(wordCopy, word);
  strcpy(textCopy, text);
  return ans;
}
/* all of the minimal sequences that are composed from the characters of s */
char* anagram(char word[], char text[]) {
  char wordCopy[WLEN], textCopy[TLEN], ans[TLEN];
  strcpy(wordCopy, word);
  strcpy(textCopy, text);
  return ans;
}
