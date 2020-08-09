#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
using namespace std;

class HashTableList
{
private:
	struct node
	{
		int key;
		string primary, secondary, name, address;
		node* next;
	};
	node* head;

public:
	HashTableList() //DEFAULT CONSTRUCTOR	
	{
		head = NULL;
	}
	void search(string n)
	{
		string name;
		ifstream data;
		data.open("database.txt");
		int lines = -1, count = 0, z = 0;;
		while (!data.eof()) //LINES CALCULATOR
		{
			data >> name;
			lines++;
		}
		lines /= 5;

		data.close();
		system("CLS");
		node* temp = head;
		while (temp != NULL) //FINS HOW MANY CONTACTS EXIST WITH THE GIVEN NAME
		{
			if (temp->name == n)
				count++;
			temp = temp->next;

		}
		if (head == NULL || count == 0) //IF NODE IS EMPTY
		{
			system("CLS");
			cout << "No Contact Found. Try Again\n\n";
			system("PAUSE");
		}
		else if (count == 1) //IF ONLY ONE CONTACT EXISTS WITH THE GIVEN NAME
		{
			ifstream data;
			data.open("database.txt");
			int tem;
			string x[4];

			cout << "KEY" << setw(14) << "NAME" << setw(20) << "PRIMARY" << setw(20) << "SECONDARY" << setw(15) << "ADDRESS" << endl;

			for (int i = 0; i < lines; i++) //TRANSFERING DATA TO ANOTHER FILE 
			{
				data >> tem >> x[0] >> x[1] >> x[2] >> x[3];
				if (n == x[0])
					cout << setw(2) << tem << setw(15) << x[0] << setw(20) << x[1] << setw(20) << x[2] << setw(15) << x[3] << endl;
			}
			data.close();
			cout << endl;
			system("PAUSE");
		}
		else //IF MORE THAN ONE CONTACTS EXIST WITH THE GIVEN NAME
		{
			string p;
			cout << count << " CONTACTS FOUND WITH SAME NAME. ENTER PRIMARY CONTACT NUMBER(XX(XX)XXX-XXXX): ";
			cin >> p;

			ifstream data;
			data.open("database.txt");
			int tem;
			string x[4];
			system("CLS");
			cout << "KEY" << setw(14) << "NAME" << setw(20) << "PRIMARY" << setw(20) << "SECONDARY" << setw(15) << "ADDRESS" << endl;

			for (int i = 0; i < lines; i++) //DISPLAYING CONTACT
			{
				data >> tem >> x[0] >> x[1] >> x[2] >> x[3];
				if (n == x[0] && p == x[1])
					cout << setw(2) << tem << setw(15) << x[0] << setw(20) << x[1] << setw(20) << x[2] << setw(15) << x[3] << endl;
			}
			data.close();
			cout << endl;
			system("PAUSE");
		}
	}
	void del(string n)
	{
		string name;
		ifstream data;
		data.open("database.txt");
		int lines = -1, count = 0, z = 0;;
		while (!data.eof()) //LINES CALCULATOR
		{
			data >> name;
			lines++;
		}
		lines /= 5;

		data.close();
		system("CLS");

		node* temp = head;
		while (temp != NULL) //FINDS HOW MANY CONTACTS EXIST WITH THE GIVEN NAME
		{
			if (temp->name == n)
				count++;
			temp = temp->next;

		}
		if (head == NULL || count == 0) //IF NODE IS EMPTY
		{
			system("CLS");
			cout << "No Contact Found. Try Again\n\n";
			system("PAUSE");
		}
		else if (count == 1) //IF ONLY ONE CONTACT EXISTS WITH THE GIVEN NAME
		{
			ifstream data;
			data.open("database.txt");
			ofstream temp2;
			temp2.open("temp.txt");
			int tem;
			string x[4];
			for (int i = 0; i < lines; i++) //TRANSFERING DATA TO ANOTHER FILE 
			{
				data >> tem >> x[0];
				if (n == x[0])
				{
					data >> x[1] >> x[2] >> x[3];
				}
				else
				{
					temp2 << tem << "\t" << x[0] << "\t";
					data >> x[1] >> x[2] >> x[3];
					temp2 << x[1] << "\t" << x[2] << "\t" << x[3] << endl;
				}
			}
			data.close();
			temp2.close();
			remove("database.txt");
			rename("temp.txt", "database.txt"); //RENAMING FILE
			temp = head;
			while (temp->name != n) //FINDING ADDRESS OF THE CONTACT 
				temp = temp->next;
			if (head == temp) //IF CONTACT IS AT THE HEAD OF THE NODE
			{
				if (head->next == NULL)
					head = NULL;
				else
					head = head->next;
			}
			else
			{
				node* prev = head;
				while (prev->next != temp) //FINDING ADDRESS OF THE PREVIOUS NODE
					prev = prev->next;
				prev->next = prev->next->next; //LINKING NODES
			}
			free(temp); //FREEING MEMORY
			cout << "CONTACT DELETED SUCESSFULLY\n\n";
			system("PAUSE");
		}
		else //IF MORE THAN ONE CONTACTS EXIST WITH THE GIVEN NAME
		{
			string p;
			cout << count << " CONTACTS FOUND WITH SAME NAME. ENTER PRIMARY CONTACT NUMBER(XX(XX)XXX-XXXX): ";
			cin >> p;

			ifstream data;
			data.open("database.txt");
			ofstream temp2;
			temp2.open("temp.txt");
			int tem;
			string x[4];

			for (int i = 0; i < lines; i++) //TRANSFERING DATA TO ANOTHER FILE 
			{
				data >> tem >> x[0] >> x[1];
				if (n == x[0] && p == x[1])
				{
					data >> x[2] >> x[3];
				}
				else
				{
					temp2 << tem << "\t" << x[0] << "\t" << x[1] << "\t";
					data >> x[2] >> x[3];
					temp2 << x[2] << "\t" << x[3] << endl;
				}
			}
			data.close();
			temp2.close();
			remove("database.txt");
			rename("temp.txt", "database.txt"); //RENAMING FILE
			temp = head;
			while (temp->name != n && temp->primary != p) //FINDING ADDRESS OF THE CONTACT 
				temp = temp->next;
			if (head == temp) //IF CONTACT IS AT THE HEAD OF THE NODE
			{
				if (head->next == NULL)
					head = NULL;
				else
					head = head->next;
			}
			else
			{
				node* prev = head;
				while (prev->next != temp) //FINDING ADDRESS OF THE PREVIOUS NODE
					prev = prev->next;
				prev->next = prev->next->next; //LINKING NODES
			}
			free(temp); //FREEING MEMORY
			system("CLS");
			cout << "\nCONTACT DELETED SUCESSFULLY\n\n";
			system("PAUSE");
		}
		
	}
	void insert(int k, string n, string p, string s, string a)
	{
		node* ptrnew = new node;
		node* temp = head;
		
		ptrnew->key = k;
		ptrnew->name = n;
		ptrnew->primary = p;
		ptrnew->secondary = s;
		ptrnew->address = a;

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
};

void display() //DISPLAYING ALL CONTACTS
{
	system("CLS");
	ifstream data;
	data.open("database.txt");
	int lines = -1;
	string temp[5];
	while (!data.eof())
	{
		data >> temp[0];
		lines++;
	}
	lines /= 5;

	data.close();
	data.open("database.txt");
	cout << "KEY" << setw(14) << "NAME" << setw(20) << "PRIMARY" << setw(20) << "SECONDARY" << setw(15) << "ADDRESS" << endl;
	for (int i = 0; i < lines; i++)
	{
		data >> temp[0] >> temp[1] >> temp[2] >> temp[3] >> temp[4];
		cout << setw(2) << temp[0] << setw(15) << temp[1] << setw(20) << temp[2] << setw(20) << temp[3] << setw(15) << temp[4] << endl;
	}
	cout << endl << endl;
	system("PAUSE");
}
int mappingfunc(int k) //RETURNS INDEX
{
	if (k % 21 > 19)
		return (k % 21) % 7;
	else
		return k % 21;
}
int keygeneration(string n) //RETURNS KEY
{
	return n[0] - 21;
}

int main()
{
	HashTableList t[20];
	int key, index, menu = 0;
	string name, primary, secondary, address;
	ifstream data;
	data.open("database.txt");

	int lines = -1;
	while (!data.eof()) //LINES CALCULATOR
	{
		data >> name;
		lines++;
	}
	lines /= 5;

	data.close();
	data.open("database.txt");
	for (int i = 0; i < lines; i++) //INPUTING FROM FILE TO HASHTABLE
	{
		data >> key;
		data >> name;
		data >> primary;
		data >> secondary;
		data >> address;

		index = mappingfunc(key);
		t[index].insert(key, name, primary, secondary, address);
	}
	data.close();
	while (menu != 5)
	{
		system("CLS");
		cout << "CONTACT MANAGEMENT SYSTEM\n1.ADD CONTACT\n2.DELETE CONTACT\n3.SEARCH CONTACT\n4.DISPLAY ALL CONTACTS\n5.EXIT\n";
		cin >> menu;

		switch (menu)
		{
		case 1:
		{
			system("CLS");
			cout << "ENTER NAME: ";
			cin >> name;
			cout << "ENTER PRIMARY CONTACT(XX(XX)XXX-XXXX): ";
			cin >> primary;
			cout << "ENTER SECONDARY CONTACT(XX(XX)XXX-XXXX): ";
			cin >> secondary;
			cout << "ENTER ADDRESS: ";
			cin >> address;
			key = keygeneration(name);
			index = mappingfunc(key);
			t[index].insert(key, name, primary, secondary, address);
			system("CLS");
			cout << "CONTACT ADDED SUCESSFULLY\n\n";
			system("PAUSE");

			ofstream data;
			data.open("database.txt", ios::app);
			data << key << "\t" << name << "\t" << primary << "\t" << secondary << "\t" << address << endl;
			data.close();
			break;
		}
		case 2:
		{
			system("CLS");
			cout << "Enter Name: ";
			cin >> name;

			if (name == "Ted")
				key = 1;
			else if (name == "Jamie")
				key = 2;
			else if (name == "Nelson")
				key = 3;
			else
				key = keygeneration(name);

			index = mappingfunc(key);
			t[index].del(name);
			break;
		}
		case 3:
		{
			system("CLS");
			cout << "Enter Name: ";
			cin >> name;

			if (name == "Ted")
				key = 1;
			else if (name == "Jamie")
				key = 2;
			else if (name == "Nelson")
				key = 3;
			else
				key = keygeneration(name);

			index = mappingfunc(key);
			t[index].search(name);
			break;
		}
		case 4:
		{
			display();
			break;
		}
		case 5:
		{
			system("CLS");
			cout << "PROGRAM ENDED SUCESSFULLY\n\n";
			break;
		}
		default:
		{
			system("CLS");
			cout << "Invalid Input. Try Again.\n\n";
			system("PAUSE");
			break;
		}
		}
	}	
}