#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

char* read_any_len_str();
char* append(char val, char* str, int* size);

/**
 * Read a line of any length from standard input
 * @return a string entered from standard input
 */

/**
 * Read a string of any length from standard input
 * @return the string read from standard input
 */
char* read_any_len_str() {
	char cur_char;
	char* str = NULL;
	int cur_size = 0;

//####hello
	//skip leading whitespace
	do{
		scanf("%c", &cur_char);
	}while(isspace(cur_char));

	do{
		str = append(cur_char, str, &cur_size);
		scanf("%c", &cur_char);
	}while(!isspace(cur_char));

	//add the null character
	str = append('\0', str, &cur_size);

	return str;
}

char* append(char val, char* str, int* size){
	(*size)++;
	str = (char*)realloc(str, *size * sizeof(char));
	str[*size - 1] = val;
	return str;
}