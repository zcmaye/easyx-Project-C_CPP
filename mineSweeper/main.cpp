#include<window.h>
#include"controller.h"
#pragma comment(lib,"Easyx_Maye.lib")
int main()
{
	Window w(400,400,EW_SHOWCONSOLE);
	w.setWindowTitle("扫雷游戏");

	Controller c;
	c.run();

	return w.exec();
}