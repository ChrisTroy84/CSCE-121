#include <iostream>
#include "cstring.h"

unsigned int length(char str[]) {
  // returns the length of the string including zero (0)
  int size = 0;
  int i;

  for (i = 0; str[i] != '\0'; ++i) {
    ++size;
  }
  return size;

  return 0;
}

unsigned int find(char str[], char character) {
  // returns 
  //  - the index of the first occurence of character in str
  //  - the size if the character is not found
  unsigned int i;
  int size = 0;

  for (i = 0; i < length(str); ++i) {
    if (str[i] != character) {
      ++size;
    }
    else {
      return i;
      break;
    }
  }
  return size;

  return 0;
}

bool equalStr(char str1[], char str2[]) {
  // returns true if they are equal and false if they are not
  unsigned int i;

  if (length(str1) != length(str2)) {
    return false;
  }
  for (i = 0; i < length(str1); ++i) {
    if (str1[i] != str2[i]) {
      return false;
    }
  }
  return true;
}