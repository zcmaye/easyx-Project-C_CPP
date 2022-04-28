#pragma once
#include"BasicWidget.h"
#include<thread>
#pragma comment(lib,"Imm32.lib")
class LineEdit:public BasicWidget
{
public:
	LineEdit(int x = 0, int y = 0, int w = 100, int h = 30);
	void show();

	void eventLoop(const ExMessage& msg);

	//弹出数据输入框
	void popInputBox();
	void setInputBoxTitle(const std::string& title);
	std::string text();
	void clear();
	//文本是否改变了
	bool textChanged();
private:
	std::string m_pretext;	//上一次的文字
	std::string m_text;		//行编辑器中的文字
	int textw;

	std::string m_title;	//行编辑器弹出窗标题

	bool m_isPopUp;	//是否弹出
};

