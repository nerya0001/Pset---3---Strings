#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "algo.h"

#define WLEN 30 //word length
#define TLEN 256 //text length

int main() {
  // declaring word
  char word[WLEN];
  char text[TLEN];

  // reading strings
  scanf("%s", word);
  scanf("%s", text);

  char numerS[TLEN];
  strcpy(numerS, numerology(word, text));
  char atbashS[TLEN];
  strcpy(atbashS, atbash(word, text));
  char anagramS[TLEN];
  strcpy(anagramS, anagram(word, text));

  printf("Gematria Sequences: %s\n", numerS);
  printf("Atbash Sequences: %s\n", atbashS);
  printf("Anagram Sequences: %s\n", anagramS);

  return 0;
}
