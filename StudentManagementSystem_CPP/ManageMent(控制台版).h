#pragma once
#include"Student.h"
#include<vector>
class ManageMent
{
	enum Operator
	{
		ShowAll =1,
		Insert,
		Erase,
		Modify,
		Find,
		Sort,
		Exit,
	};
public:
	ManageMent();
	void run();
	void menu();
	//显示所有学生信息
	void displayAll();
	//添加
	void insert();
	//删除
	void erase();
	//修改
	void modify();
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
};

