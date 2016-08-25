#include <stdlib.h>
#include <string.h>

#include "ArabicToRoman.h"
#include "RomanToArabic.h"
#include "Calculator.h"

void Calculator_add(char * buffer, char * numeral1, char * numeral2)
{
	const int sum = RomanToArabic_convert(numeral1) + RomanToArabic_convert(numeral2);
	ArabicToRoman_convert(buffer, sum);
}

void Calculator_subtract(char * buffer, char * numeral1, char * numeral2)
{
	const int difference = RomanToArabic_convert(numeral1) - RomanToArabic_convert(numeral2);
	ArabicToRoman_convert(buffer, difference);
}

