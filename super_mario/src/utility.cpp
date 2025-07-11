#include "utility.h"

int sign(int n)
{
	int s = 0;
	if (n > 0)
		s = 1;
	else if (n < 0)
		s = -1;
	return s;
}
