#include "Student.h"
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
Student::Student():number(0),math(0),chinese(0),english(0)
{
	//memset(this,0, sizeof(Student));//不能使用这个，否则会乱码
}

Student::Student(uint32 number):Student()
{
	this->number = number;
}

Student::Student(uint32 number, const std::string& name, const std::string& grade, int math, int chinese, int english)
	: number(number),name(name),grade(grade), math(math), chinese(chinese), english(english)
{}

void Student::display()
{
	cout << this->number << "\t" << this->name << "\t" << this->grade << "\t" << this->math << "\t" << this->chinese << "\t" << this->english << endl;
}

std::string Student::formatInfo()
{
	stringstream ss;
	ss<< this->number << "\t" << this->name << "\t" << this->grade << "\t" << this->math << "\t" << this->chinese << "\t" << this->english << endl;
	return ss.str();
}

void Student::formatWrite(const std::string& str)
{
	stringstream ss(str);
	ss >> this->number  >> this->name  >> this->grade  >> this->math  >> this->chinese  >> this->english;
}

bool Student::operator==(const Student& right) const
{
	return this->number == right.number;
}

bool Student::operator>(const Student& right) const
{
	return this->number > right.number;
}

bool Student::operator<(const Student& right) const
{
	return this->number < right.number;
}
