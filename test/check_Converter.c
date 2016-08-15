#include <stdlib.h>
#include <string.h>
#include <check.h>

#include "check_Converter.h"
#include "../src/Converter.h"

void test_arabic_to_roman(int number, char * expectedResult)
{
	char buffer[30];
	memset(buffer, 0, 30);
	Converter_arabic_to_roman(buffer, number);
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

TCase * ConverterTests()
{
	TCase * tc;
	tc = tcase_create("ConverterTests");
	tcase_add_test(tc, arabic_to_roman_single_digits);
	tcase_add_test(tc, arabic_to_roman_multiple_digits);
	return tc;
}
