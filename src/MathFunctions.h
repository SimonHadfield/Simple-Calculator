#pragma once

long double add(long double x, long double y)
{
	return x + y;
}

long double multiply(long double x, long double y)
{
	return x * y;
}

long double power(long double x, long double exp)
{
	return pow(x, exp);
}

long mod(long double x, long double divisor)
{
	return divisor != 0 ? (long)x % (long)divisor : 0.0;
}

long double division(long double x, long double divisor)
{
	return divisor != 0 ? x / divisor : 0.0;
}

long double factorial(unsigned int x)
{
	// base cases
	if (x == 0) { return 1; } // 0! = 1
	if (x == 1) { return 1; } // 1! = 1
	else if (x > 1)
	{
		return x * factorial(x - 1);
	}
}