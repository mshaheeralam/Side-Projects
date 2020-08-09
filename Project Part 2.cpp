#include <iostream>
#include <cmath>
using namespace std;

void SA_V(float r)
{
	float SA = 4 * 3.142 * r * r;
	cout << "Surface Area of the sphere is " << SA << endl;
	float V = 4 / 4 * 3.142 * r * r * r;
	cout << "Volume of the sphere is " << V << endl << endl;
}

bool plane(float a[4][3])
{
	float AB[3];
	AB[0] = a[0][0] - a[1][0];
	AB[1] = a[0][1] - a[1][1];
	AB[2] = a[0][2] - a[1][2];

	float AC[3];
	AC[0] = a[0][0] - a[2][0];
	AC[1] = a[0][1] - a[2][1];
	AC[2] = a[0][2] - a[2][2];

	float i1 = (AB[1] * AC[2]) - (AB[2] * AC[1]);
	float j1 = (AB[2] * AC[0]) - (AB[0] * AC[2]);
	float k1 = (AB[0] * AC[1]) - (AB[1] * AC[0]);

	if (i1 == 0 && j1 == 0 && k1 == 0)
	{
		cout << "The coordinates donot form a plane" << endl << endl;
		return false;
	}
	else
	{
		if (i1 * a[2][0] + j1 * a[2][1] + k1 * a[2][2] == i1 * a[3][0] + j1 * a[3][1] + k1 * a[3][2])
		{
			cout << "The coordinates form a plane" << endl << endl;
			return true;
		}
		else
		{
			cout << "The coordinates donot form a plane" << endl << endl;
			return false;
		}
	}
}

bool shape(float a[4][3])
{
	float AB[3];

	AB[0] = a[0][0] - a[1][0];
	AB[1] = a[0][1] - a[1][1];
	AB[2] = a[0][2] - a[1][2];

	float AC[3];

	AC[0] = a[0][0] - a[2][0];
	AC[1] = a[0][1] - a[2][1];
	AC[2] = a[0][2] - a[2][2];

	float AD[3];

	AD[0] = a[0][0] - a[3][0];
	AD[1] = a[0][1] - a[3][1];
	AD[2] = a[0][2] - a[3][2];

	float lengthAB = pow(AB[0], 2) + pow(AB[1], 2) + pow(AB[2], 2);
	float lengthAC = pow(AC[0], 2) + pow(AC[1], 2) + pow(AC[2], 2);
	float lengthAD = pow(AD[0], 2) + pow(AD[1], 2) + pow(AD[2], 2);

	if ((lengthAB == lengthAC && lengthAB * 2 == lengthAD) || (lengthAB == lengthAD && lengthAB * 2 == lengthAC) || (lengthAC == lengthAD && lengthAC * 2 == lengthAB))
	{
		cout << "Plane is a square" << endl << endl;
		return true;
	}
	else if ((lengthAB == lengthAC + lengthAD) || (lengthAC == lengthAB + lengthAD) || (lengthAD == lengthAB + lengthAC))
	{
		cout << "Plane is a rectangle" << endl << endl;
		return false;
	}
	else
	{
		cout << "Plane is a parallelogram" << endl << endl;
		return false;
	}
}

float area(float a[4][3], float b[3], float r)
{
	float AB[3];
	AB[0] = a[0][0] - a[1][0];
	AB[1] = a[0][1] - a[1][1];
	AB[2] = a[0][2] - a[1][2];

	float AC[3];
	AC[0] = a[0][0] - a[2][0];
	AC[1] = a[0][1] - a[2][1];
	AC[2] = a[0][2] - a[2][2];

	float i1 = (AB[1] * AC[2]) - (AB[2] * AC[1]);
	float j1 = (AB[2] * AC[0]) - (AB[0] * AC[2]);
	float k1 = (AB[0] * AC[1]) - (AB[1] * AC[0]);

	float x = i1 * b[0] + j1 * b[1] + k1 * b[2] - (i1 * a[2][0] + j1 * a[2][1] + k1 * a[2][2]);

	if (x < 0)
	{
		x = -x;
	}

	float y = pow(pow(i1, 2) + pow(j1, 2) + pow(k1, 2), 0.5);

	float d = x / y;
	
	if (d > r)
	{
		cout << "Plane and sphere donot intersect" << endl;
	}
	else
	{
		float R;

		R = pow(r * r - d * d, 0.5);

		return 3.142 * R * R;
	}
}

int main()
{
	float radius;
	float center[3];

	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			cout << "Enter x coordinate of sphere's center: ";
			cin >> center[i];
		}
		else if (i == 1)
		{
			cout << "Enter y coordinate of sphere's center: ";
			cin >> center[i];
		}
		if (i == 2)
		{
			cout << "Enter z coordinate of sphere's center: ";
			cin >> center[i];
			cout << endl;
		}
	}

	cout << "Enter radius of the sphere: ";
	cin >> radius;
	cout << endl;

	while (radius < 0)
	{
		cout << "Error. Enter a valid radius: ";
		cin >> radius;
		cout << endl;
	}

	if (radius > 10)
	{
		cout << "Radius greater than 10. Default radius = 1";
		radius = 1;
		cout << endl;
	}

	SA_V(radius);

	float coordinates[4][3];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == 0)
			{
				cout << "Enter first ";
				if (j == 0)
				{
					cout << "x coordinate: ";
					cin >> coordinates[i][j];
				}
				else if (j == 1)
				{
					cout << "y coordinate: ";
					cin >> coordinates[i][j];
				}
				else if (j == 2)
				{
					cout << "z coordinate: "; 
					cin >> coordinates[i][j];
				}
			}
			else if (i == 1)
			{
				cout << "Enter second ";
				if (j == 0)
				{
					cout << "x coordinate: ";
					cin >> coordinates[i][j];
				}
				else if (j == 1)
				{
					cout << "y coordinate: ";
					cin >> coordinates[i][j];
				}
				else if (j == 2)
				{
					cout << "z coordinate: ";
					cin >> coordinates[i][j];
				}
			}
			else if (i == 2)
			{
				cout << "Enter third ";
				if (j == 0)
				{
					cout << "x coordinate: ";
					cin >> coordinates[i][j];
				}
				else if (j == 1)
				{
					cout << "y coordinate: ";
					cin >> coordinates[i][j];
				}
				else if (j == 2)
				{
					cout << "z coordinate: ";
					cin >> coordinates[i][j];
				}
			}
			else if (i == 3)
			{
				cout << "Enter fourth ";
				if (j == 0)
				{
					cout << "x coordinate: ";
					cin >> coordinates[i][j];
				}
				else if (j == 1)
				{
					cout << "y coordinate: ";
					cin >> coordinates[i][j];
				}
				else if (j == 2)
				{
					cout << "z coordinate: ";
					cin >> coordinates[i][j];
					cout << endl;
				}
			}
		}
	}

	bool is_plane = plane(coordinates);

	if (is_plane)
	{
		bool is_sqaure = shape(coordinates);

		if (is_sqaure)
		{
			float a = area(coordinates, center, radius);
			cout << "Area of the cross section between sphere and plane is " << a << endl << endl;

			if (a == 0)
			{
				cout << "Radius of the sphere is tangent to the plane" << endl << endl;
			}
			
		}
	}
}