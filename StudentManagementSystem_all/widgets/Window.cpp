#include "Window.h"
#include<conio.h>
ExMessage Window::s_message;
Window::Window(int w, int h, int flag)
{
	handle = initgraph(w, h, flag);
	setbkmode(TRANSPARENT);
}

Window::~Window()
{
	closegraph();
}

void Window::setWindowTitle(const std::string& title)
{
	SetWindowText(handle, title.c_str());
}

void Window::setWindowColor(COLORREF c)
{
	::setbkcolor(c);
	clear();
}

void Window::setCursor(LPSTR curSorStyle)
{
	IDC_ARROW;
	HCURSOR hcur = LoadCursor(NULL, curSorStyle);
	SetClassLong(GetHWnd(), GCLP_HCURSOR, (long)hcur);
}

int Window::width()
{
	return ::getwidth();
}

int Window::height()
{
	return ::getheight();
}

void Window::clear()
{
	::cleardevice();
}

void Window::beginDraw()
{
	::BeginBatchDraw();
}

void Window::flushDraw()
{
	::FlushBatchDraw();
}

void Window::endDraw()
{
	::EndBatchDraw();
}



