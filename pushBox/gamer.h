#pragma once
#include"map.h"
class Gamer
{
public:
	Gamer(Map<>& map);
	//更新玩家位置
	void updatePos();
	//移动玩家
	void move(char key);
	//玩家下标
	int row()const;
	int col()const;
	char dir()const;
private:
	Map<>* m_map;
	int m_row;	//玩家当前下标
	int m_col;
	char m_dir;	//保存刚才移动的方向
};

