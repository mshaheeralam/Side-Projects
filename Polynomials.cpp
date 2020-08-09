//GROUP:
//MUHAMMAD SHAHEER ALAM 2019369
//AHMED MUAZ 2019043


#include <iostream>
#include <fstream>
using namespace std;

class List
{
private:
	struct node //LINKED LIST
	{
		int data;
		int power;
		node* next;
	};
	node* head;
public:
	List() //DEFAULT CONSTRUCTOR
	{
		head = NULL;
	}
	void addnode(int val, int pow) //ADDING NODE TO THE TAIL
	{
		node* ptrnew = new node;
		node* temp = head;
	//	temp = head;
		ptrnew->data = val;
		ptrnew->power = pow;
		ptrnew->next = NULL;
		if (head == NULL)
		{
			head = ptrnew;
			return;
		}
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = ptrnew;
	}
	void print(int v) //PRINTING LIST
	{
		int count = 0;
		node* temp = new node;
		temp = head;
		while (temp != NULL)
		{
			cout << temp->data << "x" << count;
			if (count != v - 1)
			{
				cout << " + ";
			}
			count++;
			temp = temp->next;
		}
		cout << endl;
	}
	void store() //STORING LIST TO A FILE
	{
		ofstream t;
		t.open("result_addition.txt");
		node* temp = new node;
		temp = head;
		while (temp != NULL)
		{
			t << temp->data << "\t";
			temp = temp->next;
		}
		t.close();
	}
	void operator+=(List l) //OPERATOR OVERLOADING FOR THE ADDITION OF LISTS
	{
		node* temp1 = new node;
		node* temp2 = new node;
		temp1 = head;
		temp2 = l.head;

		while (temp1 != NULL && temp2 != NULL)
		{
			temp1->data += temp2->data;
			temp1 = temp1->next;
			temp2 = temp2->next;

		}

	}
};

void add(int v, int p) //ADDITION VIA ARRAYS
{
	ifstream temp;
	temp.open("temp.txt");
	int x;
	int* a1 = new int[v];
	int* a2 = new int[v];

	temp >> x >> x;

	for (int j = 0; j < v; j++)
	{
		temp >> a1[j];
	}
	for (int i = 0; i < p - 1; i++)
	{
		for (int j = 0; j < v; j++)
		{
			temp >> a2[j];
			a1[j] += a2[j];
		}
		
	}
	cout << "Result: ";
	for (int i = 0; i < v; i++)
	{
		cout << a1[i] << "x" << i;
		if (i != v - 1)
		{
			cout << " + ";
		}
	}

	ofstream t;
	t.open("result_addition.txt");

	for (int i = 0; i < v; i++)
	{
		t << a1[i] << "\t";
	}
}

int main()
{
	ifstream read;
	read.open("temp.txt");
	int variables, poly, menu, element;
	read >> poly >> variables;

	cout << poly << " polynomials found. Which data structure you want to use for addtion?\n1. Linked List\n2. Array\nEnter: ";
	cin >> menu;

	switch (menu)
	{
	case 1:
	{
		List* l = new List[poly];

		for (int i = 0; i < variables; i++)
		{
			read >> element;
			l[0].addnode(element, i);
		}
		for (int i = 1; i < poly; i++)
		{
			for (int j = 0; j < variables; j++)
			{
				read >> element;
				l[i].addnode(element, i);
			}
			l[0] += l[i]; //ADDITION VIA LINKED LIST
		}
		cout << "Result: ";
		l[0].print(variables);
		l[0].store();
		break;
	}
	case 2:
	{
		add(variables, poly);
		break;
	}
	}
}
