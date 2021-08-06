#pragma once
#include"Student.h"
#include<vector>
#include<map>
#include"pushButton.h"
#include"Table.h"
#include"LineEdit.h"
class ManageMent
{
	enum Operator
	{
		ShowAll,
		Insert,
		Erase,
		Modify,
		Find,
		Exit,
	};
public:
	ManageMent();
	void run();
	void menu();

	void eventLoop();
	void drawBackground();

	int mainMenu(const ExMessage& msg);
	//插入和删除数据时，更新一下表格
	void updateTableData();
	//显示所有学生信息
	void displayAll();
	//添加
	void insert();
	//删除
	void erase();
	//修改
	void modify();
	//查找
	void find();
	//排序
	void sort();
private:
	//从文件读取学生信息
	void readData(const std::string& fileName);
	//保存学生信息到文件
	void writeData(const std::string& fileName);
public:
	std::string tableHeader;	//表头
	std::vector<Student> vec_stu;
	int m_prevStuCnt;	//上一次学生的数量

	std::vector<PushButton*> menu_btns;

	Table		m_insertTable;
	LineEdit	m_insertEdit;		//添加学生编辑框
	PushButton	m_insertBtn;		//添加学生确认按钮

	ExMessage m_msg;
	int m_key;
public:
	Image m_bk;
public://查找学生页面
	LineEdit*		searchEdit;
	PushButton*		searchIdBtn;
	PushButton*		searchNameBtn;
	Table*			searchTable;
public://删除学生页面
	LineEdit*	delEdit;
	PushButton* delBtn;
	Table*		delTable;
};

