#pragma once
class Group;
class OcList;
class Student
{
	string fio;
	Group *pGr; 
	list<OcList> listOc; 

public:
	void setGroup(Group *pGr); 
	Student();
	list<OcList>& getListOc();
	Student(string& fio);
	void print(); 
	void printAll(); 
	~Student();
	friend ostream& operator<<(ostream& out, Student & st);
	friend istream& operator>>(istream& in, Student & st);
};


