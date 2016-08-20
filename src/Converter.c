#include <stdlib.h>
#include <string.h>

#include "Converter.h"

#define NUMBER_OF_ROMAN_NUMERALS 7
#define LOWER_BOUND 0
#define UPPER_BOUND 4000
#define INVALID_NUMERAL_VALUE -9999

struct conversion_map 
{
	const int arabic;
	const char * roman;
};

const struct conversion_map ARABIC_TO_ROMAN[] =
{
    { 1000,  "M" },
    {  900, "CM" },
    {  500,  "D" },
    {  400, "CD" },
    {  100,  "C" },
    {   90, "XC" },
    {   50,  "L" },
    {   40, "XL" },
    {   10,  "X" },
    {    9, "IX" },
    {    5,  "V" },
    {    4, "IV" },
    {    1,  "I" }
};

const struct conversion_map ROMAN_TO_ARABIC[] =
{
    { 1000,  "M" },
    {  500,  "D" },
    {  100,  "C" },
    {   50,  "L" },
    {   10,  "X" },
    {    5,  "V" },
    {    1,  "I" }
};

static void write_error(char * buffer)
{
	strcat(buffer, "Result cannot be displayed as a roman numeral.");
}

static void convert_to_roman(char * buffer, int number)
{
	int i = 0;
	while(number)
	{
		if (number >= ARABIC_TO_ROMAN[i].arabic) 
		{
			strcat(buffer, ARABIC_TO_ROMAN[i].roman);
			number -= ARABIC_TO_ROMAN[i].arabic;		
		}
		else
		{
			i++;
		}
	}
}

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



void Converter_arabic_to_roman(char * buffer, int number)
{
	if(number >= UPPER_BOUND || number <= LOWER_BOUND)
	{
		write_error(buffer);
	} 
	else
	{
		convert_to_roman(buffer, number);
	}
}

int Converter_roman_to_arabic(char * numeral)
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
