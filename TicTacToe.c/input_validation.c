#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "input_validation.h"

bool isValidFormat(const int numArgsRead, const int numArgsNeed) {
  bool formatIsGood = numArgsRead == numArgsNeed;
  char character;
  bool message_displayed = false;
  do {
    scanf("%c", &character);
    if (!isspace(character) && !message_displayed) {
      formatIsGood = false;
      printf("Put a space between the numbers\n");
      message_displayed = true;
    }
  } while (character != '\n');
  return formatIsGood;
}


