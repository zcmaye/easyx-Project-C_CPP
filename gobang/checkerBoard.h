#pragma once
#include<BasicWidget.h>
#include<vector>
struct ExMessage;
#include"chessPieces.h"
class CheckerBoard :public BasicWidget
{
public:
	CheckerBoard(int x,int y,int rows = 15,int cols = 15,int gridSize = 25);
	~CheckerBoard();
	void show();
	void eventLoop(const ExMessage&  msg);
	//判断是否连了五子棋
	bool judge();
public:
	const ExMessage* m_msg;

public:	//鼠标操作的坐标和下标
	std::vector<std::vector<ChessPieces>> m_map;
	int whoOp;			//当前是那方在下棋

	const int GRID_W;

	int m_rows;
	int m_cols;

	int opx;
	int opy;
	int opr;
	int opc;
};

