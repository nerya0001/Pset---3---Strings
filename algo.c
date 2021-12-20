#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define WORD 30 //word length
#define TXT 1024 //text length

//concatinate char to string
void strcat_c(char *str, char c);
//numerology converter
int toNumer(char *word);
//numerology converter
int sToNumer(char *text, int start, int end);
//to atbash converter
const char* toAtbash(char word[]);
//compare two words
int compare(char *text, char *word, int n);
//reverse word
void reverse_string(char *str);
//check anagram
int check_anagram(char *word, char *text, int c, int k);
//check current char number not including spaces
int charCount(char *word, char *text, int c, int k);

/* all of the minimal sequences with the same numerology as s */
void numerology(char word[], char text[]) {
  static char wordCopy[WORD], textCopy[TXT], ans[TXT];
  strcpy(wordCopy, word);
  strcpy(textCopy, text);
  int numer = toNumer(wordCopy);

  for (int i = 0, j = 0; i < strlen(textCopy) && j < strlen(textCopy);) {
    if (sToNumer(textCopy,i,j) == numer) {
      if (isalpha(textCopy[i]) && isalpha(textCopy[j])){
        for (int k = i; k <= j; k++) {
          strcat_c(ans, textCopy[k]);
        }
        strcat_c(ans, '~');
        i++;
      } else if (!isalpha(textCopy[i])) {
        i++;
      } else if (!isalpha(textCopy[j])) {
        j++;
      }
    }
    else if (sToNumer(textCopy,i,j) > numer) {
      i++;
    }
    else if (sToNumer(textCopy,i,j) < numer) {
      j++;
    }
  }
  ans[strlen(ans) - 1] = '\0';
  printf("%s\n", ans);
}

/* all of the minimal sequences, such that when ignoring blank characters
they are idrntical to s or the revers of s in atbash */
void atbash(char word[], char text[]) {
  static char ans[TXT];
  char wordCopy[WORD], textCopy[TXT];
  strcpy(wordCopy, word);
  strcpy(textCopy, text);
  char wordatb[WORD],revers[WORD];
  strcpy(wordatb, toAtbash(wordCopy));
  strcpy(revers, wordatb);
  reverse_string(revers);

  for (int i = 0; i < strlen(textCopy);) {
    if (compare(textCopy, wordatb, i) == 0 && !isspace(textCopy[i])) {
      for (int k = i; k < strlen(wordatb) + i; k++) {
        strcat_c(ans, textCopy[k]);
      }
      strcat_c(ans, '~');
      i = i + strlen(wordatb);
    } else if (compare(textCopy, revers, i) == 0) {
      for (int k = i; k < strlen(wordatb) + i; k++) {
        strcat_c(ans, textCopy[k]);
      }
      strcat_c(ans, '~');
      i = i + strlen(wordatb);
    }
    i++;
  }
  ans[strlen(ans) - 1] = '\0';
  printf("%s\n", ans);
}

/* all of the minimal sequences that are composed from the characters of s */
void anagram(char word[], char text[]) {
  char wordCopy[WORD], textCopy[TXT];
  static char ans[TXT];
  strcpy(wordCopy, word);
  strcpy(textCopy, text);

  for (int i = 0, j = 0; i < strlen(textCopy) && j < strlen(textCopy);) {
    if ((j-i) >= strlen(wordCopy)-1) {
      if (check_anagram(wordCopy, textCopy, i, j) && !isspace(textCopy[i])) {
      for (int k = i; k <= j; k++) {
        strcat_c(ans, textCopy[k]);
      }
      strcat_c(ans, '~');
      i++;
      j++;
      } else if (isspace(textCopy[i])) {
        i++;
      } else if (charCount(wordCopy, textCopy, i, j) <= strlen(wordCopy)) {
        j++;
      } else {
        i++;
      }

    } else if ((j-i) < strlen(wordCopy)-1) {
      j++;
    }
  }

  ans[strlen(ans) - 1] = '\0';
  printf("%s", ans);
}


void strcat_c(char *str, char c) {
  for (;*str;str++); // note the terminating semicolon here.
  *str++ = c;
  *str++ = 0;
}

int toNumer(char *word) {
  int sum = 0;
  for (int i = 0; i < strlen(word); i++) {
    if (isupper(word[i])) {
      sum += word[i] - 64;
    } else if (islower(word[i])) {
      sum += word[i] - 96;
    }
  }
  // printf("%d", sum);
  return sum;
}

int sToNumer(char *text, int start, int end) {
  int sum = 0;
  for (int i = start; i <= end; i++) {
    if (isupper(text[i])) {
      sum += text[i] - 64;
    } else if (islower(text[i])) {
      sum += text[i] - 96;
    }
  }
  // printf("%d", sum);
  return sum;
}

const char* toAtbash(char word[]) {
  static char ans[TXT];
  int diffUp = 'A' + 'Z';
  int diffLow = 'a' + 'z';
  for (int i = 0; i < strlen(word); i++) {
    if (islower(word[i])){
      strcat_c(ans, diffLow - word[i]);
    } else if (isupper(word[i])) {
      strcat_c(ans, diffUp - word[i] );
    }
  }
  return ans;
}

int compare(char *text, char *word, int n) {
  int i = 0, j = 0, count = 0;

  while (i < strlen(word)) {
    if (text[n + j] == word[i]) {
      count++;
      i++;
      j++;
    } else if (text[n + i] == 32) {
      j++;
    } else {
      break;
    }
  }

  if (count == strlen(word)) {
    return 0;
  }
  return 1;
}

void reverse_string(char *str) {
    /* skip null */
    if (str == 0) {
        return;
    }
    /* skip empty string */
    if (*str == 0) {
        return;
    }
    /* get range */
    char *start = str;
    char *end = start + strlen(str) - 1; /* -1 for \0 */
    char temp;

    /* reverse */
    while (end > start) {
        /* swap */
        temp = *start;
        *start = *end;
        *end = temp;

        /* move */
        ++start;
        --end;
    }
}

//chek for anagram, work like counting sort
int check_anagram(char *word, char *text, int c, int k) {
  int first[127] = {0}, second[127] = {0};
  // Calculating frequency of characters of the first string
  for (int i = 0; i < strlen(word); i++) {
    first[(int)word[i]]++;
  }
  // Calculating frequency of characters of the first string
  for (int j = c; j <= k; j++) {
    second[(int)text[j]]++;
  }
  first[32] = 0;
  second[32] = 0;
  // Comparing the frequency of characters
  for (int l = 0; l < 127; l++) {
    if (first[l] != second[l]) {
      return 0;
    }
  }

  return 1;
}

int charCount(char *word, char *text, int c, int k) {
  int count = 0;
  int chars[127] = {0};

  // Calculating frequency of characters of the chars string
  for (int j = c; j <= k; j++) {
    chars[(int)text[j]]++;
  }

  chars[32] = 0;

  for (int l = 0; l < 127; l++) {
    if (chars[l] > 0) {
      count += chars[l];
    }
  }
  return count;
}
