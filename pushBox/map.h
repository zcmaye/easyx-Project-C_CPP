#pragma once
#include<string>
#include<vector>
#include<iostream>
#include<fstream>
//using namespace std;
enum MAP
{
	SPACE = 0,	//空地
	WALL = 1,	//墙
	DEST = 2,	//目的地
	BOX = 3,	//箱子
	PLAYER = 6	//玩家
};
template<size_t ROW = 10,size_t COL = 10>
class Map
{
	using Pointer = int(*)[COL];		//二维数组指针类型
	using MapArr = int[ROW][COL];		//二维数组

public:
	Map(const std::string& fileName = "./resource/map.txt") :m_curLevel(0)
	{
		readFile(fileName);
	}
	void showCur()
	{
		if (m_map.empty())
		{
			return;
		}
		for (int i = 0; i < ROW; i++)
		{
			for (int k = 0; k < COL; k++)
			{
				std::cout << m_map[m_curLevel][i][k] << " ";
			}
			std::cout << std::endl;
		}
	}
	void showAll()
	{
		if (m_map.empty())
		{
			return;
		}
		for (size_t le = 0; le < m_map.size(); le++)
		{
			std::cout << "le:" << le << std::endl;
			for (int i = 0; i < ROW; i++)
			{
				for (int k = 0; k < COL; k++)
				{
					std::cout << m_map[le][i][k] << " ";
				}
				std::cout << std::endl;
			}
		}
	}
	//获取当前地图
	Pointer getCurMap()
	{
		return m_map[m_curLevel];
	}
	Pointer operator[](int index)
	{
		if (index >= m_map.size())
		{
			return m_map.back();
		}
		return m_map[m_curLevel];
	}
	//是否过关
	bool isPass()
	{
		for (int i = 0; i < ROW; i++)
		{
			for (int k = 0; k < COL; k++)
			{
				if (m_map[m_curLevel][i][k] == BOX)
				{
					return false;
				}
			}
		}
		return true;
	}
	//切换到下一关，切换成功返会true 否则返回false
	bool cutNextLevel()
	{
		if (m_curLevel < m_map.size()-1)
		{
			++m_curLevel;
			return true;
		}
		return false;
	}
	//设置当前管卡
	void setCurMap(size_t level)
	{
		if (level >= m_map.size())
		{
			return;
		}
		else
		{
			m_curLevel = level;
		}
	}
	size_t row()
	{
		return ROW;
	}
	size_t col()
	{
		return COL;
	}
protected:
	void readFile(const std::string& fileName)
	{
		std::fstream read(fileName, std::ios::in);
		if (!read.is_open())
		{
			std::cout << "map file open failed~" << std::endl;
			exit(-1);
		}

		while (!read.eof())
		{
			char buf[50] = { 0 };
			//读取关卡信息，并丢掉
			read.getline(buf, 50);

			Pointer tmap = new MapArr{ 0 };
			//读Row行数据
			for(size_t row = 0;row<ROW;row++)
			{
				memset(buf, 0, sizeof(buf));
				read.getline(buf, 50);

				//遍历获取到的一行数据，如果是整数,就把数据写到数组中
				int col = 0;
				for (size_t i = 0; i < strlen(buf); i++)
				{
					//是十进制字符
					if (isdigit(buf[i]))
					{
						//把字符转成整数
						tmap[row][col++] = buf[i] - '0';	
					}
				}				
			}
			m_map.push_back(tmap);
		}

		read.close();
	}
private:
	/*
	一维数组：int map[10]			指针：int*p=map;
	二维数组：int map[10][10]		指针：int (*p)[m_col] = map;
	三维数组：int map[3][10][10]		指针：int (*p)[m_row][m_row]=map;	
	*/
	std::vector<Pointer> m_map;
	int m_curLevel;			//当前关卡
};

