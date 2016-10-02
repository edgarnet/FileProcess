/*
 * =====================================================================================
 *
 *       Filename:  fileProcess.h
 *
 *    Description:  This header file includes all function declarations for the program.
 *
 *        Version:  1.0
 *        Created:  9/16/2016 8:50:43 PM
 *       Revision:  none
 *       Compiler:  msft c
 *
 *         Author:  Edgar Perez
 *   Organization:  Washington State University
 *
 * =====================================================================================
 */


#ifndef _fileProcess_h
#define _fileProcess_h

#include	<stdio.h>
#include	<math.h>

#define 	NEWLINE		1
#define		NOT_NEWLINE	0
#define		VOWEL		2
#define		NOT_VOWEL	0
#define		DIGIT		3
#define		NOT_DIGIT	0
#define		ALPHA		4
#define		NOT_ALPHA	0
#define		LOWER		5
#define		NOT_LOWER	0
#define		UPPER		6
#define		NOT_UPPER	0
#define		WHITESPACE	7
#define		NOT_WHITESPACE	0
#define		ALNUM		8
#define		NOT_ALNUM	0
#define		PUNCT		9
#define		NOT_PUNCT	0

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
FILE * open_input_file(void);

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
void IOException(FILE *infile, FILE *outfileOne, FILE *outfileTwo);

/*************************************************************
* Function: read_character()
* Date Created: 9/16/2016         
* Date Last Modified: 9/21/2016                                   
* Description: This function reads one character at a time
* 	       from the input file using fscanf().                             
* Input parameters: The input file (see open_input_file()).                         
* Returns: A character from the input file. 
* Preconditions: The input file must be open for reading.                 
* Postconditions: A character is read and returned 
*                 sequentially.
*************************************************************/
char read_character(FILE *infile);

/*************************************************************
* Function: determine_ascii_value()
* Date Created: 9/16/2016                         
* Date Last Modified: 9/21/2016                                   
* Description: This function finds the ascii value of a
* 	       character by casting the parameter as an
* 	       integer.                             
* Input parameters: A character.                                     
* Returns: The ascii value of the given character.                            
* Preconditions: A character must be assigned to a variable.         
* Postconditions: The ascii value of the character is returned.
*************************************************************/
int determine_ascii_value(char character);

/*************************************************************
* Function: is_line()
* Date Created: 9/16/2016                                       
* Date Last Modified: 9/21/2016                                   
* Description: This function determines whether the given
* 	       character is a newline. Returns the result
* 	       as either 1 for yes, or 0 for no.                          
* Input parameters: A character.                      
* Returns: An integer: 1 for yes; 0 for no.                               
* Preconditions: A character must be assigned to a varaible.                             
* Postconditions: The nature of the character is returned.
*************************************************************/
int is_line(char character);

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
* 		 assigned to variables.                   
* Postconditions: The number of line occurrences increases by
*                 one.                     
*************************************************************/
int number_lines(char character, int current_number_lines);

/*************************************************************
* Function: is_vowel()
* Date Created: 9/16/2016                                      
* Date Last Modified: 9/21/2016                                   
* Description: This function determines whether the given
* 	       character is a vowel. Returns the result
* 	       as either 2 for yes, or 0 for no.                    
* Input parameters: A character.            
* Returns: An integer: 2 for yes; 0 for no.                   
* Preconditions: A character must be assigned to a variable.                      
* Postconditions: The nature of the character is returned.
*************************************************************/
int is_vowel(char character);

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
int number_vowels(char character, int current_number_vowels);

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
int is_digit(char character);

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
int number_digits(char character, int current_number_digits);

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
int is_alpha(char character);

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
* 	          increases by one.
*************************************************************/
int number_alphas(char character, int current_number_alphas);

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
int is_lower(char character);

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
* 	          by one.
*************************************************************/
int number_lowers(char character, int current_number_lowers);

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
int is_upper(char character);

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
* 	          by one.
*************************************************************/
int number_uppers(char character, int current_number_uppers);

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
int is_space(char character);

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
int number_spaces(char character, int current_number_spaces);

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
int is_alnum(char character);

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
*	          increases by one.
*************************************************************/
int number_alnums(char character, int current_number_alnums);

/*************************************************************
* Function: is_punct()
* Date Created: 9/16/2016                                      
* Date Last Modified: 9/21/2016                                   
* Description: This function determines whether the given
* 	       character is a punctuation. Returns the
* 	       result as either 9 for yes, or 0 for no.                             
* Input parameters: A character.     
* Returns: An integer: 9 for yes; 0 for no.                            
* Preconditions: A character must be assigned to a variable.                 
* Postconditions: The nature of the character is returned.
*************************************************************/
int is_punct(char character);

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
* 	          increases by one.
*************************************************************/
int number_puncts(char character, int current_number_puncts);

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
void print_int(FILE *outfile, int number);

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
void print_stats(FILE *outfile, char header[], int number);

/*************************************************************
* Function: close()
* Date Created: 9/16/2016                                         
* Date Last Modified: 9/21/2016                                   
* Description: This function closes three files: one input
*              file and two output files.                       
* Input parameters: Three files.                   
* Returns: Nothing.                            
* Preconditions: All files must be assigned to a varaible,
* 	         and already open.                                        
* Postconditions: All files will be successfully closed.                
*************************************************************/
void close(FILE *infile, FILE *outfileOne, FILE *outfileTwo);

#endif
