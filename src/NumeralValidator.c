#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "NumeralValidator.h"

const char * VALID_ROMAN_NUMERAL_DIGITS = "IVXLCDM";

static bool is_valid_numeral_digit(char digit)
{
	int i;
	for(i = 0; i < strlen(VALID_ROMAN_NUMERAL_DIGITS); i++)
	{
		if(digit == VALID_ROMAN_NUMERAL_DIGITS[i])
		{
			return true;
		}
	}
	return false;
}

static bool are_all_valid_numerals(const char * numeral)
{
	int i;
	for(i = 0; i < strlen(numeral); i++)
	{
		if(!is_valid_numeral_digit(numeral[i]))
		{
			return false;
		}
	}
	return true;
} 

bool NumeralValidator_isValid(const char * numeral)
{
	if(!are_all_valid_numerals(numeral))
	{
		return false;
	}
	return true;
}

