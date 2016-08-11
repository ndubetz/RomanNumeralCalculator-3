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
    {1000,  "M"},
    { 500,  "D"},
    { 100,  "C"},
    {  50,  "L"},
    {  10,  "X"},
    {   5,  "V"},
    {   1,  "I"}
};

void Converter_arabic_to_roman(char * numeral, int number)
{
	int i;
	for(i = 0; i < 7; i++)
	{
		if (number == ARABIC_TO_ROMAN[i].arabic) 
		{
			strcat(numeral, ARABIC_TO_ROMAN[i].roman);			
		}
	}
}
