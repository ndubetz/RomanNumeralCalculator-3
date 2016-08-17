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
	test_addition("MCXI", "MMXXCCII", "MMMCCCXXXIII");
	test_addition("CCXXII", "CCXXII", "CDXLIV");
	test_addition("CCCXXXIII", "CCCXXXIII", "DCLXVI");
	test_addition("CDXLIV", "CCXXII", "DCLXVI");
	test_addition("DCLXVI", "DCLXVI", "MCCXXII");
	test_addition("CMCXIX", "DLV", "MCDXLIV");
	test_addition("MDCLXVI", "CCCXXXIII", "MCMXCIX");
}
END_TEST

TCase * CalculatorTests()
{
	TCase * tc;
	tc = tcase_create("CalculatorTests");
	tcase_add_test(tc, Calculator_adds_two_numerals);
	return tc;
}

