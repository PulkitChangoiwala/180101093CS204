#include <iostream>
#include <math.h>
using namespace std;
int isPrime(long long n)
{
	if(n <= 1)
	return false;
	for(int i = 2; i <= sqrt(n); i++)
	if(n % i == 0)
		return 0;
	return 1;
}
int main()
{
	int testcases;
	long long int b;
	cin >>testcases;
	while(testcases> 0)
	{
	cin >> b;
	if(isPrime(b))
	{
		cout << "Prime\n";
	}
	else
	{
		cout << "Not Prime\n";
	}
	testcases--;
	}
	return 0;
}
