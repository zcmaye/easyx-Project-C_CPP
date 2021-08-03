/*pushButton 按钮类*/
#ifndef __PUSHBUTTON_H_
#define __PUSHBUTTON_H_
#include"Configure.h"
#include"image.h"
#include"BasicWidget.h"

class PushButton:public BasicWidget
{
public:
	PushButton(std::string text ="PushButton",int x=0,int y=0,int w =100,int h = 30);
	void show();
	
	void setText(std::string text);
	void setBackgroundImage(std::string imgPath);
	void setBackgroundColor(Color color);

	void setHover(COLORREF c);
	void setHover(std::string imgPath);
	//事件循环
	void eventLoop(const ExMessage&);

	//鼠标是否在按钮上面
	bool isin();
	//鼠标是否点击了按钮
	bool isClicked();
	

	~PushButton();

public:
	std::string text;
	bool  isshow = false;			//显示状态
	ExMessage _msg;					//鼠标消息
public:	//current
	Image* cur_img = nullptr;
	COLORREF cur_color = RGB(232, 232, 236);

public:	//normal
	Image* nor_img = nullptr;
	COLORREF nor_color = RGB(232, 232, 236);

public:	//hover
	Image* h_img = nullptr;
	COLORREF h_color = RGB(194, 195, 201);
};
#endif