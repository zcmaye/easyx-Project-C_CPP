#pragma once
#include<string>
class Student
{
	using uint32 = unsigned;
public:
	Student();
	Student(uint32 number);
	Student(uint32 number,const std::string& name,const std::string& grade,
		int math,int chinese,int englist);
	//显示信息
	void display();
	//把学生的所有信息格式化成字符串
	std::string formatInfo();
	void formatWrite(const std::string& str);
public:
	bool operator==(const Student& right) const;
	bool operator>(const Student& right) const;
	bool operator<(const Student& right) const;
public:
	uint32 number;
	std::string name;
	std::string grade;
	int math;
	int chinese;
	int english;
};

