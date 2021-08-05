#include"controller.h"
#include<Window.h>
#pragma comment(lib,"Easyx_Maye.lib")
int main()
{
	Window w(475, 475, EW_SHOWCONSOLE);
	w.setWindowTitle("2048游戏");

	Controller c;
	c.run();

	return w.exec();
}