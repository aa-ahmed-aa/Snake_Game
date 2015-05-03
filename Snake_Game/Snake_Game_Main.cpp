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
# include "LEVEL_2.h"
using namespace std;

class node_1{
public:
	int cx, cy, px, py;
};

vector <node_1> snake;
int snake_length = 3;
int food_x = 5, food_y = 5;
int snakex = 5;
int snakey = 5;
int Time = 200;


bool valid_position(int x, int y); //to make sure that x and y isn't on the snake node x, y
bool lost(); // to make sure that 
void genApple();//to calculate the food position 
void draw(char );//to draw the snake *
void eat();//to draw the eat to aposition that is't on the snake position 
void move(int x, int y);//to draw move and draw the eat 
void Move(int x, int y);//to move and draw the snake
void repeat_node_position();//to repeat the snake node position and make it follow the head
void gotoxy(int x, int y);//to go to specific Position 
void Welcoming();//Welcoming the User

void Welcoming()
{
	gotoxy(10, 10);
	cout << "0 00";
	gotoxy(9, 9);
	cout << "0   00";
	gotoxy(8, 8);
	cout << "0    0000";
	gotoxy(7, 7);
	cout << "00000    00";
	gotoxy(6, 6);
	cout << "00000    0000";
	gotoxy(5, 5);
	cout << "00000    000000";
	gotoxy(4, 4);
	cout << "00000    00000000";
	gotoxy(3, 3);
	cout << "00000   00000000000";
	gotoxy(2, 2);
	cout << "00000   0000000000000";
	gotoxy(1, 1);
	cout << "000000000 0000000000000";
}
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
		food_x = rand() % 76 + 2;
		food_y = rand() % 23 + 2;
	} while (!valid_position(food_x, food_y));
	move(food_x, food_y);
}

void draw(char ch = '*')
{
	cout << ch;
}

void eat()
{
	node_1 newnode;
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

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
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

int main()
{
	Welcoming();

	gotoxy(35, 12);
	cout << "LEVEL 1 !!! ";
	Sleep(4000);

	node_1 s1;
	s1.cx = 5;
	s1.cy = 5;
	node_1 s2;
	s2.cx = 5;
	s2.cy = 4;
	node_1 s3;
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


		if (score == 100)
		{
			Time = 150;
			system("cls");
			gotoxy(35, 12);
			cout << "LEVEL 2 !!! ";
			Sleep(2000);
			//reset the controler
			a = 's';
			b = 's';
			
			LEVEL_2 l;
			l.LEVEL$$();
		}

		//control with the snake  
		if (food_x == snake[0].cx &&food_y == snake[0].cy)
		{
			Time -= 10;
			score += 10;
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
		if (snake[0].cx <= 0)
		{
			snake[0].cy--;
			repeat_node_position();
			snake[0].cx ++;
			repeat_node_position();
			a = 'd';
		}
		else if (snake[0].cx >= 77)
		{
			snake[0].cy--;
			repeat_node_position();
			snake[0].cx --;
			repeat_node_position();
			a = 'a';
		}
		else if (snake[0].cy <= 0)
		{
			snake[0].cx++;
			repeat_node_position();
			snake[0].cy ++;
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
	cout << "Game Over !! " ;
	gotoxy(30, 15);
	cout << "Your Score : " << score << " Points" <<endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	Sleep(4000);
	exit(100);
	return 0;
}