#include <stdlib.h>
#include <string.h>
#include <check.h>

#include "check_RomanToArabic.h"
#include "../src/RomanToArabic.h"


START_TEST (roman_to_arabic_single_digits)
{
	ck_assert_int_eq(1,    RomanToArabic_convert("I")); 
	ck_assert_int_eq(5,    RomanToArabic_convert("V")); 
	ck_assert_int_eq(10,   RomanToArabic_convert("X")); 
	ck_assert_int_eq(50,   RomanToArabic_convert("L")); 
	ck_assert_int_eq(100,  RomanToArabic_convert("C")); 
	ck_assert_int_eq(500,  RomanToArabic_convert("D")); 
	ck_assert_int_eq(1000, RomanToArabic_convert("M")); 
}
END_TEST

START_TEST (roman_to_arabic_multiple_digits)
{
	ck_assert_int_eq(1111, RomanToArabic_convert("MCXI")); 
	ck_assert_int_eq(1777, RomanToArabic_convert("MDCCLXXVII")); 
	ck_assert_int_eq(2333, RomanToArabic_convert("MMCCCXXXIII")); 
	ck_assert_int_eq(2555, RomanToArabic_convert("MMDLV")); 
	ck_assert_int_eq(3111, RomanToArabic_convert("MMMCXI")); 
	ck_assert_int_eq(3777, RomanToArabic_convert("MMMDCCLXXVII")); 
	ck_assert_int_eq(3888, RomanToArabic_convert("MMMDCCCLXXXVIII")); 
}
END_TEST

START_TEST (roman_to_arabic_subtraction_cases)
{
	ck_assert_int_eq(444,  RomanToArabic_convert("CDXLIV")); 
	ck_assert_int_eq(999,  RomanToArabic_convert("CMXCIX")); 
	ck_assert_int_eq(1494, RomanToArabic_convert("MCDXCIV")); 
	ck_assert_int_eq(1949, RomanToArabic_convert("MCMXLIX")); 
	ck_assert_int_eq(2499, RomanToArabic_convert("MMCDXCIX")); 
	ck_assert_int_eq(2944, RomanToArabic_convert("MMCMXLIV")); 
	ck_assert_int_eq(3449, RomanToArabic_convert("MMMCDXLIX")); 
	ck_assert_int_eq(3994, RomanToArabic_convert("MMMCMXCIV")); 
	ck_assert_int_eq(3999, RomanToArabic_convert("MMMCMXCIX")); 
}
END_TEST

START_TEST (roman_to_arabic_invalid_numerals_return_negative_number)
{
	ck_assert_int_gt(0, RomanToArabic_convert("PBJ")); 
	ck_assert_int_gt(0, RomanToArabic_convert("MICH")); 
	ck_assert_int_gt(0, RomanToArabic_convert("0")); 
}
END_TEST

TCase * RomanToArabicTests()
{
	TCase * tc;
	tc = tcase_create("RomanToArabicTests");
	tcase_add_test(tc, roman_to_arabic_single_digits);
	tcase_add_test(tc, roman_to_arabic_multiple_digits);
	tcase_add_test(tc, roman_to_arabic_subtraction_cases);
	tcase_add_test(tc, roman_to_arabic_invalid_numerals_return_negative_number);
	return tc;
}
