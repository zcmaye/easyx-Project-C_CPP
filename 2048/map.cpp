#include "map.h"
#include<randomGenerator.h>

Map::Map():m_rows(4),m_cols(4), m_GRIDW(100),m_SPACE(15)
			,m_map(m_rows)
{
	for (int i = 0; i < m_rows; i++)
	{
		for (int k = 0; k < m_cols; k++)
		{
			m_map[i].push_back(0);
		}
	}
	//开始随机生成两个数
	generateNumber();
	generateNumber();

	//设置背景颜色
	setbkcolor(Color::back);
	cleardevice();
}


void Map::show()
{
	//初始化格子颜色
	for (int i = 0; i < m_rows; i++)
	{
		for (int k = 0; k < m_cols; k++)
		{
			printf("%d ", m_map[i][k]);
			//求出每个格子左上角的坐标
			int x = k * m_GRIDW + (k + 1) * m_SPACE;
			int y = i * m_GRIDW + (i + 1) * m_SPACE;
			int index = (int)log2(m_map[i][k]);//求以2为底的x的对数(求出每个数对应的,颜色的下标)
			DWORD tempcolor = colors[index];
			setfillcolor(tempcolor);
			setlinecolor(tempcolor);
			//fillrectangle(x, y, x + GRID_WIDTH, y + GRID_WIDTH);
			fillroundrect(x, y, x + m_GRIDW, y + m_GRIDW, 10, 10);
			if (m_map[i][k] != 0)//把当前数字,显示到窗口上
			{
				setbkmode(TRANSPARENT);
				settextstyle(50, 0, "黑体");
				settextcolor(RGB(119, 110, 101));
				char number[5] = " ";
				sprintf_s(number, "%d", m_map[i][k]);
				int temp = textwidth(number);//获取字符
				temp = m_GRIDW / 2 - temp / 2;//计算第一个字开始的位置
				outtextxy(x + temp, y + 25, number);
			}
		}
		printf("\n");
	}
}

int Map::rows()
{
	return m_rows;
}

int Map::cols()
{
	return m_cols;
}

std::vector<int>& Map::operator[](int index)
{
	return m_map[index];
}

void Map::generateNumber()
{
	while (true)
	{
		int r = RandomGenerator::global()->bounded(m_rows);
		int c = RandomGenerator::global()->bounded(m_cols);
		if (m_map[r][c] == 0)
		{
			m_map[r][c] = generate2or4(5);	//五分之一的概率生成4
			break;
		}
	}
}

int Map::generate2or4(int probability)
{
	if (RandomGenerator::global()->bounded(probability) == 0)
	{
		return 4;
	}
	return 2;
}
