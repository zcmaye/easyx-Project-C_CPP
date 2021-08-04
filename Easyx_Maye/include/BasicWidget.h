#pragma once
#include"Configure.h"
#include"commonutils/Color.h"
class BasicWidget
{
public:
	BasicWidget(int x, int y, int w, int h);
	int width() const;
	int height()const;
	void setFixedSize(int w, int h);

	int x()const;
	int y()const;
	void move(int x, int y);
	
	//未实现
	void setBackgroundColor(const Color& color);
	Color BackgroundColor();

	void setFont(const Font& font);
	const Font& font();
	virtual void show();
protected:
	int m_x;
	int m_y;
	int m_w;
	int m_h;

	Color m_bkColor;	//背景颜色
	Font m_font;		//字体
};

