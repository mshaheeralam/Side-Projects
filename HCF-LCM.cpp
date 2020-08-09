#include <iostream>
using namespace std;

int main()
{

	int a = 0, b = 0, lcm = 0, hcf = 0;

	cout << "Enter first number\n";
	cin >> a;
	cout << "Enter second number\n";
	cin >> b;

	if (a == b)
		cout << "Both numbers are same\n";
	else if (a > b)
	{
		cout << a << " is greater than " << b << endl;
		lcm = a;
	}
	else
	{
		cout << b << " is greater than " << a << endl;
		lcm = b;
	}

	for (int x = 1; x >= 1; x++)
	{
		if (lcm % a == 0 && lcm % b == 0)
		{
			cout << "LCM is " << lcm << endl;

			for (int c = 1; c <= b; c++)
			{
				if (b % c == 0 && a % c == 0)
					hcf = c;
			}
			cout << "HCF = " << hcf;
			return 0;

			break;
		}
		lcm++;
	}
	return 0;

}
