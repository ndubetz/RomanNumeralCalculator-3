#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <check.h>

#include "check_NumeralValidator.h"
#include "../src/NumeralValidator.h"

START_TEST(rejects_illegal_characters)
{
	ck_assert_int_eq(NumeralValidator_isValid("pI"), false);	
	ck_assert_int_eq(NumeralValidator_isValid("rV"), false);	
	ck_assert_int_eq(NumeralValidator_isValid("oX"), false);	
	ck_assert_int_eq(NumeralValidator_isValid("Lk"), false);	
	ck_assert_int_eq(NumeralValidator_isValid("C1"), false);	
	ck_assert_int_eq(NumeralValidator_isValid("DA"), false);	
	ck_assert_int_eq(NumeralValidator_isValid("MDCLXVI"), true);	
}
END_TEST

TCase * NumeralValidatorTests()
{
	TCase * tc;
	tc = tcase_create("NumeralValidatorTests");
	tcase_add_test(tc, rejects_illegal_characters);	
	return tc;
}

