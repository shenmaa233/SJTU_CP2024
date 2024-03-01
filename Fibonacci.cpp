#include <cstdio>
#define MAXN 1000000

int F[MAXN] = {0};

int Fibonacci(int n)
{
	if (n == 0)
		return 0;
	if (F[n])
		return F[n];
	else
		return F[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main()
{
	F[1] = 1;
	std::printf("Fn for n= 7, 15, 31 is %d, %d, %d respectively", Fibonacci(7), Fibonacci(15), Fibonacci(31));
	return 0;
}