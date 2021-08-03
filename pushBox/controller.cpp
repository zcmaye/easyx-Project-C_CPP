#include "controller.h"
#include<conio.h>
Controller::Controller()
	:gamer(m), roll(m,gamer)
{
}

void Controller::run()
{
	loadResource();
	m.setCurMap(3);
	while (true)
	{
		system("cls");
		m.showCur();
		drawMap();

		if (m.isPass())
		{
			roll.clear();
			if (!m.cutNextLevel())
			{				
				settextcolor(RED);
				settextstyle(30, 0, "黑体");
				outtextxy(20, 20, "恭喜你通关了~");
				return;
			}
		}
		char key = _getch();
		switch (key)
		{
		case ' ':
			roll.rollBack();
			break;
		default:
			roll.saveState(key);
			gamer.move(key);			
			break;
		}
	}

}

void Controller::loadResource()
{
	for (size_t i = 0; i < 7; i++)
	{
		std::string path = "./resource/images/"+std::to_string(i)+".bmp";
		m_imgs.push_back(new Image(path));
	}	
}

void Controller::drawMap()
{
	for (size_t i = 0; i < m.row(); i++)
	{
		for (size_t k = 0; k < m.col(); k++)
		{
			int x = k * 64;
			int y = i * 64;
			switch (m.getCurMap()[i][k])
			{
			case SPACE:
				putimage(x, y, m_imgs[0]);
				break;
			case WALL:
				putimage(x, y, m_imgs[1]);
				break;
			case DEST:
				putimage(x, y, m_imgs[2]);
				break;
			case BOX:
				putimage(x, y, m_imgs[3]);
				break;
			case PLAYER:
				putimage(x, y, m_imgs[4]);
				break;
			case BOX + DEST:
				putimage(x, y, m_imgs[5]);
				break;
			case PLAYER + DEST:
				putimage(x, y, m_imgs[6]);
				break;
			}
		}
	}
}


