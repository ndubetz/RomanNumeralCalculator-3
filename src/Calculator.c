#include <stdlib.h>
#include <string.h>

#include "Converter.h"
#include "Calculator.h"

void Calculator_add(char * buffer, char * numeral1, char * numeral2)
{
	int sum = Converter_roman_to_arabic(numeral1) + Converter_roman_to_arabic(numeral2);
	Converter_arabic_to_roman(buffer, sum);
}

void Calculator_subtract(char * buffer, char * numeral1, char * numeral2)
{
	int difference = Converter_roman_to_arabic(numeral1) - Converter_roman_to_arabic(numeral2);
	Converter_arabic_to_roman(buffer, difference);
}

