#include <stdlib.h>
#include <string.h>

#include "Converter.h"

struct arabic_to_roman 
{
	const int arabic;
	const char * roman;
};

struct arabic_to_roman ARABIC_TO_ROMAN[] =
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

void Converter_arabic_to_roman(char * numeral, int number)
{
	int i = 0;
	while(number)
	{
		if (number >= ARABIC_TO_ROMAN[i].arabic) 
		{
			strcat(numeral, ARABIC_TO_ROMAN[i].roman);
			number -= ARABIC_TO_ROMAN[i].arabic;		
		}
		else
		{
			i++;
		}
	}
}
