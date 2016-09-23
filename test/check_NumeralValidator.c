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

START_TEST(allows_legal_subtractions)
{
	ck_assert_int_eq(NumeralValidator_isValid("MCMXCIX"), true);	
	ck_assert_int_eq(NumeralValidator_isValid("MCDXLIV"), true);
}
END_TEST

START_TEST(rejects_numerals_where_ones_digits_appears_more_than_thrice_in_a_row)
{
	ck_assert_int_eq(NumeralValidator_isValid("MMMM"), false);	
	ck_assert_int_eq(NumeralValidator_isValid("CCCC"), false);	
	ck_assert_int_eq(NumeralValidator_isValid("XXXX"), false);	
	ck_assert_int_eq(NumeralValidator_isValid("IIII"), false);	
	ck_assert_int_eq(NumeralValidator_isValid("MMMCM"), true);	
	ck_assert_int_eq(NumeralValidator_isValid("CCCXC"), true);	
	ck_assert_int_eq(NumeralValidator_isValid("XXXIX"), true);		
}
END_TEST

TCase * NumeralValidatorTests()
{
	TCase * tc;
	tc = tcase_create("NumeralValidatorTests");
	tcase_add_test(tc, rejects_illegal_characters);	
	tcase_add_test(tc, rejects_illegal_ordering);	
	tcase_add_test(tc, allows_legal_subtractions);	
	tcase_add_test(tc, rejects_numerals_where_ones_digits_appears_more_than_thrice_in_a_row);	
	return tc;
}

