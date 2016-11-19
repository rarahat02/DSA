#include<iostream>

using namespace std;

long long int factorial(long long int n)
{
	if(n ==1) return 1;
	else return n*factorial(n-1);
}

int main (void)
{
	long long int output, input;
	cin >> input;
	
	output = factorial(input);
	cout << output << endl;
	return 0;
}
