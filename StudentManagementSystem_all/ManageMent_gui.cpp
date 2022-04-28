#include "ManageMent_gui.h"
#include<sstream>
#include<fstream>
#include<string>
#include<iostream>
#include<algorithm>
#include"widgets/Window.h"
#include<conio.h>
#include"widgets/Timer.h"
#include<sstream>

using namespace std;

ManageMent::ManageMent():m_key(0)
{
	readData("./resource/student.txt");

	m_bk = Image("./images/bk.png",Window::width(),Window::height());
	
	menu_btns.push_back(new PushButton("查看学生"));
	menu_btns.push_back(new PushButton("添加学生"));
	menu_btns.push_back(new PushButton("删除学生"));
	menu_btns.push_back(new PushButton("修改学生"));
	menu_btns.push_back(new PushButton("查找学生"));
	menu_btns.push_back(new PushButton("退出系统"));
	for (int i = 0; i < menu_btns.size(); i++)
	{
		menu_btns[i]->setFixedSize(250, 50);
		menu_btns[i]->setHover(RED);

		int x = (Window::width() - menu_btns[i]->width()) / 2;
		int topMargin = (Window::height() - menu_btns.size() * menu_btns[0]->height()) / 2;
		int y = topMargin + i * menu_btns[i]->height();
		menu_btns[i]->move(x,y);
	}

	m_insertTable.setHeader(tableHeader);
	m_insertTable.move((Window::width()-m_insertTable.width())/2, 50);
	m_insertTable.setRowCount(16);
	for (auto val : vec_stu)
	{
		m_insertTable.insert(val.formatInfo());
	}
	Font font = m_insertTable.font();
	font.setItalic(false);
	m_insertTable.setFont(font);


	m_insertEdit.setFixedSize(400, 30);
	m_insertEdit.move((Window::width() - m_insertEdit.width()) / 2, (Window::height() - m_insertEdit.height()) / 2);
	m_insertBtn.setFixedSize(50, 30);
	m_insertBtn.move(m_insertEdit.x() + m_insertEdit.width()+20, m_insertEdit.y());
	m_insertBtn.setText("确定");

	//查找页面
	searchEdit = new LineEdit(0,0,200,30);
	searchIdBtn = new PushButton("按学号查找",0,0,200,30);
	searchNameBtn = new PushButton("按姓名查找", 0, 0, 200, 30);
	searchTable = new Table;
	searchTable->setRowCount(6);
	searchTable->setHeader(tableHeader);

	font = searchTable->font();
	font.setItalic(true);
	font.setHeight(20);
	searchTable->setFont(font);



	searchIdBtn->move((Window::width() - searchIdBtn->width()) / 2, Window::height() / 4);
	searchNameBtn->move((Window::width() - searchNameBtn->width()) / 2, Window::height() / 4 + searchNameBtn->height());
	searchEdit->move((Window::width() - searchEdit->width()) / 2, Window::height() / 3);
	searchTable->move((Window::width() - searchTable->width()) / 2, Window::height() / 3 + 100);

	//修改页面
	m_modifyEdit = new LineEdit(0, 0, 200, 30);
	m_modifyEdit->move((Window::width() - m_modifyEdit->width()) / 2, Window::height() / 3);
	int width = 120;	//修改页表格宽度
	int w = width * 6;
	int vspace = (Window::width() - w) / 2;
	for (int i = 0; i < 6; i++)
	{
		m_stuEdits.push_back(new LineEdit(vspace+ i* width, m_modifyEdit->y()+120, width, 30));
		m_stuEdits[i]->setCursorHide(true);	//隐藏光标
	}
	m_stuEdits[0]->setInputBoxTitle("请输入学号");
	m_stuEdits[1]->setInputBoxTitle("请输入姓名");
	m_stuEdits[2]->setInputBoxTitle("请输入班级");
	m_stuEdits[3]->setInputBoxTitle("请输入数学成绩");
	m_stuEdits[4]->setInputBoxTitle("请输入语文成绩");
	m_stuEdits[5]->setInputBoxTitle("请输入英语成绩");

	//删除页面
	delEdit = new LineEdit(0, 0, 200, 30);;
	delBtn = new PushButton("删除", 0, 0, 200, 30);
	delTable = new Table;
	delTable->setRowCount(6);
	delTable->setHeader(tableHeader);
	delEdit->setInputBoxTitle("请输入学生学号");

	delEdit->move((Window::width() - (delEdit->width()*2+20)) / 2, Window::height() / 3);
	delBtn->move(delEdit->x() + delEdit->width()+20, Window::height() / 3);
	delTable->move((Window::width() - delTable->width()) / 2, Window::height() / 3 + 100);

}

void ManageMent::run()
{
	Window::beginDraw();
	while (true)
	{		
		//printf("----------\n");
		Window::clear();
		drawBackground();

		if (Window::hasMsg())
		{
			m_msg = Window::getMsg();
			switch (m_msg.message)
			{
			case WM_KEYDOWN:		//按键消息
				switch (m_msg.vkcode)
				{
				case VK_ESCAPE:		//ESC
					opt = 66;
					break;
				}
				break;
			default:				//其他的都是鼠标消息了
				this->eventLoop();
				break;
			}
		}


		switch (opt)
		{
		case 66:
			opt = mainMenu(m_msg);
			break;
		case ManageMent::ShowAll:
			displayAll();
			break;
		case ManageMent::Insert:
			insert();
			break;
		case ManageMent::Erase:
			erase();
			break;
		case ManageMent::Modify:
			modify();
			break;
		case ManageMent::Find:
			find();
			break;
		case ManageMent::Exit:
			writeData("./resource/student.txt");
			exit(666);
			break;
		default:
			break;
		}	
		Window::flushDraw();
	}
	Window::endDraw();
}

void ManageMent::menu()
{
	for (int i = 0; i < menu_btns.size(); i++)
	{
		menu_btns[i]->show();
	}
}

void ManageMent::eventLoop()
{
	if (opt == ShowAll)
	{
		m_insertTable.eventLoop(m_msg);
	}
	else if (opt == Insert)
	{
		
		m_insertBtn.eventLoop(m_msg);
		m_insertEdit.eventLoop(m_msg);
	}
	else if(opt == Find)
	{
		searchIdBtn->eventLoop(m_msg);
		searchNameBtn->eventLoop(m_msg);
		searchEdit->eventLoop(m_msg);
	}
	else if (opt == Erase)
	{
		delBtn->eventLoop(m_msg);
		delEdit->eventLoop(m_msg);
	}
	else if (opt == Modify)
	{
		m_modifyEdit->eventLoop(m_msg);

		if (haveStu)
		{
			for (int i = 0; i < 6; i++)
			{
				m_stuEdits[i]->eventLoop(m_msg);
			}
		}
	}
}

void ManageMent::drawBackground()
{
	m_bk.draw();//绘制背景

}

int ManageMent::mainMenu(const ExMessage& msg)
{
	settextstyle(50, 0, "黑体");
	char title[50] = "学生成绩管理系统";
	outtextxy((Window::width() - textwidth(title)) / 2, 50, title);

	settextstyle(25, 0, "黑体");
	outtextxy(550, 480, "作者：顽石老师");

	for (auto btn : menu_btns)
	{
		btn->show();
	}
	for (size_t i = 0; i < menu_btns.size(); i++)
	{
		menu_btns[i]->eventLoop(msg);
		if (menu_btns[i]->isClicked())
		{
			return i;
		}
	}
	return 66;
}

void ManageMent::updateTableData()
{
	m_insertTable.clear();
	for (auto val : vec_stu)
	{
		m_insertTable.insert(val.formatInfo());
	}
}

void ManageMent::displayAll()
{
	m_insertTable.show();
}

void ManageMent::insert()
{
	settextstyle(50, 0, "黑体");
	char title[50] = "添加学生";
	outtextxy((Window::width() - textwidth(title)) / 2, 50, title);

	m_insertEdit.show();
	m_insertBtn.show();
	settextstyle(30, 0, "黑体");
	outtextxy(m_insertEdit.x()-50, m_insertEdit.y()-150, "请依次输入<学号 姓名 班级 数学 语文 英语>");

	//点一次会触发多次，所以用定时器来延迟一下
	if (m_insertBtn.isClicked() && Timer::startTimer(200,0))
	{
		std::string newData = m_insertEdit.text();
		if (newData.empty() || std::count(newData.begin(),newData.end(),' ')!=5)
		{
			printf("插入失败，字符串为空，或者格式不满足\n");
			return;
		}
		
		//格式化数据
		std::replace(newData.begin(), newData.end(), ' ', '\t');
		//把数据放入表格
		m_insertTable.insert(newData);	
		//把数据
		Student t;
		t.formatWrite(newData);
		vec_stu.push_back(t);
		m_insertEdit.clear();
		
		printf("插入成功啦\n");
		updateTableData();
	}

	//m_insertEdit.updateText();

	//Student stu;
	//cout << "请依次输入<学号,姓名,班级,数学,语文,英语>" << endl;
	//cin >> stu.number >> stu.name >> stu.grade >> stu.math >> stu.chinese >> stu.english;
	//vec_stu.push_back(stu);
}

void ManageMent::erase()
{
	settextstyle(50, 0, "黑体");
	char title[50] = "删除学生";
	outtextxy((Window::width() - textwidth(title)) / 2, 50, title);

	delEdit->show();
	delBtn->show();
	delTable->show();

	static std::vector<Student>::iterator delIt = vec_stu.end();
	if (delEdit->textChanged())
	{
		std::string info = delEdit->text();
		if (info.empty())
			return;

		Student stu;
		stringstream stream(info);
		stream >> stu.number;
		delIt = std::find(vec_stu.begin(), vec_stu.end(), stu);
		if (delIt != vec_stu.end())
		{
			delTable->insert(delIt->formatInfo());
		}
	}
	
	//删除按钮按下
	if (delBtn->isClicked() && delIt != vec_stu.end() && Timer::startTimer(200,1))
	{
		std::cout << "delete" << std::endl;
		vec_stu.erase(delIt);
		delTable->clear();
		delIt = vec_stu.end();

		updateTableData();
	}
	
}

void ManageMent::modify()
{
	settextstyle(50, 0, "黑体");
	char title[50] = "修改学生";
	outtextxy((Window::width() - textwidth(title)) / 2, 50, title);

	m_modifyEdit->show();
	for (int i = 0; i < 6; i++)
	{
		m_stuEdits[i]->show();
	}
	//略
	settextstyle(30, 0, "黑体");
	outtextxy(m_modifyEdit->x()-80, m_modifyEdit->y() - 80, "请输入需要修改的学生学号");
	//settextstyle(18, 0, "黑体");
	//outtextxy(m_stuEdits[0]->x(), m_stuEdits[0]->y()-40, "点击对应格子即可修改");


	if (m_modifyEdit->textChanged())
	{
		printf("sdfsfd");
		std::string res =m_modifyEdit->text();
		Student stu;
		std::stringstream stream(res);
		stream >> stu.number;
		//stu.name = res;

		auto findIt = std::find(vec_stu.begin(), vec_stu.end(), stu);
		
		if (findIt != vec_stu.end())
		{
			m_modifyIt = findIt;
			haveStu = true;
			cout << "找到咯~ ";
			//searchTable->insert(findIt->formatInfo());
			m_stuEdits[0]->setText(to_string(findIt->number));
			m_stuEdits[1]->setText(findIt->name);
			m_stuEdits[2]->setText(findIt->grade);
			m_stuEdits[3]->setText(to_string(findIt->math));
			m_stuEdits[4]->setText(to_string(findIt->chinese));
			m_stuEdits[5]->setText(to_string(findIt->english));

			findIt->display();
		}
		else {
			haveStu = false;

		}
	}
	
	if (haveStu)
	{
		//如果修改了学生信息
		for (int i = 0; i < 6; i++)
		{
			if (m_stuEdits[i]->textChanged())
			{
				switch (i)
				{
				case 0:		//修改了学号
					m_modifyIt->number = atoi(m_stuEdits[i]->text().data());
					break;
				case 1:		//修改了姓名
					m_modifyIt->name	= m_stuEdits[i]->text();
					break;
				case 2:		//修改了班级
					m_modifyIt->grade = m_stuEdits[i]->text();
					break;
				case 3:		//修改了数学
					m_modifyIt->math = atoi(m_stuEdits[i]->text().data());
					break;
				case 4:		//修改了语文
					m_modifyIt->chinese = atoi(m_stuEdits[i]->text().data());
					printf("修改了语文\n");
					break;
				case 5:		//修改了英语
					m_modifyIt->english = atoi(m_stuEdits[i]->text().data());
					break;
				}
				updateTableData();
			}
		}
	}
	else if(!isfirst)
	{
		settextstyle(18, 0, "黑体");
		setfillcolor(RGB(194, 195, 201));
		solidrectangle(m_stuEdits[0]->x(), m_stuEdits[0]->y(), m_stuEdits[0]->x() + 6 * 120, m_stuEdits[0]->y() + 30);
		outtextxy(m_stuEdits[0]->x(), m_stuEdits[0]->y()+5, "未找到你要修改的学生，请查证后重试~");
	}
	else
	{
		settextstyle(18, 0, "黑体");
		setfillcolor(RGB(194, 195, 201));
		solidrectangle(m_stuEdits[0]->x(), m_stuEdits[0]->y(), m_stuEdits[0]->x() + 6 * 120, m_stuEdits[0]->y() + 30);
		outtextxy(m_stuEdits[0]->x(), m_stuEdits[0]->y() + 5, "请在上方输入框中输入要查找的学生学号，然后点击此处信息直接编辑");
	}
}

void ManageMent::find()
{
	settextstyle(50, 0, "黑体");
	char title[50] = "查找学生";
	outtextxy((Window::width() - textwidth(title)) / 2, 50, title);
	
	int where = -1;		//记录时按学号查找还是按姓名查找
	if (searchIdBtn->isClicked())
	{
		std::cout << "numberBtn->isClickedQAQ~" << std::endl;
		searchEdit->setInputBoxTitle("请输入学号");
		searchEdit->popInputBox();
		where = 0;
	}
	if (searchNameBtn->isClicked())
	{
		searchEdit->setInputBoxTitle("请输入姓名");
		searchEdit->popInputBox();
		where = 1;
	}

	searchIdBtn->show();
	searchNameBtn->show();
	searchTable->show();
	

	std::string res = searchEdit->text();
	if (!res.empty())
	{
		Student stu;
		std::stringstream stream(res);
		if (where == 0)
		{
			stream >> stu.number ;
			auto findIt = std::find(vec_stu.begin(), vec_stu.end(), stu);
			if (findIt != vec_stu.end())
			{
				cout << "找到咯~ ";
				searchTable->insert(findIt->formatInfo());
				findIt->display();
			}
		}
		else if (where == 1)
		{
			stream >> stu.name;
			for (Student& s : vec_stu)
			{
				if (s.name == stu.name)
				{
					cout << "找到咯~ ";
					searchTable->insert(s.formatInfo());
					s.display();
				}
			}
		}
	}
	
}

void ManageMent::sort()
{
	//默认升序
	std::sort(vec_stu.begin(), vec_stu.end());
	std::cout << "排序成功QAQ~" << std::endl;
}


void ManageMent::readData(const std::string& fileName)
{
	fstream stream(fileName.c_str(), ios::in);
	if (!stream.is_open())
	{
		cerr << fileName << " file open failed" << endl;
		return;
	}
	Student stu;
	char buf[1024] = { 0 };
	//读取表头
	stream.getline(buf, 1024);
	tableHeader = buf;
	//读取数据
	while (!stream.eof())
	{
		memset(buf, 0, sizeof(buf));
		stream.getline(buf, 1024);
		//跳过空行
		if (strlen(buf) == 0)
			break;
		//格式化读取
		stringstream ss(buf);
		ss >> stu.number >> stu.name >> stu.grade >> stu.math >> stu.chinese >> stu.english;
		vec_stu.push_back(stu);
	}
	stream.close();
}

void ManageMent::writeData(const std::string& fileName)
{
	fstream write(fileName.c_str(), ios::trunc | ios::out);
	if (!write.is_open())
	{
		cerr << fileName << " file open failed [save]";
		return;
	}
	tableHeader += '\n';
	write.write(tableHeader.c_str(), tableHeader.size());
	for (auto& val : vec_stu)
	{
		string info = val.formatInfo();
		write.write(info.c_str(),info.size());
	}
	write.close();
}
