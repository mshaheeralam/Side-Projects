#include <iostream>
using namespace std;

class String
{
private:
	char* cptr = new char[50];
	int size;
	
public:

	String() //DEFAULT CONSTRUCTOR
	{
		size = 50;
	}
	String(char *temp) //TAKES IN CHARACTER ARRAY
	{
		int count = 0;
		delete[] cptr;

		for (int i = 0; temp[i] != '\0'; i++)
		{
			count++;
		}
		size = count;

		char* x = new char[size + 1];

		for (int i = 0; i < size + 1; i++)
		{
			x[i] = temp[i];
		}
		cptr = x;

	}
	String(int s) //TAKES IN SIZE OF THE ARRAY
	{
		size = s;
		delete[] cptr;
		char* a = new char[s];
		cptr = a;
	}
	~String() //DESTRUCTOR 
	{ }
	String operator+(String a) //+ OVERLOADING (CONCATENATION)
	{
		String temp;
		int count = 0;
		temp.size = size + a.size;
		delete[] temp.cptr;
		char *b = new char[temp.size + 1];

		for (int i = 0; i < size; i++)
		{
			b[i] = cptr[i];
		}
		for (int i = size; i < temp.size + 1; i++)
		{
			b[i] = a.cptr[count];
			count++;
		}
		temp.cptr = b;
		return temp;
	}
	void operator+=(String a) //+= OVERLOADING (CONCATENATION)
	{
		int count = 0;
		int temp = size + a.size;
		char* b = new char[temp + 1];
		
		for (int i = 0; i < size; i++)
		{
			b[i] = cptr[i];
		}
		delete[] cptr;
		for (int i = size; i < temp + 1; i++)
		{
			b[i] = a.cptr[count];
			count++;
		}
		size = temp;
		cptr = b;

	}
	char operator[](int x) //GETTING INDIVIDUAL ELEMENTS
	{
		return cptr[x];
	}
	bool operator==(String a)
	{
		if (a.cptr == cptr)
			return true;
		else
			return false;
	}
	bool operator!=(String a)
	{
		if (a.cptr != cptr)
			return true;
		else
			return false;
	}
	bool operator>(String a)
	{
		if (cptr > a.cptr)
			return true;
		else
			return false;
	}
	bool operator<(String a)
	{
		if (cptr < a.cptr)
			return true;
		else
			return false;
	}
	String operator()(int x, int y)
	{
		int s = y - x + 1;
		String a(s+1);
		int count = x;
		for (int i = 0; i < s; i++)
		{
			a.cptr[i] = cptr[x];
			x++;
		}
		a.cptr[s] = '\0';

		return a;
	}
	String operator<< (int x) //LEFT SHIFT
	{
		String temp(x + 1);

		for (int i = 0; i < x; i++)
		{
			temp.cptr[i] = cptr[i];
		}
		temp.cptr[x] = '\0';

		char* a = new char[size - x + 1];
		int count = 0;
		for (int i = x; i < size; i++)
		{
			a[count] = cptr[i];
			count++;
		}
		a[size - x] = '\0';
		size = size - x + 1;
		delete[] cptr;
		cptr = a;
		return temp;
	}
	String operator>> (int x) //RIGHT SHIFT
	{
		String temp(x + 1);
		int count = size - 2;
		for (int i = 0; i < x; i++)
		{
			temp.cptr[i] = cptr[count];
			count--;
		}
		temp.cptr[x] = '\0';

		char* a = new char[size - x];

		for (int i = 0; i < size - x - 1; i++)
		{
			a[i] = cptr[i];
		}
		a[size - x - 1] = '\0';
		delete[] cptr;
		cptr = a;
		size = size - x;
		return temp;
	}
	friend ostream& operator<<(ostream& out, String s);
	friend istream& operator>>(istream& in, String s);
	int sizeofarray() //RETURNS SIZE OF ARRAY
	{
		int count = 0;
		for (int i = 0; cptr[i] != '\0'; i++)
		{
			count++;
		}
		return count + 1;
	}
	int sizeofstring() //RETURNS SIZE OF STRING
	{
		int count = 0;
		for (int i = 0; cptr[i] != '\0'; i++)
		{
			count++;
		}
		return count;
	}

};

ostream& operator<<(ostream& out, String s)
{
	for (int i = 0; i < s.size; i++)
	{
		out << s.cptr[i] << " ";;
	}
	out << endl;

	return out;
}
istream& operator>>(istream& in, String s)
{
	cout << "Enter Size: ";
	in >> s.size;
	for (int i = 0; i < s.size; i++)
	{
		cout << "Enter Element Number " << i + 1 << ": ";
		cin >> s.cptr[i];
	}
	s.cptr[s.size] = '\0';
	return in;
}

int main()
{
	char c1[] = "1234";
	char c2[] = "ABCDEF";

	String s1(c1), s2(c2), s3, s4,s5;

	cout << "S1: " << s1;

	char d = s1[2];
	cout << "D = S1[2]" << endl << "D: " << d << endl;

	cout << "S2: " << s2;
	
	s3 = s2 + s1;
	cout << "S3 = S2 + S1" << endl << "S3: " << s3;

	s1 += s2;
	cout << "S1 += S2" << endl << "S1: " << s1;

	s4 = s1(2, 6);
	cout << "S4 = S1(2, 6)\nS4: " << s4;
	
	s3 = s1 << 3;
	cout << "S3 = S1 << 3\nS1: " << s1 << "S3: " << s3;
	s4 = s1 >> 4;
	cout << "S4 = S1 << 4\nS2: " << s1 << "S4: " << s4;

	cout << "Size of S1 Array; " << s1.sizeofarray() << endl;
	cout << "Size of S1 String; " << s1.sizeofstring() << endl;
	cout << "Size of S2 Array; " << s2.sizeofarray() << endl;
	cout << "Size of S2 String; " << s2.sizeofstring() << endl;
	cout << "Size of S3 Array; " << s3.sizeofarray() << endl;
	cout << "Size of S3 String; " << s3.sizeofstring() << endl;
	cout << "Size of S4 Array; " << s4.sizeofarray() << endl;
	cout << "Size of S4 String; " << s4.sizeofstring() << endl;
}