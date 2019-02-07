#include<iostream>
#include<assert.h>

//This code shows how to calculate Fibonacci number using two different ways.
//The first is using naive algorithm and the second using fast algorithm.

long long int fibonacci_naive(long long int n)
{
	if (n <= 1)
	{
		return n;
	}
	return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}


long long int fibonacci_fast(long long int n)
{

	long long int *f = (long long int*)malloc((n+1)*sizeof(long long int));//The problem was with the size of the array we need one extra space because we are returning F[n]
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
	}
	return f[n];

}


int test_solution()
{
	for (int n = 0; n <= 20; n++)
	{
		assert(fibonacci_fast(3) == 2);
		assert(fibonacci_fast(10) == 55);
		for (int n = 0; n < 20; ++n)
			assert(fibonacci_fast(n) == fibonacci_naive(n));
	}
	return 0;
}


	int main()
	{
		long long int n = 0;
		std::cin >> n;
		long long int F;
		F = fibonacci_fast(n);
		std::cout << F <<std::endl;
		//test_solution();
		//system("pause");
		return 0;
	}
