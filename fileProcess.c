/*
 * =====================================================================================
 *
 *       Filename:  fileProcess.c
 *
 *    Description:  This source file contains all function definitions for the program.
 *
 *        Version:  1.0
 *        Created:  9/16/2016 10:03:02 PM
 *       Revision:  none
 *       Compiler:  msft c
 *
 *         Author:  Edgar Perez 
 *   Organization:  Washington State University
 *
 * =====================================================================================
 */

#include	"fileProcess.h"

/*************************************************************
* Function: open_input_file()
* Date Created: 9/16/2016
* Date Last Modified: 9/21/2016
* Description: This function opens the "input.dat" file.
* Input parameters: None.
* Returns: An input file.
* Preconditions: The file must be created beforehand.
* Postconditions: The file is ready for reading data.
*************************************************************/
FILE * open_input_file(void){
	FILE *infile;
	infile = fopen("input.dat", "r");
	return infile;
}

/*************************************************************
* Function: IOException()
* Date Created: 9/16/2016
* Date Last Modified: 9/21/2016
* Description: This function determines if the files can be opened.
* Input parameters: None.
* Returns: Nothing.
* Preconditions: The three files must be open beforehand
* Postconditions: The function will print a warning if files,
				  could not be open, along with success prompt. 
*************************************************************/
void IOException(FILE *infile, FILE *outfileOne, FILE *outfileTwo) {
	if(infile == NULL) {
		printf("Input file could not be opened!");
	}
	else if ((outfileOne == NULL) && (outfileTwo == NULL)) {
		printf("One of your output files could not be opened!");
	}
	else {
		printf("All files were opened!\n");
	}
}

/*************************************************************
* Function: read_character()
* Date Created: 9/16/2016
* Date Last Modified: 9/21/2016
* Description: This function reads one character at a time
*              from the input file using fscanf().
* Input parameters: The input file (see open_input_file()).
* Returns: A character from the input file.
* Preconditions: The input file must be open for reading.
* Postconditions: A character is read and returned
*                 sequentially.
*************************************************************/
char read_character(FILE *infile){
	char input = ' ';
	fscanf(infile, "%c", &input);
	return input;
}

/*************************************************************
* Function: determine_ascii_value()
* Date Created: 9/16/2016
* Date Last Modified: 9/21/2016
* Description: This function finds the ascii value of a
*              character by casting the parameter as an
*              integer.
* Input parameters: A character.
* Returns: The ascii value of the given character.
* Preconditions: A character must be assigned to a variable.
* Postconditions: The ascii value of the character is returned.
*************************************************************/
int determine_ascii_value(char character){
	int ascii_value = 0;
	ascii_value = (int)character;
	return ascii_value;
}

/*************************************************************
* Function: is_line()
* Date Created: 9/16/2016
* Date Last Modified: 9/21/2016
* Description: This function determines whether the given
*              character is a newline. Returns the result
*              as either 1 for yes, or 0 for no.
* Input parameters: A character.
* Returns: An integer: 1 for yes; 0 for no.
* Preconditions: A character must be assigned to a varaible.
* Postconditions: The nature of the character is returned.
*************************************************************/
int is_line(char character){
	int line = 0;
	if(character == '\n'){
		line = NEWLINE;
	}
	else{
		line = NOT_NEWLINE;
	}
	return line;
}

/*************************************************************
* Function: number_lines()
* Date Created: 9/16/2016
* Date Last Modified: 9/21/2016
* Description: This function adds one to a counting variable
*              assuming is_line() returns a number greater
*              than 0 for the given character.
* Input parameters: A character and an integer for counting.
* Returns: Adds one to the given integer.
* Preconditions: Both the given character and integer must be
*                assigned to variables.
* Postconditions: The number of line occurrences increases by
*                 one.
*************************************************************/
int number_lines(char character, int current_number_lines){
	if(is_line(character) == NEWLINE){
		++current_number_lines;
	}
	return current_number_lines;
}

/*************************************************************
* Function: is_vowel()
* Date Created: 9/16/2016
* Date Last Modified: 9/21/2016
* Description: This function determines whether the given
*              character is a vowel. Returns the result
*              as either 2 for yes, or 0 for no.
* Input parameters: A character.
* Returns: An integer: 2 for yes; 0 for no.
* Preconditions: A character must be assigned to a variable.
* Postconditions: The nature of the character is returned.
*************************************************************/
int is_vowel(char character){
	int vowel = 0;
	if(determine_ascii_value(character) == 65 ||
			determine_ascii_value(character) == 69 ||
			determine_ascii_value(character) == 73 ||
			determine_ascii_value(character) == 79 ||
			determine_ascii_value(character) == 85 ||
			determine_ascii_value(character) == 97 ||
			determine_ascii_value(character) == 101 ||
			determine_ascii_value(character) == 105 ||
			determine_ascii_value(character) == 111 ||
			determine_ascii_value(character) == 117){
		vowel = VOWEL;
	}
	else{
		vowel = NOT_VOWEL;
	}
	return vowel;
}

/*************************************************************
* Function: number_vowels()
* Date Created: 9/16/2016
* Date Last Modified: 9/21/2016
* Description: This function adds one to a counting variable
*              assuming is_vowel() returns a number greater
*              than 0 for the given character.
* Input parameters: A character and an integer for counting.
* Returns: Adds one to the given integer.
* Preconditions: Both the given character and integer must be
*                assigned to variables.
* Postconditions: The number of vowel occurrences increases by
*                 one.
*************************************************************/
int number_vowels(char character, int current_number_vowels){
	if(is_vowel(character) == VOWEL){
		++current_number_vowels;
	}
	return current_number_vowels;
}

/*************************************************************
* Function: is_digit()
* Date Created: 9/16/2016
* Date Last Modified: 9/21/2016
* Description: This function determines whether the given
*              character is a vowel. Returns the result
*              as either 3 for yes, or 0 for no.
* Input parameters: A character.
* Returns: An integer: 3 for yes; 0 for no.
* Preconditions: A character must be assigned to a variable.
* Postconditions: The nature of the character is returned.
*************************************************************/
int is_digit(char character){
	int digit = 0;
	if(determine_ascii_value(character) == 48 ||
			determine_ascii_value(character) == 49 ||
			determine_ascii_value(character) == 50 ||
			determine_ascii_value(character) == 51 ||
			determine_ascii_value(character) == 52 ||
			determine_ascii_value(character) == 53 ||
			determine_ascii_value(character) == 54 ||
			determine_ascii_value(character) == 55 ||
			determine_ascii_value(character) == 56 ||
			determine_ascii_value(character) == 57){
		digit = DIGIT;
	}
	else{
		digit = NOT_DIGIT;
	}
	return digit;
}

/*************************************************************
* Function: number_digits()
* Date Created: 9/16/2016
* Date Last Modified: 9/21/2016
* Description: This function adds one to a counting variable
*              assuming is_digits() returns a number greater
*              than 0 for the given character.
* Input parameters: A character and an integer for counting.
* Returns: Adds one to the given integer.
* Preconditions: Both the given character and integer must be
*                assigned to variables.
* Postconditions: The number of digit occurrences increases by
*                 one.
*************************************************************/
int number_digits(char character, int current_number_digits){
	if(is_digit(character) == DIGIT){
		++current_number_digits;
	}
	return current_number_digits;
}

/*************************************************************
* Function: is_alpha()
* Date Created: 9/16/2016
* Date Last Modified: 9/21/2016
* Description: This function determines whether the given
*              character is alphabetical. Returns the
*              result as either 4 for yes, or 0 for no.
* Input parameters: A character.
* Returns: An integer: 4 for yes; 0 for no.
* Preconditions: A character must be assigned to a variable.
* Postconditions: The nature of the character is returned.
*************************************************************/
int is_alpha(char character){
	int alpha = 0;
	if((determine_ascii_value(character) >= 65 && determine_ascii_value(character) <= 90) || (determine_ascii_value(character) >= 97 && determine_ascii_value(character) <= 122)){
		alpha = ALPHA;
	}
	else{
		alpha = NOT_ALPHA;
	}
	return alpha;
}

/*************************************************************
* Function: number_alphas()
* Date Created: 9/16/2016
* Date Last Modified: 9/21/2016
* Description: This function adds one to a counting variable
*              assuming is_alpha() returns a number greater
*              than 0 for the given character.
* Input parameters: A character and an integer for counting.
* Returns: Adds one to the given integer.
* Preconditions: Both the given character and integer must be
*                assigned to variables.
* Postconditions: The number of alphabetical occurrences
*                 increases by one.
*************************************************************/
int number_alphas(char character, int current_number_alphas){
	if(is_alpha(character) == ALPHA){
		++current_number_alphas;
	}
	return current_number_alphas;
}

/*************************************************************
* Function: is_lower()
* Date Created: 9/16/2016
* Date Last Modified: 9/21/2016
* Description: This function determines whether the given
*              character is lowercase. Returns the result
*              as either 5 for yes, or 0 for no.
* Input parameters: A character.
* Returns: An integer: 5 for yes; 0 for no.
* Preconditions: A character must be assigned to a variable.
* Postconditions: The nature of the character is returned.
*************************************************************/
int is_lower(char character){
	int lower = 0;
	if(determine_ascii_value(character) >= 97 && determine_ascii_value(character) <= 122){
		lower = LOWER;
	}
	else{
		lower = NOT_LOWER;
	}
	return lower;
}

/*************************************************************
* Function: number_lowers()
* Date Created: 9/16/2016
* Date Last Modified: 9/21/2016
* Description: This function adds one to a counting variable
*              assuming is_lower() returns a number greater
*              than 0 for the given character.
* Input parameters: A character and an integer for counting.
* Returns: Adds one to the given integer.
* Preconditions: Both the given character and integer must be
*                assigned to variables.
* Postconditions: The number of lowercase occurrences increases
*                 by one.
*************************************************************/
int number_lowers(char character, int current_number_lowers){
	if(is_lower(character) == LOWER){
		++current_number_lowers;
	}
	return current_number_lowers;
}

/*************************************************************
* Function: is_upper()
* Date Created: 9/16/2016
* Date Last Modified: 9/21/2016
* Description: This function determines whether the given
*              character is uppercase. Returns the result
*              as either 6 for yes, or 0 for no.
* Input parameters: A character.
* Returns: An integer: 6 for yes; 0 for no.
* Preconditions: A character must be assigned to a variable.
* Postconditions: The nature of the character is returned.
*************************************************************/
int is_upper(char character){
	int upper = 0;
	if(determine_ascii_value(character) >= 65 && determine_ascii_value(character) <= 90){
		upper = UPPER;
	}
	else{
		upper = NOT_UPPER;
	}
	return upper;
}

/*************************************************************
* Function: number_uppers()
* Date Created: 9/16/2016
* Date Last Modified: 9/21/2016
* Description: This function adds one to a counting variable
*              assuming is_upper() returns a number greater
*              than 0 for the given character.
* Input parameters: A character and an integer for counting.
* Returns: Adds one to the given integer.
* Preconditions: Both the given character and integer must be
*                assigned to variables.
* Postconditions: The number of uppercase occurrences increases
*                 by one.
*************************************************************/
int number_uppers(char character, int current_number_uppers){
	if(is_upper(character) == UPPER){
		++current_number_uppers;
	}
	return current_number_uppers;
}

/*************************************************************
* Function: is_space()
* Date Created: 9/16/2016
* Date Last Modified: 9/21/2016
* Description: This function determines whether the given
*              character is a type of space. Returns the
*              result as either 7 for yes, or 0 for no.
* Input parameters: A character.
* Returns: An integer: 7 for yes; 0 for no.
* Preconditions: A character must be assigned to a variable.
* Postconditions: The nature of the character is returned.
*************************************************************/
int is_space(char character){
	int space = 0;
	if(character == ' ' || character == '\f' || character == '\n' || character == '\r' || character == '\t' || character == '\v'){
		space = WHITESPACE;
	}
	else{
		space = NOT_WHITESPACE;
	}
	return space;
}

/*************************************************************
* Function: number_space()
* Date Created: 9/16/2016
* Date Last Modified: 9/21/2016
* Description: This function adds one to a counting variable
*              assuming is_space() returns a number greater
*              than 0 for the given character.
* Input parameters: A character and an integer for counting.
* Returns: Adds one to the given integer.
* Preconditions: Both the given character and integer must be
*                assigned to variables.
* Postconditions: The number of space occurrences increases by
*                 one.
*************************************************************/
int number_spaces(char character, int current_number_spaces){
	if(is_space(character) == WHITESPACE){
		++current_number_spaces;
	}
	return current_number_spaces;
}

/*************************************************************
* Function: is_alnum()
* Date Created: 9/16/2016
* Date Last Modified: 9/21/2016
* Description: This function determines whether the given
*              character is alpha-numeric. Returns the result
*              as either 8 for yes, or 0 for no.
* Input parameters: A character.
* Returns: An integer: 8 for yes; 0 for no.
* Preconditions: A character must be assigned to a variable.
* Postconditions: The nature of the character is returned.
*************************************************************/
int is_alnum(char character){
	int alnum = 0;
	if((determine_ascii_value(character) >= 48 && determine_ascii_value(character) <= 57) || (determine_ascii_value(character) >= 65 && determine_ascii_value(character) <= 122)){
		alnum = ALNUM;
	}
	else{
		alnum = NOT_ALNUM;
	}
	return alnum;
}

/*************************************************************
* Function: number_alnums()
* Date Created: 9/16/2016
* Date Last Modified: 9/21/2016
* Description: This function adds one to a counting variable
*              assuming is_alnum() returns a number greater
*              than 0 for the given character.
* Input parameters: A character and an integer for counting.
* Returns: Adds one to the given integer.
* Preconditions: Both the given character and integer must be
*                assigned to variables.
* Postconditions: The number of alpha-numeric occurrences
*                 increases by one.
*************************************************************/
int number_alnums(char character, int current_number_alnums){
	if(is_alnum(character) == ALNUM){
		++current_number_alnums;
	}
	return current_number_alnums;
}

/*************************************************************
* Function: is_punct()
* Date Created: 9/16/2016
* Date Last Modified: 9/21/2016
* Description: This function determines whether the given
*              character is a punctuation. Returns the
*              result as either 9 for yes, or 0 for no.
* Input parameters: A character.
* Returns: An integer: 9 for yes; 0 for no.
* Preconditions: A character must be assigned to a variable.
* Postconditions: The nature of the character is returned.
*************************************************************/
int is_punct(char character){
	int punct = 0;
	if((determine_ascii_value(character) >= 33 && determine_ascii_value(character) <= 47) || (determine_ascii_value(character) >= 58 && determine_ascii_value(character) <= 64) || (determine_ascii_value(character) >= 91 && determine_ascii_value(character) <= 96) || (determine_ascii_value(character) >= 123 && determine_ascii_value(character) <= 126)){
		punct = PUNCT;
	}
	else{
		punct = NOT_PUNCT;
	}
	return punct;
}

/*************************************************************
* Function: number_puncts()
* Date Created: 9/16/2016
* Date Last Modified: 9/21/2016
* Description: This function adds one to a counting variable
*              assuming is_punct() returns a number greater
*              than 0 for the given character.
* Input parameters: A character and an integer for counting.
* Returns: Adds one to the given integer.
* Preconditions: Both the given character and integer must be
*                assigned to variables.
* Postconditions: The number of punctuation occurrences
*                 increases by one.
*************************************************************/
int number_puncts(char character, int current_number_puncts){
	if(is_punct(character) == PUNCT){
		++current_number_puncts;
	}
	return current_number_puncts;
}

/*************************************************************
* Function: print_int()
* Date Created: 9/16/2016
* Date Last Modified: 9/21/2016
* Description: This function prints an integer to an output
*              file.
* Input parameters: An output file and integer.
* Returns: Nothing.
* Preconditions: An output file must be opened for writing,
*                along with an integer assigned to a varaible.
* Postconditions: The given integer will be printed to the
*                 output file.
*************************************************************/
void print_int(FILE *outfile, int number){
	fprintf(outfile, "%d\n", number);
}

/*************************************************************
* Function: print_stats()
* Date Created: 9/16/2016
* Date Last Modified: 9/21/2016
* Description: This function prints a char array and its
*              respective datum to an output file.
* Input parameters: An output file, char array, and integer.
* Returns: Nothing.
* Preconditions: An output file must be opened for writing,
*                along with a char array and an integer,
*                both assigned to variables.
* Postconditions: The given char array and integer will be
*                 printed to the output file.
*************************************************************/
void print_stats(FILE *outfile, char header[], int number){
	fprintf(outfile, "%s\t%d\n", header, number);
}

/*************************************************************
* Function: close()
* Date Created: 9/16/2016
* Date Last Modified: 9/21/2016
* Description: This function closes three files: one input
*              file and two output files.
* Input parameters: Three files.
* Returns: Nothing.
* Preconditions: All files must be assigned to a varaible,
*                and already open.
* Postconditions: All files will be successfully closed.
*************************************************************/
void close(FILE *infile, FILE *outfileOne, FILE *outfileTwo){
	fclose(infile);
	fclose(outfileOne);
	fclose(outfileTwo);
}
