#ifndef _ALGO_H_
#define _ALGO_H_

  /* all of the minimal sequences with the same numerology as s */
  char* numerology(char str[], char text[]);
  /* all of the minimal sequences, such that when ignoring blank characters
  they are idrntical to s or the revers of s in atbash */
  char* atbash(char str[], char text[]);
  /* all of the minimal sequences that are composed from the characters of s */
  char* anagram(char str[], char text[]);

  #endif
