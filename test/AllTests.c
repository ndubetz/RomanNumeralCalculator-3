#include <stdlib.h>
#include <check.h>

#include "check_Converter.h"

Suite * RomanNumeralSuite(void)
{
	Suite * s;
	s = suite_create("AllTests"); 
	suite_add_tcase(s, ConverterTests());
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
