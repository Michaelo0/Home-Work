// HomeWork.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Group.h"
#include "Student.h"
#include "Disc.h"
#include "OcList.h"


ostream& operator<<(ostream& out, Disc & dis)
{
	return out << dis.name << endl << dis.pass_mark << endl;
}

istream& operator>>(istream& in, Disc & dis)
{
	return in >> dis.name >> dis.pass_mark;
}

ostream& operator<<(ostream& out, OcList & list1)
{
	out << list1.name << endl;
	out << list1.oclist.size() << endl;
	for (auto pos : list1.oclist) out << pos << endl;
	return out;
}

istream& operator>>(istream& in, OcList & list1)
{

	in >> list1.name;
	int n;
	in >> n;
	int oc;
	for (int i = 0; i < n; i++)
	{
		in >> oc;
		list1.oclist.push_back(oc);
	}
	return in;
}

ostream& operator<<(ostream& out, Student & st)
{
	out << st.fio << endl;
	out << st.listOc.size() << endl;
	for (auto pos : st.listOc) out << pos;
	return out;
}

istream& operator>>(istream& in, Student & st)
{
	in >> st.fio;
	int n;
	in >> n;
	OcList *pL;
	for (int i = 0; i < n; i++)
	{
		pL = new OcList;
		in >> *pL;
		st.listOc.push_back(*pL);
	}
	return in;
}

ostream& operator<<(ostream& out, Group & gr)
{
	out << gr.name << endl;
	out << gr.listSt.size() << endl;
	for (auto pos : gr.listSt) out << pos;
	out << gr.listDis.size() << endl;
	for (auto pos : gr.listDis) out << pos;
	return out;
}

istream& operator>>(istream& in, Group & gr)
{
	in >> gr.name;
	int n;
	in >> n;
	Student *pSt;
	for (int i = 0; i < n; i++)
	{
		pSt = new Student;
		in >> *pSt;
		pSt->setGroup(&gr);
		gr.listSt.push_back(*pSt);
	}
	in >> n;
	Disc *pDis;
	for (int i = 0; i < n; i++)
	{
		pDis = new Disc;
		in >> *pDis;
		gr.listDis.push_back(*pDis);
	}
	return in;
}

list<Group>listGr; 

int _tmain(int argc, _TCHAR* argv[])
{
	int Reg;
	string buf1;
	Group *pGr = 0; 
	Student *pSt = 0;
	OcList *pLOc;
	Disc *pDis = 0;
	int i, Num;
	int Oc;
	int flag;
	ofstream ofs;
	ifstream ifs;

	while (1)
	{
		cout << "Input a mode number: 1- Create a new group 2- Create a new student 3- Create new discipline 4- Input the discipline marks for the student 5 - Print data 8- Retain data in a file 9- Read data from a file 10 - Exit" <<
			endl << "Mode №=";
		cin >> Reg;
		switch (Reg)
		{
		case 1: 
			cout << "Input a name of group: "; cin >> buf1;
			pGr = new Group(buf1);
			listGr.push_back(*pGr); 
			break;
		case 2: 
			if (listGr.size() == 0) {
				cout << "The group list is empty, you must create a new group or read it from file before a new student creation  " << endl;
				break;
			}
			cout << "Input the name of student: "; cin >> buf1;
			pSt = new Student(buf1);
			cout << "List of existing groups:" << endl;
			i = 1;
			for (auto& pos : listGr) {
				cout << i << ". Name: "; pos.print();
				i++;
			}
			cout << "Input the group number for student: "; cin >> Num;
			i = 1;
			for (auto& pos : listGr) {
				if (Num == i) {
					pos.add(*pSt);
					break;
				}
				i++;
			}
			break;
		case 3: 
			if (listGr.size() == 0) {
				cout << "The group list is empty, you must create a new group or read it from file before a new discipline creation" << endl;
				break;
			}
			cout << "Input the name of discipline: "; cin >> buf1;
			pDis = new Disc(buf1);
			cout << "The existing group list:" << endl;
			i = 1;
			for (auto& pos : listGr) {
				cout << i << ". Name: "; pos.print();
				i++;
			}
			cout << "Input the group number for discipline: "; cin >> Num;
			i = 1;
			for (auto& pos : listGr) {
				if (Num == i) {
					pos.add(*pDis);
					break;
				}
				i++;
			}
			break;
		case 4: 
			if (listGr.size() == 0) {
				cout << "The group list is empty, you must create a new group or read it from file before a new mark input" << endl;
				break;
			}

			cout << "The existing group list:" << endl;
			i = 1;
			for (auto& pos : listGr) {
				cout << i << ". Name: "; pos.print();
				i++;
			}
			cout << "Input a group number for discipline and student research: "; cin >> Num;
			i = 1;
			for (auto& pos : listGr) {
				if (Num == i) {
					pGr = &pos;
					break;
				}
				i++;
			}
			if (pGr->getListDis().size() == 0) {
				cout << "The discipline list is empty, you must create a new discipline or read it from file before a new mark input" << endl;
				break;
			}
			i = 1;
			for (auto& pos : pGr->getListDis()) {
				cout << i << ". Name: "; pos.print();
				i++;
			}
			cout << "Input the discipline number for choice: "; cin >> Num;
			i = 1;
			for (auto& pos : pGr->getListDis()) {
				if (Num == i) {
					pDis = &pos;
					break;
				}
				i++;
			}

			if (pGr->getListSt().size() == 0) {
				cout << "The student list is empty, you must create a new student or read it from file before a new mark input" << endl;
				break;
			}
			i = 1;
			for (auto& pos : pGr->getListSt()) {
				cout << i << ". name: "; pos.print();
				i++;
			}
			cout << "Input the discipline number for choice: "; cin >> Num;
			i = 1;
			for (auto& pos : pGr->getListSt()) {
				if (Num == i) {
					pSt = &pos;
					break;
				}
				i++;
			}
			cout << "Input a new mark: "; cin >> Oc;
			flag = 0;

			if (pSt->getListOc().size()>0) for (auto& pos : pSt->getListOc()) if (pos.getDisName() == pDis->getName()) 
			{
				pos.getOcList().push_back(Oc); flag = 1; break;
			}
			if (flag == 0)
			{
				pLOc = new OcList(pDis->getName());
				pLOc->add(Oc);
				pSt->getListOc().push_back(*pLOc);
			}
			break;
		case 5: 
				cout << "Count of groups: " << listGr.size() << endl;
				for (auto pos : listGr) pos.printAll();  
				break;
		case 8: 
			ofs.open("MyFileDat.txt");
			ofs << listGr.size() << endl;
			for (auto& pos : listGr) ofs << pos;
			ofs.close();
			break;
		case 9: 
			ifs.open("MyFileDat.txt");
			ifs >> Num; 
			listGr.clear();
			for (int i = 0; i < Num; i++)
			{
				pGr = new Group;
				ifs >> *pGr;
				listGr.push_back(*pGr);
			}

			ifs.close();
			if (listGr.size() == 0)
				cout << "There is no file for reading or it is empty, data hasn't been read" << endl;
			else cout << "Data has been succesfully read" << endl;
			break;
		
		case 10: 
			ofs.close();
			return 0;
		

		}

	}
	return 0;
}


