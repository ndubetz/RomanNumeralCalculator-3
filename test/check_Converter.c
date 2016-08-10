#include <stdlib.h>
#include <string.h>
#include <check.h>

#include "check_Converter.h"
#include "../src/Converter.h"


START_TEST (convert_to_single_roman_digits)
{
	char buffer[30];
	memset(buffer, 0, 30);
	Converter_arabic_to_roman(buffer, 1);
	ck_assert_str_eq(buffer, "I");
}
END_TEST

TCase * ConverterTests()
{
	TCase * tc;
	tc = tcase_create("ConverterTests");
	tcase_add_test(tc, convert_to_single_roman_digits);
	return tc;
}
