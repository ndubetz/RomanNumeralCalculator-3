#include <stdlib.h>
#include <string.h>
#include <check.h>

#include "check_ArabicToRoman.h"
#include "../src/ArabicToRoman.h"

void test_arabic_to_roman(int number, char * expectedResult)
{
	char buffer[50];
	memset(buffer, 0, 50);
	ArabicToRoman_convert(buffer, number);
	ck_assert_str_eq(buffer, expectedResult);
}

START_TEST (arabic_to_roman_single_digits)
{
	test_arabic_to_roman(1,    "I");
	test_arabic_to_roman(5,    "V");
	test_arabic_to_roman(10,   "X");
	test_arabic_to_roman(50,   "L");
	test_arabic_to_roman(100,  "C");
	test_arabic_to_roman(500,  "D");
	test_arabic_to_roman(1000, "M");
}
END_TEST

START_TEST (arabic_to_roman_multiple_digits)
{
	test_arabic_to_roman(1666, "MDCLXVI");
	test_arabic_to_roman(2222, "MMCCXXII");
	test_arabic_to_roman(3888, "MMMDCCCLXXXVIII");
}
END_TEST

START_TEST (arabic_to_roman_subtraction_cases)
{
	test_arabic_to_roman(3999, "MMMCMXCIX");
	test_arabic_to_roman(2444, "MMCDXLIV");
	test_arabic_to_roman(1949, "MCMXLIX");
	test_arabic_to_roman(494, "CDXCIV");
}
END_TEST

START_TEST (arabic_to_roman_error_cases)
{
	char * error_message = "Result cannot be displayed as a roman numeral.";
	test_arabic_to_roman(4001, error_message);
	test_arabic_to_roman(4000, error_message);
	test_arabic_to_roman(0,    error_message);
	test_arabic_to_roman(-1,   error_message);
}
END_TEST

TCase * ArabicToRomanTests()
{
	TCase * tc;
	tc = tcase_create("ArabicToRomanTests");
	tcase_add_test(tc, arabic_to_roman_single_digits);
	tcase_add_test(tc, arabic_to_roman_multiple_digits);
	tcase_add_test(tc, arabic_to_roman_subtraction_cases);
	tcase_add_test(tc, arabic_to_roman_error_cases);
	return tc;
}
