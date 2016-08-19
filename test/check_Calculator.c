#include <stdlib.h>
#include <string.h>
#include <check.h>

#include "check_Calculator.h"
#include "../src/Calculator.h"

void test_addition(char * numeral1, char * numeral2, char * result)
{
	char buffer[50];
	memset(buffer, 0, 50);
	Calculator_add(buffer, numeral1, numeral2);
	ck_assert_str_eq(buffer, result);
}

void test_subtraction(char * numeral1, char * numeral2, char * result)
{
	char buffer[50];
	memset(buffer, 0, 50);
	Calculator_subtract(buffer, numeral1, numeral2);
	ck_assert_str_eq(buffer, result);
}

START_TEST (Calculator_adds_two_numerals)
{
	test_addition("MCXI", "MMCCXXII", "MMMCCCXXXIII");
	test_addition("CCXXII", "CCXXII", "CDXLIV");
	test_addition("CCCXXXIII", "CCCXXXIII", "DCLXVI");
	test_addition("CDXLIV", "CCXXII", "DCLXVI");
	test_addition("DCLXVI", "DCLXVI", "MCCCXXXII");
	test_addition("CMCXIX", "DLV", "MDLXXIV");
	test_addition("MDCLXVI", "CCCXXXIII", "MCMXCIX");
}
END_TEST

START_TEST (Calculator_add_error_cases)
{
	char * error_message = "Result cannot be displayed as a roman numeral.";
	test_addition("MM", "MM", error_message);
	test_addition("MM", "MMI", error_message);
	test_addition("EMACS", "VIM", error_message);
}
END_TEST

START_TEST (Calculator_subtracts_two_numerals)
{
	test_subtraction("MMMDCLXVII", "MMDCLXVI", "MI");
	test_subtraction("MM", "DCLXVI", "MCCCXXXIV");
	test_subtraction("MM", "MCMXCIX", "I");
	test_subtraction("MDCCLXXVII", "CMXXXIX", "DCCCXXXVIII");
	test_subtraction("MMMCDLIV", "MMMCCXLV", "CCIX");
	test_subtraction("MMM", "MMI", "CMXCIX");
	test_subtraction("MMDLV", "MCMXCIX", "DLVI");
}
END_TEST

START_TEST (Calculator_subtract_error_cases)
{
	char * error_message = "Result cannot be displayed as a roman numeral.";
	test_subtraction("MMM", "MMM", error_message);
	test_subtraction("MMM", "MMMI", error_message);
	test_subtraction("GNU", "MIT", error_message);
}
END_TEST

TCase * CalculatorTests()
{
	TCase * tc;
	tc = tcase_create("CalculatorTests");
	tcase_add_test(tc, Calculator_adds_two_numerals);
	tcase_add_test(tc, Calculator_add_error_cases);
	tcase_add_test(tc, Calculator_subtracts_two_numerals);
	tcase_add_test(tc, Calculator_subtract_error_cases);
	return tc;
}

