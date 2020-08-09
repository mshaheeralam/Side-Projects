#include <iostream>
using namespace std;

class Package
{
protected:
	string nameS, addressS, cityS, stateS, nameR, addressR, cityR, stateR;
	int zipcodeS, zipcodeR;
	double weight, costperounce;
public:
	Package()
	{
		zipcodeR = zipcodeS = 0;
		weight = costperounce = 0;
	}
	Package(string n1, string n2, string a1, string a2, string c1, string c2, string s1, string s2, int z1, int z2, double w, double c)
	{
		nameS = n1;
		addressS = a1;
		cityS = c1;
		stateS = s1;
		nameR = n2;
		addressR = a2;
		cityR = c2;
		stateR = s2;
		if (z1 < 0)
			zipcodeS = -z1;
		else
			zipcodeS = z1;
		if (z2 < 0)
			zipcodeR = -z2;
		else
			zipcodeR = z2;
		if (w < 0)
			weight = -w;
		else
			weight = w;
		if (c < 0)
			costperounce = -c;
		else
			costperounce = c;
	}
	double calculateCost(double w, double c)
	{
		return w * c;
	}

};

class TwoDayPackage : public Package
{
protected:
	double flatfee;
public:
	TwoDayPackage(double f, string n1, string n2, string a1, string a2, string c1, string c2, string s1, string s2, int z1, int z2, double w, double c)
	{
		Package::Package(n1, n2, a1, a2, c1, c2, s1, s2, z1, z2, w, c);
		flatfee = f;
	}
	double calculateCost(double f, double w, double c)
	{
		return Package::calculateCost(w, c) + f;
	}
};

class OvernightPackage : public Package
{
protected:
	double feeperounce;
public:
	OvernightPackage(double f, string n1, string n2, string a1, string a2, string c1, string c2, string s1, string s2, int z1, int z2, double w, double c)
	{
		Package::Package(n1, n2, a1, a2, c1, c2, s1, s2, z1, z2, w, c);
		feeperounce = f;
	}
	double calculateCost(double f, double w, double c)
	{
		return Package::calculateCost(w, c) + f;
	}
};

int main()
{
	TwoDayPackage P1(100, "a", "b", "c", "d", "e", "f", "g", "h", 000, 001, 20.2, 33.3);
	OvernightPackage P2(200, "a", "b", "c", "d", "e", "f", "g", "h", 000, 001, 20.2, 33.3);

	cout << "Cost for Two Day Package: " << P1.calculateCost(100, 20.2, 33.3) << endl;
	cout << "Cost for Overnight Package: " << P2.calculateCost(200, 20.2, 33.3) << endl;
}