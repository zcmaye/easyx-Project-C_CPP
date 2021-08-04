#pragma once
#include"map.h"
class Controller
{
	enum State { None, Win, Lose };
public:
	Controller();
	void run();

	void mouseEvent();
	void openNull(int row, int col);
	void judge(int row, int col);
private:
	Map m_map;
	
	bool isOver;
	bool isWin;
};

