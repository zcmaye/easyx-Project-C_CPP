#include "controller.h"
#include<conio.h>


Controller::Controller()
	:flag(false)
{

}
void Controller::run()
{
	while (true)
	{
		map.show();
		GameControl();
		GameWin();
	}
}

//向上移动
void Controller::moveup()
{
	/*
	向上移动:遍历每列
	*/
	for (int i = 0; i < map.cols(); i++)
	{
		int temp = 0;
		for (int begin = 1; begin < map.rows(); begin++)
		{
			if (map[begin][i] != 0)
			{
				if (map[temp][i] == 0)
				{
					map[temp][i] = map[begin][i];
					map[begin][i] = 0;
				}
				else if (map[temp][i] == map[begin][i])
				{
					map[temp][i] += map[begin][i];
					map[begin][i] = 0;
					temp++;
				}
				else
				{
					map[temp + 1][i] = map[begin][i];
					if (temp + 1 != begin)//如果temp+1和begn不在同一个位置,就让begin所在的位置的数字置空
					{
						map[begin][i] = 0;
					}
					temp++;
				}
				flag = 1;
			}
		}
	}
}
//向下移动
void Controller::movedown()
{
	for (int i = 0; i < map.cols(); i++)
	{
		int temp = map.rows() - 1;
		for (int begin = map.rows() - 2; begin >= 0; begin--)
		{
			if (map[begin][i] != 0)
			{
				if (map[temp][i] == 0)
				{
					map[temp][i] = map[begin][i];
					map[begin][i] = 0;
				}
				else if (map[temp][i] == map[begin][i])
				{
					map[temp][i] += map[begin][i];
					map[begin][i] = 0;
					temp--;
				}
				else
				{
					map[temp - 1][i] = map[begin][i];
					if ((temp - 1) != begin)
					{
						map[begin][i] = 0;
					}
					temp--;
				}
				flag = 1;
			}
		}
	}
}
//向左移动
void Controller::moveleft()
{
	for (int i = 0; i < map.rows(); i++)
	{
		int temp = 0;
		for (int begin = 1; begin < map.cols(); begin++)
		{
			if (map[i][begin] != 0)
			{
				if (map[i][temp] == 0)
				{
					map[i][temp] = map[i][begin];
					map[i][begin] = 0;;
				}
				else if (map[i][temp] == map[i][begin])
				{
					map[i][temp] += map[i][begin];
					map[i][begin] = 0;
					temp++;
				}
				else
				{
					map[i][temp + 1] = map[i][begin];
					if (temp + 1 != begin)
					{
						map[i][begin] = 0;
					}
					temp++;
				}
				flag = 1;
			}
		}
	}
}
//向右移动
void Controller::moveright()
{
	for (int i = 0; i < map.rows(); i++)
	{
		int temp = map.cols() - 1;
		for (int begin = map.cols() - 2; begin >= 0; begin--)
		{
			if (map[i][begin] != 0)
			{
				if (map[i][temp] == 0)
				{
					map[i][temp] = map[i][begin];
					map[i][begin] = 0;
				}
				else if (map[i][temp] == map[i][begin])
				{
					map[i][temp] += map[i][begin];
					map[i][begin] = 0;
					temp--;
				}
				else
				{
					map[i][temp - 1] = map[i][begin];
					if (temp - 1 != begin)
					{
						map[i][begin] = 0;
					}
					temp--;
				}
				flag = 1;
			}
		}
	}
}
void Controller::GameControl()
{
	switch (_getch())
	{
	case 72:
	case 'w':
	case 'W':
		moveup();
		break;
	case 80:
	case 's':
	case 'S':
		movedown();
		break;
	case 75:
	case 'a':
	case 'A':
		moveleft();
		break;
	case 77:
	case 'd':
	case 'D':
		moveright();
		break;
	default:
		break;
	}
	if (flag == 1)
	{
		map.generateNumber();
		flag = 0;
	}
	//userkey = 0;
}
void Controller::GameWin()
{
	for (int i = 0; i < map.rows(); i++)
	{
		for (int k = 0; k < map.cols(); k++)
		{
			if (map[i][k] == 2048)
			{
				HWND hnd = GetHWnd();
				int isok = MessageBox(hnd, "你赢了", "提示", MB_OKCANCEL);
				if (isok == IDOK)
				{
					//GameInit();
				}
				else
				{
					exit(666);
				}
			}
		}
	}
}