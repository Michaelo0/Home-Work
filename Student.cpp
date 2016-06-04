#include "stdafx.h"
#include "Group.h"
#include "OcList.h"
#include "Student.h"


Student::Student()
{
}


Student::~Student()
{
}

Student::Student(string& fio)
{
	this->fio = fio;
}

void Student::setGroup(Group *pGr) 
{
	this->pGr = pGr;
}

void Student::print() 
{
	cout << fio << endl;
}

void Student::printAll()
{
	cout << fio << endl;
	cout << "Disciplines' marks: " << endl;
	if (listOc.size() == 0)
		cout << "Disciplines' marks list is empty." << endl;
	else
		for (auto pos : listOc)
		{
			pos.printAll();
		}

}

list<OcList>& Student::getListOc()
{
	return listOc;
}
