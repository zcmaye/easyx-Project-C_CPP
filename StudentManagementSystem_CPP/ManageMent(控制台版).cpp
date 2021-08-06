#include "ManageMent.h"
#include<sstream>
#include<fstream>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

ManageMent::ManageMent()
{
	readData("./student.txt");
	//writeData("./test.txt");
}

void ManageMent::run()
{
	menu();
	while (true)
	{		
		cout << "请选择>";
		int op = -1;
		cin >> op;
		switch (op)
		{
		case 0:
			system("cls");
			menu();
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
		case ManageMent::Sort:
			sort();
			break;
		case ManageMent::Exit:
			writeData("./test.txt");
			break;
		default:
			break;
		}
	}
}

void ManageMent::menu()
{
	cout << "***** 学生成绩管理系统 *****" << endl;
	cout << "***** 1,查看学生       *****" << endl;
	cout << "***** 2,添加学生       *****" << endl;
	cout << "***** 3,删除学生       *****" << endl;
	cout << "***** 4,修改学生       *****" << endl;
	cout << "***** 5,查找学生       *****" << endl;
	cout << "***** 6,排序          *****" << endl;
	cout << "***** 7,退出系统       *****" << endl;
	cout << "***** 0,清除屏幕       *****" << endl;
	cout << endl;
}

void ManageMent::displayAll()
{
	std::cout << this->tableHeader << endl;
	for (auto& val : vec_stu)
	{
		val.display();
	}
	std::cout << "共(" << vec_stu.size() << ")条数据" << endl;
}

void ManageMent::insert()
{
	Student stu;
	cout << "请依次输入<学号,姓名,班级,数学,语文,英语>" << endl;
	cin >> stu.number >> stu.name >> stu.grade >> stu.math >> stu.chinese >> stu.english;
	vec_stu.push_back(stu);
}

void ManageMent::erase()
{
	int number = -1;
	cout << "请输入要删除的学生的学号>";
	cin >> number;
	auto delIt = std::find(vec_stu.begin(), vec_stu.end(), Student(number));
	if (delIt != vec_stu.end())
	{
		vec_stu.erase(delIt);
	}
}

void ManageMent::modify()
{
	//略
}

void ManageMent::find()
{
	cout << "*** 选择查找属性     ***" << endl;
	cout << "*** 1,按学号查找     ***" << endl;
	cout << "*** 2,按姓名查找     ***" << endl;
	int op = -1;
	cout << "select>";
	cin >> op;
	Student stu;
	if (op == 1)
	{
		cout << "输入学号:";
		cin >> stu.number;
		auto findIt = std::find(vec_stu.begin(), vec_stu.end(), stu);
		if (findIt != vec_stu.end())
		{
			cout << "找到咯~ ";
			findIt->display();
		}
	}
	else
	{
		cout << "输入姓名:";
		cin >> stu.name;
		for (Student& s : vec_stu)
		{
			if (s.name == stu.name)
			{
				cout << "找到咯~ ";
				s.display();
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
