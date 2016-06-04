#include "stdafx.h"
#include "Disc.h"
#include "Student.h"
#include "OcList.h"


OcList::OcList()
{
}


OcList::~OcList()
{
}

OcList::OcList(string name)
{
	this->name = name;

}

void OcList::add(int oc) 
{
	oclist.push_back(oc);
}

double OcList::getAvMark() 
{
	double sum = 0;
	for (auto pos : oclist) sum += pos;
	if (oclist.size()>0) return sum / oclist.size();
	return 0;
}

list<int>& OcList::getOcList()
{
	return oclist;
}

string & OcList::getDisName()
{
	return name;
}

void OcList::printAll() 
{
	cout << name << ": ";
	if (oclist.size() == 0)
		cout << "There is no marks." << endl;
	else
	{
		for (auto pos : oclist) cout << pos << ' ';
		cout << "Av. mark: " << getAvMark() << endl;
	}
}

