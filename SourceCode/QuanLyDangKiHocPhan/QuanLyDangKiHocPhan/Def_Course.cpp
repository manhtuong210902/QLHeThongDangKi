#include "Course.h"
#include "ListStudents.h"
// Constructor
Course::Course()
{
	makh = name = "";
}

Course::Course(string _makh, string _name)
{
	makh = _makh;
	name = _name;
}

Course::Course( Course& cour)
{
	makh = cour.makh;
	name = cour.name;
	rost.SetSize(cour.rost.GetSize());
	rost.SetRoster(cour.rost.GetRoster(), cour.rost.GetSize());
}

Course& Course::operator=(Course& cour)
{
	makh = cour.makh;
	name = cour.name;
	rost.SetSize(cour.rost.GetSize());
	rost.SetRoster(cour.rost.GetRoster(),cour.rost.GetSize());
	return *this;
}

Course::~Course()
{
	makh = name = "";
}

// Setter - Getter
string Course::GetID() { return makh; }
string Course::GetName() { return name; }
// Nhap Xuat
void Course::Input()
{
	textBgColor(0, 3);
	gotoXY(26, 12);
	cout << "Nhap Ma khoa hoc: ";
	gotoXY(26, 14);
	cout << "Nhap ten khoa hoc: ";

	textBgColor(0, 7);
	gotoXY(26, 13);
	getline(cin, makh);
	gotoXY(26, 15);
	getline(cin, name);

	cout << endl;
}

void Course::Output(const ListStudent list)
{
	string temp = "Cac sinh vien da dang ki kh " + name + " la: ";
	titleMid(15, 15, temp, 7, 2, 51, 1);
	rost.PrintStudent(list);
	cout << endl;
}



bool Course::AddStudent(string idStudent)
{
	if (rost.IsFull()) {
		return false;
	}
	rost.Push(idStudent);
	return true;
}

bool Course::RemoveStudent(string idStudent)
{
	if (rost.Remove(idStudent) == true) {
		return true;
	}
	return false;
}

bool Course::IsFullStudent()
{
	return rost.IsFull();
}
