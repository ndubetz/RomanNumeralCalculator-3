#include <stdlib.h>
#include <string.h>
#include <check.h>

#include "check_Calculator.h"
#include "../src/Calculator.h"


START_TEST (Calculator_add_basic_cases)
{
	char buffer[50];
	memset(buffer, 0, 50);
	Calculator_add(buffer, "I", "I");
	ck_assert_str_eq(buffer, "II");
}
END_TEST

TCase * CalculatorTests()
{
	TCase * tc;
	tc = tcase_create("CalculatorTests");
	tcase_add_test(tc, Calculator_add_basic_cases);
	return tc;
}

