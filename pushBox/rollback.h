#pragma once
#include<stack>
#include"map.h"
#include"gamer.h"
class Rollback
{
public:
	Rollback(Map<>& map,Gamer& gamer);
	//一步一步回退
	void rollBack();
	//保存上一步的状态
	void saveState(char key);
	//清空所有状态
	void clear();
private:
	struct Point
	{
		int r;		
		int c;
		int data;
	};
	struct State
	{
		struct Point pos[3];
	};
	std::stack<State> s;
	Map<>& map;
	Gamer& gamer;
};

