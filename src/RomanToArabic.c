#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "RomanToArabic.h"
#include "ConversionMap.h"

#define NUMBER_OF_ROMAN_NUMERALS 7
#define INVALID_NUMERAL_VALUE -9999

const struct ConversionMap ROMAN_TO_ARABIC[] =
{
    { 1000,  "M" },
    {  500,  "D" },
    {  100,  "C" },
    {   50,  "L" },
    {   10,  "X" },
    {    5,  "V" },
    {    1,  "I" }
};

static int convert_numeral(char numeral, int previous_number)
{
	const char numeral_as_string[] = {numeral, '\0'};
	int j;
	
	for(j = 0; j < NUMBER_OF_ROMAN_NUMERALS; j++)
	{	
		if(strcmp(numeral_as_string, ROMAN_TO_ARABIC[j].roman) == 0)
		{
			return (ROMAN_TO_ARABIC[j].arabic >= previous_number)
				?  ROMAN_TO_ARABIC[j].arabic
				: -ROMAN_TO_ARABIC[j].arabic;
		}		
	}
	return INVALID_NUMERAL_VALUE;
}

int RomanToArabic_convert(char * numeral)
{
	int number = 0;
	int previous_number = 0;
	int i;
	for(i = strlen(numeral); i--;)
	{
		int numeral_value = convert_numeral(numeral[i], previous_number);
		number += numeral_value; 
		previous_number = numeral_value;
	}
	return number;
}
