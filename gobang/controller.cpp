#include "controller.h"
#include<Window.h>
#include<easyx.h>
Controller::Controller()
	:checkerBoard(75,75)
{
	m_bk = Image("./resource/images/bk.jpg");
}
void Controller::run()
{

	Window::beginDraw();
	while (true)
	{
		m_bk.draw();
		checkerBoard.show();
		Window::flushDraw();

		if (Window::hasMsg())
		{
			static ExMessage msg;
			msg = Window::getMsg();
			if (checkerBoard.judge())
			{
				char str[50] = { 0 };
				wsprintf(str, "%s с╝ак", checkerBoard.whoOp == ChessPieces::Black ? "white" : "Black");
				MessageBox(GetHWnd(), str, "hit", MB_OK);
				exit(66);
			}
			checkerBoard.eventLoop(msg);
		}
		Window::flushDraw();
	}
	Window::endDraw();
}