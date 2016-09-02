#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "NumeralValidator.h"

const char * VALID_ROMAN_NUMERALS = "IVXLCDM";

static bool is_valid_numeral(char numeral)
{
	int i;
	for(i = 0; i < strlen(VALID_ROMAN_NUMERALS); i++)
	{
		if(numeral == VALID_ROMAN_NUMERALS[i])
		{
			return true;
		}
	}
	return false;
}

bool NumeralValidator_isValid(const char * numeral)
{

	int i;
	for(i = 0; i < strlen(numeral); i++)
	{
		if(!is_valid_numeral(numeral[i]))
		{
			return false;
		}
	}
	return true;
}

