#include"controller.h"
#include<Window.h>
#pragma comment(lib,"Easyx_Maye.lib")
int main()
{
	Window w(640,640,EW_SHOWCONSOLE);

	Controller c;
	c.run();


	return w.exec();
}