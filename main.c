/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  This program reads input from an input file and reads each character
 *    		    at a time while evaluating its ascii value and whether it is a line,
 *    		    vowel, digit, alpha character, lowercase character, uppercase 
 *    		    character, space, alphanumeric, or punctuation. Files will also be
 *    		    checked for a successful opening and closing.
 *
 *        Version:  1.0
 *        Created:  9/17/2016 12:00:58 AM
 *       Revision:  none
 *       Compiler:  msft c
 *
 *         Author:  Edgar Perez 
 *   Organization:  Washington State University
 *
 * =====================================================================================
 */

#include	"fileProcess.h"

//Can't forget int main()!
int main(void){

	/* The following variables store the characters read from "input.dat", the ascii values of those characters, and the "input.dat" file itself. */
	char one = '\0', two = '\0', three = '\0', four = '\0', five = '\0', six = '\0', seven = '\0', eight = '\0', nine = '\0', ten = '\0';
	int asciiOne = 0, asciiTwo = 0, asciiThree = 0, asciiFour = 0, asciiFive = 0, asciiSix = 0, asciiSeven = 0, asciiEight =0, asciiNine = 0, asciiTen =0;
	int current_lines = 0, current_vowels = 0, current_digits = 0, current_alphas = 0, current_lowers = 0, current_uppers = 0, current_spaces = 0, current_alnums = 0, current_puncts = 0;
	int proxy = 0;
	FILE *infile = NULL;
	infile = open_input_file();

	/* The following variables store the output files along with the character arrays used in "output_stats.dat". */
	FILE *outputAscii = fopen("output_ascii.dat", "w");
	FILE *outputStats = fopen("output_stats.dat", "w");
	IOException(infile, outputAscii, outputStats);
	char headerLines[20] = "Number Lines:";
	char headerVowels[20] = "Number Vowels:";
	char headerDigits[20] = "Number Digits:";
	char headerAlphas[20] = "Number Alphas:";
	char headerLowers[20] = "Number Lowers:";
	char headerUppers[20] = "Number Uppers:";
	char headerSpaces[20] = "Number Spaces:";
	char headerAlnums[20] = "Number Alnums:";
	char headerPuncts[20] = "Number Puncts:";

	/* The following are the characters from the input file and their ascii values stored in the variables below. */
	one = read_character(infile);
	asciiOne = determine_ascii_value(one);

	two = read_character(infile);
	asciiTwo = determine_ascii_value(two);

	three = read_character(infile);
	asciiThree = determine_ascii_value(three);

	four = read_character(infile);
	asciiFour = determine_ascii_value(four);
	
	five = read_character(infile);
	asciiFive = determine_ascii_value(five);

	six = read_character(infile);
	asciiSix = determine_ascii_value(six);

	seven = read_character(infile);
	asciiSeven = determine_ascii_value(seven);

	eight = read_character(infile);
	asciiEight = determine_ascii_value(eight);

	nine = read_character(infile);
	asciiNine = determine_ascii_value(nine);

	ten = read_character(infile);
	asciiTen = determine_ascii_value(ten);

	/* The following are the counting variables added to a "total" variable used in the "output_stats.dat" file. */
	current_lines = number_lines(one, proxy) + number_lines(two, proxy) + number_lines(three, proxy) + number_lines(four, proxy) + number_lines(five, proxy) +
		number_lines(six, proxy) + number_lines(seven, proxy) + number_lines(eight, proxy) + number_lines(nine, proxy) + number_lines(ten, proxy);

	current_vowels = number_vowels(one, proxy) + number_vowels(two, proxy) + number_vowels(three, proxy) + number_vowels(four, proxy) + number_vowels(five, proxy) +
		number_vowels(six, proxy) + number_vowels(seven, proxy) + number_vowels(eight, proxy) + number_vowels(nine, proxy) + number_vowels(ten, proxy);

	current_digits = number_digits(one, proxy) + number_digits(two, proxy) + number_digits(three, proxy) + number_digits(four, proxy) + number_digits(five, proxy) +
		number_digits(six, proxy) + number_digits(seven, proxy) + number_digits(eight, proxy) + number_digits(nine, proxy) + number_digits(ten, proxy);

	current_alphas = number_alphas(one, proxy) + number_alphas(two, proxy) + number_alphas(three, proxy) + number_alphas(four, proxy) + number_alphas(five, proxy) +
		number_alphas(six, proxy) + number_alphas(seven, proxy) + number_alphas(eight, proxy) + number_alphas(nine, proxy) + number_alphas(ten, proxy);

	current_lowers = number_lowers(one, proxy) + number_lowers(two, proxy) + number_lowers(three, proxy) + number_lowers(four, proxy) + number_lowers(five, proxy) +
		number_lowers(six, proxy) + number_lowers(seven, proxy) + number_lowers(eight, proxy) + number_lowers(nine, proxy) + number_lowers(ten, proxy);

	current_uppers = number_uppers(one, proxy) + number_uppers(two, proxy) + number_uppers(three, proxy) + number_uppers(four, proxy) + number_uppers(five, proxy) +
		number_uppers(six, proxy) + number_uppers(seven, proxy) + number_uppers(eight, proxy) + number_uppers(nine, proxy) + number_uppers(ten, proxy);

	current_spaces = number_spaces(one, proxy) + number_spaces(two, proxy) + number_spaces(three, proxy) + number_spaces(four, proxy) + number_spaces(five, proxy) +
		number_spaces(six, proxy) + number_spaces(seven, proxy) + number_spaces(eight, proxy) + number_spaces(nine, proxy) + number_spaces(ten, proxy);

	current_alnums = number_alnums(one, proxy) + number_alnums(two, proxy) + number_alnums(three, proxy) + number_alnums(four, proxy) + number_alnums(five, proxy) +
		number_alnums(six, proxy) + number_alnums(seven, proxy) + number_alnums(eight, proxy) + number_alnums(nine, proxy) + number_alnums(ten, proxy);

	current_puncts = number_puncts(one, proxy) + number_puncts(two, proxy) + number_puncts(three, proxy) + number_puncts(four, proxy) + number_puncts(five, proxy) +
		number_puncts(six, proxy) + number_puncts(seven, proxy) + number_puncts(eight, proxy) + number_puncts(nine, proxy) + number_puncts(ten, proxy);

	/* The following function calls print the ascii values of the first ten characters to the "outut_ascii.dat" file. */
	print_int(outputAscii, asciiOne);
	print_int(outputAscii, asciiTwo);
	print_int(outputAscii, asciiThree);
	print_int(outputAscii, asciiFour);
	print_int(outputAscii, asciiFive);
	print_int(outputAscii, asciiSix);
	print_int(outputAscii, asciiSeven);
	print_int(outputAscii, asciiEight);
	print_int(outputAscii, asciiNine);
	print_int(outputAscii, asciiTen);

	/* The following functions calls use the character arrays and "total" varaibles to print data to the "output_stats.dat" file. */
	print_stats(outputStats, headerLines, current_lines);
	print_stats(outputStats, headerVowels, current_vowels);
	print_stats(outputStats, headerDigits, current_digits);
	print_stats(outputStats, headerAlphas, current_alphas);
	print_stats(outputStats, headerLowers, current_lowers);
	print_stats(outputStats, headerUppers, current_uppers);
	print_stats(outputStats, headerSpaces, current_spaces);
	print_stats(outputStats, headerAlnums, current_alnums);
	print_stats(outputStats, headerPuncts, current_puncts);

	/* Last but not least, this function call closes all three files used. */
	close(infile, outputAscii, outputStats);

	return 0;
}
