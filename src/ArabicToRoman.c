#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ArabicToRoman.h"
#include "ConversionMap.h"

#define LOWER_BOUND 0
#define UPPER_BOUND 4000

const struct ConversionMap ARABIC_TO_ROMAN[] =
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

static void write_error(char * buffer, char * message)
{
	strcat(buffer, message);
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

static bool number_can_be_converted(int number)
{
	return LOWER_BOUND < number && number < UPPER_BOUND;
} 

void ArabicToRoman_convert(char * buffer, int number)
{
	if(number_can_be_converted(number))
	{
		convert_to_roman(buffer, number);
	} 
	else
	{
		write_error(buffer, "Result cannot be displayed as a roman numeral.");
	}
}

