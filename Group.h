#pragma once
class Student;
class Disc;
class Group
{
	string name;
	list<Student> listSt; 
	list<Disc> listDis; 
public:
	Group();
	list<Student> & getListSt();
	list<Disc> & getListDis();

	Group(string& name);
	void add(Student & st); 
	void add(Disc & dis); 
	void print(); 
	void printAll(); 
	~Group();
	friend ostream& operator<<(ostream& out, Group & gr);
	friend istream& operator>>(istream& in, Group & gr);
};



