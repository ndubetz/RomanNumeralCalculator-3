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

TCase * CalculatorTests()
{
	TCase * tc;
	tc = tcase_create("CalculatorTests");
	tcase_add_test(tc, Calculator_adds_two_numerals);
	tcase_add_test(tc, Calculator_add_error_cases);
	return tc;
}

