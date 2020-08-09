#include <iostream>
#include <cmath>

using namespace std;

float length(int x1, int y1, int x2, int y2)
{
	float len = pow(pow(x1 - x2, 2) + pow(y1 - y2, 2), 0.5);
	return len;
}

float perimeter(int x1, int y1, int x2, int y2, int x3, int y3)
{
	float len1 = pow(pow(x1 - x2, 2) + pow(y1 - y2, 2), 0.5);
	float len2 = pow(pow(x2 - x3, 2) + pow(y2 - y3, 2), 0.5);
	float len3 = pow(pow(x3 - x1, 2) + pow(y3 - y1, 2), 0.5);
	return len1 + len2 + len3;
}

float area(int l1, int l2, int l3)
{
	float p = (l1 + l2 + l3) / 2;
	float area = pow(p * (p - l1) * (p - l2) * (p - l3), 0.5);
	return area;
}

float checklength(float length)
{
	if (length < 0)
	{
		cout << "Length is less than 0\n";
		length = 1;
		cout << "New length is " << length << endl;
	}
	else if (length > 10)
	{
		cout << "Length is greater than 10\n";
		length = 1;
		cout << "New length is " << length << endl;;
	}
	else
		cout << "Length is " << length << endl;;

	return length;
}

void equilateral(int x1, int y1, int x2, int y2, int x3, int y3)
{
	if (length(x1, y1, x2, y2) == length(x3, y3, x2, y2) == length(x1, y1, x3, y3))
	{
		cout << "Triangle is equilateral" << endl << endl;
	}
	else
	{
		cout << "Triangle is not equilateral" << endl << endl;
	}
}

void isoceles(int x1, int y1, int x2, int y2, int x3, int y3)
{
	if (length(x1, y1, x2, y2) == length(x3, y3, x2, y2) || length(x1, y1, x3, y3) == length(x3, y3, x2, y2) || length(x1, y1, x2, y2) == length(x3, y3, x1, y1))
	{
		cout << "Triangle is isoceles" << endl << endl;
	}
	else
	{
		cout << "Triangle is not isoceles" << endl << endl;
	}
}

void print(int x1, int y1, int x2, int y2, int x3, int y3)
{
	float l1 = pow(pow(x1 - x2, 2) + pow(y1 - y2, 2), 0.5);
	float l2 = pow(pow(x2 - x3, 2) + pow(y2 - y3, 2), 0.5);
	float l3 = pow(pow(x3 - x1, 2) + pow(y3 - y1, 2), 0.5);

	float p = (l1 + l2 + l3) / 2;
	float area = pow(p * (p - l1) * (p - l2) * (p - l3), 0.5);

	char a[10][10];

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			float len1 = pow(pow(x1 - i, 2) + pow(y1 - j, 2), 0.5);
			float len2 = pow(pow(x2 - i, 2) + pow(y2 - j, 2), 0.5);
			float len3 = pow(pow(x1 - x2, 2) + pow(y1 - y2, 2), 0.5);

			float p1 = (len1 + len2 + len3) / 2;
			float a1 = pow(p * (p - len1) * (p - len2) * (p - len3), 0.5);

			float len4 = pow(pow(x1 - i, 2) + pow(y1 - j, 2), 0.5);
			float len5 = pow(pow(x3 - i, 2) + pow(y3 - j, 2), 0.5);
			float len6 = pow(pow(x1 - x3, 2) + pow(y1 - y3, 2), 0.5);

			float p2 = (len4 + len5 + len6) / 2;
			float a2 = pow(p2 * (p2 - len1) * (p2 - len2) * (p2 - len3), 0.5);

			float len7 = pow(pow(x3 - i, 2) + pow(y3 - j, 2), 0.5);
			float len8 = pow(pow(x2 - i, 2) + pow(y2 - j, 2), 0.5);
			float len9 = pow(pow(x3 - x2, 2) + pow(y3 - y2, 2), 0.5);

			float p3 = (len7 + len8 + len9) / 2;
			float a3 = pow(p * (p - len7) * (p - len8) * (p - len9), 0.5);

			if (area == a1 + a2 + a3)
			{
				a[i][j] = '*';
			}
			else
				a[i][j] = ' ';
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << a[i][j];
		}
	}
}

void right(int x1, int y1, int x2, int y2, int x3, int y3)
{
	float a = pow(x1 - x2, 2) + pow(y1 - y2, 2);
	float b = pow(x2 - x3, 2) + pow(y2 - y3, 2);
	float c = pow(x3 - x1, 2) + pow(y3 - y1, 2);


	if (a + b == c || a + c == b || b + c == a)
	{
		cout << "This is a right triangle" << endl << endl;
	}
	else
	{
		cout << "This not a right triangle" << endl << endl;;
	}

}

int main()
{
	int menu = 1;

	while (menu != 0)
	{
		cout << "Choose an option:\n";
		cout << "1. Calculate length of each side of the triangle\n";
		cout << "2. Calculate perimeter of the triangle\n";
		cout << "3. Calculate area using lengths\n";
		cout << "4. Calculate area of the triangle using cartesian coordinates\n";
		cout << "5. Check if lengths of the triangle are less than 0 or greater than 10\n";
		cout << "7. Check if triangle is right angled or not\n";
		cout << "8. Check if triangle is equilateral or not\n";
		cout << "9. Check if triangle is isoceles or not\n";
		cout << "11. Print the triangle\n";
		cout << "0. Exit the program\n" << endl;
		cout << "Enter option number: ";
		cin >> menu;
		cout << endl;

		switch (menu)
		{
		case 1:
		{
			int x1, x2, x3, y1, y2, y3;

			cout << "Enter first x coordinate of the triangle: ";
			cin >> x1;
			cout << "Enter first y coordinate of the triangle: ";
			cin >> y1;
			cout << "Enter second x coordinate of the triangle: ";
			cin >> x2;
			cout << "Enter second y coordinate of the triangle: ";
			cin >> y2;
			cout << "Enter third x coordinate of the triangle: ";
			cin >> x3;
			cout << "Enter third y coordinate of the triangle: ";
			cin >> y3;
			cout << endl;

			cout << "Length of first side(l): " << length(x1, y1, x2, y2) << endl;
			cout << "Length of second side(m): " << length(x2, y2, x3, y3) << endl;
			cout << "Length of third side(n): " << length(x3, y3, x1, y1) << endl << endl;

			break;
		}
		case 2:
		{
			int x1, x2, x3, y1, y2, y3;

			cout << "Enter first x coordinate of the triangle: ";
			cin >> x1;
			cout << "Enter first y coordinate of the triangle: ";
			cin >> y1;
			cout << "Enter second x coordinate of the triangle: ";
			cin >> x2;
			cout << "Enter second y coordinate of the triangle: ";
			cin >> y2;
			cout << "Enter third x coordinate of the triangle: ";
			cin >> x3;
			cout << "Enter third y coordinate of the triangle: ";
			cin >> y3;
			cout << endl;

			cout << "Perimeter of the triangle: " << perimeter(x1, y1, x2, y2, x3, y3) << endl << endl;

			break;

		}
		case 3:
		{
			int l1, l2, l3;
			float a;
			cout << "Enter first length : ";
			cin >> l1;
			cout << "Enter second length : ";
			cin >> l2;
			cout << "Enter third length : ";
			cin >> l3;
			cout << "Area of the triangle: " << area(l1, l2, l3) << endl << endl;
			break;
		}
		case 4:
		{
			int x1, x2, x3, y1, y2, y3;

			cout << "Enter first x coordinate of the triangle: ";
			cin >> x1;
			cout << "Enter first y coordinate of the triangle: ";
			cin >> y1;
			cout << "Enter second x coordinate of the triangle: ";
			cin >> x2;
			cout << "Enter second y coordinate of the triangle: ";
			cin >> y2;
			cout << "Enter third x coordinate of the triangle: ";
			cin >> x3;
			cout << "Enter third y coordinate of the triangle: ";
			cin >> y3;
			cout << endl;

			float len1 = pow(pow(x1 - x2, 2) + pow(y1 - y2, 2), 0.5);
			float len2 = pow(pow(x2 - x3, 2) + pow(y2 - y3, 2), 0.5);
			float len3 = pow(pow(x3 - x1, 2) + pow(y3 - y1, 2), 0.5);

			cout << "Area of the triangle: " << area(len1, len2, len3) << endl << endl;

			break;
		}
		case 5:
		{
			int x1, x2, x3, y1, y2, y3;

			cout << "Enter first x coordinate of the triangle: ";
			cin >> x1;
			cout << "Enter first y coordinate of the triangle: ";
			cin >> y1;
			cout << "Enter second x coordinate of the triangle: ";
			cin >> x2;
			cout << "Enter second y coordinate of the triangle: ";
			cin >> y2;
			cout << "Enter third x coordinate of the triangle: ";
			cin >> x3;
			cout << "Enter third y coordinate of the triangle: ";
			cin >> y3;
			cout << endl;

			float len1 = pow(pow(x1 - x2, 2) + pow(y1 - y2, 2), 0.5);
			float len2 = pow(pow(x2 - x3, 2) + pow(y2 - y3, 2), 0.5);
			float len3 = pow(pow(x3 - x1, 2) + pow(y3 - y1, 2), 0.5);

			len1 = checklength(len1);
			len2 = checklength(len2);
			len3 = checklength(len3);

			break;

		}
		case 7:
		{
			int x1, x2, x3, y1, y2, y3;

			cout << "Enter first x coordinate of the triangle: ";
			cin >> x1;
			cout << "Enter first y coordinate of the triangle: ";
			cin >> y1;
			cout << "Enter second x coordinate of the triangle: ";
			cin >> x2;
			cout << "Enter second y coordinate of the triangle: ";
			cin >> y2;
			cout << "Enter third x coordinate of the triangle: ";
			cin >> x3;
			cout << "Enter third y coordinate of the triangle: ";
			cin >> y3;
			cout << endl;

			right(x1, y1, x2, y2, x3, y3);

			break;

		}
		case 8:
		{
			int x1, x2, x3, y1, y2, y3;

			cout << "Enter first x coordinate of the triangle: ";
			cin >> x1;
			cout << "Enter first y coordinate of the triangle: ";
			cin >> y1;
			cout << "Enter second x coordinate of the triangle: ";
			cin >> x2;
			cout << "Enter second y coordinate of the triangle: ";
			cin >> y2;
			cout << "Enter third x coordinate of the triangle: ";
			cin >> x3;
			cout << "Enter third y coordinate of the triangle: ";
			cin >> y3;
			cout << endl;

			equilateral(x1, y1, x2, y2, x3, y3);

			break;

		}
		case 9:
		{
			int x1, x2, x3, y1, y2, y3;

			cout << "Enter first x coordinate of the triangle: ";
			cin >> x1;
			cout << "Enter first y coordinate of the triangle: ";
			cin >> y1;
			cout << "Enter second x coordinate of the triangle: ";
			cin >> x2;
			cout << "Enter second y coordinate of the triangle: ";
			cin >> y2;
			cout << "Enter third x coordinate of the triangle: ";
			cin >> x3;
			cout << "Enter third y coordinate of the triangle: ";
			cin >> y3;
			cout << endl;

			isoceles(x1, y1, x2, y2, x3, y3);

			break;
		}
		case 11:
		{
			int x1, x2, x3, y1, y2, y3;

			cout << "Enter first x coordinate of the triangle: ";
			cin >> x1;
			cout << "Enter first y coordinate of the triangle: ";
			cin >> y1;
			cout << "Enter second x coordinate of the triangle: ";
			cin >> x2;
			cout << "Enter second y coordinate of the triangle: ";
			cin >> y2;
			cout << "Enter third x coordinate of the triangle: ";
			cin >> x3;
			cout << "Enter third y coordinate of the triangle: ";
			cin >> y3;
			cout << endl;

			print(x1, y1, x2, y2, x3, y3);

			break;
		}
		}
	}

	
}
