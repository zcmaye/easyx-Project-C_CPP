#pragma once
#include"BasicWidget.h"
#include"pushButton.h"
#include<vector>
class Table :public BasicWidget
{
public:
	Table(int row = 1, int col = 0);
	void setRowCount(int row);
	void setColCount(int col);

	//插入以\t分隔的字符串数据
	void setHeader(const std::string& data);
	void insert(const std::string& data);
	void clear();

	void eventLoop(const ExMessage& msg);


	void show();
	std::vector<std::string> split(std::string str, char  separator = '\t');
private:
	void drawTableGrid();
	void drawTableText();
	void drawHeader();
	void updateData();		//更新数据
	
	//初始化换页按钮位置
	void initPageBtnPos();

private:
	size_t m_rows;
	size_t m_cols;

	int m_gridw;
	int m_gridh;

	std::string m_header;
	std::vector<std::string> m_datas;
private:	//换页处理
	int m_curPage;	//当前页
	int m_maxPage;	//总页数
	int m_extraData;	//如果不是整数页，那么保存一下最后一页有多少条数据

	PushButton m_prevPageBtn;		//上一页
	PushButton m_nextPageBtn;		//下一页
	PushButton m_beginPageBtn;		//第一页
	PushButton m_endPageBtn;		//末尾页
};

