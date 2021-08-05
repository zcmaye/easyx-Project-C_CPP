#include "..\2048\map.h"
#include "map.h"
#include<iostream>
#include<functional>
Map::Map(int rows, int cols)
	:m_rows(rows),m_cols(cols),
	m_map(new int* [rows])
{
	for (int i = 0; i < m_rows; i++)
	{
		m_map[i] = new int[m_cols] {0};
	}
	init();

	loadResource();


	//std::unique_ptr<int* [], void(*)(int* [])> up(new int* [], [](int*[]) {});
	//std::unique_ptr<int*, void(*)(int**)> up(new int*[rows], [](int** p) {});
	//std::unique_ptr<int*, std::function<void(int**)>> up(new int* [rows], [](int** p) {});
}

Map::Map()
{
}

void Map::show()
{
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			std::cout << m_map[i][k] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Map::draw()
{
	for (int i = 0; i < m_rows; i++)
	{
		for (int k = 0; k < m_cols; k++)
		{
			if (m_map[i][k] >= 0 && m_map[i][k] <= 8)
			{
				putimage(k * 40, i * 40, m_imgs[m_map[i][k]]);
			}
			else if (m_map[i][k] == -1)
			{
				putimage(k * 40, i * 40, m_imgs[9]);
			}
			else if (m_map[i][k] >= 19 && m_map[i][k] <= 28)
			{
				putimage(k * 40, i * 40, m_imgs[10]);
			}
			else if (m_map[i][k] > 28)
			{
				putimage(k * 40, i * 40, m_imgs[11]);
			}
		}
	}
}

void Map::loadResource()
{
	for (int i = 0; i < 12; i++)
	{
		std::string imgPath = "./resource/images/" + std::to_string(i) + ".jpg";
		m_imgs.push_back(new Image(imgPath,40,40));
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

void Map::init()
{
	for (size_t i = 0; i < m_rows; i++)
	{
		for (int k = 0; k < m_cols; k++)
		{
			m_map[i][k] = 0;
		}
	}
	//给数组里面随机埋雷 雷用-1表示 只要10个
	for (int i = 0; i < 10; )
	{
		int r = rand() % m_rows;
		int c = rand() % m_cols;
		if (m_map[r][c] == 0)
		{
			m_map[r][c] = -1;
			i++;			//只有成功设置了一个雷，i才会自增
		}
	}

	//雷周围的九宫格数字都加1（雷自己除外 -1）
	for (int i = 0; i < m_rows; i++)
	{
		for (int k = 0; k < m_cols; k++)
		{
			//找到每一个雷
			if (m_map[i][k] == -1)
			{
				//遍历雷周围的九宫格
				for (int r = i - 1; r <= i + 1; r++)
				{
					for (int c = k - 1; c <= k + 1; c++)
					{
						if ((r >= 0 && r < m_rows && c >= 0 && c < m_cols) && m_map[r][c] != -1)
						{
							m_map[r][c] ++;
						}
					}
				}

			}
		}
	}

	//加密格子
	for (int i = 0; i < m_rows; i++)
	{
		for (int k = 0; k < m_cols; k++)
		{
			m_map[i][k] += 20;
		}
	}
}

int* Map::operator[](int index)
{
	return m_map[index];
}
