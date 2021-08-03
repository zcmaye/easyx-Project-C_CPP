#pragma once
#include"Configure.h"
#include<conio.h>

/*@setCursor光标样式名字
	IDC_ARROW,   //正常
	IDC_IBEAM,	//工
	IDC_WAIT,    //○
	IDC_CROSS,   //十
	IDC_UPARROW, //↑
	IDC_SIZE,	//????
	IDC_ICON,    //????
	IDC_SIZENWSE,//左上角缩放
	IDC_SIZENESW,//右上角缩放
	IDC_SIZEWE,	//左右
	IDC_SIZENS,	//上下
	IDC_SIZEALL,	//带箭头的十
	IDC_NO		//(X)
*/

class Window
{
public:
	Window(int w, int h,int flag = 0);
	~Window();
	void setWindowTitle(const std::string& title);
	void setWindowColor(COLORREF c);
	void setCursor(LPSTR curSorStyle);
	inline int exec() { system("pause"); return 0; };
public://static
	static int width();
	static int height();
	static void clear();
	static void beginDraw();
	static void flushDraw();
	static void endDraw();

	inline static bool hasMsg() { return peekmessage(&s_message, EM_MOUSE | EM_KEY); }
	inline static const ExMessage& getMsg() { return s_message; }

private:
	HWND handle;	//当前窗口句柄
	static ExMessage s_message;
};

