#include "tests.h"

int main()
{
	/* { "tws": 1945, "d": [ {"v": 1}, {"v": 2}, {"v": 3}, {"v": 4}, {"v": 5} ] } */
	TestNumericNlohmann(NUMBERS_OF_SAMPLES);
	TestNumericRapid(NUMBERS_OF_SAMPLES);

	/* { "tws": 1945, "d": {"v": [1, 2, 3, 4, 5, 6]} } */
	TestNumericNlohmannWithVect(NUMBERS_OF_SAMPLES);
	TestNumericRapidWithVect(NUMBERS_OF_SAMPLES);

	system("pause");
	return 0;
}