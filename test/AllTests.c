#include <stdlib.h>
#include <check.h>

#include "check_NumeralValidator.h"
#include "check_ArabicToRoman.h"
#include "check_RomanToArabic.h"
#include "check_Calculator.h"

Suite * RomanNumeralSuite(void)
{
	Suite * s;
	s = suite_create("AllTests"); 
	suite_add_tcase(s, NumeralValidatorTests());
	suite_add_tcase(s, ArabicToRomanTests());
	suite_add_tcase(s, RomanToArabicTests());
	suite_add_tcase(s, CalculatorTests());
	return s;
}

int main(int argc, char **argv)
{
	Suite * s;
	SRunner * runner;
	int number_fails;
	
	s = RomanNumeralSuite();
	runner = srunner_create(s);
	srunner_run_all(runner, CK_NORMAL);
	number_fails = srunner_ntests_failed(runner);
	srunner_free(runner);

	return number_fails;
}
