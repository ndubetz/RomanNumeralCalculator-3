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

START_TEST(rejects_illegal_ordering)
{
	ck_assert_int_eq(NumeralValidator_isValid("VIL"), false);	
	ck_assert_int_eq(NumeralValidator_isValid("MIC"), false);	
	ck_assert_int_eq(NumeralValidator_isValid("CID"), false);	
	ck_assert_int_eq(NumeralValidator_isValid("VIM"), false);	
	ck_assert_int_eq(NumeralValidator_isValid("DLVX"), false);	
	ck_assert_int_eq(NumeralValidator_isValid("CCVL"), false);	
	ck_assert_int_eq(NumeralValidator_isValid("VCII"), false);	
	ck_assert_int_eq(NumeralValidator_isValid("MVM"), false);	
	ck_assert_int_eq(NumeralValidator_isValid("DVD"), false);	
	ck_assert_int_eq(NumeralValidator_isValid("LXIC"), false);	
	ck_assert_int_eq(NumeralValidator_isValid("LC"), false);	
}
END_TEST

TCase * NumeralValidatorTests()
{
	TCase * tc;
	tc = tcase_create("NumeralValidatorTests");
	tcase_add_test(tc, rejects_illegal_characters);	
	tcase_add_test(tc, rejects_illegal_ordering);	
	return tc;
}

