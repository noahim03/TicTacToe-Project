#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "input_val.h"

bool isValidFormat(const int numArgsRead, const int numArgsNeed) {
    bool formatIsGood = numArgsRead == numArgsNeed;
    char character;
    do {
        scanf("%c", &character);
        if (!isspace(character)) {
            formatIsGood = false;
        }
    } while (character != '\n');
    return formatIsGood;
}

int getValidInt(const char* prompt) {
    int num;
    const int numArgsNeeded = 1;
    int numArgsRead;
    do {
        printf("%s", prompt);
        numArgsRead = scanf(" %d", &num);
    } while (!isValidFormat(numArgsRead, numArgsNeeded));

    return num;
}

double getValidDouble(const char* prompt) {
    double num;
    const int numArgsNeeded = 1;
    int numArgsRead;
    do {
        printf("%s", prompt);
        numArgsRead = scanf(" %lf", &num);
    } while (!isValidFormat(numArgsRead, numArgsNeeded));

    return num;
}
