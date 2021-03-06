#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "algo.h"

#define WORD 30 //word length
#define TXT 1024 //text length

int main() {
  // declaring word
  char word[WORD];
  char text[TXT];

  // reading strings
  scanf("%s", word);
  for (int i = 0; i < strlen(word); i++) {
    if (word[i] == '~') {
      printf("Gematria Sequences: \n");
      printf("Atbash Sequences: \n");
      printf("Anagram Sequences: ");
      return 0;
    }
  }
  scanf("%[^~]s", text);

  printf("Gematria Sequences: ");
  numerology(word, text);
  printf("Atbash Sequences: ");
  atbash(word, text);
  printf("Anagram Sequences: ");
  anagram(word, text);

  return 0;
}
