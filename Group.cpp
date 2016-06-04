#include "stdafx.h"
#include "Student.h"
#include "Disc.h"
#include "Group.h"
#include "OcList.h"


Group::Group()
{
}

Group::Group(string& name)
{
	this->name = name;
}
Group::~Group()
{
}

void Group::add(Student & st) 
{
	st.setGroup(this); 
	listSt.push_back(st); 
}
void Group::add(Disc & dis)
{
	listDis.push_back(dis);

}

void Group::print() 
{
	cout << name << endl;
}

list<Student> & Group::getListSt()
{
	return listSt;
}
list<Disc> & Group::getListDis()
{
	return listDis;
}

void Group::printAll() 
{
	cout << "Name of group: " << name << endl;
	cout << "discipline list of the group : " << endl;
	if (listDis.size() == 0)
		cout << "the list is empty." << endl;
	else
		for (auto pos : listDis)
		{
			pos.printAll();
		}
	cout << "student list of the group: " << endl;
	if (listSt.size() == 0)
		cout << "the list is empty." << endl;
	else
		for (auto pos : listSt)
		{
			pos.printAll();
		}

}

