#include "controller.h"
#include<Window.h>

Controller::Controller()
	:m_map(10,10),
	isOver(false),isWin(false)
{

}
void Controller::run()
{
	while (true)
	{
		mouseEvent();
		m_map.draw(); 	
		if (isOver || isWin)
		{
			char text[50] = { 0 };
			if (isOver)
			{
				strcpy_s(text, "你点到了雷，是否再来一把？");
			}
			else
			{
				strcpy_s(text, "你过关了，是否再来一把？");
			}
			//询问用户是否再来一把
			int ret = MessageBox(GetHWnd(), text, "提示", MB_OKCANCEL);
			if (ret == IDOK)
			{
				m_map.init();
				isOver = false;
				isWin = false;
			}
			else
			{
				exit(0);
			}
		}
	}
}

void Controller::mouseEvent()
{
	if (Window::hasMsg())
	{
		const ExMessage& msg = Window::getMsg();
		//鼠标msg 里面有x，y但是没有行和列，自己求一下
		int r = msg.y / 40;
		int c = msg.x / 40;
		//鼠标左键点击打开对应的格子,让数组元素-20
		if (msg.message == WM_LBUTTONDOWN)
		{
			if (m_map[r][c] >= 19 && m_map[r][c] <= 28)
			{
				m_map[r][c] -= 20;
				openNull(r, c);
				judge(r, c);
				//showMap(m_map);
			}
		}
		//鼠标右键标记格子
		else if (msg.message == WM_RBUTTONDOWN)
		{
			if (m_map[r][c] >= 19 && m_map[r][c] <= 28)	//如果没有打开，也没有标记，就标记一下
			{
				m_map[r][c] += 20;
				//showMap(m_map);
			}
			else if (m_map[r][c] > 28)	//已经标记过了，取消标记
			{
				m_map[r][c] -= 20;
			}
		}
	}
}

void Controller::openNull(int row, int col)
{
	if (m_map[row][col] == 0)
	{
		for (int i = row - 1; i <= row + 1; i++)
		{
			for (int k = col - 1; k <= col + 1; k++)
			{
				//如果周围的格子没有被打开，就打开
				if ((i >= 0 && i < m_map.rows() && k >= 0 && k < m_map.cols()) && m_map[i][k] > 19 && m_map[i][k] <= 28)
				{
					m_map[i][k] -= 20;
					openNull(i, k);
				}
			}
		}
	}
}

void Controller::judge(int row, int col)
{
	//点到了雷，游戏结束（输了）
	if (m_map[row][col] == -1)
	{
		for (int i = 0; i < m_map.rows(); i++)
		{
			for (int k = 0; k < m_map.cols(); k++)
			{
				//打开未标记，但没有打开的雷
				if (m_map[i][k] == 19)
				{
					m_map[i][k] -= 20;
				}
				//标记了的雷
				else if (m_map[i][k] == 39)
				{
					m_map[i][k] -= 40;
				}
			}
		}
		isOver = true;
		return;
	}
	//赢了，应该点开的格子都点开了，就赢了
	static int cnt = 0;
	for (int i = 0; i < m_map.rows(); i++)
	{
		for (int k = 0; k < m_map.cols(); k++)
		{
			if (m_map[i][k] >= 0 && m_map[i][k] <= 8)
			{
				cnt++;
			}
		}
	}

	if (cnt == m_map.rows() * m_map.cols() - 10)
	{
		isWin = true;
	}
	cnt = 0;
}