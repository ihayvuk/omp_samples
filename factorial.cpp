#include <iostream>

using namespace std;

long factorial(int number)
{
   long fac = 1;

   #pragma omp parallel for reduction(* : fac)
   for (int n = 2; n <= number; ++n)
   {
		fac *= n;
   }

   return fac;
}

int main()
{
	const int n = 10;

	long fact_n = factorial(n);
	cout << "factorial(" << n << ") = " << fact_n << endl;

	return 0;
}

