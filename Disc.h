#pragma once
class Disc
{
	string name;
	double pass_mark;
public:
	string& getName(); 
	Disc();
	Disc(string &name);
	void setPassMark(double pass_mark); 
	void print(); 
	void printAll(); 
	~Disc();
	friend ostream& operator<<(ostream& out, Disc & dis);
	friend istream& operator>>(istream& in, Disc & dis);
};

