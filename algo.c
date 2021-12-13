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
        i = j;
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
  // printf("wordatb = %s\n",wordatb);
  // printf("revers = %s\n",revers);
  for (int i = 0; i < strlen(textCopy);) {
    // printf(" = %d\n", compare(textCopy, wordatb, i));
    if (compare(textCopy, wordatb, i) == 0) {
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

int check_anagram(char a[], char b[])
{
  int first[26] = {0}, second[26] = {0}, c=0;
  // Calculating frequency of characters of the first string
  while (a[c] != '\0') {
    first[a[c]-'a']++;
    c++;
  }
  c = 0;
  while (b[c] != '\0') {
    second[b[c]-'a']++;
    c++;
  }
  // Comparing the frequency of characters
  for (c = 0; c < 26; c++)
    if (first[c] != second[c])
      return 0;

  return 1;
}

// /* all of the minimal sequences that are composed from the characters of s */
void anagram(char word[], char text[]) {
  char wordCopy[WORD], textCopy[TXT];
  static char ans[TXT];
  strcpy(wordCopy, word);
  strcpy(textCopy, text);
  char curr[WORD];

  for (int i = 0, j = 0; i < strlen(textCopy) && j < strlen(textCopy);) {
    strcat_c(curr, textCopy[i]);
    while (j < strlen(wordCopy)) {
      strcat_c(curr, textCopy[i]);
      j++;
    }
    if (check_anagram(wordCopy, curr) == 1) {
      strcat(ans, curr);
      strcat_c(ans, '~');
    }
    i += j;
  }
  ans[strlen(ans) - 1] = '\0';
  printf("%s\n", ans);
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
  int i = 0, count = 0;
  // printf(" word len is -> %d", (int)strlen(word));
  while (i < strlen(word)) {
    if (text[n + i] == word[i]) {
      // printf("%c %c",text[n+i], word[i]);
      // printf(" next char is -> %c",text[n+i]);
      count++;
    }
    i++;
  }
  // printf(" count = %d\n", count);
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
