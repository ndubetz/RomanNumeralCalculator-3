#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "NumeralValidator.h"

const char * VALID_ROMAN_NUMERAL_DIGITS = "MDCLXVI";
const int INVALID_NUMERAL_VALUE = -1;
const int MAX_FREQUENCY_FOR_ONES_DIGITS = 3;
const int MAX_FREQUENCY_FOR_FIVES_DIGITS = 1;

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
	if(numeral % 2 == 0)
	{
		return frequency > MAX_FREQUENCY_FOR_ONES_DIGITS;
	}
	return frequency > MAX_FREQUENCY_FOR_FIVES_DIGITS;
}

static bool is_a_valid_numeral(const int * numerals_as_ints, const int length)
{
	int i;
	int previous = INVALID_NUMERAL_VALUE;
	int frequency = 0;
	for(i = 0; i < length; i++)
	{
		if(numerals_as_ints[i] == INVALID_NUMERAL_VALUE)
		{
			return false;
		}
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
	
	if(is_a_valid_numeral(numerals_as_ints, strlen(numeral)))
	{
		return true;
	}
	return false;
}

