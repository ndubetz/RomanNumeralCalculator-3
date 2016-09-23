#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "NumeralValidator.h"

const char * VALID_ROMAN_NUMERAL_DIGITS = "MDCLXVI";
const int INVALID_NUMERAL_VALUE = -1;

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

static bool are_all_valid_numerals(int * numerals_as_ints, int length)
{
	int i;
	for(i = 0; i < length; i++)
	{
		if(numerals_as_ints[i] == INVALID_NUMERAL_VALUE)
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

static bool is_legal_subtraction(const int numeral_as_int, const int previous)
{
	return (numeral_as_int == (previous - 2) || numeral_as_int == (previous - 1))
			&& previous % 2 == 0; 
}

static bool numeral_occurs_too_many_times(const int numeral, const int frequency)
{
	return (numeral % 2 == 0 && frequency > 3)
		|| (numeral % 2 == 1 && frequency > 1);
}

static bool numerals_are_in_order(const int * numerals_as_ints, const int length)
{
	int i;
	int previous = INVALID_NUMERAL_VALUE;
	int frequency = 0;
	for(i = 0; i < length; i++)
	{
		if(numerals_as_ints[i] >= previous 
		 || is_legal_subtraction(numerals_as_ints[i], previous))
		{
			if(numerals_as_ints[i] == previous)
			{
				frequency++;
			}
			else
			{
				frequency = 1;
			}
			if(numeral_occurs_too_many_times(numerals_as_ints[i], frequency))
			{
				return false;
			}
			previous = numerals_as_ints[i];
		}
		else
		{
			return false;
		}
	}
	return true;
} 

bool NumeralValidator_isValid(const char * numeral)
{
	int numerals_as_ints[strlen(numeral)];
	map_numerals_to_ints(numerals_as_ints, numeral);
	
	if(!(numerals_are_in_order(numerals_as_ints, strlen(numeral))
	&& are_all_valid_numerals(numerals_as_ints, strlen(numeral))))
	{
		return false;
	}
	return true;
}

