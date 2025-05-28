
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

#define Depth 5
#define Width 8

int map[15][15];
int map2[15][15];
int score[15][15];

int judge(int x, int y);
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
	int x = 0, y = 0, Eva;
	int i, j;
	Eva = evaluate();
	if (Eva == 5)
	{
		for (i = 0; i < 15; i++)
			for (j = 0; j < 15; j++)
				map2[i][j] = map[i][j];
		return -1;
	}
	else
		if (Eva == -5)
		{
			for (i = 0; i < 15; i++)
				for (j = 0; j < 15; j++)
					map2[i][j] = map[i][j];
			return 0;
		}
		else
		{
			;
		}
	/*
	if (judge(x, y) == -1)
		return -1;
	else
		return 0;
		*/
}
int evaluate()
{

	int i, j, k, sum = 0;


	for (i = 0; i <= 14; i++)
		for (j = 0; j <= 14; j++)
		{


			sum = 0;
			for (k = 0; k <= 3; k++)
				if (j + k <= 14)
					sum += map[i][j + k];
				else
				{
					sum = 0;
					break;
				}
			if (sum == -4)
				if (j - 1 >= 0 && j + 4 <= 14)
				{
					if (map[i][j - 1] == 0 || map[i][j + 4] == 0)
					{
						if (map[i][j - 1] == 0)
							map[i][j - 1] = -1;

						else
							map[i][j + 4] = -1;
						return 5;
					}
				}
				else
					if (j - 1 >= 0)
					{
						if (map[i][j - 1] == 0)
						{
							map[i][j - 1] = -1;
							return 5;
						}
					}
					else
						if (j + 4 >= 0)
							if (map[i][j + 4] == 0)
							{
								map[i][j + 4] = -1;
								return 5;
							}

			sum = 0;
			for (k = 0; k <= 3; k++)
				if (i + k <= 14)
					sum += map[i + k][j];
				else
				{
					sum = 0;
					break;
				}

			if (sum == -4)
				if (i - 1 >= 0 && i + 4 <= 14)
				{
					if (map[i - 1][j] == 0 || map[i + 4][j] == 0)
					{
						if (map[i - 1][j] == 0)
							map[i - 1][j] = -1;
						else
							map[i + 4][j] = -1;
						return 5;

					}
				}
				else
					if (i - 1 >= 0)
					{
						if (map[i - 1][j] == 0)
						{
							map[i - 1][j] = -1;
							return 5;
						}
					}
					else
						if (i + 4 <= 14)
							if (map[i + 4][j] == 0)
							{
								map[i + 4][j] = -1;
								return 5;
							}

			sum = 0;
			for (k = 0; k <= 3; k++)
				if (i + k <= 14 && j + k <= 14)
					sum += map[i + k][j + k];
				else
				{
					sum = 0;
					break;
				}

			if (sum == -4)
				if (i - 1 >= 0 && j - 1 >= 0 && i + 4 <= 14 && j + 4 <= 14)
				{
					if (map[i - 1][j - 1] == 0 || map[i + 4][j + 4] == 0)
					{
						if (map[i - 1][j - 1] == 0)
							map[i - 1][j - 1] = -1;
						else
							map[i + 4][j + 4] = -1;
						return 5;
					}
				}
				else
					if (i - 1 >= 0 && j - 1 >= 0)
					{
						if (map[i - 1][j - 1] == 0)
						{
							map[i - 1][j - 1] = -1;
							return 5;
						}
					}
					else
						if (i + 4 <= 14 && j + 4 <= 14)
							if (map[i + 4][j + 4] == 0)
							{
								map[i + 4][j + 4] = -1;
								return 5;
							}


			sum = 0;
			for (k = 0; k <= 3; k++)
				if (j + 3 - k <= 14 && i + k <= 14)
					sum += map[i + k][j + 3 - k];
				else
				{
					sum = 0;
					break;
				}
			if (sum == -4)
				if (i - 1 >= 0 && j + 3 + 1 <= 14 && i + 3 + 1 <= 14 && j - 1 >= 0)
				{
					if (map[i - 1][j + 3 + 1] == 0 || map[i + 3 + 1][j - 1] == 0)
					{
						if (map[i - 1][j + 3 + 1] == 0)
							map[i - 1][j + 3 + 1] = -1;
						else
							map[i + 3 + 1][j - 1] = -1;
						return 5;
					}
				}
				else
					if (i - 1 >= 0 && j + 3 + 1 >= 0)
					{
						if (map[i - 1][j + 3 + 1] == 0)
						{
							map[i - 1][j + 3 + 1] = -1;
							return 5;
						}
					}
					else
						if (i + 3 + 1 <= 14 && j - 1 <= 14)
							if (map[i + 3 + 1][j - 1] == 0)
							{
								map[i + 3 + 1][j - 1] = -1;
								return 5;
							}
		}


	for (i = 0; i <= 14; i++)
		for (j = 0; j <= 14; j++)
		{
			sum = 0;
			for (k = 0; k <= 3; k++)
				if (j + k <= 14)
					sum += map[i][j + k];
				else
				{
					sum = 0;
					break;
				}
			if (sum == 4)
				if (j - 1 >= 0 && j + 4 <= 14)
				{
					if (map[i][j - 1] == 0 || map[i][j + 4] == 0)
					{
						if (map[i][j - 1] == 0)
							map[i][j - 1] = -1;

						else
							map[i][j + 4] = -1;
						return -5;
					}
				}
				else
					if (j - 1 >= 0)
					{
						if (map[i][j - 1] == 0)
						{
							map[i][j - 1] = -1;
							return -5;
						}
					}
					else
						if (j + 4 <= 14)
							if (map[i][j + 4] == 0)
							{
								map[i][j + 4] = -1;
								return -5;
							}

			sum = 0;
			for (k = 0; k <= 3; k++)
				if (i + k <= 14)
					sum += map[i + k][j];
				else
				{
					sum = 0;
					break;
				}

			if (sum == 4)
				if (i - 1 >= 0 && i + 4 <= 14)
				{
					if (map[i - 1][j] == 0 || map[i + 4][j] == 0)
					{
						if (map[i - 1][j] == 0)
							map[i - 1][j] = -1;
						else
							map[i + 4][j] = -1;
						return -5;

					}
				}
				else
					if (i - 1 >= 0)
					{
						if (map[i - 1][j] == 0)
						{
							map[i - 1][j] = -1;
							return -5;
						}
					}
					else
						if (i + 4 <= 14)
							if (map[i + 4][j] == 0)
							{
								map[i + 4][j] = -1;
								return -5;
							}

			sum = 0;
			for (k = 0; k <= 3; k++)
				if (i + k <= 14 && j + k <= 14)
					sum += map[i + k][j + k];
				else
				{
					sum = 0;
					break;
				}
			if (sum == 4)
				if (i - 1 >= 0 && j - 1 >= 0 && i + 4 <= 14 && j + 4 <= 14)
				{
					if (map[i - 1][j - 1] == 0 || map[i + 4][j + 4] == 0)
					{
						if (map[i - 1][j - 1] == 0)
							map[i - 1][j - 1] = -1;
						else
							map[i + 4][j + 4] = -1;
						return -5;
					}
				}
				else
					if (i - 1 >= 0 && j - 1 >= 0)
					{
						if (map[i - 1][j - 1] == 0)
						{
							map[i - 1][j - 1] = -1;
							return -5;
						}
					}
					else
						if (i + 4 <= 14 && j + 4 <= 14)
							if (map[i + 4][j + 4] == 0)
							{
								map[i + 4][j + 4] = -1;
								return -5;
							}


			sum = 0;
			for (k = 0; k <= 3; k++)
				if (j + 3 - k <= 14 && i + k <= 14)
					sum += map[i + k][j + 3 - k];
				else
				{
					sum = 0;
					break;
				}
			if (sum == 4)
				if (i - 1 >= 0 && j + 3 + 1 <= 14 && i + 3 + 1 <= 14 && j - 1 >= 0)
				{
					if (map[i - 1][j + 3 + 1] == 0 || map[i + 3 + 1][j - 1] == 0)
					{
						if (map[i - 1][j + 3 + 1] == 0)
							map[i - 1][j + 3 + 1] = -1;
						else
							map[i + 3 + 1][j - 1] = -1;
						return -5;
					}
				}
				else
					if (i - 1 >= 0 && j + 3 + 1 <= 14)
					{
						if (map[i - 1][j + 3 + 1] == 0)
						{
							map[i - 1][j + 3 + 1] = -1;
							return -5;
						}
					}
					else
						if (i + 3 + 1 <= 14 && j - 1 >= 0)
							if (map[i + 3 + 1][j - 1] == 0)
							{
								map[i + 3 + 1][j - 1] = -1;
								return -5;
							}
		}

	//11011  10111 11101
	for (i = 0; i <= 14; i++)
		for (j = 0; j <= 14; j++)
		{
			sum = 0;
			for (k = 0; k <= 4; k++)
				if (j + k <= 14)
					sum += map[i][j + k];
				else
				{
					sum = 0;
					break;
				}
			if (sum == 4)
				if (j + 4 <= 14)
				{
					if (map[i][j + 1] == 0)
						map[i][j + 1] = -1;
					else
						if (map[i][j + 2] == 0)
							map[i][j + 2] = -1;
						else
							if (map[i][j + 3] == 0)
								map[i][j + 3] = -1;
					return -5;
				}


			sum = 0;
			for (k = 0; k <= 4; k++)
				if (i + k <= 14)
					sum += map[i + k][j];
				else
				{
					sum = 0;
					break;
				}
			if (sum == 4)
				if (i + 4 <= 14)
				{
					if (map[i + 1][j] == 0)
						map[i + 1][j] = -1;
					else
						if (map[i + 2][j] == 0)
							map[i + 2][j] = -1;
						else
							if (map[i + 3][j] == 0)
								map[i + 3][j] = -1;
					return -5;
				}

			sum = 0;
			for (k = 0; k <= 4; k++)
				if (i + k <= 14 && j + k <= 14)
					sum += map[i + k][j + k];
				else
				{
					sum = 0;
					break;
				}
			if (sum == 4)
				if (i + 4 <= 14 && j + 4 <= 14)
					if (map[i][j] == 1 && map[i + 4][j + 4] == 1)
					{
						if (map[i + 1][j + 1] == 0)
							map[i + 1][j + 1] = -1;
						else
							if (map[i + 2][j + 2] == 0)
								map[i + 2][j + 2] = -1;
							else
								if (map[i + 3][j + 3] == 0)
									map[i + 3][j + 3] = -1;
						return -5;
					}

			sum = 0;
			for (k = 0; k <= 4; k++)
				if (j + 4 - k <= 14 && i + k <= 14)
					sum += map[i + k][j + 4 - k];
				else
				{
					sum = 0;
					break;
				}
			if (sum == 4)
				if (i + 4 <= 14 && j + 4 <= 14)
					if (map[i][j + 4] == 1 && map[i + 4][j] == 1)
					{
						if (map[i + 1][j + 3] == 0)
							map[i + 1][j + 3] = -1;
						else
							if (map[i + 2][j + 2] == 0)
								map[i + 2][j + 2] = -1;
							else
								if (map[i + 3][j + 1] == 0)
									map[i + 3][j + 1] = -1;
						return -5;
					}
		}


	for (i = 0; i < 15; i++)
		for (j = 0; j < 15; j++)
			score[i][j] = 0;
	//111
	for (i = 0; i <= 14; i++)
		for (j = 0; j <= 14; j++)
		{
			if (j + 2 <= 14)
				if (map[i][j] == 1 && map[i][j + 1] == 1 && map[i][j + 2] == 1)
					if (j - 1 >= 0 && j + 3 <= 14)
					{
						if (map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 1 && map[i][j + 2] == 1 && map[i][j + 3] == 0)
						{
							score[i][j - 1] += 10;
							score[i][j + 3] += 10;
						}
						else
							if (map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 1 && map[i][j + 2] == 1 && map[i][j + 3] == -1)
								score[i][j - 1] += 5;
							else
								if (map[i][j - 1] == -1 && map[i][j] == 1 && map[i][j + 1] == 1 && map[i][j + 2] == 1 && map[i][j + 3] == 0)
									score[i][j + 3] += 5;
					}
					else
						if (j - 1 >= 0)
						{
							if (map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 1 && map[i][j + 2] == 1)
								score[i][j - 1] += 5;
						}
						else
							if (j + 3 <= 14)
								if (map[i][j] == 1 && map[i][j + 1] == 1 && map[i][j + 2] == 1 && map[i][j + 3] == 0)
									score[i][j + 3] += 5;

			if (i + 2 <= 14)
				if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i + 2][j] == 1)
					if (i - 1 >= 0 && i + 3 <= 14)
					{
						if (map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 1 && map[i + 2][j] == 1 && map[i + 3][j] == 0)
						{
							score[i - 1][j] += 10;
							score[i + 3][j] += 10;
						}
						else
							if (map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 1 && map[i + 2][j] == 1 && map[i + 3][j] == -1)
								score[i - 1][j] += 5;
							else
								if (map[i - 1][j] != -1 && map[i][j] == 1 && map[i + 1][j] == 1 && map[i + 2][j] == 1 && map[i + 3][j] == 0)
									score[i + 3][j] += 5;
					}
					else
						if (i - 1 >= 0)
						{
							if (map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 1 && map[i + 2][j] == 1)
								score[i - 1][j] += 5;
						}
						else
							if (i + 3 <= 14)
								if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i + 2][j] == 1 && map[i + 3][j] == 0)
									score[i + 3][j] += 5;


			if (i + 2 <= 14 && j + 2 <= 14)
				if (map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == 1)
					if (i - 1 >= 0 && j - 1 >= 0 && i + 3 <= 14 && j + 3 <= 14)
					{

						if (map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == 1 && map[i + 3][j + 3] == 0)
						{
							score[i - 1][j - 1] += 10;
							score[i + 3][j + 3] += 10;
						}
						else
							if (map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == 1 && map[i + 3][j + 3] == -1)
								score[i - 1][j - 1] += 5;
							else
								if (map[i - 1][j - 1] == -1 && map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == 1 && map[i + 3][j + 3] == 0)
									score[i + 3][j + 3] += 5;
					}
					else
						if (i - 1 >= 0 && j - 1 >= 0)
						{
							if (map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == 1)
								score[i - 1][j - 1] += 5;
						}
						else
							if (i + 3 <= 14 && j + 3 <= 14)
								if (map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == 1 && map[i + 3][j + 3] == 0)
									score[i + 3][j + 3] += 5;


			if (i + 2 <= 14 && j + 2 <= 14)
				if (map[i][j + 2] == 1 && map[i + 1][j + 2 - 1] == 1 && map[i + 2][j + 2 - 2] == 1)
					if (i - 1 >= 0 && j + 3 <= 14 && i + 3 <= 14 && j - 1 >= 0)
					{
						if (map[i - 1][j + 3] == 0 && map[i][j + 2] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j] == 1 && map[i + 3][j - 1] == 0)
						{
							score[i - 1][j + 3] += 10;
							score[i + 3][j - 1] += 10;
						}
						else
							if (map[i - 1][j + 3] == 0 && map[i][j + 2] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j] == 1 && map[i + 3][j - 1] == -1)
								score[i - 1][j + 3] += 5;
							else
								if (map[i - 1][j + 3] == -1 && map[i][j + 2] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j] == 1 && map[i + 3][j - 1] == 0)
									score[i + 3][j - 1] += 5;
					}
					else
						if (i - 1 >= 0 && j + 3 <= 14)
						{
							if (map[i - 1][j + 3] == 0 && map[i][j + 2] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j] == 1)
								score[i - 1][j + 3] += 5;
						}
						else
							if (i + 3 <= 14 && j - 1 >= 0)
								if (map[i][j + 2] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j] == 1 && map[i + 3][j - 1] == 0)
									score[i + 3][j - 1] += 5;
		}


		//101
		for (i = 0; i <= 14; i++)
			for (j = 0; j <= 14; j++)
			{
				if (j + 2 <= 14)
					if (map[i][j] == 1 && map[i][j + 1] == 0 && map[i][j + 2] == 1)
						if (j - 1 >= 0 && j + 3 <= 14)
						{
							if (map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 0 && map[i][j + 2] == 1 && map[i][j + 3] == 0)
							{
								score[i][j - 1] += 10;
								score[i][j + 1] += 10;
								score[i][j + 3] += 10;
							}
							else
								if (map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 0 && map[i][j + 2] == 1 && map[i][j + 3] == -1)
								{
									score[i][j - 1] += 5;
									score[i][j + 1] += 5;
								}
								else
									if (map[i][j - 1] == -1 && map[i][j] == 1 && map[i][j + 1] == 1 && map[i][j + 2] == 1 && map[i][j + 3] == 0)
									{
										score[i][j + 1] += 5;
										score[i][j + 3] += 5;
									}
						}
						else
							if (j - 1 >= 0)
							{
								if (map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 0 && map[i][j + 2] == 1)
								{
									score[i][j - 1] += 5;
									score[i][j + 1] += 5;
								}
									
							}
							else
								if (j + 3 <= 14)
									if (map[i][j] == 1 && map[i][j + 1] == 0 && map[i][j + 2] == 1 && map[i][j + 3] == 0)
									{
										score[i][j + 1] += 5;
										score[i][j + 3] += 5;
									}
										

				if (i + 2 <= 14)
					if (map[i][j] == 1 && map[i + 1][j] == 0 && map[i + 2][j] == 1)
						if (i - 1 >= 0 && i + 3 <= 14)
						{
							if (map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 0 && map[i + 2][j] == 1 && map[i + 3][j] == 0)
							{
								score[i - 1][j] += 10;
								score[i + 1][j] += 10;
								score[i + 3][j] += 10;
							}
							else
								if (map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 0 && map[i + 2][j] == 1 && map[i + 3][j] == -1)
								{
									score[i - 1][j] += 5;
									score[i + 1][j] += 5;
								}
								else
									if (map[i - 1][j] != -1 && map[i][j] == 1 && map[i + 1][j] == 0 && map[i + 2][j] == 1 && map[i + 3][j] == 0)
									{
										score[i + 1][j] += 5;
										score[i + 3][j] += 5;
									}		
						}
						else
							if (i - 1 >= 0)
							{
								if (map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 0 && map[i + 2][j] == 1)
								{
									score[i - 1][j] += 5;
									score[i + 1][j] += 5;
								}
							}
							else
								if (i + 3 <= 14)
									if (map[i][j] == 1 && map[i + 1][j] == 0 && map[i + 2][j] == 1 && map[i + 3][j] == 0)
									{
										score[i + 1][j] += 5;
										score[i + 3][j] += 5;
									}		

				if (i + 2 <= 14 && j + 2 <= 14)
					if (map[i][j] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j + 2] == 1)
						if (i - 1 >= 0 && j - 1 >= 0 && i + 3 <= 14 && j + 3 <= 14)
						{

							if (map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j + 2] == 1 && map[i + 3][j + 3] == 0)
							{
								score[i - 1][j - 1] += 10;
								score[i + 1][j + 1] += 10;
								score[i + 3][j + 3] += 10;
							}
							else
								if (map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j + 2] == 1 && map[i + 3][j + 3] == -1)
								{
									score[i - 1][j - 1] += 5;
									score[i + 1][j + 1] += 5;
								}
								else
									if (map[i - 1][j - 1] == -1 && map[i][j] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j + 2] == 1 && map[i + 3][j + 3] == 0)
									{
										score[i + 1][j + 1] += 5;
										score[i + 3][j + 3] += 5;
									}
						}
						else
							if (i - 1 >= 0 && j - 1 >= 0)
							{
								if (map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j + 2] == 1)
								{
									score[i - 1][j - 1] += 5;
									score[i + 1][j + 1] += 5;
								}	
							}
							else
								if (i + 3 <= 14 && j + 3 <= 14)
									if (map[i][j] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j + 2] == 1 && map[i + 3][j + 3] == 0)
									{
										score[i + 1][j + 1] += 5;
										score[i + 3][j + 3] += 5;
									}


				if (i + 2 <= 14 && j + 2 <= 14)
					if (map[i][j + 2] == 1 && map[i + 1][j + 2 - 1] == 0 && map[i + 2][j + 2 - 2] == 1)
						if (i - 1 >= 0 && j + 3 <= 14 && i + 3 <= 14 && j - 1 >= 0)
						{
							if (map[i - 1][j + 3] == 0 && map[i][j + 2] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j] == 1 && map[i + 3][j - 1] == 0)
							{
								score[i - 1][j + 3] += 10;
								score[i + 1][j + 1] += 10;
								score[i + 3][j - 1] += 10;
							}
							else
								if (map[i - 1][j + 3] == 0 && map[i][j + 2] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j] == 1 && map[i + 3][j - 1] == -1)
									score[i - 1][j + 3] += 5;
								else
									if (map[i - 1][j + 3] == -1 && map[i][j + 2] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j] == 1 && map[i + 3][j - 1] == 0)
										score[i + 3][j - 1] += 5;
						}
						else
							if (i - 1 >= 0 && j + 3 <= 14)
							{
								if (map[i - 1][j + 3] == 0 && map[i][j + 2] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j] == 1)
									score[i - 1][j + 3] += 5;
							}
							else
								if (i + 3 <= 14 && j - 1 >= 0)
									if (map[i][j + 2] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j] == 1 && map[i + 3][j - 1] == 0)
										score[i + 3][j - 1] += 5;
			}

	//1101//1011
	for (i = 0; i <= 14; i++)
		for (j = 0; j <= 14; j++)
		{
			if (j == 0)
			{
				if (map[i][j] == 1 && map[i][j + 1] == 1 && map[i][j + 2] == 0 && map[i][j + 3] == 1 && map[i][j + 4] == 0)
				{
					score[i][j + 2] += 5;
					score[i][j + 4] += 5;
				}
				else
					if (map[i][j] == 1 && map[i][j + 1] == 0 && map[i][j + 2] == 1 && map[i][j + 3] == 1 && map[i][j + 4] == 0)
					{
						score[i][j + 1] += 5;
						score[i][j + 4] += 5;
					}
			}
			else
				if (j - 1 >= 0 && j + 4 <= 14)
				{
					if ((map[i][j] == 1 && map[i][j + 1] == 1 && map[i][j + 2] == 0 && map[i][j + 3] == 1) || (map[i][j] == 1 && map[i][j + 1] == 0 && map[i][j + 2] == 1 && map[i][j + 3] == 1))

						if (map[i][j - 1] == 0 && map[i][j + 4] == 0)
						{
							if (map[i][j + 2] == 0)
							{
								score[i][j - 1] += 5;
								score[i][j + 2] += 10;
								score[i][j + 4] += 5;
							}
							else
								if (map[i][j + 1] == 0)
								{
									score[i][j - 1] += 5;
									score[i][j + 1] += 10;
									score[i][j + 4] += 5;
								}
						}
						else
							if (map[i][j - 1] == 0 && map[i][j + 4] == -1)
							{
								if (map[i][j + 2] == 0)
								{
									score[i][j - 1] += 5;
									score[i][j + 2] += 5;
								}
								else
									if (map[i][j + 1] == 0)
									{
										score[i][j - 1] += 5;
										score[i][j + 1] += 5;
									}
							}
							else
								if (map[i][j - 1] == -1 && map[i][j + 4] == 0)
								{
									if (map[i][j + 2] == 0)
									{
										score[i][j + 4] += 5;
										score[i][j + 2] += 5;
									}
									else
										if (map[i][j + 1] == 0)
										{
											score[i][j + 4] += 5;
											score[i][j + 1] += 5;
										}
								}
				}
				else
					if (j == 11)
						if (map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 1 && map[i][j + 2] == 0 && map[i][j + 3] == 1)
						{
							score[i][j + 2] += 5;
							score[i][j - 1] += 5;
						}
						else
							if (map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 0 && map[i][j + 2] == 1 && map[i][j + 3] == 1)
							{
								score[i][j + 1] += 5;
								score[i][j - 1] += 5;
							}



			if (i == 0)
			{
				if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i + 2][j] == 0 && map[i + 3][j] == 1 && map[i + 4][j] == 0)
				{
					score[i + 2][j] += 5;
					score[i + 4][j] += 5;
				}
				else
					if (map[i][j] == 1 && map[i + 1][j] == 0 && map[i + 2][j] == 1 && map[i + 3][j] == 1 && map[i + 4][j] == 0)
					{
						score[i + 1][j] += 5;
						score[i + 4][j] += 5;
					}
			}
			else
				if (i - 1 >= 0 && i + 4 <= 14)
				{
					if ((map[i][j] == 1 && map[i + 1][j] == 1 && map[i + 2][j] == 0 && map[i + 3][j] == 1) || (map[i][j] == 1 && map[i + 1][j] == 0 && map[i + 2][j] == 1 && map[i + 3][j] == 1))

						if (map[i - 1][j] == 0 && map[i + 4][j] == 0)
						{
							if (map[i + 2][j] == 0)
							{
								score[i - 1][j] += 5;
								score[i + 2][j] += 10;
								score[i + 4][j] += 5;
							}
							else
								if (map[i + 1][j] == 0)
								{
									score[i - 1][j] += 5;
									score[i + 1][j] += 10;
									score[i + 4][j] += 5;
								}
						}
						else
							if (map[i - 1][j] == 0 && map[i + 4][j] == -1)
							{
								if (map[i + 2][j] == 0)
								{
									score[i - 1][j] += 5;
									score[i + 2][j] += 5;
								}
								else
									if (map[i + 1][j] == 0)
									{
										score[i - 1][j] += 5;
										score[i + 1][j] += 5;
									}
							}
							else
								if (map[i - 1][j] == -1 && map[i + 4][j] == 0)
								{
									if (map[i + 2][j] == 0)
									{
										score[i + 4][j] += 5;
										score[i + 2][j] += 5;
									}
									else
										if (map[i + 1][j] == 0)
										{
											score[i + 4][j] += 5;
											score[i + 1][j] += 5;
										}
								}
				}
				else
					if (i == 11)
						if (map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 1 && map[i + 2][j] == 0 && map[i + 3][j] == 1)
						{
							score[i + 2][j] += 5;
							score[i - 1][j] += 5;
						}
						else
							if (map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 0 && map[i + 2][j] == 1 && map[i + 3][j] == 1)
							{
								score[i + 1][j] += 5;
								score[i - 1][j] += 5;
							}



			if (i == 0 && j >= 0 && j + 4 <= 14)
			{
				if (map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == 0 && map[i + 3][j + 3] == 1 && map[i + 4][j + 4] == 0)
				{
					score[i + 2][j + 2] += 5;
					score[i + 4][j + 4] += 5;
				}
				else
					if (map[i][j] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j + 2] == 1 && map[i + 3][j + 3] == 1 && map[i + 4][j + 4] == 0)
					{
						score[i + 1][j + 1] += 5;
						score[i + 4][j + 4] += 5;
					}
			}
			else
				if (i >= 0 && j == 0 && i + 4 <= 14)
				{
					if (map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == 0 && map[i + 3][j + 3] == 1 && map[i + 4][j + 4] == 0)
					{
						score[i + 2][j + 2] += 5;
						score[i + 4][j + 4] += 5;
					}
					else
						if (map[i][j] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j + 2] == 1 && map[i + 3][j + 3] == 1 && map[i + 4][j + 4] == 0)
						{
							score[i + 1][j + 1] += 5;
							score[i + 4][j + 4] += 5;
						}
				}
				else
					if (i - 1 >= 0 && i + 4 <= 14 && j - 1 >= 0 && j + 4 <= 14)
					{
						if ((map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == 0 && map[i + 3][j + 3] == 1) || (map[i][j] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j + 2] == 1 && map[i + 3][j + 3] == 1))

							if (map[i - 1][j - 1] == 0 && map[i + 4][j + 4] == 0)
							{
								if (map[i + 2][j + 2] == 0)
								{
									score[i - 1][j - 1] += 5;
									score[i + 2][j + 2] += 10;
									score[i + 4][j + 4] += 5;
								}
								else
									if (map[i + 1][j + 1] == 0)
									{
										score[i - 1][j - 1] += 5;
										score[i + 1][j + 1] += 10;
										score[i + 4][j + 4] += 5;
									}
							}
							else
								if (map[i - 1][j - 1] == 0 && map[i + 4][j + 4] == -1)
								{
									if (map[i + 2][j + 2] == 0)
									{
										score[i - 1][j - 1] += 5;
										score[i + 2][j + 2] += 5;
									}
									else
										if (map[i + 1][j + 1] == 0)
										{
											score[i - 1][j - 1] += 5;
											score[i + 1][j + 1] += 5;
										}
								}
								else
									if (map[i - 1][j - 1] == -1 && map[i + 4][j + 4] == 0)
									{
										if (map[i + 2][j + 2] == 0)
										{
											score[i + 4][j + 4] += 5;
											score[i + 2][j + 2] += 5;
										}
										else
											if (map[i + 1][j + 1] == 0)
											{
												score[i + 4][j + 4] += 5;
												score[i + 1][j + 1] += 5;
											}
									}
					}
					else
						if (i == 11 && j >= 1 && j + 3 <= 14)
						{
							if (map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == 0 && map[i + 3][j + 3] == 1)
							{
								score[i + 2][j + 2] += 5;
								score[i - 1][j - 1] += 5;
							}
							else
								if (map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j + 2] == 1 && map[i + 3][j + 3] == 1)
								{
									score[i + 1][j + 1] += 5;
									score[i - 1][j - 1] += 5;
								}
						}
						else
							if (j == 11 && i >= 1 && i + 3 <= 14)
							{
								if (map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == 0 && map[i + 3][j + 3] == 1)
								{
									score[i + 2][j + 2] += 5;
									score[i - 1][j - 1] += 5;
								}
								else
									if (map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j + 2] == 1 && map[i + 3][j + 3] == 1)
									{
										score[i + 1][j + 1] += 5;
										score[i - 1][j - 1] += 5;
									}
							}



			if (j == 4 && i >= 0 && i + 4 <= 14)
			{
				if (map[i][j] == 0 && map[i + 1][j - 1] == 1 && map[i + 2][j - 2] == 0 && map[i + 3][j - 3] == 1 && map[i + 4][j - 4] == 1)
				{
					score[i][j] += 5;
					score[i + 2][j - 2] += 5;
				}
				else
					if (map[i][j] == 0 && map[i + 1][j - 1] == 1 && map[i + 2][j - 2] == 1 && map[i + 3][j - 3] == 0 && map[i + 4][j - 4] == 1)
					{
						score[i][j] += 5;
						score[i + 3][j - 3] += 5;
					}
			}
			else
				if (i == 0 && j >= 4)
				{
					if (map[i][j] == 1 && map[i + 1][j - 1] == 1 && map[i + 2][j - 2] == 0 && map[i + 3][j - 3] == 1 && map[i + 4][j - 4] == 0)
					{
						score[i + 4][j - 4] += 5;
						score[i + 2][j - 2] += 5;
					}
					else
						if (map[i][j] == 1 && map[i + 1][j - 1] == 0 && map[i + 2][j - 2] == 1 && map[i + 3][j - 3] == 1 && map[i + 4][j - 4] == 0)
						{
							score[i + 1][j - 1] += 5;
							score[i + 4][j - 4] += 5;
						}
				}
				else
					if (i == 11 && j - 4 >= 0)
					{
						if (map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 1 && map[i + 2][j - 2] == 0 && map[i + 3][j - 3] == 1)
						{
							score[i - 1][j + 1] += 5;
							score[i + 2][j - 2] += 5;
						}
						else
							if (map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 0 && map[i + 2][j - 2] == 1 && map[i + 3][j - 3] == 1)
							{
								score[i - 1][j + 1] += 5;
								score[i + 1][j - 1] += 5;
							}
					}
					else
						if (j == 14 && i >= 0 && i + 4 <= 14)
						{
							if (map[i][j] == 1 && map[i + 1][j - 1] == 1 && map[i + 2][j - 2] == 0 && map[i + 3][j - 3] == 1 && map[i + 4][j - 4] == 0)
							{
								score[i + 4][j - 4] += 5;
								score[i + 2][j - 2] += 5;
							}
							else
								if (map[i][j] == 1 && map[i + 1][j - 1] == 0 && map[i + 2][j - 2] == 1 && map[i + 3][j - 3] == 1 && map[i + 4][j - 4] == 0)
								{
									score[i + 1][j - 1] += 5;
									score[i + 4][j - 4] += 5;
								}
						}
						else
							if (i - 1 >= 0 && i + 4 <= 14 && j - 4 >= 0 && j + 1 <= 14)
							{
								if ((map[i][j] == 1 && map[i + 1][j - 1] == 1 && map[i + 2][j - 2] == 0 && map[i + 3][j - 3] == 1) || (map[i][j] == 1 && map[i + 1][j - 1] == 0 && map[i + 2][j - 2] == 1 && map[i + 3][j - 3] == 1))
									if (map[i - 1][j + 1] == 0 && map[i + 4][j - 4] == 0)
									{
										if (map[i + 2][j - 2] == 0)
										{
											score[i - 1][j + 1] += 5;
											score[i + 2][j - 2] += 10;
											score[i + 4][j - 4] += 5;
										}
										else
											if (map[i + 1][j - 1] == 0)
											{
												score[i - 1][j + 1] += 5;
												score[i + 1][j - 1] += 10;
												score[i + 4][j - 4] += 5;
											}
									}
									else
										if (map[i - 1][j + 1] == 0 && map[i + 4][j - 4] == -1)
										{
											if (map[i + 2][j - 2] == 0)
											{
												score[i - 1][j + 1] += 5;
												score[i + 2][j - 2] += 5;
											}
											else
												if (map[i + 1][j - 1] == 0)
												{
													score[i - 1][j + 1] += 5;
													score[i + 1][j - 1] += 5;
												}
										}
										else
											if (map[i - 1][j + 1] == -1 && map[i + 4][j - 4] == 0)
											{
												if (map[i + 2][j - 2] == 0)
												{
													score[i + 4][j - 4] += 5;
													score[i + 2][j - 2] += 5;
												}
												else
													if (map[i + 1][j - 1] == 0)
													{
														score[i + 4][j - 4] += 5;
														score[i + 1][j - 1] += 5;
													}
											}
							}

		}
		//11
	for (i = 0; i <= 14; i++)
		for (j = 0; j <= 14; j++)
		{
			if (j + 1 <= 14)
				if (map[i][j] == 1 && map[i][j + 1] == 1)
					if (j == 0)
					{
						if (map[i][j] == 1 && map[i][j + 1] == 1 && map[i][j + 2] == 0 && map[i][j + 3] == 0 && map[i][j + 4] == 0)
							score[i][j + 2] += 3;
					}
					else
						if (j == 1)
						{
							if (map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 1 && map[i][j + 2] == 0 && map[i][j + 3] == 0)
							{
								score[i][j + 2] += 3;
								score[i][j - 1] += 3;
							}
							else
								if (map[i][j - 1] == -1 && map[i][j] == 1 && map[i][j + 1] == 1 && map[i][j + 2] == 0 && map[i][j + 3] == 0 && map[i][j + 4] == 0)
									score[i][j + 2] += 3;
						}
						else
							if (j == 2)
							{
								if (map[i][j - 2] == 0 && map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 1 && map[i][j + 2] == 0 && map[i][j + 3] == 0)
								{
									score[i][j + 2] += 4;
									score[i][j - 1] += 3;
								}
								else
									if (map[i][j - 2] == -1 && map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 1 && map[i][j + 2] == 0 && map[i][j + 3] == 0)
									{
										score[i][j + 2] += 3;
										score[i][j - 1] += 3;
									}
									else
										if (map[i][j - 1] == -1 && map[i][j] == 1 && map[i][j + 1] == 1 && map[i][j + 2] == 0 && map[i][j + 3] == 0 && map[i][j + 4] == 0)
											score[i][j + 2] += 3;
							}
							else
								if (j - 3 >= 0 && j + 4 <= 14)
								{
									if (map[i][j - 1] == -1 && map[i][j] == 1 && map[i][j + 1] == 1 && map[i][j + 2] == 0 && map[i][j + 3] == 0 && map[i][j + 4] == 0)
										score[i][j + 2] += 3;
									else
										if (map[i][j - 2] == -1 && map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 1 && map[i][j + 2] == 0 && map[i][j + 3] == 0)
										{
											score[i][j - 1] += 3;
											score[i][j + 2] += 3;
										}
										else
											if (map[i][j - 2] == 0 && map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 1 && map[i][j + 2] == 0 && map[i][j + 3] == 0)
											{
												score[i][j - 1] += 4;
												score[i][j + 2] += 4;
											}
											else
												if (map[i][j - 2] == 0 && map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 1 && map[i][j + 2] == 0 && map[i][j + 3] == -1)
												{
													score[i][j - 1] = 3;
													score[i][j + 2] = 3;
												}
												else
													if (map[i][j - 3] == 0 && map[i][j - 2] == 0 && map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 1 && map[i][j + 2] == -1)
														score[i][j - 1] = 3;
								}
								else
									if (j == 11)
									{
										if (map[i][j - 2] == 0 && map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 1 && map[i][j + 2] == 0 && map[i][j + 3] == 0)
										{
											score[i][j - 1] = 4;
											score[i][j + 2] = 3;
										}
										else
											if (map[i][j - 2] == -1 && map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 1 && map[i][j + 2] == 0 && map[i][j + 3] == 0)
											{
												score[i][j - 1] = 3;
												score[i][j + 2] = 3;
											}
											else
												if (map[i][j - 2] == 0 && map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 1 && map[i][j + 2] == 0 && map[i][j + 3] == -1)
												{
													score[i][j - 1] = 3;
													score[i][j + 2] = 3;
												}
												else
													if (map[i][j - 3] == 0 && map[i][j - 2] == 0 && map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 1 && map[i][j + 2] == -1)
														score[i][j - 1] = 3;
									}
									else
										if (j == 12)
										{
											if (map[i][j - 2] == 0 && map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 1 && map[i][j + 2] == 0)
											{
												score[i][j - 1] = 3;
												score[i][j + 2] = 3;
											}
											else
												if (map[i][j - 3] == 0 && map[i][j - 2] == 0 && map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 1 && map[i][j + 2] == -1)
													score[i][j - 1] = 3;
										}
										else
											if (j == 13)
												if (map[i][j - 3] == 0 && map[i][j - 2] == 0 && map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 1)
													score[i][j - 1] = 3;


			if (i + 1 <= 14)
				if (map[i][j] == 1 && map[i + 1][j] == 1)
					if (i == 0)
					{
						if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i + 2][j] == 0 && map[i + 3][j] == 0 && map[i + 4][j] == 0)
							score[i + 2][j] += 3;
					}
					else
						if (i == 1)
						{
							if (map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 1 && map[i + 2][j] == 0 && map[i + 3][j] == 0)
							{
								score[i + 2][j] += 3;
								score[i - 1][j] += 3;
							}
							else
								if (map[i - 1][j] == -1 && map[i][j] == 1 && map[i + 1][j] == 1 && map[i + 2][j] == 0 && map[i + 3][j] == 0 && map[i + 4][j] == 0)
									score[i + 2][j] += 3;
						}
						else
							if (i == 2)
							{
								if (map[i - 2][j] == 0 && map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 1 && map[i + 2][j] == 0 && map[i + 3][j] == 0)
								{
									score[i + 2][j] += 4;
									score[i - 1][j] += 3;
								}
								else
									if (map[i - 2][j] == -1 && map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 1 && map[i + 2][j] == 0 && map[i + 3][j] == 0)
									{
										score[i + 2][j] += 3;
										score[i - 1][j] += 3;
									}
									else
										if (map[i - 1][j] == -1 && map[i][j] == 1 && map[i + 1][j] == 1 && map[i + 2][j] == 0 && map[i + 3][j] == 0 && map[i + 4][j] == 0)
											score[i + 2][j] += 3;
							}
							else
								if (i - 3 >= 0 && i + 4 <= 14)
								{
									if (map[i - 1][j] == -1 && map[i][j] == 1 && map[i + 1][j] == 1 && map[i + 2][j] == 0 && map[i + 3][j] == 0 && map[i + 4][j] == 0)
										score[i + 2][j] += 3;
									else
										if (map[i - 2][j] == -1 && map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 1 && map[i + 2][j] == 0 && map[i + 3][j] == 0)
										{
											score[i - 1][j] += 3;
											score[i + 2][j] += 3;
										}
										else
											if (map[i - 2][j] == 0 && map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 1 && map[i + 2][j] == 0 && map[i + 3][j] == 0)
											{
												score[i - 1][j] += 4;
												score[i + 2][j] += 4;
											}
											else
												if (map[i - 2][j] == 0 && map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 1 && map[i + 2][j] == 0 && map[i + 3][j] == -1)
												{
													score[i - 1][j] = 3;
													score[i + 2][j] = 3;
												}
												else
													if (map[i - 3][j] == 0 && map[i - 2][j] == 0 && map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 1 && map[i + 2][j] == -1)
														score[i - 1][j] = 3;
								}
								else
									if (i == 11)
									{
										if (map[i - 2][j] == 0 && map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 1 && map[i + 2][j] == 0 && map[i + 3][j] == 0)
										{
											score[i - 1][j] = 4;
											score[i + 2][j] = 3;
										}
										else
											if (map[i - 2][j] == -1 && map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 1 && map[i + 2][j] == 0 && map[i + 3][j] == 0)
											{
												score[i - 1][j] = 3;
												score[i + 2][j] = 3;
											}
											else
												if (map[i - 2][j] == 0 && map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 1 && map[i + 2][j] == 0 && map[i + 3][j] == -1)
												{
													score[i - 1][j] = 3;
													score[i + 2][j] = 3;
												}
												else
													if (map[i - 3][j] == 0 && map[i - 2][j] == 0 && map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 1 && map[i + 2][j] == -1)
														score[i - 1][j] = 3;
									}
									else
										if (i == 12)
										{
											if (map[i - 2][j] == 0 && map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 1 && map[i + 2][j] == 0)
											{
												score[i - 1][j] = 3;
												score[i + 2][j] = 3;
											}
											else
												if (map[i - 3][j] == 0 && map[i - 2][j] == 0 && map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 1 && map[i + 2][j] == -1)
													score[i - 1][j] = 3;
										}
										else
											if (i == 13)
												if (map[i - 3][j] == 0 && map[i - 2][j] == 0 && map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 1)
													score[i - 1][j] = 3;



			if (i + 1 <= 14 && j + 1 <= 14)
				if (map[i][j] == 1 && map[i + 1][j + 1] == 1)
				{
					if (i == 0)
					{
						if (j + 4 <= 14)
						{
							if (map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == 0 && map[i + 3][j + 3] == 0 && map[i + 4][j + 4] == 0)
								score[i + 2][j + 2] += 2;
						}
					}
					else
						if (i == 1)
						{
							if (j + 3 <= 14)
								if (map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == 0 && map[i + 3][j + 3] == 0)
								{
									score[i + 2][j + 2] += 2;
									score[i - 1][j - 1] += 2;
								}
								else
									if (j + 4 <= 14)
										if (map[i - 1][j - 1] == -1 && map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == 0 && map[i + 3][j + 3] == 0 && map[i + 4][j + 4] == 0)
											score[i + 2][j + 2] += 2;
						}
						else
							if (i == 2)
							{
								if (j == 12)
								{
									if (map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == 0)
									{
										score[i + 2][j + 2] += 2;
										score[i - 1][j - 1] += 3;
									}
								}
								else
									if (j + 3 <= 14)
										if (map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == 0 && map[i + 3][j + 3] == 0)
										{
											score[i + 2][j + 2] += 3;
											score[i - 1][j - 1] += 3;
										}
										else
											if (map[i - 2][j - 2] == -1 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == 0 && map[i + 3][j + 3] == 0)
											{
												score[i - 1][j - 1] += 2;
												score[i + 2][j + 2] += 2;
											}
											else
												if (j + 4 <= 14)
													if (map[i - 1][j - 1] == -1 && map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == 0 && map[i + 3][j + 3] == 0 && map[i + 4][j + 4] == 0)
														score[i + 2][j + 2] += 2;
							}
					if (i >= 3 && i <= 10)
					{
						if (j <= 11)
						{
							if (map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == 0 && map[i + 3][j + 3] == 0)
							{
								score[i + 2][j + 2] += 4;
								score[i - 1][j - 1] += 4;
							}
							else
								if (map[i - 2][j - 2] == -1 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == 0 && map[i + 3][j + 3] == 0)
								{
									score[i - 1][j - 1] += 2;
									score[i + 2][j + 2] += 2;
								}
								else
									if (map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == 0 && map[i + 3][j + 3] == -1)
									{
										score[i - 1][j - 1] += 2;
										score[i + 2][j + 2] += 2;
									}
									else
										if (map[i - 3][j - 3] == 0 && map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == -1)
											score[i - 1][j - 1] += 2;
										else
											if (j + 4 <= 14)
												if (map[i - 1][j - 1] == -1 && map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == 0 && map[i + 3][j + 3] == 0 && map[i + 4][j + 4] == 0)
													score[i + 2][j + 2] += 2;
						}
						else
							if (j == 12)
							{
								if (map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == 0)
								{
									score[i + 2][j + 2] += 2;
									score[i - 1][j - 1] += 3;
								}
								else
									if (map[i - 3][j - 3] == 0 && map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == -1)
										score[i - 1][j - 1] += 2;

							}
							else
								if (j == 13)
								{
									if (map[i - 3][j - 3] == 0 && map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 1)
										score[i - 1][j - 1] += 2;
								}
					}
					if (i == 11)
					{

						if (j + 3 <= 14)
							if (map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == 0 && map[i + 3][j + 3] == 0)
							{
								score[i + 2][j + 2] += 3;
								score[i - 1][j - 1] += 3;
							}
							else
								if (map[i - 2][j - 2] == -1 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == 0 && map[i + 3][j + 3] == 0)
								{
									score[i - 1][j - 1] += 2;
									score[i + 2][j + 2] += 2;
								}
								else
									if (map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == 0 && map[i + 3][j + 3] == -1)
									{
										score[i - 1][j - 1] += 2;
										score[i + 2][j + 2] += 2;
									}
									else
										if (map[i - 3][j - 3] == 0 && map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == -1)
											score[i - 1][j - 1] += 2;
										else
											if (j == 12)
											{
												if (map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == 0)
												{
													score[i + 2][j + 2] += 2;
													score[i - 1][j - 1] += 3;
												}
											}
											else
												if (j == 13)
													if (map[i - 3][j - 3] == 0 && map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 1)
														score[i - 1][j - 1] += 2;

					}
					else
						if (i == 12)
						{
							if (j + 3 <= 14)
							{
								if (map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == 0)
								{
									score[i + 2][j + 2] += 2;
									score[i - 1][j - 1] += 3;
								}
								else
									if (map[i - 3][j - 3] == 0 && map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == -1)
										score[i - 1][j - 1] += 2;
							}
							else
								if (j == 12)
								{
									if (map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == 0)
									{
										score[i + 2][j + 2] += 2;
										score[i - 1][j - 1] += 3;
									}
								}
								else
									if (j == 13)
										if (map[i - 3][j - 3] == 0 && map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 1)
											score[i - 1][j - 1] += 2;
						}
						else
							if (i == 13)
								if (j - 3 >= 0)
									if (map[i - 3][j - 3] == 0 && map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 1)
										score[i - 1][j - 1] += 2;

				}

			if (i + 1 <= 14 && j - 1 >= 0)
				if (map[i][j] == 1 && map[i + 1][j - 1] == 1)
				{
					if (i == 0)
					{
						if (j - 4 >= 0)
						{
							if (map[i][j] == 1 && map[i + 1][j - 1] == 1 && map[i + 2][j - 2] == 0 && map[i + 3][j - 3] == 0 && map[i + 4][j - 4] == 0)
								score[i + 2][j - 2] += 2;
						}
					}
					else
						if (i == 1)
						{
							if (j - 3 >= 0)
								if (map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 1 && map[i + 2][j - 2] == 0 && map[i + 3][j - 3] == 0)
								{
									score[i + 2][j - 2] += 2;
									score[i - 1][j + 1] += 2;
								}
								else
									if (j - 4 >= 0)
										if (map[i - 1][j + 1] == -1 && map[i][j] == 1 && map[i + 1][j - 1] == 1 && map[i + 2][j - 2] == 0 && map[i + 3][j - 3] == 0 && map[i + 4][j - 4] == 0)
											score[i + 2][j - 2] += 2;
						}
						else
							if (i == 2)
							{
								if (j == 2)
								{
									if (map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 1 && map[i + 2][j - 2] == 0)
									{
										score[i + 2][j - 2] += 2;
										score[i - 1][j + 1] += 3;
									}
								}
								else
									if (j - 3 >= 0)
										if (map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 1 && map[i + 2][j - 2] == 0 && map[i + 3][j - 3] == 0)
										{
											score[i + 2][j - 2] += 3;
											score[i - 1][j + 1] += 3;
										}
										else
											if (map[i - 2][j + 2] == -1 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 1 && map[i + 2][j - 2] == 0 && map[i + 3][j - 3] == 0)
											{
												score[i - 1][j + 1] += 2;
												score[i + 2][j - 2] += 2;
											}
											else
												if (j - 4 >= 0)
													if (map[i - 1][j + 1] == -1 && map[i][j] == 1 && map[i + 1][j - 1] == 1 && map[i + 2][j - 2] == 0 && map[i + 3][j - 3] == 0 && map[i + 4][j - 4] == 0)
														score[i + 2][j - 2] += 2;
							}
					if (i >= 3 && i <= 10)
					{
						if (j >= 3)
						{
							if (map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 1 && map[i + 2][j - 2] == 0 && map[i + 3][j - 3] == 0)
							{
								score[i + 2][j - 2] += 4;
								score[i - 1][j + 1] += 4;
							}
							else
								if (map[i - 2][j + 2] == -1 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 1 && map[i + 2][j - 2] == 0 && map[i + 3][j - 3] == 0)
								{
									score[i - 1][j + 1] += 2;
									score[i + 2][j - 2] += 2;
								}
								else
									if (map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 1 && map[i + 2][j - 2] == 0 && map[i + 3][j - 3] == -1)
									{
										score[i - 1][j + 1] += 2;
										score[i + 2][j - 2] += 2;
									}
									else
										if (map[i - 3][j + 3] == 0 && map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 1 && map[i + 2][j - 2] == -1)
											score[i - 1][j + 1] += 2;
										else
											if (j - 4 >= 0)
												if (map[i - 1][j + 1] == -1 && map[i][j] == 1 && map[i + 1][j - 1] == 1 && map[i + 2][j - 2] == 0 && map[i + 3][j - 3] == 0 && map[i + 4][j - 4] == 0)
													score[i + 2][j - 2] += 2;
						}
						else
							if (j == 2)
							{
								if (map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 1 && map[i + 2][j - 2] == 0)
								{
									score[i + 2][j - 2] += 2;
									score[i - 1][j + 1] += 3;
								}
								else
									if (map[i - 3][j + 3] == 0 && map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 1 && map[i + 2][j - 2] == -1)
										score[i - 1][j + 1] += 2;

							}
							else
								if (j == 1)
								{
									if (map[i - 3][j + 3] == 0 && map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 1)
										score[i - 1][j + 1] += 2;
								}
					}
					if (i == 3)
					{

						if (j - 3 >= 0)
							if (map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 1 && map[i + 2][j - 2] == 0 && map[i + 3][j - 3] == 0)
							{
								score[i + 2][j - 2] += 3;
								score[i - 1][j + 1] += 3;
							}
							else
								if (map[i - 2][j + 2] == -1 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 1 && map[i + 2][j - 2] == 0 && map[i + 3][j - 3] == 0)
								{
									score[i - 1][j + 1] += 2;
									score[i + 2][j - 2] += 2;
								}
								else
									if (map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 1 && map[i + 2][j - 2] == 0 && map[i + 3][j - 3] == -1)
									{
										score[i - 1][j + 1] += 2;
										score[i + 2][j - 2] += 2;
									}
									else
										if (map[i - 3][j + 3] == 0 && map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 1 && map[i + 2][j - 2] == -1)
											score[i - 1][j + 1] += 2;
										else
											if (j == 2)
											{
												if (map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 1 && map[i + 2][j - 2] == 0)
												{
													score[i + 2][j - 2] += 2;
													score[i - 1][j + 1] += 3;
												}
											}
											else
												if (j == 1)
													if (map[i - 3][j + 3] == 0 && map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 1)
														score[i - 1][j + 1] += 2;

					}
					else
						if (i == 12)
						{
							if (j - 3 >= 0)
							{
								if (map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 1 && map[i + 2][j - 2] == 0)
								{
									score[i + 2][j - 2] += 2;
									score[i - 1][j + 1] += 3;
								}
								else
									if (map[i - 3][j + 3] == 0 && map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 1 && map[i + 2][j - 2] == -1)
										score[i - 1][j + 1] += 2;
							}
							else
								if (j == 2)
								{
									if (map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 1 && map[i + 2][j - 2] == 0)
									{
										score[i + 2][j - 2] += 2;
										score[i - 1][j + 1] += 3;
									}
								}
								else
									if (j == 1)
										if (map[i - 3][j + 3] == 0 && map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 1)
											score[i - 1][j + 1] += 2;
						}
						else
							if (i == 13)
								if (j + 3 <= 14)
									if (map[i - 3][j + 3] == 0 && map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 1)
										score[i - 1][j + 1] += 2;

				}

		}

		//1
		for (i = 0; i <= 14; i++)
			for (j = 0; j <= 14; j++)
			{
				if (j + 1 <= 14)
					if (map[i][j] == 1)
						if (j == 0)
						{
							if (map[i][j] == 1 && map[i][j + 1] == 0 && map[i][j + 2] == 0 && map[i][j + 3] == 0 && map[i][j + 4] == 0)
								score[i][j + 1] += 1;
						}
						else
							if (j == 1)
							{
								if (map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 0 && map[i][j + 2] == 0 && map[i][j + 3] == 0)
								{
									score[i][j + 1] += 1;
									score[i][j - 1] += 1;
								}
								else
									if (map[i][j - 1] == -1 && map[i][j] == 1 && map[i][j + 1] == 0 && map[i][j + 2] == 0 && map[i][j + 3] == 0 && map[i][j + 4] == 0)
										score[i][j + 1] += 1;
							}
							else
								if (j == 2)
								{
									if (map[i][j - 2] == 0 && map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 0 && map[i][j + 2] == 0)
									{
										score[i][j + 1] += 2;
										score[i][j - 1] += 2;
									}
									else
										if (map[i][j - 2] == -1 && map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 0 && map[i][j + 2] == 0 && map[i][j + 3] == 0)
										{
											score[i][j + 1] += 1;
											score[i][j - 1] += 1;
										}
										else
											if (map[i][j - 1] == -1 && map[i][j] == 1 && map[i][j + 1] == 0 && map[i][j + 2] == 0 && map[i][j + 3] == 0 && map[i][j + 4] == 0)
												score[i][j + 1] += 1;
								}
								else
									if (j - 3 >= 0 && j + 4 <= 14)
									{
										if (map[i][j - 1] == -1 && map[i][j] == 1 && map[i][j + 1] == 0 && map[i][j + 2] == 0 && map[i][j + 3] == 0 && map[i][j + 4] == 0)
											score[i][j + 2] += 1;
										else
											if (map[i][j - 2] == -1 && map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 0 && map[i][j + 2] == 0 && map[i][j + 3] == 0)
											{
												score[i][j - 1] += 1;
												score[i][j + 1] += 1;
											}
											else
												if (map[i][j - 2] == 0 && map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 0 && map[i][j + 2] == 0)
												{
													score[i][j - 1] += 2;
													score[i][j + 1] += 2;
												}
												else
													if (map[i][j - 2] == 0 && map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 0 && map[i][j + 2] == 0 && map[i][j + 3] == -1)
													{
														score[i][j - 1] = 2;
														score[i][j + 1] = 1;
													}
													else
														if (map[i][j - 3] == 0 && map[i][j - 2] == 0 && map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 0 && map[i][j + 2] == -1)
														{
															score[i][j - 1] = 1;
															score[i][j + 1] = 1;
														}
									}
									else
										if (j == 11)
										{
											if (map[i][j - 2] == 0 && map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 0 && map[i][j + 2] == 0)
											{
												score[i][j - 1] = 2;
												score[i][j + 1] = 2;
											}
											else
												if (map[i][j - 2] == -1 && map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 0 && map[i][j + 2] == 0 && map[i][j + 3] == 0)
												{
													score[i][j - 1] = 1;
													score[i][j + 1] = 1;
												}
												else
													if (map[i][j - 2] == 0 && map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 0 && map[i][j + 2] == 0 && map[i][j + 3] == -1)
													{
														score[i][j - 1] = 2;
														score[i][j + 1] = 1;
													}
													else
														if (map[i][j - 3] == 0 && map[i][j - 2] == 0 && map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 1 && map[i][j + 2] == -1)
															score[i][j - 1] = 1;
										}
										else
											if (j == 12)
											{
												if (map[i][j - 2] == 0 && map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 0 && map[i][j + 2] == 0)
												{
													score[i][j - 1] = 2;
													score[i][j + 1] = 2;
												}
												else
													if (map[i][j - 3] == 0 && map[i][j - 2] == 0 && map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 0 && map[i][j + 2] == -1)
													{
														score[i][j - 1] = 1;
														score[i][j + 1] = 1;
													}
											}
											else
												if (j == 13)
													if (map[i][j - 3] == 0 && map[i][j - 2] == 0 && map[i][j - 1] == 0 && map[i][j] == 1 && map[i][j + 1] == 0)
													{
														score[i][j - 1] = 1;
														score[i][j + 1] = 1;
													}


				if (i + 1 <= 14)
					if (map[i][j] == 1)
						if (i == 0)
						{
							if (map[i][j] == 1 && map[i + 1][j] == 0 && map[i + 2][j] == 0 && map[i + 3][j] == 0 && map[i + 4][j] == 0)
								score[i + 1][j] += 1;
						}
						else
							if (i == 1)
							{
								if (map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 0 && map[i + 2][j] == 0 && map[i + 3][j] == 0)
								{
									score[i + 1][j] += 1;
									score[i - 1][j] += 1;
								}
								else
									if (map[i - 1][j] == -1 && map[i][j] == 1 && map[i + 1][j] == 0 && map[i + 2][j] == 0 && map[i + 3][j] == 0 && map[i + 4][j] == 0)
										score[i + 1][j] += 1;
							}
							else
								if (i == 2)
								{
									if (map[i - 2][j] == 0 && map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 0 && map[i + 2][j] == 0 && map[i + 3][j] == 0)
									{
										score[i + 1][j] += 1;
										score[i - 1][j] += 2;
									}
									else
										if (map[i - 2][j] == -1 && map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 0 && map[i + 2][j] == 0 && map[i + 3][j] == 0)
										{
											score[i + 1][j] += 1;
											score[i - 1][j] += 1;
										}
										else
											if (map[i - 1][j] == -1 && map[i][j] == 1 && map[i + 1][j] == 0 && map[i + 2][j] == 0 && map[i + 3][j] == 0 && map[i + 4][j] == 0)
												score[i + 1][j] += 1;
								}
								else
									if (i - 3 >= 0 && i + 4 <= 14)
									{
										if (map[i - 1][j] == -1 && map[i][j] == 1 && map[i + 1][j] == 0 && map[i + 2][j] == 0 && map[i + 3][j] == 0 && map[i + 4][j] == 0)
											score[i + 1][j] += 1;
										else
											if (map[i - 2][j] == -1 && map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 0 && map[i + 2][j] == 0 && map[i + 3][j] == 0)
											{
												score[i - 1][j] += 1;
												score[i + 1][j] += 1;
											}
											else
												if (map[i - 2][j] == 0 && map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 0 && map[i + 2][j] == 0)
												{
													score[i - 1][j] += 2;
													score[i + 1][j] += 2;
												}
												else
													if (map[i - 2][j] == 0 && map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 0 && map[i + 2][j] == 0 && map[i + 3][j] == -1)
													{
														score[i - 1][j] = 2;
														score[i + 1][j] = 1;
													}
													else
														if (map[i - 3][j] == 0 && map[i - 2][j] == 0 && map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 0 && map[i + 2][j] == -1)
														{
															score[i + 1][j] = 1;
															score[i - 1][j] = 1;
														}
															
									}
									else
										if (i == 11)
										{
											if (map[i - 2][j] == 0 && map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 0 && map[i + 2][j] == 0)
											{
												score[i - 1][j] = 2;
												score[i + 1][j] = 2;
											}
											else
												if (map[i - 2][j] == -1 && map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 0 && map[i + 2][j] == 0 && map[i + 3][j] == 0)
												{
													score[i - 1][j] = 1;
													score[i + 1][j] = 1;
												}
												else
													if (map[i - 2][j] == 0 && map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 0 && map[i + 2][j] == 0 && map[i + 3][j] == -1)
													{
														score[i - 1][j] = 2;
														score[i + 1][j] = 1;
													}
													else
														if (map[i - 3][j] == 0 && map[i - 2][j] == 0 && map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 0 && map[i + 2][j] == -1)
															score[i - 1][j] = 1;
										}
										else
											if (i == 12)
											{
												if (map[i - 2][j] == 0 && map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 0 && map[i + 2][j] == 0)
												{
													score[i - 1][j] = 1;
													score[i +1][j] = 2;
												}
												else
													if (map[i - 3][j] == 0 && map[i - 2][j] == 0 && map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 0 && map[i + 2][j] == -1)
													{
														score[i + 1][j] = 1;
														score[i - 1][j] = 1;
													}
														
											}
											else
												if (i == 13)
													if (map[i - 3][j] == 0 && map[i - 2][j] == 0 && map[i - 1][j] == 0 && map[i][j] == 1 && map[i + 1][j] == 0)
													{
														score[i - 1][j] = 1;
														score[i + 1][j] = 1;
													}


				if (i + 1 <= 14 && j + 1 <= 14)
					if (map[i][j] == 1)
					{
						if (i == 0)
						{
							if (j + 4 <= 14)
							{
								if (map[i][j] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j + 2] == 0 && map[i + 3][j + 3] == 0 && map[i + 4][j + 4] == 0)
									score[i + 2][j + 2] += 1;
							}
						}
						else
							if (i == 1)
							{
								if (j + 3 <= 14)
									if (map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j + 2] == 0 && map[i + 3][j + 3] == 0)
									{
										score[i + 1][j + 1] += 2;
										score[i - 1][j - 1] += 2;
									}
									else
										if (j + 4 <= 14)
											if (map[i - 1][j - 1] == -1 && map[i][j] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j + 2] == 0 && map[i + 3][j + 3] == 0 && map[i + 4][j + 4] == 0)
												score[i + 1][j + 1] += 2;
							}
							else
								if (i == 2)
								{
									if (j == 12)
									{
										if (map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j + 2] == 0)
										{
											score[i + 1][j + 1] += 1;
											score[i - 1][j - 1] += 2;
										}
									}
									else
										if (j + 3 <= 14)
											if (map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j + 2] == 0 && map[i + 3][j + 3] == 0)
											{
												score[i + 1][j + 1] += 2;
												score[i - 1][j - 1] += 2;
											}
											else
												if (map[i - 2][j - 2] == -1 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j + 2] == 0 && map[i + 3][j + 3] == 0)
												{
													score[i - 1][j - 1] += 1;
													score[i + 1][j + 1] += 1;
												}
												else
													if (j + 4 <= 14)
														if (map[i - 1][j - 1] == -1 && map[i][j] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j + 2] == 0 && map[i + 3][j + 3] == 0 && map[i + 4][j + 4] == 0)
															score[i + 1][j + 1] += 1;
								}
						if (i >= 3 && i <= 10)
						{
							if (j <= 11)
							{
								if (map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j + 2] == 0 && map[i + 3][j + 3] == 0)
								{
									score[i + 1][j + 1] += 2;
									score[i - 1][j - 1] += 2;
								}
								else
									if (map[i - 2][j - 2] == -1 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j + 2] == 0 && map[i + 3][j + 3] == 0)
									{
										score[i - 1][j - 1] += 1;
										score[i + 1][j + 1] += 1;
									}
									else
										if (map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j + 2] == 0 && map[i + 3][j + 3] == -1)
										{
											score[i - 1][j - 1] += 2;
											score[i + 1][j + 1] += 2;
										}
										else
											if (map[i - 3][j - 3] == 0 && map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j + 2] == -1)
											{
												score[i - 1][j - 1] += 2;
												score[i + 1][j + 1] += 1;
											}
											else
												if (j + 4 <= 14)
													if (map[i - 1][j - 1] == -1 && map[i][j] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j + 2] == 0 && map[i + 3][j + 3] == 0 && map[i + 4][j + 4] == 0)
														score[i + 1][j + 1] += 2;
													
							}
							else
								if (j == 12)
								{
									if (map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j + 2] == 0)
									{
										score[i + 1][j + 1] += 1;
										score[i - 1][j - 1] += 2;
									}
									else
										if (map[i - 3][j - 3] == 0 && map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j + 2] == -1)
										{
											score[i - 1][j - 1] += 1;
											score[i + 1][j + 1] += 1;
										}
											

								}
								else
									if (j == 13)
									{
										if (map[i - 3][j - 3] == 0 && map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 0)
										{
											score[i - 1][j - 1] += 2;
											score[i + 1][j + 1] += 1;
										}
											
									}
						}
						if (i == 11)
						{

							if (j + 3 <= 14)
								if (map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j + 2] == 0 && map[i + 3][j + 3] == 0)
								{
									score[i + 1][j + 1] += 2;
									score[i - 1][j - 1] += 2;
								}
								else
									if (map[i - 2][j - 2] == -1 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j + 2] == 0 && map[i + 3][j + 3] == 0)
									{
										score[i - 1][j - 1] += 1;
										score[i + 1][j + 1] += 1;
									}
									else
										if (map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j + 2] == 0 && map[i + 3][j + 3] == -1)
										{
											score[i - 1][j - 1] += 1;
											score[i + 1][j + 1] += 1;
										}
										else
											if (map[i - 3][j - 3] == 0 && map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j + 2] == -1)
											{
												score[i - 1][j - 1] += 1;
												score[i + 1][j + 1] += 1;
											}
											else
												if (j == 12)
												{
													if (map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j + 2] == 0)
													{
														score[i + 1][j + 1] += 1;
														score[i - 1][j - 1] += 2;
													}
												}
												else
													if (j == 13)
														if (map[i - 3][j - 3] == 0 && map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 0)
														{
															score[i - 1][j - 1] += 1;
															score[i + 1][j + 1] += 1;
														}
						}
						else
							if (i == 12)
							{
								if (j + 3 <= 14)
								{
									if (map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j + 2] == 0)
									{
										score[i + 1][j + 1] += 1;
										score[i - 1][j - 1] += 2;
									}
									else
										if (map[i - 3][j - 3] == 0 && map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j + 2] == -1)
										{
											score[i - 1][j - 1] += 1;
											score[i + 1][j + 1] += 1;
										}
											
								}
								else
									if (j == 12)
									{
										if (map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 0 && map[i + 2][j + 2] == 0)
										{
											score[i + 1][j + 1] += 1;
											score[i - 1][j - 1] += 1;
										}
									}
									else
										if (j == 13)
											if (map[i - 3][j - 3] == 0 && map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 0)
											{
												score[i - 1][j - 1] += 1;
												score[i + 1][j + 1] += 1;
											}
												
							}
							else
								if (i == 13)
									if (j - 3 >= 0)
										if (map[i - 3][j - 3] == 0 && map[i - 2][j - 2] == 0 && map[i - 1][j - 1] == 0 && map[i][j] == 1 && map[i + 1][j + 1] == 0)
										{
											score[i - 1][j - 1] += 1;
											score[i + 1][j + 1] += 1;
										}
											

					}

				if (i + 1 <= 14 && j - 1 >= 0)
					if (map[i][j] == 1)
					{
						if (i == 0)
						{
							if (j - 4 >= 0)
							{
								if (map[i][j] == 1 && map[i + 1][j - 1] == 0 && map[i + 2][j - 2] == 0 && map[i + 3][j - 3] == 0 && map[i + 4][j - 4] == 0)
									score[i + 1][j - 1] += 1;
							}
						}
						else
							if (i == 1)
							{
								if (j - 3 >= 0)
									if (map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 0 && map[i + 2][j - 2] == 0 && map[i + 3][j - 3] == 0)
									{
										score[i + 1][j - 1] += 1;
										score[i - 1][j + 1] += 1;
									}
									else
										if (j - 4 >= 0)
											if (map[i - 1][j + 1] == -1 && map[i][j] == 1 && map[i + 1][j - 1] == 0 && map[i + 2][j - 2] == 0 && map[i + 3][j - 3] == 0 && map[i + 4][j - 4] == 0)
												score[i + 1][j - 1] += 1;
							}
							else
								if (i == 2)
								{
									if (j == 2)
									{
										if (map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 0 && map[i + 2][j - 2] == 0)
										{
											score[i + 1][j - 1] += 2;
											score[i - 1][j + 1] += 3;
										}
									}
									else
										if (j - 3 >= 0)
											if (map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 0 && map[i + 2][j - 2] == 0 && map[i + 3][j - 3] == 0)
											{
												score[i + 1][j - 1] += 3;
												score[i - 1][j + 1] += 3;
											}
											else
												if (map[i - 2][j + 2] == -1 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 0 && map[i + 2][j - 2] == 0 && map[i + 3][j - 3] == 0)
												{
													score[i - 1][j + 1] += 2;
													score[i + 1][j - 1] += 2;
												}
												else
													if (j - 4 >= 0)
														if (map[i - 1][j + 1] == -1 && map[i][j] == 1 && map[i + 1][j - 1] == 0 && map[i + 2][j - 2] == 0 && map[i + 3][j - 3] == 0 && map[i + 4][j - 4] == 0)
															score[i + 1][j - 1] += 2;
								}
						if (i >= 3 && i <= 10)
						{
							if (j >= 3)
							{
								if (map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 0 && map[i + 2][j - 2] == 0)
								{
									score[i + 1][j - 1] += 2;
									score[i - 1][j + 1] += 2;
								}
								else
									if (map[i - 2][j + 2] == -1 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 0 && map[i + 2][j - 2] == 0 && map[i + 3][j - 3] == 0)
									{
										score[i - 1][j + 1] += 2;
										score[i + 1][j - 1] += 2;
									}
									else
										if (map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 0 && map[i + 2][j - 2] == 0 && map[i + 3][j - 3] == -1)
										{
											score[i - 1][j + 1] += 2;
											score[i + 1][j - 1] += 2;
										}
										else
											if (map[i - 3][j + 3] == 0 && map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 0 && map[i + 2][j - 2] == -1)
											{
												score[i - 1][j + 1] += 2;
												score[i + 1][j - 1] += 2;
											}
											else
												if (j - 4 >= 0)
													if (map[i - 1][j + 1] == -1 && map[i][j] == 1 && map[i + 1][j - 1] == 0 && map[i + 2][j - 2] == 0 && map[i + 3][j - 3] == 0 && map[i + 4][j - 4] == 0)
														score[i + 1][j - 1] += 2;
							}
							else
								if (j == 2)
								{
									if (map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 0 && map[i + 2][j - 2] == 0)
									{
										score[i + 1][j - 1] += 2;
										score[i - 1][j + 1] += 3;
									}
									else
										if (map[i - 3][j + 3] == 0 && map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 0 && map[i + 2][j - 2] == -1)
											score[i - 1][j + 1] += 2;

								}
								else
									if (j == 1)
									{
										if (map[i - 3][j + 3] == 0 && map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 1)
											score[i - 1][j + 1] += 2;
									}
						}
						if (i == 3)
						{

							if (j - 3 >= 0)
								if (map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 0 && map[i + 2][j - 2] == 0 && map[i + 3][j - 3] == 0)
								{
									score[i + 1][j - 1] += 3;
									score[i - 1][j + 1] += 3;
								}
								else
									if (map[i - 2][j + 2] == -1 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 0 && map[i + 2][j - 2] == 0 && map[i + 3][j - 3] == 0)
									{
										score[i - 1][j + 1] += 2;
										score[i + 1][j - 1] += 2;
									}
									else
										if (map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 0 && map[i + 2][j - 2] == 0 && map[i + 3][j - 3] == -1)
										{
											score[i - 1][j + 1] += 2;
											score[i + 1][j - 1] += 2;
										}
										else
											if (map[i - 3][j + 3] == 0 && map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 0 && map[i + 2][j - 2] == -1)
											{
												score[i - 1][j + 1] += 2;
												score[i + 1][j - 1] += 2;
											}
											else
												if (j == 2)
												{
													if (map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 0 && map[i + 2][j - 2] == 0)
													{
														score[i + 1][j - 1] += 2;
														score[i - 1][j + 1] += 3;
													}
												}
												else
													if (j == 1)
														if (map[i - 3][j + 3] == 0 && map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 0)
														{
															score[i - 1][j + 1] += 2;
															score[i + 1][j - 1] += 2;
														}
						}
						else
							if (i == 12)
							{
								if (j - 3 >= 0)
								{
									if (map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 0 && map[i + 2][j - 2] == 0)
									{
										score[i + 1][j - 1] += 2;
										score[i - 1][j + 1] += 3;
									}
									else
										if (map[i - 3][j + 3] == 0 && map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 0 && map[i + 2][j - 2] == -1)
											score[i - 1][j + 1] += 2;
								}
								else
									if (j == 2)
									{
										if (map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 0 && map[i + 2][j - 2] == 0)
										{
											score[i + 1][j - 1] += 2;
											score[i - 1][j + 1] += 3;
										}
									}
									else
										if (j == 1)
											if (map[i - 3][j + 3] == 0 && map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 0)
											{
												score[i - 1][j + 1] += 2;
												score[i + 1][j - 1] += 2;
											}			
							}
							else
								if (i == 13)
									if (j + 3 <= 14)
										if (map[i - 3][j + 3] == 0 && map[i - 2][j + 2] == 0 && map[i - 1][j + 1] == 0 && map[i][j] == 1 && map[i + 1][j - 1] == 0)
										{
											score[i - 1][j + 1] += 2;
											score[i + 1][j - 1] += 2;
										}

					}

			}


	printf("\n");
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 15; j++)
		{
			printf("%2d", score[i][j]);
		}
		printf("\n");

	}
	return 0;
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
			else
				if (sum == -5)
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
			else
				if (sum == -5)
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
			else
				if (sum == -5)
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
			else
				if (sum == -5)
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
	int starttime = 0, endtime = 0;
	int x = 7, y = 7, i, j, time = 0, flag = 0, t = 0;
	for (i = 0; i < 15; i++)
		for (j = 0; j < 15; j++)
		{
			map[i][j] = 0;
			map2[i][j] = 0;
			score[i][j] = 0;
		}
	print(true);
	map2[x][y] = 1;
	Sleep(10);
	print(false);
	Sleep(10);
	while (true)
	{
		starttime = clock();
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

				if (AIRobot() == -1)
				{
					printf("\nLose£¡");
					return 0;
				}
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

				if (AIRobot() == -1)
				{
					printf("\nLose£¡");
					return 0;
				}
				flag = 0;
			}
		}


		if (time == 1000)
			print(true);



		if (time == 1001)
			time = 0;

		endtime = clock() - starttime;
		//printf("\n%lf   %lf   %lf", FPS,endtime, FPS - endtime);

		if (FPS - endtime > 0 && endtime > 0)
			Sleep(FPS - endtime);


	}
}

