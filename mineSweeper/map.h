#pragma once
#include<memory>
#include<vector>
#include<Image.h>
class Map
{
public:
	Map(int rows, int cols);
	void show();
	void init();
	void draw();
	void loadResource();

	int rows();
	int cols();

	//std::unique_ptr<int* []>& getMap() { return m_map; }
	//operator std::unique_ptr<int* []>& () { return m_map;}
	int* operator[](int index);
private:
	std::unique_ptr<int*[]> m_map;
	std::vector<Image*> m_imgs;

	int m_rows;
	int m_cols;
};

