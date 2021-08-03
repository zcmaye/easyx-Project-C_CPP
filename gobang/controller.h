#pragma once
#include<Image.h>
#include"checkerBoard.h"
class Controller
{
public:
	Controller();
	void run();

private:
	Image m_bk;

	CheckerBoard checkerBoard;
};

