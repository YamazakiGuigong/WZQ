#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<math.h>

#define Depth 5
#define Width 8

int map[15][15];
int map2[15][15];
int score[15][15];
int score2[15][15];

int evaluate();

void gotoxy(int x, int y)
{
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO curInfo;
	curInfo.dwSize = 1;
	curInfo.bVisible = FALSE;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &curInfo);

	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void print(bool Reveal)
{
	int i, j;
	if (Reveal == true)
		for (i = 0; i <= 14; i++)
			for (j = 0; j <= 14; j++)
			{
				gotoxy(j * 2, i);
				if (map[i][j] == 0 && i != 0 && i != 14 && j != 0 && j != 14)
					printf("©à©¤");
				else
					if (map[i][j] == 0 && i == 0 && j == 0)
						printf("©°©¤");
					else
						if (map[i][j] == 0 && i == 0 && j == 14)
							printf("©´ ");
						else
							if (map[i][j] == 0 && i == 14 && j == 0)
								printf("©¸©¤");
							else
								if (map[i][j] == 0 && i == 14 && j == 14)
									printf("©¼ ");
								else
									if (map[i][j] == 0 && i >= 1 && i <= 13 && j == 0)
										printf("©À©¤");
									else
										if (map[i][j] == 0 && i >= 1 && i <= 13 && j == 14)
											printf("©È ");
										else
											if (map[i][j] == 0 && j >= 1 && j <= 13 && i == 0)
												printf("©Ð©¤");
											else
												if (map[i][j] == 0 && j >= 1 && j <= 13 && i == 14)
													printf("©Ø©¤");
				if (map[i][j] == 1)
					printf("¡ñ");
				if (map[i][j] == -1)
				{
					gotoxy(j * 2 - 1, i);
					printf("  ");
					gotoxy(j * 2, i);
					printf("¡ð");
				}

			}
	else
		for (i = 0; i <= 14; i++)
			for (j = 0; j <= 14; j++)
			{
				gotoxy(j * 2, i);
				if (map2[i][j] == 0 && i != 0 && i != 14 && j != 0 && j != 14)
					printf("©à©¤");
				else
					if (map2[i][j] == 0 && i == 0 && j == 0)
						printf("©°©¤");
					else
						if (map2[i][j] == 0 && i == 0 && j == 14)
							printf("©´ ");
						else
							if (map2[i][j] == 0 && i == 14 && j == 0)
								printf("©¸©¤");
							else
								if (map2[i][j] == 0 && i == 14 && j == 14)
									printf("©¼ ");
								else
									if (map2[i][j] == 0 && i >= 1 && i <= 13 && j == 0)
										printf("©À©¤");
									else
										if (map2[i][j] == 0 && i >= 1 && i <= 13 && j == 14)
											printf("©È ");
										else
											if (map2[i][j] == 0 && j >= 1 && j <= 13 && i == 0)
												printf("©Ð©¤");
											else
												if (map2[i][j] == 0 && j >= 1 && j <= 13 && i == 14)
													printf("©Ø©¤");
				if (map2[i][j] == 1)
					printf("¡ñ");
				if (map2[i][j] == -1)
				{
					gotoxy(j * 2 - 1, i);
					printf("  ");
					gotoxy(j * 2, i);
					printf("¡ð");
				}

			}
}

int AIRobot()
{
	int i = 0, j = 0, sum = 0;
	evaluate();
	for (i = 0; i <= 14; i++)
		for (j = 0; j <= 14; j++)
			if (score != 0)
				sum++;
	if (sum > Width)
	{
		for (i = 0; i <= 14; i++)
			for (j = 0; j <= 14; j++)
				score2[i][j] = abs(score[i][j]);

	}

	for (i = 0; i <= Width; i++)
		return 0;
}

int evaluate()
{
	int dir[4][2] =
	{
		{0, 1},
		{1, 0},
		{1, 1},
		{1, -1}
	};

	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 15; j++)
			score[i][j] = 0;

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (map[i][j] != 0)
				continue;

			int black_score = 0;

			for (int d = 0; d < 4; d++)
			{
				int dx = dir[d][0];
				int dy = dir[d][1];
				int count = 1;
				int open_ends = 0;
				int x = i + dx;
				int y = j + dy;

				while (x >= 0 && x < 15 && y >= 0 && y < 15)
				{
					if (map[x][y] == -1)
					{
						count++;
						x += dx;
						y += dy;
					}
					else
					{
						if (map[x][y] == 0)
							open_ends++;
						break;
					}
				}

				x = i - dx;
				y = j - dy;
				while (x >= 0 && x < 15 && y >= 0 && y < 15)
				{
					if (map[x][y] == -1)
					{
						count++;
						x -= dx;
						y -= dy;
					}
					else if (map[x][y] == 0) open_ends++;
					break;

				}

				if (count >= 5)
					black_score += 10000;
				else if (count == 4)
				{
					if (open_ends == 2)
						black_score += 1000;

					else if (open_ends == 1)
						black_score += 500;
				}
				else if (count == 3)
				{
					if (open_ends == 2)
						black_score += 200;

					else if (open_ends == 1)
						black_score += 50;
				}
				else if (count == 2)
				{
					if (open_ends == 2)
						black_score += 20;

					else if (open_ends == 1)
						black_score += 5;
				}
				else if (count == 1)
					if (open_ends == 2)
						black_score += 1;

			}

			int white_score = 0;


			for (int d = 0; d < 4; d++)
			{
				int dx = dir[d][0];
				int dy = dir[d][1];
				int count = 1;
				int open_ends = 0;
				int x = i + dx;
				int y = j + dy;

				while (x >= 0 && x < 15 && y >= 0 && y < 15)
				{
					if (map[x][y] == 1)
					{
						count++;
						x += dx;
						y += dy;
					}
					else if (map[x][y] == 0) open_ends++;
					break;

				}

				x = i - dx;
				y = j - dy;
				while (x >= 0 && x < 15 && y >= 0 && y < 15)
				{
					if (map[x][y] == 1)
					{
						count++;
						x -= dx;
						y -= dy;
					}
					else if (map[x][y] == 0) open_ends++;
					break;

				}

				if (count >= 5)
					white_score += 10000;
				else if (count == 4)
				{
					if (open_ends == 2)
						white_score += 1000;

					else if (open_ends == 1)
						white_score += 500;
				}
				else if (count == 3)
				{
					if (open_ends == 2)
						white_score += 200;

					else if (open_ends == 1)
						white_score += 50;
				}
				else if (count == 2)
				{
					if (open_ends == 2)
						white_score += 20;

					else if (open_ends == 1)
						white_score += 5;
				}
				else if (count == 1)
					if (open_ends == 2)
						white_score += 1;

			}

			score[i][j] = black_score - white_score;
		}
	}


	int total_score = 0;
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 15; j++)
			total_score += score[i][j];

	printf("\n");
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
			printf("%3d ", score[i][j]);
		printf("\n\n\n");
	}
	printf("\n%d", total_score);
	return total_score;
}

int judge(int x, int y)
{
	int i, i1, j, j1, sum;

	sum = 0;
	for (i = y - 5; i <= y; i++)
	{
		for (j = i; j < i + 5; j++)
		{
			if (j >= 0 && j <= 14)
				sum += map[x][j];
			else
			{
				sum = 0;
				continue;
			}
			if (sum == 5)
				return 1;
			else if (sum == -5)
				return -1;

		}
		sum = 0;
	}

	sum = 0;
	for (i = x - 5; i <= x; i++)
	{
		for (j = i; j < i + 5; j++)
		{
			if (j >= 0 && j < 15)
				sum += map[j][y];
			else
			{
				sum = 0;
				continue;
			}
			if (sum == 5)
				return 1;
			else if (sum == -5)
				return -1;
		}
		sum = 0;

	}

	sum = 0;
	for (i = x - 5, i1 = y - 5; i <= x; i++, i1++)
	{
		for (j = i, j1 = i1; j < i + 5; j++, j1++)
		{
			if (j >= 0 && j <= 14 && j1 >= 0 && j1 <= 14)
				sum += map[j][j1];
			else
			{
				sum = 0;
				continue;
			}
			if (sum == 5)
				return 1;
			else if (sum == -5)
				return -1;
		}
		sum = 0;
	}

	sum = 0;
	for (i = x - 5, i1 = y + 5; i <= x; i++, i1--)
	{
		for (j = i, j1 = i1; j < i + 5; j++, j1--)
		{
			if (j >= 0 && j < 15 && j1 >= 0 && j1 <= 15)
				sum += map[j][j1];
			else
			{
				sum = 0;
				continue;
			}
			if (sum == 5)
				return 1;
			else if (sum == -5)
				return -1;
		}
		sum = 0;
	}
	return 0;
}

int main()
{
	const clock_t FPS = 1000 / 120;
	char ch;
	int ch2 = 0;
	int x = 7, y = 7, i, j, time = 0, flag = 0, t = 0;

	for (i = 0; i < 15; i++)
		for (j = 0; j < 15; j++)
		{
			map[i][j] = 0;
			map2[i][j] = 0;
			score[i][j] = 0;
			score2[i][j] = 0;
		}
	print(true);
	map2[x][y] = 1;
	Sleep(10);
	print(false);
	Sleep(10);

	while (true)
	{
		clock_t starttime = clock();
		time++;
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 0 || ch == 224)
				ch = _getch();

			if (ch == 'w' || ch == 's' || ch == 'a' || ch == 'd' || ch == 13 || ch == 72 || ch == 80 || ch == 75 || ch == 77)
			{
				for (i = 0; i < 15; i++)
					for (j = 0; j < 15; j++)
						map2[i][j] = map[i][j];
				switch (ch)
				{
				case 'w': if (x - 1 >= 0) x--; break;
				case 'a': if (y - 1 >= 0) y--; break;
				case 's': if (x + 1 <= 14) x++; break;
				case 'd': if (y + 1 <= 14) y++; break;
				case  72: if (x - 1 >= 0) x--; break;
				case  75: if (y - 1 >= 0) y--; break;
				case  80: if (x + 1 <= 14) x++; break;
				case  77: if (y + 1 <= 14) y++; break;
				case  13: if (map[x][y] == 0) { map[x][y] = 1; flag = 1; break; }
				}
				map2[x][y] = 1;
			}
			print(false);
			Sleep(1);
			if (flag == 1)
			{
				if (judge(x, y) == 1)
				{
					printf("\nWin£¡");
					return 0;
				}
				else
					AIRobot();
				flag = 0;
			}
		}

		if (time == 400)
			print(false);

		if (_kbhit())
		{
			ch = _getch();
			if (ch == 'w' || ch == 's' || ch == 'a' || ch == 'd' || ch == 13 || ch == 72 || ch == 80 || ch == 75 || ch == 77)
			{
				for (i = 0; i < 15; i++)
					for (j = 0; j < 15; j++)
						map2[i][j] = map[i][j];
				switch (ch)
				{
				case 'w': if (x - 1 >= 0) x--; break;
				case 'a': if (y - 1 >= 0) y--; break;
				case 's': if (x + 1 <= 14) x++; break;
				case 'd': if (y + 1 <= 14) y++; break;
				case  72: if (x - 1 >= 0) x--; break;
				case  75: if (y - 1 >= 0) y--; break;
				case  80: if (x + 1 <= 14) x++; break;
				case  77: if (y + 1 <= 14) y++; break;
				case 13: if (map[x][y] == 0) { map[x][y] = 1; flag = 1; break; }
				}
				map2[x][y] = 1;
			}
			print(false);
			Sleep(1);
			if (flag == 1)
			{
				if (judge(x, y) == 1)
				{
					printf("\nWin£¡");
					return 0;
				}
				else
					AIRobot();
				flag = 0;
			}
		}

		if (time == 1000)
			print(true);

		if (time == 1001)
			time = 0;

		clock_t endtime = clock() - starttime;
		if (FPS - endtime > 0 && endtime > 0)
			Sleep(FPS - endtime);
	}
}

