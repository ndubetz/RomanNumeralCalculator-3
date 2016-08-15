#include <stdlib.h>
#include <string.h>

#include "Converter.h"

struct conversion_map 
{
	const int arabic;
	const char * roman;
};

struct conversion_map ARABIC_TO_ROMAN[] =
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

struct conversion_map ROMAN_TO_ARABIC[] =
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

void Converter_arabic_to_roman(char * buffer, int number)
{
	if(number >= 4000 || number <= 0)
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
		const char numeral_as_string[] = {numeral[i], '\0'};
		int j;
		for(j = 0; j < 7; j++)
		{	
			if(strcmp(numeral_as_string, ROMAN_TO_ARABIC[j].roman) == 0)
			{
				number += (ROMAN_TO_ARABIC[j].arabic >= previous_number)
					?  ROMAN_TO_ARABIC[j].arabic
					: -ROMAN_TO_ARABIC[j].arabic;
				previous_number = ROMAN_TO_ARABIC[j].arabic;
			}		
		}
	}
	return number;
}
