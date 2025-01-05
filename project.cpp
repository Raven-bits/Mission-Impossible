#include<iostream>
#include<conio.h>
#include<windows.h>
#include<iomanip>
#include<fstream>
#include<cstdlib>
#include<string>
#include<ctime>
using namespace std;



//Global Variables

bool gameOver = false;
const char body = '|';
const char head = '0';
const char leftHand = '/';
const char rightHand = '\\';
char leftLeg = '/';
char rightLeg = '\\';
const char bulletsUp = '^';
const char bulletsDown = 'o';
const char bulletsLeft = '>';
const char bulletsRight = '<';
const char enemyBulletLeft = '-';
const char enemyBulletRight = '_';
const char enemyBulletUp = '!';
const char enemyBulletDown = '*';
bool Eup, Edown, Eleft, Eright;
bool up, down, lt, rt;
const char enemy = 'V';
const char enemyHead = 'I';
const char enemyLeft = '[';
const char enemyRight = ']';
const char obstacle = '#';

bool gameWin = false;
const int height = 30;                 //heigth
const int width = 60;
int bodyX = width / 2;
int bodyY = height - 5;              //width
char game[height][width];
int sx = width / 2, sy = height - 2;				 //coordinates 
int s2x = (width / 2) + 6, s2y = height - 2;        //coordinates 
int lives = 3;                    //lives
int level = 1;                    //levels
char gameBoundry = 219;
bool lvlUp = false;
bool isenemydead = false;
int score = 0;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//enemy
int enemy2X = width - 9;
int enemy2Y = 8;
int enemy1X = 6;
int enemy1Y = 15;
int enemy3X = height - 6;
int enemy3Y = 5;
int enemy4X = width - 6;
int enemy4Y = height - 6;
int enemy5X = height / 2;
int enemy5Y = width / 2;
int enemy6X = 44;
int enemy6Y = 14;
bool bulletHit = false;

bool enemy1alive = true;
bool enemy2alive = true;
bool enemy3alive = true;
bool enemy4alive = true;
bool enemy5alive = true;
bool enemy6alive = true;

//soloman 
const char solomanLeft = '[';
const char solomanRight = ']';
const char solomanheart = 'O';
const char solomantenticales = 'X';
int soloX = (width / 2);     //soloman
int soloY = 10;             //soloman
int exitx = width / 2;
int exitY = 1;
int direction = 0;
char exitdoor = 220;
int randomDirection1 = 1; // Enemy 1 direction
int randomDirection2 = 0; // Enemy 2 direction
int randomDirection3 = 1; // Enemy 3 direction
int randomDirection4 = 0; // Enemy 4 direction
int randomDirection5 = 1; // Enemy 5 direction
int randomDirection6 = 0; // Enemy 6 direction

//Prototypes

int main();
void newlvl();
void gameLoop();
void positions();
void pause();
void continu();
void menu();
void player();
void print();
void instructions();
void controller();
void soloManMotion();
void boundarycheck();
void soloethanenemy();
void killEnemy();

//Functions

void positions()
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (y == 0 || y == height - 1)
				game[y][x] = gameBoundry;
			else if (x == 0 || x == width - 1)
				game[y][x] = gameBoundry;
			else
				game[y][x] = ' ';
		}
	}
	game[bodyY][bodyX] = body;
	game[bodyY - 1][bodyX] = head;
	game[bodyY][bodyX - 1] = leftHand;
	game[bodyY][bodyX + 1] = rightHand;
	game[bodyY + 1][bodyX - 1] = leftLeg;
	game[bodyY + 1][bodyX + 1] = rightLeg;




	if (level == 1)
	{
		//obstacle 1
		game[20][10] = enemyLeft;
		game[20][11] = obstacle;
		game[20][12] = obstacle;
		game[20][14] = enemyRight;
		game[20][13] = obstacle;

		//obstacle 1
		game[20][width - 10] = enemyRight;
		game[20][width - 11] = obstacle;
		game[20][width - 12] = obstacle;
		game[20][width - 14] = enemyLeft;
		game[20][width - 13] = obstacle;

		//enemy
		// Enemy 1 Positioning
		game[enemy1Y + 1][enemy1X] = enemy;
		game[enemy1Y][enemy1X] = enemyHead;
		game[enemy1Y][enemy1X - 1] = enemyLeft;
		game[enemy1Y][enemy1X + 1] = enemyRight;
		game[enemy1Y + 1][enemy1X - 1] = enemyLeft;
		game[enemy1Y + 1][enemy1X + 1] = enemyRight;

		// Enemy 2 Positioning
		game[enemy2Y + 1][enemy2X] = enemy;
		game[enemy2Y][enemy2X] = enemyHead;
		game[enemy2Y][enemy2X - 1] = enemyLeft;
		game[enemy2Y][enemy2X + 1] = enemyRight;
		game[enemy2Y + 1][enemy2X - 1] = enemyLeft;
		game[enemy2Y + 1][enemy2X + 1] = enemyRight;

	}
	if (level == 2)
	{
		//obstacle 1
		game[20][10] = enemyLeft;
		game[20][11] = obstacle;
		game[20][12] = obstacle;
		game[20][15] = enemyRight;
		game[20][13] = obstacle;
		game[20][14] = obstacle;

		//obstacle 1
		game[20][width - 10] = enemyRight;
		game[20][width - 11] = obstacle;
		game[20][width - 12] = obstacle;
		game[20][width - 15] = enemyLeft;
		game[20][width - 13] = obstacle;
		game[20][width - 14] = obstacle;

		game[18][width - 6] = enemyRight;
		game[18][width - 7] = obstacle;
		game[18][width - 8] = obstacle;
		game[18][width - 11] = enemyLeft;
		game[18][width - 9] = obstacle;
		game[18][width - 10] = obstacle;

		// Enemy 1 Positioning
		game[enemy1Y + 1][enemy1X] = enemy;
		game[enemy1Y][enemy1X] = enemyHead;
		game[enemy1Y][enemy1X - 1] = enemyLeft;
		game[enemy1Y][enemy1X + 1] = enemyRight;
		game[enemy1Y + 1][enemy1X - 1] = enemyLeft;
		game[enemy1Y + 1][enemy1X + 1] = enemyRight;

		// Enemy 2 Positioning
		game[enemy2Y + 1][enemy2X] = enemy;
		game[enemy2Y][enemy2X] = enemyHead;
		game[enemy2Y][enemy2X - 1] = enemyLeft;
		game[enemy2Y][enemy2X + 1] = enemyRight;
		game[enemy2Y + 1][enemy2X - 1] = enemyLeft;
		game[enemy2Y + 1][enemy2X + 1] = enemyRight;

		// Enemy 3 Positioning
		game[enemy3Y + 1][enemy3X] = enemy;
		game[enemy3Y][enemy3X] = enemyHead;
		game[enemy3Y][enemy3X - 1] = enemyLeft;
		game[enemy3Y][enemy3X + 1] = enemyRight;
		game[enemy3Y + 1][enemy3X - 1] = enemyLeft;
		game[enemy3Y + 1][enemy3X + 1] = enemyRight;
	}
	if (level == 3)
	{
		//obstacle 1
		game[20][10] = enemyLeft;
		game[20][11] = obstacle;
		game[20][12] = obstacle;
		game[20][15] = enemyRight;
		game[20][13] = obstacle;
		game[20][14] = obstacle;

		//obstacle 1
		game[20][width - 10] = enemyRight;
		game[20][width - 11] = obstacle;
		game[20][width - 12] = obstacle;
		game[20][width - 15] = enemyLeft;
		game[20][width - 13] = obstacle;
		game[20][width - 14] = obstacle;

		game[18][width - 6] = enemyRight;
		game[18][width - 7] = obstacle;
		game[18][width - 8] = obstacle;
		game[18][width - 11] = enemyLeft;
		game[18][width - 9] = obstacle;
		game[18][width - 10] = obstacle;

		game[18][6] = enemyRight;
		game[18][7] = obstacle;
		game[18][8] = obstacle;
		game[18][11] = enemyLeft;
		game[18][9] = obstacle;
		game[18][10] = obstacle;

		// Enemy 1 Positioning
		game[enemy1Y + 1][enemy1X] = enemy;
		game[enemy1Y][enemy1X] = enemyHead;
		game[enemy1Y][enemy1X - 1] = enemyLeft;
		game[enemy1Y][enemy1X + 1] = enemyRight;
		game[enemy1Y + 1][enemy1X - 1] = enemyLeft;
		game[enemy1Y + 1][enemy1X + 1] = enemyRight;

		// Enemy 2 Positioning
		game[enemy2Y + 1][enemy2X] = enemy;
		game[enemy2Y][enemy2X] = enemyHead;
		game[enemy2Y][enemy2X - 1] = enemyLeft;
		game[enemy2Y][enemy2X + 1] = enemyRight;
		game[enemy2Y + 1][enemy2X - 1] = enemyLeft;
		game[enemy2Y + 1][enemy2X + 1] = enemyRight;

		// Enemy 3 Positioning
		game[enemy3Y + 1][enemy3X] = enemy;
		game[enemy3Y][enemy3X] = enemyHead;
		game[enemy3Y][enemy3X - 1] = enemyLeft;
		game[enemy3Y][enemy3X + 1] = enemyRight;
		game[enemy3Y + 1][enemy3X - 1] = enemyLeft;
		game[enemy3Y + 1][enemy3X + 1] = enemyRight;

		// Enemy 4 Positioning
		game[enemy4Y + 1][enemy4X] = enemy;
		game[enemy4Y][enemy4X] = enemyHead;
		game[enemy4Y][enemy4X - 1] = enemyLeft;
		game[enemy4Y][enemy4X + 1] = enemyRight;
		game[enemy4Y + 1][enemy4X - 1] = enemyLeft;
		game[enemy4Y + 1][enemy4X + 1] = enemyRight;

	}
	if (level == 4)
	{
		//obstacle 1
		game[20][10] = enemyLeft;
		game[20][11] = obstacle;
		game[20][12] = obstacle;
		game[20][15] = enemyRight;
		game[20][13] = obstacle;
		game[20][14] = obstacle;

		//obstacle 1
		game[20][width - 10] = enemyRight;
		game[20][width - 11] = obstacle;
		game[20][width - 12] = obstacle;
		game[20][width - 15] = enemyLeft;
		game[20][width - 13] = obstacle;
		game[20][width - 14] = obstacle;

		game[18][width - 6] = enemyRight;
		game[18][width - 7] = obstacle;
		game[18][width - 8] = obstacle;
		game[18][width - 11] = enemyLeft;
		game[18][width - 9] = obstacle;
		game[18][width - 10] = obstacle;

		game[18][6] = enemyRight;
		game[18][7] = obstacle;
		game[18][8] = obstacle;
		game[18][11] = enemyLeft;
		game[18][9] = obstacle;
		game[18][10] = obstacle;

		game[15][6] = enemyRight;
		game[15][7] = obstacle;
		game[15][8] = obstacle;
		game[15][11] = enemyLeft;
		game[15][9] = obstacle;
		game[15][10] = obstacle;

		// Enemy 1 Positioning
		game[enemy1Y + 1][enemy1X] = enemy;
		game[enemy1Y][enemy1X] = enemyHead;
		game[enemy1Y][enemy1X - 1] = enemyLeft;
		game[enemy1Y][enemy1X + 1] = enemyRight;
		game[enemy1Y + 1][enemy1X - 1] = enemyLeft;
		game[enemy1Y + 1][enemy1X + 1] = enemyRight;

		// Enemy 2 Positioning
		game[enemy2Y + 1][enemy2X] = enemy;
		game[enemy2Y][enemy2X] = enemyHead;
		game[enemy2Y][enemy2X - 1] = enemyLeft;
		game[enemy2Y][enemy2X + 1] = enemyRight;
		game[enemy2Y + 1][enemy2X - 1] = enemyLeft;
		game[enemy2Y + 1][enemy2X + 1] = enemyRight;

		// Enemy 3 Positioning
		game[enemy3Y + 1][enemy3X] = enemy;
		game[enemy3Y][enemy3X] = enemyHead;
		game[enemy3Y][enemy3X - 1] = enemyLeft;
		game[enemy3Y][enemy3X + 1] = enemyRight;
		game[enemy3Y + 1][enemy3X - 1] = enemyLeft;
		game[enemy3Y + 1][enemy3X + 1] = enemyRight;

		// Enemy 4 Positioning
		game[enemy4Y + 1][enemy4X] = enemy;
		game[enemy4Y][enemy4X] = enemyHead;
		game[enemy4Y][enemy4X - 1] = enemyLeft;
		game[enemy4Y][enemy4X + 1] = enemyRight;
		game[enemy4Y + 1][enemy4X - 1] = enemyLeft;
		game[enemy4Y + 1][enemy4X + 1] = enemyRight;

		// Enemy 5 Positioning
		game[enemy5Y + 1][enemy5X] = enemy;
		game[enemy5Y][enemy5X] = enemyHead;
		game[enemy5Y][enemy5X - 1] = enemyLeft;
		game[enemy5Y][enemy5X + 1] = enemyRight;
		game[enemy5Y + 1][enemy5X - 1] = enemyLeft;
		game[enemy5Y + 1][enemy5X + 1] = enemyRight;


	}
	if (level == 5)
	{
		//obstacle 1
		game[20][10] = enemyLeft;
		game[20][11] = obstacle;
		game[20][12] = obstacle;
		game[20][15] = enemyRight;
		game[20][13] = obstacle;
		game[20][14] = obstacle;

		//obstacle 1
		game[20][width - 10] = enemyRight;
		game[20][width - 11] = obstacle;
		game[20][width - 12] = obstacle;
		game[20][width - 15] = enemyLeft;
		game[20][width - 13] = obstacle;
		game[20][width - 14] = obstacle;

		game[18][width - 6] = enemyRight;
		game[18][width - 7] = obstacle;
		game[18][width - 8] = obstacle;
		game[18][width - 11] = enemyLeft;
		game[18][width - 9] = obstacle;
		game[18][width - 10] = obstacle;

		game[18][6] = enemyRight;
		game[18][7] = obstacle;
		game[18][8] = obstacle;
		game[18][11] = enemyLeft;
		game[18][9] = obstacle;
		game[18][10] = obstacle;

		game[15][6] = enemyRight;
		game[15][7] = obstacle;
		game[15][8] = obstacle;
		game[15][11] = enemyLeft;
		game[15][9] = obstacle;
		game[15][10] = obstacle;

		// Enemy 1 Positioning
		game[enemy1Y + 1][enemy1X] = enemy;
		game[enemy1Y][enemy1X] = enemyHead;
		game[enemy1Y][enemy1X - 1] = enemyLeft;
		game[enemy1Y][enemy1X + 1] = enemyRight;
		game[enemy1Y + 1][enemy1X - 1] = enemyLeft;
		game[enemy1Y + 1][enemy1X + 1] = enemyRight;

		// Enemy 2 Positioning
		game[enemy2Y + 1][enemy2X] = enemy;
		game[enemy2Y][enemy2X] = enemyHead;
		game[enemy2Y][enemy2X - 1] = enemyLeft;
		game[enemy2Y][enemy2X + 1] = enemyRight;
		game[enemy2Y + 1][enemy2X - 1] = enemyLeft;
		game[enemy2Y + 1][enemy2X + 1] = enemyRight;

		// Enemy 3 Positioning
		game[enemy3Y + 1][enemy3X] = enemy;
		game[enemy3Y][enemy3X] = enemyHead;
		game[enemy3Y][enemy3X - 1] = enemyLeft;
		game[enemy3Y][enemy3X + 1] = enemyRight;
		game[enemy3Y + 1][enemy3X - 1] = enemyLeft;
		game[enemy3Y + 1][enemy3X + 1] = enemyRight;

		// Enemy 4 Positioning
		game[enemy4Y + 1][enemy4X] = enemy;
		game[enemy4Y][enemy4X] = enemyHead;
		game[enemy4Y][enemy4X - 1] = enemyLeft;
		game[enemy4Y][enemy4X + 1] = enemyRight;
		game[enemy4Y + 1][enemy4X - 1] = enemyLeft;
		game[enemy4Y + 1][enemy4X + 1] = enemyRight;

		// Enemy 5 Positioning
		game[enemy5Y + 1][enemy5X] = enemy;
		game[enemy5Y][enemy5X] = enemyHead;
		game[enemy5Y][enemy5X - 1] = enemyLeft;
		game[enemy5Y][enemy5X + 1] = enemyRight;
		game[enemy5Y + 1][enemy5X - 1] = enemyLeft;
		game[enemy5Y + 1][enemy5X + 1] = enemyRight;

		// Enemy 6 Positioning
		game[enemy6Y + 1][enemy6X] = enemy;
		game[enemy6Y][enemy6X] = enemyHead;
		game[enemy6Y][enemy6X - 1] = enemyLeft;
		game[enemy6Y][enemy6X + 1] = enemyRight;
		game[enemy6Y + 1][enemy6X - 1] = enemyLeft;
		game[enemy6Y + 1][enemy6X + 1] = enemyRight;

	}
	///exit door
	game[exitY][exitx] = exitdoor;
	game[exitY][exitx - 1] = exitdoor;
	game[exitY][exitx + 1] = exitdoor;
	game[exitY][exitx - 2] = exitdoor;
	game[exitY][exitx + 2] = exitdoor;
	//soloman
	game[soloY][soloX - 1] = solomanLeft;
	game[soloY][soloX] = solomantenticales;
	game[soloY][soloX + 1] = solomanRight;
	game[soloY + 1][soloX] = solomanheart;
	game[soloY + 1][soloX - 1] = solomanLeft;
	game[soloY + 1][soloX + 1] = solomanRight;
	game[soloY + 1][soloX - 4] = solomanLeft;
	game[soloY + 1][soloX - 3] = solomantenticales;
	game[soloY + 1][soloX - 2] = solomanRight;
	game[soloY + 1][soloX + 2] = solomanLeft;
	game[soloY + 1][soloX + 3] = solomantenticales;
	game[soloY + 1][soloX + 4] = solomanRight;
	game[soloY + 2][soloX - 1] = solomanLeft;
	game[soloY + 2][soloX] = solomantenticales;
	game[soloY + 2][soloX + 1] = solomanRight;

	up = down = rt = lt = false;
}
void pause()
{
	char check2;
	do {
		system("cls");
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 120; j++)
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
				if ((i == 6 || i == 7 || i == 17 || i == 18) && (j >= 40 && j <= 80))
				{
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
					cout << gameBoundry;
				}

				else if ((j == 40 || j == 80) && (i > 6 && i < 19))
				{
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
					cout << gameBoundry;
				}

				else if (i == 11 && j == 49)
				{
					cout << "To Resume Game, Press r";
					j += 22;
				}
				else if (i == 12 && j == 49)
				{
					cout << "To See Menu, Press m";
					j += 19;
				}
				else if (i == 13 && j == 49)
				{
					cout << "For Game Over, Press 0";
					j += 21;
				}
				else
					cout << " ";
			}
			cout << '\n';
		}
		check2 = _getch();
		Beep(600, 200);
		if (check2 == 'm')
			gameLoop();
		else if (check2 == '0')
		{
			gameOver = true;
			gameLoop();
			break;
		}
	} while (check2 != 'r');
	system("cls");
}
void instructions()
{

	char check;
	do {
		system("cls");
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 90; j++)
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
				if ((i == 6 || i == 7 || i == 17 || i == 18) && (j >= 40 && j <= 80))
				{
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
					cout << gameBoundry;
				}
				else if ((j == 40 || j == 80) && (i > 6 && i < 19))
				{
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
					cout << gameBoundry;
				}
				else if (i == 8 && j == 41)
				{
					cout << "To Move Up, Press W";
					j += 18;
				}
				else if (i == 10 && j == 41)
				{
					cout << "To Move Down, Press S";
					j += 20;
				}
				else if (i == 12 && j == 41)
				{
					cout << "To Move Left, Press A";
					j += 20;
				}
				else if (i == 14 && j == 41)
				{
					cout << "To Move Right, Press D";
					j += 21;
				}
				else if (i == 16 && j == 41)
				{
					cout << "To Exit, Press E";
					j += 15;
				}
				else
					cout << " ";
			}
			cout << '\n';
		}
		check = _getch();
		Beep(600, 200);
	} while (check != 'e');
	system("cls");
}

void enemyMovement()
{


	// Generate random directions for both enemies (0 for left, 1 for right, 2 for up, 3 for down)
	randomDirection1 = rand() % 4; // Enemy 1 direction
	randomDirection2 = rand() % 4; // Enemy 2 direction
	randomDirection3 = rand() % 4; // Enemy 3 direction
	randomDirection4 = rand() % 4; // Enemy 4 direction
	randomDirection5 = rand() % 4; // Enemy 5 direction
	randomDirection6 = rand() % 4; // Enemy 6 direction

	int i = 1;
	if (level > i)
	{
		i++;
	}
	// Movement logic for Enemy 1
	if (randomDirection1 == 0 && enemy1alive) {
		// Move left for Enemy 1
		if (enemy1X - i > 4) {
			enemy1X = enemy1X - i;
		}
	}
	else if (randomDirection1 == 1 && enemy1alive) {
		// Move right for Enemy 1
		if (enemy1X < width - 5 - i) {
			enemy1X = enemy1X + i;
		}
	}
	else if (randomDirection1 == 2 && enemy1alive) {
		// Move up for Enemy 1
		if (enemy1Y - i > 2) {
			enemy1Y = enemy1Y - i;
		}
	}
	else if (enemy1alive) {
		// Move down for Enemy 1
		if (enemy1Y < height - 3 - i) {
			enemy1Y = enemy1Y + i;
		}
	}

	// Movement logic for Enemy 2
	if (randomDirection2 == 0 && enemy2alive) {
		// Move left for Enemy 2
		if (enemy2X - i > 4) {
			enemy2X = enemy2X - i;
		}
	}
	else if (randomDirection2 == 1 && enemy2alive) {
		// Move right for Enemy 2
		if (enemy2X < width - 5 - i) {
			enemy2X = enemy2X + i;
		}
	}
	else if (randomDirection2 == 2 && enemy2alive) {
		// Move up for Enemy 2
		if (enemy2Y - i > 2) {
			enemy2Y = enemy2Y - i;
		}
	}
	else if (enemy2alive) {
		// Move down for Enemy 2
		if (enemy2Y < height - 3 - i) {
			enemy2Y = enemy2Y + i;
		}
	}
	if (randomDirection3 == 0 && enemy3alive) {
		// Move left for Enemy 3
		if (enemy3X - i > 4) {
			enemy3X = enemy3X - i;
		}
	}
	else if (randomDirection3 == 1 && enemy3alive) {
		// Move right for Enemy 3
		if (enemy3X < width - 5 - i) {
			enemy3X = enemy3X + i;
		}
	}
	else if (randomDirection3 == 2 && enemy3alive) {
		// Move up for Enemy 3
		if (enemy3Y - i > 2) {
			enemy3Y = enemy3Y - i;
		}
	}
	else if (enemy3alive) {
		// Move down for Enemy 3
		if (enemy3Y < height - 3 - i) {
			enemy3Y = enemy3Y + i;
		}
	}

	// Enemy 4
	if (randomDirection4 == 0 && enemy4alive) {
		// Move left for Enemy 4
		if (enemy4X - i > 4) {
			enemy4X = enemy4X - i;
		}
	}
	else if (randomDirection4 == 1 && enemy4alive) {
		// Move right for Enemy 4
		if (enemy4X < width - 5 - i) {
			enemy4X = enemy4X + i;
		}
	}
	else if (randomDirection4 == 2 && enemy4alive) {
		// Move up for Enemy 4
		if (enemy4Y - i > 2) {
			enemy4Y = enemy4Y - i;
		}
	}
	else if (enemy4alive) {
		// Move down for Enemy 4
		if (enemy4Y < height - 3 - i) {
			enemy4Y = enemy4Y + i;
		}
	}

	// Enemy 5
	if (randomDirection5 == 0 && enemy5alive) {
		// Move left for Enemy 5
		if (enemy5X - i > 4) {
			enemy5X = enemy5X - i;
		}
	}
	else if (randomDirection5 == 1 && enemy5alive) {
		// Move right for Enemy 5
		if (enemy5X < width - 5 - i) {
			enemy5X = enemy5X + i;
		}
	}
	else if (randomDirection5 == 2 && enemy5alive) {
		// Move up for Enemy 5
		if (enemy5Y - i > 2) {
			enemy5Y = enemy5Y - i;
		}
	}
	else if (enemy5alive) {
		// Move down for Enemy 5
		if (enemy5Y < height - 3 - i) {
			enemy5Y = enemy5Y + i;
		}
	}

	// Enemy 6
	if (randomDirection6 == 0 && enemy6alive) {
		// Move left for Enemy 6
		if (enemy6X - i > 4) {
			enemy6X = enemy6X - i;
		}
	}
	else if (randomDirection6 == 1 && enemy6alive) {
		// Move right for Enemy 6
		if (enemy6X < width - 5 - i) {
			enemy6X = enemy6X + i;
		}
	}
	else if (randomDirection6 == 2 && enemy6alive) {
		// Move up for Enemy 6
		if (enemy6Y - i > 2) {
			enemy6Y = enemy6Y - i;
		}
	}
	else if (enemy6alive) {
		// Move down for Enemy 6
		if (enemy6Y < height - 3 - i) {
			enemy6Y = enemy6Y + i;
		}
	}

}

void gameLoop()
{
	char option;
	if (!gameOver)
	{

		do {

			menu();
			option = _getch();
			Beep(600, 200);
			system("cls");

			switch (option)
			{
			case '1':
				while (!gameOver)
				{
					print();
					boundarycheck();
					soloethanenemy();
					if (_kbhit())
						controller();
					player();
					if (rand() % 5 == 1)
						enemyMovement();
					soloManMotion();
				}
				break;
			case '2':

				break;

			case '3':

				instructions();
				break;

			case '4':
				gameOver = true;
				break;
			default:
				break;
			}
		} while (!gameOver);
	}

	if (gameOver)
	{

		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		system("cls");
		cout << "" << endl << endl;
		cout << " ------------------------------------------------------------------------- " << endl;
		cout << "|    *****      *     *       * ******       ****  *       ****** ****    |" << endl;
		cout << "|   *          * *    * *   * * *           *    *  *     * *     *   *   |" << endl;
		cout << "|   *  ****   *   *   *  * *  * *****       *    *   *   *  ****  ****    |" << endl;
		cout << "|   *  *  *  *******  *   *   * *           *    *    * *   *     * *     |" << endl;
		cout << "|    *****  *       * *       * ******       ****      *    ***** *   *   |" << endl;
		cout << " ------------------------------------------------------------------------- " << endl;
		cout << "" << endl << endl;
		cout << "                        Y O U R   S C O R E : " << score << endl << endl;
		cout << "" << endl << endl;
		Beep(400, 800);
		Sleep(1500);
		system("cls");

		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 120; j++)
			{
				if ((i == 11 || i == 12 || i == 17 || i == 18) && (j >= 40 && j <= 80))
				{
					cout << gameBoundry;
				}

				else if ((j == 40 || j == 80) && (i > 11 && i < 19))
				{
					cout << gameBoundry;
				}

				else if (i == 14 && j == 41)
				{
					cout << "If You Want to Continue Press C";
					j += 30;
				}
				else if (i == 15 && j == 41)
				{
					cout << "If You Want to Exit Game Press E";
					j += 31;
				}
				else
					cout << " ";
			}
			cout << '\n';
		}
	}
	char cont;
	do
	{
		cont = _getch();
		Beep(600, 200);
		switch (cont)
		{
		case 'c':
		case 'C':
			continu();
			break;
		case 'e':
		case 'E':
			system("cls");

			for (int i = 0; i < 30; i++)
			{
				for (int j = 0; j < 120; j++)
				{
					SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
					if ((i == 6 || i == 7 || i == 17 || i == 18) && (j >= 40 && j <= 80))
					{
						SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
						cout << gameBoundry;
					}

					else if ((j == 40 || j == 80) && (i > 6 && i < 19))
					{
						SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
						cout << gameBoundry;
					}
					else if (i == 13 && j == 43)
					{
						cout << "ThankYou For Playing Mission Imposible";
						j += 34;
					}
					else
						cout << " ";
				}
				cout << '\n';
			}
			cont = '^';
			break;

		default:
			break;
		}
	} while (cont != '^');
}

void continu()
{
	system("cls");
	sx = width / 2, sy = height - 2;
	lives = 3;
	level = 1;
	gameOver = false;
	positions();
	if (gameWin)
	{
		gameOver = true;
		main();
	}
	gameLoop();
}

void menu()
{
	system("cls");
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 120; j++)
		{
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			if ((i == 6 || i == 7 || i == 17 || i == 18) && (j >= 40 && j <= 80))
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
				cout << gameBoundry;
			}

			else if ((j == 40 || j == 80) && (i > 6 && i < 19))
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
				cout << gameBoundry;
			}

			else if (i == 10 && j == 46)
			{
				cout << "1.Start";
				j += 6;
			}
			else if (i == 11 && j == 46)
			{
				cout << "2.HighScores";
				j += 11;
			}
			else if (i == 12 && j == 46)
			{
				cout << "3.Instructions";
				j += 13;
			}
			else if (i == 13 && j == 46)
			{
				cout << "4.Exit";
				j += 5;
			}
			else
				cout << " ";
		}
		cout << '\n';
	}

}
void soloManMotion()
{
	// Clear the previous positions of the solo man
	int tempSoloY = soloY;
	int tempSoloX = soloX;

	int i = 1;

	// Avoid enemy collision: Check if the solo man is close to enemy 1 or enemy 2
	bool enemyClose = false;
	if ((abs(soloX - enemy1X) <= 3 && abs(soloY - enemy1Y) <= 2) ||
		(abs(soloX - enemy2X) <= 3 && abs(soloY - enemy2Y) <= 2) ||
		(abs(soloX - enemy3X) <= 3 && abs(soloY - enemy3Y) <= 2) ||
		(abs(soloX - enemy4X) <= 3 && abs(soloY - enemy4Y) <= 2) ||
		(abs(soloX - enemy5X) <= 3 && abs(soloY - enemy5Y) <= 2) ||
		(abs(soloX - enemy6X) <= 3 && abs(soloY - enemy6Y) <= 2)) {
		enemyClose = true;
	}

	// Update direction based on proximity to enemies
	if (level > i)
	{
		i++;

		// If enemies are close, change the solo man's direction
		if (enemyClose) {
			// If solo man is moving left, change to right, and vice versa
			if (direction == 0) {
				direction = 1;  // Change to right
			}
			else {
				direction = 0;  // Change to left
			}
		}

		// Move solo man
		switch (direction) {
		case 0: // Move left
			if (soloX - i > 4)
				soloX = soloX - i;
			else
				direction = 1;  // Change direction to right if left border is reached
			break;
		case 1: // Move right
			if (soloX < width - 5 - i)
				soloX = soloX + i;
			else
				direction = 0;  // Change direction to left if right border is reached
			break;
		}
	}
	else
	{
		// Default behavior without level increment
		switch (direction) {
		case 0: // Move left
			if (soloX > 6)
				soloX = soloX - i;
			else
				direction = 1;  // Change direction to right if left border is reached
			break;
		case 1: // Move right
			if (soloX < width - 6)
				soloX = soloX + i;
			else
				direction = 0;  // Change direction to left if right border is reached
			break;
		}
	}

	if (tempSoloY != soloY || tempSoloX != soloX)
	{
		game[tempSoloY][tempSoloX - 1] = ' ';
		game[tempSoloY][tempSoloX] = ' ';
		game[tempSoloY][tempSoloX + 1] = ' ';
		game[tempSoloY + 1][tempSoloX] = ' ';
		game[tempSoloY + 1][tempSoloX - 1] = ' ';
		game[tempSoloY + 1][tempSoloX + 1] = ' ';
		game[tempSoloY + 1][tempSoloX - 4] = ' ';
		game[tempSoloY + 1][tempSoloX - 3] = ' ';
		game[tempSoloY + 1][tempSoloX - 2] = ' ';
		game[tempSoloY + 1][tempSoloX + 2] = ' ';
		game[tempSoloY + 1][tempSoloX + 3] = ' ';
		game[tempSoloY + 1][tempSoloX + 4] = ' ';
		game[tempSoloY + 2][tempSoloX - 1] = ' ';
		game[tempSoloY + 2][tempSoloX] = ' ';
		game[tempSoloY + 2][tempSoloX + 1] = ' ';

		// Update game with new positions of the solo man
		game[soloY][soloX - 1] = solomanLeft;
		game[soloY][soloX] = solomantenticales;
		game[soloY][soloX + 1] = solomanRight;
		game[soloY + 1][soloX] = solomanheart;
		game[soloY + 1][soloX - 1] = solomanLeft;
		game[soloY + 1][soloX + 1] = solomanRight;
		game[soloY + 1][soloX - 4] = solomanLeft;
		game[soloY + 1][soloX - 3] = solomantenticales;
		game[soloY + 1][soloX - 2] = solomanRight;
		game[soloY + 1][soloX + 2] = solomanLeft;
		game[soloY + 1][soloX + 3] = solomantenticales;
		game[soloY + 1][soloX + 4] = solomanRight;
		game[soloY + 2][soloX - 1] = solomanLeft;
		game[soloY + 2][soloX] = solomantenticales;
		game[soloY + 2][soloX + 1] = solomanRight;
	}
	///*int ch = rand() % 8;
	//switch (ch)
	//{
	//case 0:
	//	game[soloY + 4][soloX] = enemyBulletDown;
	//	break;
	//case 1:
	//	game[soloY - 4][soloX] = enemyBulletUp;
	//	break;
	//case 2:
	//	game[soloY + 1][soloX + 5] = enemyBulletLeft;
	//	break;
	//case 3:
	//	game[soloY + 1][soloX - 5] = enemyBulletRight;
	//	break;
	//}*/
}


void print()
{
	Sleep(59.99);
	std::cout << "\033[?25l";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	cout << "Score: ";

	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << score;

	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	cout << "\t\tLevel: ";

	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << level;

	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	cout << "\t\tLives: ";

	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << lives << '\n';

	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; j++)
		{
			cout << game[i][j];
		}
		cout << '\n';
	}

	cout << "\n\n\n\n\t       Press I to See Instructions\n";
	cout << "\t       Press P to Pause The Game\n\n";

}


void player()
{
	/*game[bodyY][bodyX] = ' ';
	game[bodyY - 1][bodyX] = ' ';
	game[bodyY][bodyX - 1] = ' ';
	game[bodyY][bodyX + 1] = ' ';
	game[bodyY + 1][bodyX - 1] = leftLeg;
	game[bodyY + 1][bodyX + 1] = rightLeg;*/
	for (int y = 0; y < height; y++)
	{
		for (int x = width - 1; x >= 0; x--)
		{
			if (game[y][x] == obstacle || game[y][x] == enemy || game[y][x] == enemyLeft || game[y][x] == enemyRight || game[y][x] == enemyHead || game[y][x] == enemyHead || game[y][x] == solomanLeft || game[y][x] == solomanRight || game[y][x] == exitdoor) {
				if (game[y + 1][x] == bulletsUp) {
					game[y + 1][x] = ' ';
					up = false;
				}
				else if (game[y - 1][x] == bulletsDown) {
					game[y - 1][x] = ' ';
					down = false;
				}
			}
			if (game[y][x] == enemyRight || game[y][x] == enemyLeft || game[y][x] == enemyHead || game[y][x] == enemyHead || game[y][x] == solomanLeft || game[y][x] == solomanRight || game[y][x] == exitdoor) {
				if (game[y][x + 1] == bulletsRight) {
					game[y][x + 1] = ' ';
					lt = false;
				}
				else if (game[y][x - 1] == bulletsLeft) {
					game[y][x - 1] = ' ';
					rt = false;
				}
			}
			//player bullets movement
			if ((game[y][x] == gameBoundry && game[y + 1][x] == bulletsUp))
			{
				game[y + 1][x] = ' ';
				up = false;
			}
			if (game[y][x] == gameBoundry && game[y][x - 1] == bulletsLeft)
			{
				game[y][x - 1] = ' ';
				rt = false;
			}

			if (game[y][x] == bulletsUp)
			{
				game[y][x] = ' ';
				game[y - 1][x] = bulletsUp;
			}
			if (game[y][x - 1] == bulletsLeft)
			{
				game[y][x - 1] = ' ';
				game[y][x] = bulletsLeft;
			}
			//enemy bullets spawn
			if (rand() % 8 == 1)
			{
				if ((game[y][x] == enemy && y == bodyY) || (game[y][x] == enemy && y == bodyY - 1) || (game[y][x] == enemy && y == bodyY + 1) || (game[y][x] == enemyHead && y == bodyY) || (game[y][x] == enemyHead && y == bodyY - 1) || (game[y][x] == enemyHead && y == bodyY + 1))
				{
					if (x > bodyX)
						game[y][x - 2] = enemyBulletRight;
					else
						game[y][x + 2] = enemyBulletLeft;

				}
				if ((game[y][x] == enemy && x == bodyX) || (game[y][x] == enemy && x == bodyX - 1) || (game[y][x] == enemy && x == bodyX + 1) || (game[y][x] == enemyHead && x == bodyX) || (game[y][x] == enemyHead && x == bodyX - 1) || (game[y][x] == enemyHead && x == bodyX + 1))
				{
					if (y > bodyY)
					{
						game[y - 2][x] = enemyBulletUp; // Spawn bullet above the enemy
					}
					else
					{
						game[y + 2][x] = enemyBulletDown; // Spawn bullet below the enemy
					}
				}
			}

			//	enemy bullets movement
			if (game[y][x] == gameBoundry && game[y + 1][x] == enemyBulletUp)
			{
				game[y + 1][x] = ' ';
			}
			if (game[y][x] == exitdoor && game[y + 1][x] == enemyBulletUp)
			{
				game[y + 1][x] = ' ';
			}
			if (game[y][x] == gameBoundry && game[y - 1][x] == enemyBulletDown)
			{
				game[y - 1][x] = ' ';
			}


			if (game[y][x] == enemyBulletUp)
			{
				game[y][x] = ' ';
				game[y - 1][x] = enemyBulletUp;
			}
			if (game[y][x - 1] == enemyBulletLeft)
			{
				game[y][x - 1] = ' ';
				game[y][x] = enemyBulletLeft;
			}
			if (game[y][x] == enemyBulletRight)
			{
				if (game[y][x - 1] == gameBoundry || game[y][x - 1] == enemyRight)
					game[y][x] = ' ';
			}
			//gameover check
			if (game[y][x] == enemyBulletDown || game[y][x] == enemyBulletRight || game[y][x] == enemyBulletLeft || game[y][x] == enemyBulletUp)
			{
				if (game[y][x + 1] == leftHand || game[y][x + 1] == head || game[y][x + 1] == leftLeg || game[y][x - 1] == rightLeg || game[y][x - 1] == head || game[y][x - 1] == rightHand || game[y + 1][x] == head || game[y - 1][x] == body || game[y - 1][x] == leftLeg || game[y - 1][x] == rightLeg)
				{
					if (lives > 0)
					{
						lives--;
						bodyX = width / 2;
						bodyY = height - 5;
						positions();
					}
				}

			}
			if (game[y][x] == bulletsDown || game[y][x] == bulletsRight || game[y][x] == bulletsLeft || game[y][x] == bulletsUp)
			{
				// Check for the enemy at all possible locations:
				if (
					game[y][x + 1] == enemyLeft || game[y][x - 1] == enemyRight ||   // Check for left and right sides
					game[y - 1][x] == enemyHead || game[y - 1][x] == enemy ||        // Check for enemy's head or body above
					game[y + 1][x] == enemy || game[y + 1][x] == enemyHead ||        // Check for enemy's body or head below
					game[y][x + 1] == enemy || game[y][x + 2] == enemy ||            // Check for right part (if bigger enemy)
					game[y][x - 1] == enemy || game[y][x - 2] == enemy ||            // Check for left part (if bigger enemy)
					game[y - 1][x + 1] == enemy || game[y - 1][x - 1] == enemy ||    // Check for diagonals above
					game[y + 1][x + 1] == enemy || game[y + 1][x - 1] == enemy       // Check for diagonals below
					)
				{
					// Clear bullet position
					game[y][x] = ' ';
					game[y][x - 1] = ' ';
					game[y][x + 1] = ' ';
					game[y + 1][x] = ' ';
					game[y + 1][x - 1] = ' ';
					game[y + 1][x + 1] = ' ';
					game[y - 1][x] = ' ';
					game[y - 1][x - 1] = ' ';
					game[y - 1][x + 1] = ' ';
				}
			}


			//exit door check
			if (game[y][x] == exitdoor && game[y + 1][x] == head)
			{
				level++;
				lives = 3;
				score += 5;
				bodyY = height - 5;
				bodyX = width / 2;
				positions();
			}
			//enemy and obstacle collision check and exit door as well
			if (game[y][x] == obstacle || game[y][x] == enemyLeft || game[y][x] == enemyRight || game[y][x] == exitdoor)
			{
				if (game[y][x + 1] == enemyLeft || game[y][x + 1] == enemyRight || game[y][x - 1] == enemyLeft || game[y][x - 1] == enemyRight) {
					if (level == 1)
					{
						//obstacle 1
						game[20][10] = enemyLeft;
						game[20][11] = obstacle;
						game[20][12] = obstacle;
						game[20][14] = enemyRight;
						game[20][13] = obstacle;

						//obstacle 1
						game[20][width - 10] = enemyRight;
						game[20][width - 11] = obstacle;
						game[20][width - 12] = obstacle;
						game[20][width - 14] = enemyLeft;
						game[20][width - 13] = obstacle;
					}
					if (level == 2)
					{
						//obstacle 1
						game[20][10] = enemyLeft;
						game[20][11] = obstacle;
						game[20][12] = obstacle;
						game[20][15] = enemyRight;
						game[20][13] = obstacle;
						game[20][14] = obstacle;

						//obstacle 1
						game[20][width - 10] = enemyRight;
						game[20][width - 11] = obstacle;
						game[20][width - 12] = obstacle;
						game[20][width - 15] = enemyLeft;
						game[20][width - 13] = obstacle;
						game[20][width - 14] = obstacle;

						game[18][width - 6] = enemyRight;
						game[18][width - 7] = obstacle;
						game[18][width - 8] = obstacle;
						game[18][width - 11] = enemyLeft;
						game[18][width - 9] = obstacle;
						game[18][width - 10] = obstacle;
					}
					if (level == 3)
					{
						//obstacle 1
						game[20][10] = enemyLeft;
						game[20][11] = obstacle;
						game[20][12] = obstacle;
						game[20][15] = enemyRight;
						game[20][13] = obstacle;
						game[20][14] = obstacle;

						//obstacle 1
						game[20][width - 10] = enemyRight;
						game[20][width - 11] = obstacle;
						game[20][width - 12] = obstacle;
						game[20][width - 15] = enemyLeft;
						game[20][width - 13] = obstacle;
						game[20][width - 14] = obstacle;

						game[18][width - 6] = enemyRight;
						game[18][width - 7] = obstacle;
						game[18][width - 8] = obstacle;
						game[18][width - 11] = enemyLeft;
						game[18][width - 9] = obstacle;
						game[18][width - 10] = obstacle;

						game[18][6] = enemyRight;
						game[18][7] = obstacle;
						game[18][8] = obstacle;
						game[18][11] = enemyLeft;
						game[18][9] = obstacle;
						game[18][10] = obstacle;
					}
					if (level == 4)
					{
						//obstacle 1
						game[20][10] = enemyLeft;
						game[20][11] = obstacle;
						game[20][12] = obstacle;
						game[20][15] = enemyRight;
						game[20][13] = obstacle;
						game[20][14] = obstacle;

						//obstacle 1
						game[20][width - 10] = enemyRight;
						game[20][width - 11] = obstacle;
						game[20][width - 12] = obstacle;
						game[20][width - 15] = enemyLeft;
						game[20][width - 13] = obstacle;
						game[20][width - 14] = obstacle;

						game[18][width - 6] = enemyRight;
						game[18][width - 7] = obstacle;
						game[18][width - 8] = obstacle;
						game[18][width - 11] = enemyLeft;
						game[18][width - 9] = obstacle;
						game[18][width - 10] = obstacle;

						game[18][6] = enemyRight;
						game[18][7] = obstacle;
						game[18][8] = obstacle;
						game[18][11] = enemyLeft;
						game[18][9] = obstacle;
						game[18][10] = obstacle;

						game[15][6] = enemyRight;
						game[15][7] = obstacle;
						game[15][8] = obstacle;
						game[15][11] = enemyLeft;
						game[15][9] = obstacle;
						game[15][10] = obstacle;
					}
					if (level == 5)
					{
						//obstacle 1
						game[20][10] = enemyLeft;
						game[20][11] = obstacle;
						game[20][12] = obstacle;
						game[20][15] = enemyRight;
						game[20][13] = obstacle;
						game[20][14] = obstacle;

						//obstacle 1
						game[20][width - 10] = enemyRight;
						game[20][width - 11] = obstacle;
						game[20][width - 12] = obstacle;
						game[20][width - 15] = enemyLeft;
						game[20][width - 13] = obstacle;
						game[20][width - 14] = obstacle;

						game[18][width - 6] = enemyRight;
						game[18][width - 7] = obstacle;
						game[18][width - 8] = obstacle;
						game[18][width - 11] = enemyLeft;
						game[18][width - 9] = obstacle;
						game[18][width - 10] = obstacle;

						game[18][6] = enemyRight;
						game[18][7] = obstacle;
						game[18][8] = obstacle;
						game[18][11] = enemyLeft;
						game[18][9] = obstacle;
						game[18][10] = obstacle;

						game[15][6] = enemyRight;
						game[15][7] = obstacle;
						game[15][8] = obstacle;
						game[15][11] = enemyLeft;
						game[15][9] = obstacle;
						game[15][10] = obstacle;
					}
				}

			}
		}
	}

	for (int y = 0; y < height; y++)
	{
		for (int x = width - 1; x >= 0; x--)

		{
			if (game[y][x] == obstacle || game[y][x] == enemy || game[y][x] == enemyLeft || game[y][x] == enemyRight || game[y][x] == enemyHead) {
				if (game[y + 1][x] == bulletsUp) {
					game[y + 1][x] = ' ';
					up = false;
				}
				else if (game[y - 1][x] == bulletsDown) {
					game[y - 1][x] = ' ';
					down = false;
				}
			}
			if (game[y][x] == enemyRight || game[y][x] == enemyLeft) {
				if (game[y][x + 1] == bulletsRight) {
					game[y][x + 1] = ' ';
					lt = false;
				}
				else if (game[y][x - 1] == bulletsLeft) {
					game[y][x - 1] = ' ';
					rt = false;
				}
				//if()
			}




			if (game[y][x] == gameBoundry && game[y + 1][x] == bulletsUp)
			{
				game[y + 1][x] = ' ';
				up = false;
			}
			if (game[y][x] == gameBoundry && game[y][x - 1] == bulletsLeft)
			{
				game[y][x - 1] = ' ';
				rt = false;
			}

			if (game[y][x] == bulletsUp)
			{
				game[y][x] = ' ';
				game[y - 1][x] = bulletsUp;
				up = false;
			}
			if (game[y][x - 1] == bulletsLeft)
			{
				game[y][x - 1] = ' ';
				game[y][x] = bulletsLeft;
				lt = false;
			}

		}
	}

	for (int y = height - 1; y >= 0; y--)
	{
		for (int x = 0; x < width; x++)
		{
			if (game[y - 2][x] == bulletsDown && game[y][x] == gameBoundry)
			{
				game[y - 2][x] = ' ';
				down = false;
			}

			if (game[y][x + 1] == bulletsRight && game[y][x] == gameBoundry)
			{
				game[y][x + 1] = ' ';
				lt = false;
			}

			if (game[y][x] == bulletsDown)
			{
				game[y][x] = ' ';
				game[y + 1][x] = bulletsDown;
			}
			if (game[y][x + 1] == bulletsRight)
			{
				game[y][x + 1] = ' ';
				game[y][x] = bulletsRight;
			}

		}
	}
	killEnemy();
	// Update the player's position
	game[bodyY][bodyX] = body;
	game[bodyY - 1][bodyX] = head;
	game[bodyY][bodyX - 1] = leftHand;
	game[bodyY][bodyX + 1] = rightHand;
	game[bodyY + 1][bodyX - 1] = leftLeg;
	game[bodyY + 1][bodyX + 1] = rightLeg;

	// Check for game over conditions
	if (lives <= 0) {
		gameOver = true;

	}
}
void controller()
{
	bool ok = true;
	game[bodyY][bodyX] = ' ';
	game[bodyY - 1][bodyX] = ' ';
	game[bodyY][bodyX - 1] = ' ';
	game[bodyY][bodyX + 1] = ' ';
	game[bodyY + 1][bodyX - 1] = ' ';
	game[bodyY + 1][bodyX + 1] = ' ';
	char move;
	move = _getch();
	switch (move)
	{
	case 'w':
	case 'W':
		if (bodyY - 1 > 1)
		{
			if (game[bodyY - 2][bodyX] != enemyLeft && game[bodyY - 2][bodyX] != obstacle && game[bodyY - 2][bodyX] != enemyRight && game[bodyY - 1][bodyX + 1] != obstacle && game[bodyY - 1][bodyX + 1] != enemyLeft && game[bodyY - 1][bodyX - 1] != enemyRight && game[bodyY - 1][bodyX - 1] != obstacle && game[bodyY - 1][bodyX - 1] != enemyLeft && game[bodyY - 2][bodyX] != enemy)
				bodyY--;
		}
		break;
	case 'a':
	case 'A':
		if (bodyX > 2)
		{
			if (game[bodyY][bodyX - 2] != enemyRight && game[bodyY + 1][bodyX - 2] != enemyRight && game[bodyY - 1][bodyX - 1] != enemyRight)
				bodyX--;
		}
		break;
	case 's':
	case 'S':
		if (bodyY + 1 < height - 2)
		{
			if (game[bodyY + 2][bodyX + 1] != enemyLeft && game[bodyY + 2][bodyX + 1] != obstacle && game[bodyY + 2][bodyX + 1] != enemyRight && game[bodyY + 2][bodyX - 1] != enemyLeft && game[bodyY + 2][bodyX - 1] != obstacle && game[bodyY + 2][bodyX - 1] != enemyRight)
				bodyY++;
		}
		break;
	case 'd':
	case 'D':
		if (bodyX + 1 < width - 2)
		{
			if (game[bodyY][bodyX + 2] != enemyLeft && game[bodyY + 1][bodyX + 2] != enemyLeft && game[bodyY - 1][bodyX + 1] != enemyLeft)
				bodyX++;
		}
		break;

	case 'u':
		if (!up && !down && !lt && !rt)
		{
			game[bodyY - 2][bodyX] = bulletsUp;
			up = true;
		}
		ok = false;
		break;
	case 'j':
		if (!up && !down && !lt && !rt)
		{
			down = true;
			game[bodyY + 2][bodyX] = bulletsDown;
		}
		ok = false;
		break;
	case 'k':
		if (!up && !down && !lt && !rt)
		{
			rt = true;
			game[bodyY - 1][bodyX + 3] = bulletsLeft;
		}
		ok = false;
		break;
	case 'h':
		if (!up && !down && !lt && !rt)
		{
			lt = true;
			game[bodyY - 1][bodyX - 3] = bulletsRight;
		}
		ok = false;
		break;
	case 'i':
	case 'I':
		instructions();
		break;
	case 'p':
	case 'P':
		pause();
		break;
	default:
		ok = false;
		break;
	}
	game[bodyY][bodyX] = body;
	game[bodyY - 1][bodyX] = head;
	game[bodyY][bodyX - 1] = leftHand;
	game[bodyY][bodyX + 1] = rightHand;
	game[bodyY + 1][bodyX - 1] = rightLeg;
	game[bodyY + 1][bodyX + 1] = leftLeg;

	if (ok)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << "Score: ";

		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		cout << score;

		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << "\t\tLevel: ";

		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		cout << level;

		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << "\t\tLives: ";

		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		cout << lives << '\n';

		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);

		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; j++)
			{
				cout << game[i][j];
			}
			cout << '\n';
		}

		cout << "\n\n\n\n\t       Press I to See Instructions\n";
		cout << "\t       Press P to Pause The Game\n\n";
	}


	game[bodyY + 1][bodyX - 1] = leftLeg;
	game[bodyY + 1][bodyX + 1] = rightLeg;
}


void boundarycheck()
{
	if (bodyY <= 1 || bodyY + 2 >= height - 1 || bodyX <= 2 || bodyX + 1 >= width - 1) {
		lives--;
		bodyX = width / 2;
		bodyY = height - 5;
		positions();

	}
}
void soloethanenemy() {
	// Check if any part of Ethan's body is within the bounds of Soloman
	bool collisionDetected = false;

	// Check for collision with the head
	if ((bodyY - 1 >= soloY - 4 && bodyY - 1 <= soloY + 4) && (bodyX >= soloX - 4 && bodyX <= soloX + 4)) {
		collisionDetected = true;
	}

	// Check for collision with the body
	if ((bodyY >= soloY - 4 && bodyY <= soloY + 4) && (bodyX >= soloX - 4 && bodyX <= soloX + 4)) {
		collisionDetected = true;
	}

	// Check for collision with the left hand
	if ((bodyY >= soloY - 4 && bodyY <= soloY + 4) && (bodyX - 1 >= soloX - 4 && bodyX - 1 <= soloX + 4)) {
		collisionDetected = true;
	}

	// Check for collision with the right hand
	if ((bodyY >= soloY - 1 && bodyY <= soloY + 1) && (bodyX + 1 >= soloX - 4 && bodyX + 1 <= soloX + 4)) {
		collisionDetected = true;
	}

	// Check for collision with the left leg
	if ((bodyY + 1 >= soloY - 4 && bodyY + 1 <= soloY + 4) && (bodyX - 1 >= soloX - 4 && bodyX - 1 <= soloX + 4)) {
		collisionDetected = true;
	}

	// Check for collision with the right leg
	if ((bodyY + 1 >= soloY - 4 && bodyY + 1 <= soloY + 4) && (bodyX + 1 >= soloX - 4 && bodyX + 1 <= soloX + 4)) {
		collisionDetected = true;
	}

	// If a collision is detected, handle it
	if (collisionDetected) {
		if (lives > 0) {
			lives--; // Decrease lives if collision occurs
			bodyX = width / 2; // Reset player position
			bodyY = height - 5; // Reset player position
			positions(); // Update the game state
		}
	}
}
void newlvl()
{
	if ((exitY - 1 == head && exitx == head) || (exitY - 2 == head && exitx == head))
	{
		if (level <= 5)
		{
			level += 1;
			score += 50;
			lives = 3;
			bodyX = width / 2;
			bodyY = height - 5;
			soloY = width / 2;     //soloman
			soloX = 8;             //soloman
			exitY = width / 2;
			exitx = 1;
			positions();

		}

	}
}

void killEnemy()
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++) {
			bool enemyKilled = false;
			// Check for bullets in the game
			// If a bullet is present, check for enemies
			if (game[y][x] == bulletsUp || game[y][x] == bulletsDown || game[y][x] == bulletsLeft || game[y][x] == bulletsRight) {
				// Check for enemies in the adjacent positions
				if (y > 0 && y < height - 1 && x > 0 && x < width - 1) {
					if (game[y][x] == bulletsUp && (game[y - 1][x] == enemy || game[y - 1][x] == enemyRight || game[y - 1][x] == enemyLeft)) {
						if ((x == enemy1X || x - 1 == enemy1X || x + 1 == enemy1X) && (y - 2 == enemy1Y)) {
							enemy1alive = false;
							score += 2;
							game[enemy1Y][enemy1X] = ' ';
							game[enemy1Y][enemy1X - 1] = ' ';
							game[enemy1Y][enemy1X + 1] = ' ';
							game[enemy1Y + 1][enemy1X] = ' ';
							game[enemy1Y + 1][enemy1X - 1] = ' ';
							game[enemy1Y + 1][enemy1X + 1] = ' ';

						}
					}
					if (game[y][x] == bulletsDown && (game[y + 1][x] == enemyHead || game[y + 1][x] == enemyLeft || game[y + 1][x] == enemyRight)) {
						if ((x == enemy1X || x - 1 == enemy1X || x + 1 == enemy1X) && (y + 1 == enemy1Y)) {
							enemy1alive = false;
							score += 2;
							game[enemy1Y][enemy1X] = ' ';
							game[enemy1Y][enemy1X - 1] = ' ';
							game[enemy1Y][enemy1X + 1] = ' ';
							game[enemy1Y + 1][enemy1X] = ' ';
							game[enemy1Y + 1][enemy1X - 1] = ' ';
							game[enemy1Y + 1][enemy1X + 1] = ' ';

						}
					}
					if (game[y][x] == bulletsLeft && game[y][x - 1] == enemyRight) {
						if ((x - 2 == enemy1X) && (y == enemy1Y || y - 1 == enemy1Y || y + 1 == enemy1Y)) {
							enemy1alive = false;
							score += 2;
							game[enemy1Y][enemy1X] = ' ';
							game[enemy1Y][enemy1X - 1] = ' ';
							game[enemy1Y][enemy1X + 1] = ' ';
							game[enemy1Y + 1][enemy1X] = ' ';
							game[enemy1Y + 1][enemy1X - 1] = ' ';
							game[enemy1Y + 1][enemy1X + 1] = ' ';

						}
						if ((x - 2 == enemy2X) && (y == enemy2Y || y - 1 == enemy2Y || y + 1 == enemy2Y)) {
							enemy1alive = false;
							score += 2;
							game[enemy2Y][enemy2X] = ' ';
							game[enemy2Y][enemy2X - 1] = ' ';
							game[enemy2Y][enemy2X + 1] = ' ';
							game[enemy2Y + 1][enemy2X] = ' ';
							game[enemy2Y + 1][enemy2X - 1] = ' ';
							game[enemy2Y + 1][enemy2X + 1] = ' ';

						}if ((x - 2 == enemy3X) && (y == enemy3Y || y - 1 == enemy3Y || y + 1 == enemy3Y)) {
							enemy1alive = false;
							score += 2;
							game[enemy3Y][enemy3X] = ' ';
							game[enemy3Y][enemy3X - 1] = ' ';
							game[enemy3Y][enemy3X + 1] = ' ';
							game[enemy3Y + 1][enemy3X] = ' ';
							game[enemy3Y + 1][enemy3X - 1] = ' ';
							game[enemy3Y + 1][enemy3X + 1] = ' ';

						}if ((x - 2 == enemy4X) && (y == enemy4Y || y - 1 == enemy4Y || y + 1 == enemy4Y)) {
							enemy1alive = false;
							score += 2;
							game[enemy4Y][enemy4X] = ' ';
							game[enemy4Y][enemy4X - 1] = ' ';
							game[enemy4Y][enemy4X + 1] = ' ';
							game[enemy4Y + 1][enemy4X] = ' ';
							game[enemy4Y + 1][enemy4X - 1] = ' ';
							game[enemy4Y + 1][enemy4X + 1] = ' ';

						}if ((x - 2 == enemy5X) && (y == enemy5Y || y - 1 == enemy5Y || y + 1 == enemy5Y)) {
							enemy1alive = false;
							score += 2;
							game[enemy5Y][enemy5X] = ' ';
							game[enemy5Y][enemy5X - 1] = ' ';
							game[enemy5Y][enemy5X + 1] = ' ';
							game[enemy5Y + 1][enemy5X] = ' ';
							game[enemy5Y + 1][enemy5X - 1] = ' ';
							game[enemy5Y + 1][enemy5X + 1] = ' ';

						}
						if ((x - 2 == enemy6X) && (y == enemy6Y || y - 1 == enemy6Y || y + 1 == enemy6Y)) {
							enemy1alive = false;
							score += 2;
							game[enemy6Y][enemy6X] = ' ';
							game[enemy6Y][enemy6X - 1] = ' ';
							game[enemy6Y][enemy6X + 1] = ' ';
							game[enemy6Y + 1][enemy6X] = ' ';
							game[enemy6Y + 1][enemy6X - 1] = ' ';
							game[enemy6Y + 1][enemy6X + 1] = ' ';

						}
					}
					if (game[y][x] == bulletsRight && game[y][x + 1] == enemyLeft) {
						if ((x + 2 == enemy1X) && (y == enemy1Y || y - 1 == enemy1Y || y + 1 == enemy1Y)) {
							enemy1alive = false;
							score += 2;
							game[enemy1Y][enemy1X] = ' ';
							game[enemy1Y][enemy1X - 1] = ' ';
							game[enemy1Y][enemy1X + 1] = ' ';
							game[enemy1Y + 1][enemy1X] = ' ';
							game[enemy1Y + 1][enemy1X - 1] = ' ';
							game[enemy1Y + 1][enemy1X + 1] = ' ';

						}
						if ((x + 2 == enemy2X) && (y == enemy2Y || y - 1 == enemy2Y || y + 1 == enemy2Y)) {
							enemy2alive = false;
							score += 2;
							game[enemy2Y][enemy2X] = ' ';
							game[enemy2Y][enemy2X - 1] = ' ';
							game[enemy2Y][enemy2X + 1] = ' ';
							game[enemy2Y + 1][enemy2X] = ' ';
							game[enemy2Y + 1][enemy2X - 1] = ' ';
							game[enemy2Y + 1][enemy2X + 1] = ' ';

						}
						if ((x + 2 == enemy3X) && (y == enemy3Y || y - 1 == enemy3Y || y + 1 == enemy3Y)) {
							enemy3alive = false;
							score += 2;
							game[enemy3Y][enemy3X] = ' ';
							game[enemy3Y][enemy3X - 1] = ' ';
							game[enemy3Y][enemy3X + 1] = ' ';
							game[enemy3Y + 1][enemy3X] = ' ';
							game[enemy3Y + 1][enemy3X - 1] = ' ';
							game[enemy3Y + 1][enemy3X + 1] = ' ';

						}
						if ((x + 2 == enemy4X) && (y == enemy4Y || y - 1 == enemy4Y || y + 1 == enemy4Y)) {
							enemy4alive = false;
							score += 2;
							game[enemy4Y][enemy4X] = ' ';
							game[enemy4Y][enemy4X - 1] = ' ';
							game[enemy4Y][enemy4X + 1] = ' ';
							game[enemy4Y + 1][enemy4X] = ' ';
							game[enemy4Y + 1][enemy4X - 1] = ' ';
							game[enemy4Y + 1][enemy4X + 1] = ' ';

						}
						if ((x + 2 == enemy5X) && (y == enemy5Y || y - 1 == enemy5Y || y + 1 == enemy5Y)) {
							enemy5alive = false;
							score += 2;
							game[enemy5Y][enemy5X] = ' ';
							game[enemy5Y][enemy5X - 1] = ' ';
							game[enemy5Y][enemy5X + 1] = ' ';
							game[enemy5Y + 1][enemy5X] = ' ';
							game[enemy5Y + 1][enemy5X - 1] = ' ';
							game[enemy5Y + 1][enemy5X + 1] = ' ';

						}
						if ((x + 2 == enemy6X) && (y == enemy6Y || y - 1 == enemy6Y || y + 1 == enemy6Y)) {
							enemy6alive = false;
							score += 2;
							game[enemy6Y][enemy6X] = ' ';
							game[enemy6Y][enemy6X - 1] = ' ';
							game[enemy6Y][enemy6X + 1] = ' ';
							game[enemy6Y + 1][enemy6X] = ' ';
							game[enemy6Y + 1][enemy6X - 1] = ' ';
							game[enemy1Y + 1][enemy1X + 1] = ' ';

						}
					}

				}
			}
		}
	}
}
int main()
{
	srand(time(0));
	if (!gameOver || !gameWin)
	{

		positions();
		gameLoop();
	}
	exit(0);
}