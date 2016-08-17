#include <stdlib.h>
#include <string.h>
#include <check.h>

#include "check_Converter.h"
#include "../src/Converter.h"

void test_arabic_to_roman(int number, char * expectedResult)
{
	char buffer[50];
	memset(buffer, 0, 50);
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

START_TEST (roman_to_arabic_single_digits)
{
	ck_assert_int_eq(1,    Converter_roman_to_arabic("I")); 
	ck_assert_int_eq(5,    Converter_roman_to_arabic("V")); 
	ck_assert_int_eq(10,   Converter_roman_to_arabic("X")); 
	ck_assert_int_eq(50,   Converter_roman_to_arabic("L")); 
	ck_assert_int_eq(100,  Converter_roman_to_arabic("C")); 
	ck_assert_int_eq(500,  Converter_roman_to_arabic("D")); 
	ck_assert_int_eq(1000, Converter_roman_to_arabic("M")); 
}
END_TEST

START_TEST (roman_to_arabic_multiple_digits)
{
	ck_assert_int_eq(1111, Converter_roman_to_arabic("MCXI")); 
	ck_assert_int_eq(1777, Converter_roman_to_arabic("MDCCLXXVII")); 
	ck_assert_int_eq(2333, Converter_roman_to_arabic("MMCCCXXXIII")); 
	ck_assert_int_eq(2555, Converter_roman_to_arabic("MMDLV")); 
	ck_assert_int_eq(3111, Converter_roman_to_arabic("MMMCXI")); 
	ck_assert_int_eq(3777, Converter_roman_to_arabic("MMMDCCLXXVII")); 
	ck_assert_int_eq(3888, Converter_roman_to_arabic("MMMDCCCLXXXVIII")); 
}
END_TEST

START_TEST (roman_to_arabic_subtraction_cases)
{
	ck_assert_int_eq(444,  Converter_roman_to_arabic("CDXLIV")); 
	ck_assert_int_eq(999,  Converter_roman_to_arabic("CMXCIX")); 
	ck_assert_int_eq(1494, Converter_roman_to_arabic("MCDXCIV")); 
	ck_assert_int_eq(1949, Converter_roman_to_arabic("MCMXLIX")); 
	ck_assert_int_eq(2499, Converter_roman_to_arabic("MMCDXCIX")); 
	ck_assert_int_eq(2944, Converter_roman_to_arabic("MMCMXLIV")); 
	ck_assert_int_eq(3449, Converter_roman_to_arabic("MMMCDXLIX")); 
	ck_assert_int_eq(3994, Converter_roman_to_arabic("MMMCMXCIV")); 
	ck_assert_int_eq(3999, Converter_roman_to_arabic("MMMCMXCIX")); 
}
END_TEST

START_TEST (roman_to_arabic_invalid_numerals_return_negative_number)
{
	ck_assert_int_gt(0, Converter_roman_to_arabic("PBJ")); 
	ck_assert_int_gt(0, Converter_roman_to_arabic("MICH")); 
	ck_assert_int_gt(0, Converter_roman_to_arabic("0")); 
}
END_TEST

TCase * ConverterTests()
{
	TCase * tc;
	tc = tcase_create("ConverterTests");
	tcase_add_test(tc, arabic_to_roman_single_digits);
	tcase_add_test(tc, arabic_to_roman_multiple_digits);
	tcase_add_test(tc, arabic_to_roman_subtraction_cases);
	tcase_add_test(tc, arabic_to_roman_error_cases);
	tcase_add_test(tc, roman_to_arabic_single_digits);
	tcase_add_test(tc, roman_to_arabic_multiple_digits);
	tcase_add_test(tc, roman_to_arabic_subtraction_cases);
	tcase_add_test(tc, roman_to_arabic_invalid_numerals_return_negative_number);
	return tc;
}
