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
	return (long)x % (long)divisor;
}

long double division(long double x, long double divisor)
{
	return x / divisor;
}