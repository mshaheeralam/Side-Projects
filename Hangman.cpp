#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	char words[][15] = { "Seoul", "Tokyo", "Istanbul", "Kuala Lumpur", "Singapore", "New York", "Dubai", "Paris", "London", "Bangkok", "Islamabad", "Pakistan", "France", "Germany","Lahore","Spain","Saudi Arabia", }; //WORDS ARRAY
	srand(time(0));
	int length = sizeof(words) / sizeof(words[0]); //CALCULATES WORDS IN THE ARRAY
	int index = rand() % length;
	int chances = 8;
	char letters[15];
	char letter;
	char usedletters[30]; //ARRAY OF USED LETTERS
	char x;
	bool used = false;
	int count = 0;
	bool win;

	cout << "\tWELCOME TO HANGMAN!" << endl << endl;
	cout << "Instructions: " << endl << endl;
	cout << "1. All the words are either a country or a city\n";
	cout << "2. First letter of each word is capital\n";
	cout << "3. You only have 8 chances to guess the word\n" << endl;
	cout << "\tENJOY THE GAME!" << endl << endl;
	system("pause");
	system("cls");


	for (int i = 0; i < 30; i++) //INITIALIZES THIS ARRAY WITH ZERO
	{
		usedletters[i] = '0';
	}

	for (int i = 0; words[index][i] != '\0'; i++) //DISPLAYS BLANKS AND UNDERSCORES
	{
		if (words[index][i] == ' ')
		{
			cout << " ";
		}
		else
		{
			cout << "_ ";
		}
	}

	cout << endl << endl;;

	while (chances != 0)
	{
		cout << "Chances left: " << chances << endl << endl;

		switch (chances) //DISPLAYS HANGMAN
		{
		case 7:
		{
			cout << " O\n";
			break;
		}
		case 6:
		{
			cout << " O\n";
			cout << " |\n";
			break;
		}
		case 5:
		{
			cout << " O\n";
			cout << " |\\" << endl;
			break;
		}
		case 4:
		{
			cout << " O\n";
			cout << "/|\\" << endl;
			break;
		}
		case 3:
		{
			cout << " O\n";
			cout << "/|\\" << endl;
			cout << " |\n";
			break;
		}
		case 2:
		{
			cout << " O\n";
			cout << "/|\\" << endl;
			cout << " |\n";
			cout << "/\n";
			break;
		}
		case 1:
		{
			cout << " O\n";
			cout << "/|\\" << endl;
			cout << " |\n";
			cout << "/ \\" << endl; ;
			break;
		}
		}

		for (int i = 0; words[index][i] != '\0'; i++) //CHECKS IF WORD IS COMPLETE
		{
			if (words[index][i] == letters[i])
			{
				win = true;
			}
			else
			{
				win = false;
				break;
			}
		}

		if (win) //IF WORD IS COMPLETE
		{
			system("cls");
			cout << "\nCongratulations! You won.\n";
			cout << endl;
			system("pause");
			exit(0);
		}

		cout << "\nEnter letter: ";
		cin >> letter;
		cout << endl << endl;
		system("pause");
		system("cls");

		for (int i = 0; i < 30; i++) //CHECKS IF THE LETTER WAS ALREADY ENTERED
		{
			if (usedletters[i] == letter)
			{
				used = true;
				break;
			}
		}

		if (used)
		{
			cout << "\nYou cannot enter " << letter << " again\n" << endl;
		}
		else
		{
			for (int i = 0; words[index][i] != '\0'; i++) //STORES CORRECT LETTER IN LETTERS ARRAY
			{
				if (words[index][i] == letter)
				{
					letters[i] = letter;
				}
				else if (words[index][i] == ' ')
				{
					letters[i] = ' ';
				}
			}

			for (int i = 0; words[index][i] != '\0'; i++) //DISPLAYS INCOMPLETE WORD
			{
				if (words[index][i] == letters[i])
				{
					cout << letters[i] << " ";
				}
				else
				{
					cout << "_ ";
				}
			}

			for (int i = 0; i < 15; i++)
			{
				if (words[index][i] == letter)
				{
					break;
				}
				else if (words[index][i] == '\0')
				{
					chances--;
					break;
				}
			}
			cout << endl << endl;
		}

		for (int i = 0; i < 30; i++) //ADD EACH ENTERED LETTER TO USEDLETTERS ARRAY
		{
			if (usedletters[i] == '0')
			{
				usedletters[i] = letter;
				used = false;
				break;
			}
		}
	}

	system("cls");
	cout << "\nYou lost.\n";
	cout << "\nCorrect word was ";
	for (int i = 0; words[index][i] != '\0'; i++)
	{
		cout << words[index][i];
	}
	cout << endl << endl;
	system("pause");
	exit(0);
}