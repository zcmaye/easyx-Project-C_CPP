#include "Table.h"
#include<iostream>
using namespace std;
Table::Table(int row, int col) 
	:m_rows(row), m_cols(col),  m_curPage(0), m_maxPage(0)
	,BasicWidget(0,0,0,0)
{
	m_prevPageBtn.setText("上一页");
	m_nextPageBtn.setText("下一页");
	m_beginPageBtn.setText("第一页");
	m_endPageBtn.setText("结尾页");

}

void Table::setRowCount(int row)
{
	m_rows = row;
}

void Table::setColCount(int col)
{
	m_cols = col;
}


void Table::setHeader(const std::string& data)
{
	m_header = data;
	m_cols = std::count(m_header.begin(), m_header.end(), '\t') - 1;


	int textw = ::textwidth("计算机1401");
	int texth = ::textheight(m_header.c_str());

	m_gridw = textw + 15;
	m_gridh = texth + 10;

	//设置从父类继承过来的宽度和高度
	m_h = m_rows * m_gridh;
	m_w = m_cols* m_gridw;
}

void Table::insert(const std::string& data)
{
	m_datas.push_back(data);
	updateData();
}

void Table::clear()
{
	m_datas.clear();
	updateData();
}

void Table::eventLoop(const ExMessage& msg)
{
	m_prevPageBtn.eventLoop(msg);
	m_nextPageBtn.eventLoop(msg);
	m_beginPageBtn.eventLoop(msg);
	m_endPageBtn.eventLoop(msg);

	if (m_prevPageBtn.isClicked())
	{
		//cout << "m_prevPageBtn" << endl;
		if (m_curPage != 0)
		{
			m_curPage--;
		}
		//cout << "m_extraData:" << m_extraData << endl;
	}
	if (m_nextPageBtn.isClicked())
	{
		//cout << "m_nextPageBtn" << endl;
		if (m_curPage != m_maxPage)
		{
			m_curPage++;
		}
	}
	if (m_beginPageBtn.isClicked())
	{
		m_curPage = 0;
		//cout << "m_beginPageBtn" << endl;
	}
	if (m_endPageBtn.isClicked())
	{
		m_curPage = m_maxPage;
		//cout << "m_endPageBtn" << endl;
	}
	//cout << "m_curPage:" << m_curPage << "/" << m_maxPage << endl;
}

void Table::drawTableGrid()
{
	if (m_rows == 0)
	{
		m_rows = m_datas.size();
	}
	drawHeader();
	setlinestyle(PS_SOLID, 1);
	//表格横线
	for (size_t i = 0; i < m_rows + 1; i++)
	{
		//m_x + m_cols * textw 表格的总宽度
		int resy = m_y + m_gridh * i;
		line(m_x, resy, m_x + m_cols * m_gridw, resy);
	}
	//表格竖线
	for (size_t k = 0; k < m_cols+1; k++)
	{
		line(m_x + k * m_gridw, m_y, m_x + k * m_gridw, m_y + m_gridh * m_rows);
	}

	if (m_maxPage > 0)
	{
		initPageBtnPos();
	}
}

void Table::drawTableText()
{
	//防止越界
	if (m_rows > m_datas.size() &&m_datas.size()!=0)
	{
		m_rows = m_datas.size();
	}

	int begPos = m_curPage * m_rows;			//当前页数*每页行数，获取当前页在m_datas中的数据下标
	int endPos = m_rows + m_curPage * m_rows;	//上面的数据加上 每行的行数，获取一页的数据
	//如果是最后一页，只遍历余下的数据
	if (m_curPage == m_maxPage)
	{
		endPos = begPos + m_extraData;
	}
	//如果没有数据，不输出
	if (m_datas.size() == 0)
	{
		endPos = 0;
	}

	for (int beg = begPos,i =0; beg < endPos; beg++,i++)
	{
		std::vector<std::string> line_data = split(m_datas[beg]);

		for (size_t k = 0; k < line_data.size(); k++)
		{
			int tx = m_x + k * m_gridw;
			int ty = m_y + i * m_gridh;
			BasicWidget::show();
			outtextxy(tx,ty+5, line_data[k].c_str());
		}	
	}
}

void Table::drawHeader()
{
	//绘制表头表格
	setlinestyle(PS_SOLID, 2);
	rectangle(m_x, m_y - 30, m_x + m_gridw * m_cols, m_y);
	for (size_t i = 0; i < m_cols + 1; i++)
	{
		line(m_x + i * m_gridw, m_y - 30, m_x + i * m_gridw, m_y);
	}
	//绘制表头数据
	std::vector<std::string> header = split(m_header);
	for (auto it = header.begin(); it != header.end();)
	{
		if (it->empty())
		{
			it = header.erase(it);
		}
		else
		{
			it++;
		}
	}
	int space = 0;
	for (size_t i = 0; i < header.size(); i++)
	{
		space = (m_gridw - textwidth(header[i].c_str())) / 2;	//居中显示表头，计算两边的间隔
		outtextxy(m_x + i * m_gridw + space, m_y - m_gridh+5, header[i].c_str());
	}
}

void Table::updateData()
{
	//计算最大页数
	if (m_rows >= m_datas.size())
	{
		m_maxPage = 0;
		m_extraData = m_datas.size();
	}
	else
	{	
		m_extraData = m_datas.size() % m_rows;	//计算余下多少条数据
		m_maxPage = m_datas.size() / m_rows;	
	}
}

void Table::initPageBtnPos()
{
	m_prevPageBtn.move(m_x, m_y + m_gridh * m_rows + 20);
	m_nextPageBtn.move(m_x + 100, m_y + m_gridh * m_rows + 20);
	m_beginPageBtn.move(m_x + 200, m_y + m_gridh * m_rows + 20);
	m_endPageBtn.move(m_x + 300, m_y + m_gridh * m_rows + 20);

	m_prevPageBtn.show();
	m_nextPageBtn.show();
	m_beginPageBtn.show();
	m_endPageBtn.show();

	std::string pageInfo("共" + std::to_string(m_maxPage + 1) + "页,第" + std::to_string(m_curPage + 1) + "页");
	outtextxy(m_x + 450, m_y + m_gridh * m_rows + 20, pageInfo.c_str());
}

std::vector<std::string> Table::split(std::string str,char  separator)
{
	std::vector<std::string> res;
	for (size_t pos = 0; pos != std::string::npos ; )
	{
		if (pos != 0)
			pos++;
		//以指定的字符分隔
		pos = str.find(separator);
		//保存分隔出来的字符串
		res.push_back(str.substr(0, pos));
		//剩下未分隔的字符串
		str = std::string(str.data() + pos+1);	
	}	
	return res;
}

void Table::show()
{
	BasicWidget::show();
	drawTableGrid();
	drawTableText();
}

