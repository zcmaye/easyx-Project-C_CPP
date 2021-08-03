#include<Window.h>
#include"controller.h"
#pragma comment(lib,"Easyx_Maye.lib")

int main()
{
	Window w(600, 500,EW_SHOWCONSOLE);
	Controller c;
	c.run();

	return w.exec();
}