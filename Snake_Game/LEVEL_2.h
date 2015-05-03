# include <Windows.h>
# include <vector>
# include <cstdlib>
# include <iostream>
# include <conio.h>
# include <ctime>
# include <cmath>
# include <stdint.h>
# include <dos.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fstream>
# include <algorithm>
using namespace std;

class node{
public:
	int cx, cy, px, py;
};


int score = 0;

class LEVEL_2
{
public:
	vector <node> snake;
	int snake_length = 3;
	int food_x = 5, food_y = 5;
	int snakex = 5;
	int snakey = 5;
	int Time = 200;

bool valid_position(int x, int y)
{
	for (int i = 0; i<snake_length; i++)
	{
		if (x == snake[i].cx && y == snake[i].cy)
			return false;
	}
	return true;
}

bool lost()
{
	for (int i = 1; i<snake_length; i++)
	{
		if (snake[0].cx == snake[i].cx && snake[0].cy == snake[i].cy)
			return true;
	}
	return false;
}

void genApple()
{
	do
	{
		srand(time(NULL));
		food_x = rand() % 35 + 3;
		food_y = rand() % 15 + 3;
	} while (!valid_position(food_x, food_y));
	move(food_x, food_y);
}

void draw(char ch = '*')
{
	cout << ch;
}

void eat()
{
	node newnode;
	newnode.cx = snake[snake_length - 1].px;
	newnode.cy = snake[snake_length - 1].py;
	snake.push_back(newnode);
	snake_length++;
	genApple();
}

void move(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	draw('o');
}

void Move(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	draw();
}

void repeat_node_position()
{
	Move(snake[0].cx, snake[0].cy);
	for (int i = 1; i<snake_length; i++)
	{
		snake[i].px = snake[i].cx;
		snake[i].py = snake[i].cy;
		snake[i].cx = snake[i - 1].px;
		snake[i].cy = snake[i - 1].py;
		Move(snake[i].cx, snake[i].cy);
	}
	Sleep(Time);
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void board()
{
	gotoxy(1, 1);
	for (int i = 1; i<40; i++)
	{
		cout << "#";
	}

	gotoxy(1, 20);
	for (int i = 1; i<40; i++)
	{
		cout << "#";
	}

	for (int i = 1; i<20; i++)
	{
		gotoxy(1, i);
		cout << "#";
	}
	for (int i = 1; i<20; i++)
	{
		gotoxy(40, i);
		cout << "#";
	}
}

void LEVEL()
{
	board();

	node s1;
	s1.cx = 5;
	s1.cy = 5;
	node s2;
	s2.cx = 5;
	s2.cy = 4;
	node s3;
	s3.cx = 5;
	s3.cy = 3;
	snake.push_back(s1);
	snake.push_back(s2);
	snake.push_back(s3);

	char a = 's';
	char b = 's';
	while (!lost())
	{
		system("cls");
		board();
		//control with the snake  
		if (food_x == snake[0].cx &&food_y == snake[0].cy)
		{
			score += 10;
			Time -= 10;
			eat();
		}

		move(food_x, food_y);
		b = a;
		snake[0].px = snake[0].cx;
		snake[0].py = snake[0].cy;
		Move(snake[0].cx, snake[0].cy);

		if (_kbhit())
		{
			a = _getch();
		}

		//control with the game area
		if (snake[0].cx <= 2)
		{
			gotoxy(10, 10);
			cout << "  CRASH  !!"; Sleep(1000);
			break;
		}
		else if (snake[0].cx >= 39)
		{
			gotoxy(10, 10);
			cout << "CRASH  !!"; Sleep(1000);
			break;
		}
		else if (snake[0].cy <= 2)
		{
			gotoxy(10,10 );
			cout << " CRASH !!  "; Sleep(1000);
			break;
		}
		else if (snake[0].cy >= 19)
		{
			gotoxy(10, 10);
			cout << "CRASH  !!"; Sleep(1000);
			break;
		}
		else if (a == 'a' && b != 'd')
		{
			snake[0].cx -= 1;
			repeat_node_position();
		}
		else if (a == 'w' && b != 's')
		{
			snake[0].cy -= 1;
			repeat_node_position();
		}
		else if (a == 's' && b != 'w')
		{
			snake[0].cy += 1;
			repeat_node_position();
		}
		else if (a == 'd' && b != 'a')
		{
			snake[0].cx += 1;
			repeat_node_position();
		}
		else
		{
			a = b;
		}
	}

	system("cls");
	gotoxy(35,13);
	cout << "Game Over !! ";
	gotoxy(30, 15);
	cout << "Your Score : " << score << " Points"<< endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	Sleep(4000);
	exit(100);
}//third Level 

bool valid_position$$(int x, int y)
{
	for (int i = 0; i<snake_length; i++)
	{
		if (x == snake[i].cx && y == snake[i].cy)
			return false;
		else if ((x>10 && x<50 && y == 5) || (x>10 && x < 50 && y == 20))
			return false;
	}
	return true;
}

void genApple$$()
{
	do
	{
		srand(time(NULL));
		food_x = rand() % 35 + 3;
		food_y = rand() % 15 + 3;
	}while (!valid_position$$(food_x, food_y));
	move(food_x, food_y);
}

void eat$$()
{
	node newnode;
	newnode.cx = snake[snake_length - 1].px;
	newnode.cy = snake[snake_length - 1].py;
	snake.push_back(newnode);
	snake_length++;
	genApple$$();
}

void Borad$$()
{
	gotoxy(21, 5);
	for (int i = 20; i<50; i++)
	{
		cout << "@";
	}

	gotoxy(21, 20);
	for (int i = 20; i<50; i++)
	{
		cout << "@";
	}
}

void LEVEL$$()
{
	Borad$$();
	node s1;
	s1.cx = 5;
	s1.cy = 5;
	node s2;
	s2.cx = 5;
	s2.cy = 4;
	node s3;
	s3.cx = 5;
	s3.cy = 3;
	snake.push_back(s1);
	snake.push_back(s2);
	snake.push_back(s3);

	char a = 's';
	char b = 's';

	while (!lost())
	{
		system("cls");
		Borad$$();
	
		if (score == 200)
		{
			system("cls");
			gotoxy(35, 12);
			cout << "LEVEL 3 !!! ";
			Sleep(2000);
			//reset the controler 
			a = 's';
			b = 's';

			LEVEL_2 q;
			q.LEVEL();
		}

		//control with the snake  
		if (food_x == snake[0].cx &&food_y == snake[0].cy)
		{
			score += 10;
			Time -= 10;
			eat$$();
		}

		move(food_x, food_y);
		b = a;
		snake[0].px = snake[0].cx;
		snake[0].py = snake[0].cy;
		Move(snake[0].cx, snake[0].cy);

		if (_kbhit())
		{
			a = _getch();
		}

		//control with the game area
		if ( (snake[0].cx >= 20 && snake[0].cx<=51) && snake[0].cy == 5 )
		{
			system("cls");
			gotoxy(35,12);
			cout << "  CRASH  !!"; Sleep(1000);
			break;
		}
		else if ( (snake[0].cx >= 20 && snake[0].cx <= 51)  && snake[0].cy == 20 )
		{
			system("cls");
			gotoxy(35,12);
			cout << "  CRASH  !!"; Sleep(1000);
			break;
		}

		if (snake[0].cx <= 0)
		{
			snake[0].cy--;
			repeat_node_position();
			snake[0].cx++;
			repeat_node_position();
			a = 'd';
		}
		else if (snake[0].cx >= 77)
		{
			snake[0].cy--;
			repeat_node_position();
			snake[0].cx--;
			repeat_node_position();
			a = 'a';
		}
		else if (snake[0].cy <= 0)
		{
			snake[0].cx++;
			repeat_node_position();
			snake[0].cy++;
			repeat_node_position();
			a = 's';
		}
		else if (snake[0].cy >= 24)
		{
			snake[0].cx--;
			repeat_node_position();
			snake[0].cy--;
			repeat_node_position();
			a = 'w';
		}
		else if (a == 'a' && b != 'd')
		{
			snake[0].cx -= 1;
			repeat_node_position();
		}
		else if (a == 'w' && b != 's')
		{
			snake[0].cy -= 1;
			repeat_node_position();
		}
		else if (a == 's' && b != 'w')
		{
			snake[0].cy += 1;
			repeat_node_position();
		}
		else if (a == 'd' && b != 'a')
		{
			snake[0].cx += 1;
			repeat_node_position();
		}
		else
		{
			a = b;
		}
	}
	//end of game loop
	system("cls");
	gotoxy(35, 13);
	cout << "Game Over !! ";
	gotoxy(30, 15);
	cout << "Your Score : " << score << " Points" <<endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	Sleep(4000);
	exit(100);
}
};