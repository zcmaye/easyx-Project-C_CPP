#pragma once
#include<Configure.h>
#include<vector>
class Map
{
	enum Color //枚举格子颜色
	{
		zero = RGB(205, 193, 180), //0的颜色
		twoTo1 = RGB(238, 228, 218), //2的颜色
		twoTo2 = RGB(237, 224, 200), //4的颜色
		twoTo3 = RGB(242, 177, 121), //8的颜色
		twoTo4 = RGB(245, 149, 99), //16的颜色
		twoTo5 = RGB(246, 124, 95), //32的颜色
		twoTo6 = RGB(246, 94, 59), //64的颜色
		twoTo7 = RGB(242, 177, 121), //128的颜色
		twoTo8 = RGB(237, 204, 97), //256的颜色
		twoTo9 = RGB(255, 0, 128), //512的颜色
		twoTo10 = RGB(145, 0, 72), //1024的颜色
		twoTo11 = RGB(242, 17, 158), //2048的颜色
		back = RGB(187, 173, 160) //背景颜色
	};
	Color colors[12] = { zero,twoTo1,twoTo2,twoTo3,twoTo4,twoTo5,twoTo6,twoTo7,twoTo8,twoTo9,twoTo10,twoTo11 };
public:
	Map();
	void show();

private:
	//随机生成2 或 4 probability生成4的概率
	int  generate2or4(int probability);
private:
	const int m_rows;
	const int m_cols;
	const int m_GRIDW;
	const int m_SPACE;
	std::vector<std::vector<int>> m_map;
};

