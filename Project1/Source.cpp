#include <iostream>
#include <string>
#include <iomanip>

#define SIZE 12
using namespace std;

int flag = 0;


//////////////////////////////////////////////////////////////////
class people
{
public:
	int Atk;
	void setAtk(int atk)
	{
		Atk = atk;
	}
	void getAtk(int atk)
	{
		cout << left << setw(7) << " ";
		cout << left << setw(5) << "ATK";
		cout << left << setw(2) << ": ";
		cout << atk;
	}
};

class human : public people
{
public:
	int Hp;
	string Name;

	void getHp(int hp)
	{
		cout << left << setw(7) << " ";
		cout << left << setw(5) << "HP";
		cout << left << setw(2) << ": ";
		cout << hp;
	}
	void getName(string name)
	{
		cout << left << setw(7) << " ";
		cout << left << setw(5) << "Name";
		cout << left << setw(2) << ": ";
		cout << name;
	}
	void hp_check(int hp)
	{
		if (hp <= 0)
		{
			system("CLS");
			cout << "You Dead!";
			flag = 1;
		}
	}

};

class monster : public people
{
public:
	int return_atk()
	{
		return Atk;
	}
};

human h1;
monster m1, m2;
//////////////////////////////////////////////////////////////////
void print(int maze[][SIZE], string name, int hp, int atk)
{
	int i, j;

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			switch (maze[i][j])
			{
				case 0: cout << "  ";
					break;
				case 1: cout << "¡­";
					break;
				case 2: cout << "¢I";
					break;
				case 3: cout << "¢Õ";
					break;
				case 4: cout << "¢Ö";
					break;
				case 5: cout << "¢Û";
					break;
				case 6: cout << "¢Û";
			}
		}
		if (i == 0)
		{
			h1.getName(name);
		}
		if (i == 1)
		{
			h1.getHp(hp);
		}
		if (i == 2)
		{
			h1.getAtk(atk);
			m1.setAtk(atk);
			m2.setAtk(atk * 2);
		}
		cout << endl;
	}
}


void move(char input, int &nowx, int &nowy, int maze[SIZE][SIZE], int &hp)
{
	switch (input)
	{
		case 'w':
			if (maze[nowx - 1][nowy] == 0 || maze[nowx - 1][nowy] == 3
				|| maze[nowx - 1][nowy] == 5 || maze[nowx - 1][nowy] == 6)
			{
				if (maze[nowx - 1][nowy] == 3)
				{
					system("CLS");
					cout << "Game Over!";
					flag = 1;
				}
				else
				{
					if (maze[nowx - 1][nowy] == 5)
					{
						hp = hp - m1.return_atk();
						h1.hp_check(hp);
					}
					if (maze[nowx - 1][nowy] == 6)
					{
						hp = hp - m2.return_atk();
						h1.hp_check(hp);
					}
					nowx--;
					maze[nowx + 1][nowy] = 0;
					maze[nowx][nowy] = 4;
				}
			}
			break;

		case 'a':
			if (maze[nowx][nowy - 1] == 0 || maze[nowx][nowy - 1] == 3
				|| maze[nowx][nowy - 1] == 5 || maze[nowx][nowy - 1] == 6)
			{
				if (maze[nowx][nowy - 1] == 3)
				{
					system("CLS");
					cout << "Game Over!";
					flag = 1;
				}
				else
				{
					if (maze[nowx][nowy - 1] == 5)
					{
						hp = hp - m1.return_atk();
						h1.hp_check(hp);
					}
					if (maze[nowx][nowy - 1] == 6)
					{
						hp = hp - m2.return_atk();
						h1.hp_check(hp);
					}
					nowy--;
					maze[nowx][nowy + 1] = 0;
					maze[nowx][nowy] = 4;
				}
			}
			break;

		case 's':
			if (maze[nowx + 1][nowy] == 0 || maze[nowx + 1][nowy] == 3
				|| maze[nowx + 1][nowy] == 5 || maze[nowx + 1][nowy] == 6)
			{
				if (maze[nowx + 1][nowy] == 3)
				{
					system("CLS");
					cout << "Game Over!";
					flag = 1;
				}
				else
				{
					if (maze[nowx + 1][nowy] == 5)
					{
						hp = hp - m1.return_atk();
						h1.hp_check(hp);
					}					
					if (maze[nowx + 1][nowy] == 6)
					{
						hp = hp - m2.return_atk();
						h1.hp_check(hp);
					}
					nowx++;
					maze[nowx - 1][nowy] = 0;
					maze[nowx][nowy] = 4;
				}
			}
			break;

		case 'd':
			if (maze[nowx][nowy + 1] == 0 || maze[nowx][nowy + 1] == 3
				|| maze[nowx][nowy + 1] == 5 || maze[nowx][nowy + 1] == 6)
			{
				if (maze[nowx][nowy + 1] == 3)
				{
					system("CLS");
					cout << "Game Over!";
					flag = 1;
				}
				else
				{
					if (maze[nowx][nowy + 1] == 5)
					{
						hp = hp - m1.return_atk();
						h1.hp_check(hp);
					}
					if (maze[nowx][nowy + 1] == 6)
					{
						hp = hp - m2.return_atk();
						h1.hp_check(hp);
					}
					nowy++;
					maze[nowx][nowy - 1] = 0;
					maze[nowx][nowy] = 4;
				}
			}
			break;

		default: 
		break;
	}
}


int main()
{
	while (1)
	{
		char input;
		int nowx = 1, nowy = 1;
		int maze[SIZE][SIZE] =
		{
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
			{ 1, 0, 2, 5, 0, 0, 2, 0, 2, 0, 2, 1 },
			{ 1, 0, 2, 0, 2, 0, 2, 0, 0, 0, 2, 1 },
			{ 1, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 1 },
			{ 1, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 1 },
			{ 1, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 1 },
			{ 1, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 1 },
			{ 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 1 },
			{ 1, 0, 0, 2, 2, 2, 2, 6, 2, 0, 0, 1 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 1 },
			{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 0, 3, 1 },
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
		};
		int choice;
		flag = 0;

		cout << "RPG Game" << endl << "1. New Game" << endl << "2. Exit"
			<< endl << "Your choice: ";
		cin >> choice;

		if (choice == 1)
		{
			string name,YesNo;
			int hp = 100, atk;

			system("CLS");
			cout << "Name: ";
			cin >> name;
			cout << "HP: " << hp << endl;
			cout << "ATK: ";
			cin >> atk;

			cout << "OK ? (y / n): ";
			cin >> YesNo;
			if (YesNo == "y")
			{
				system("CLS");
				maze[nowx][nowy] = 4;
				print(maze, name, hp, atk);
				cout << "Move (w/a/s/d) :";

				while (cin >> input)
				{
					system("CLS");

					move(input, nowx, nowy, maze, hp);

					if (flag == 1)
					{
						system("CLS");
						cout << "Game Over!" << endl << endl;
						break;
					}
					else
					{
						print(maze, name, hp, atk);
						cout << "Move (w/a/s/d) :";
					}
				}
			}
			else
				system("CLS");
		}
		else
			break;
	}

	system("pause");
	return 0;
}

