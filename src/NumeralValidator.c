#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "NumeralValidator.h"

const char * VALID_ROMAN_NUMERAL_DIGITS = "IVXLCDM";
const int INVALID_NUMERAL_VALUE = -1;

static bool is_valid_numeral_digit(const char digit)
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

static int map_roman_digit_to_int(const char digit)
{
	int i;
	for(i = 0; i < strlen(VALID_ROMAN_NUMERAL_DIGITS); i++)
	{
		if(digit == VALID_ROMAN_NUMERAL_DIGITS[i])
		{
			return i;
		}
	}
	return INVALID_NUMERAL_VALUE;
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

static void map_numerals_to_ints(int * numerals_as_ints, const char * numeral)
{
	int i;
	for(i = 0; i < strlen(numeral); i++)
	{
		numerals_as_ints[i] = map_roman_digit_to_int(numeral[i]);	
	}
}

static bool numerals_are_in_order(const int * numerals_as_ints, const int length)
{
	int i;
	int order = 8;
	for(i = 0; i < length; i++)
	{
		if(numerals_as_ints[i] > order)
		{
			return false;
		}
		else
		{
			order = numerals_as_ints[i];
		}
	}
	return true;
} 

bool NumeralValidator_isValid(const char * numeral)
{
	int numerals_as_ints[strlen(numeral)];
	map_numerals_to_ints(numerals_as_ints, numeral);
	
	if(!numerals_are_in_order(numerals_as_ints, strlen(numeral)))
	{
		return false;
	}
	if(!are_all_valid_numerals(numeral))
	{
		return false;
	}
	return true;
}

