#pragma once
#include"map.h"
#include"gamer.h"
#include"rollback.h"
#include<Image.h>
class Controller
{
public:
	Controller();
	void run();
	void loadResource();
	void drawMap();
private:
	Map<> m;
	int level;
	std::vector<Image*> m_imgs;

	Gamer gamer;
	Rollback roll;

};

