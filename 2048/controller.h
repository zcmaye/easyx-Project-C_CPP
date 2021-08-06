#pragma once
#include"map.h"
class Controller
{
public:
	Controller();
	void run();
	void moveup();
	void movedown();
	void moveleft();
	void moveright();
	void GameControl();
	void GameWin();
private:
	Map map;
	bool flag;
};

