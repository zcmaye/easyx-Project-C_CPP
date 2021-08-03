#include"Window.h"
#include"Image.h"
#include"pushButton.h"
#include"LineEdit.h"

int main()
{
	Window w(640, 480,EW_SHOWCONSOLE);
	w.setCursor(IDC_CROSS);
	w.setWindowTitle("Maye Easyx");
	w.setWindowColor(RGB(194, 195, 201));


	setbkmode(TRANSPARENT);

	LineEdit edit(100,100,200,30);

	Window::beginDraw();
	while (true)
	{		
		Window::clear();
		edit.updateText();
		edit.show();

		std::cout << edit.text() << std::endl;
		Window::flushDraw();
	}


	return w.exec();
}