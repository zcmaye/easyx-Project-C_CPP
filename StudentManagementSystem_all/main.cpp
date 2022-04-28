#include"ManageMent_gui.h"
#include"widgets/Window.h"
#include"widgets/Table.h"
#include"widgets/Timer.h"
int main()
{
	Window w(960, 640, EW_SHOWCONSOLE | EW_NOCLOSE);
	w.setWindowTitle("学生成绩管理系统");

	ManageMent m;
	m.run();

	return w.exec();
}