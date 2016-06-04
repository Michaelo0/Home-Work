#include "stdafx.h"
#include "Disc.h"


Disc::Disc()
{
	pass_mark = 0;
}

Disc::Disc(string& name)
{
	this->name = name;
	pass_mark = 0;
}

void Disc::setPassMark(double pass_mark) 
{
	this->pass_mark = pass_mark;
}
Disc::~Disc()
{
}
void Disc::print()
{
	cout << name << endl;
}

void Disc::printAll()
{
	cout << name << ", Проходной балл: " << pass_mark << endl;
}

string& Disc::getName() 
{
	return name;
}

