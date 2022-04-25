#include "Student.h"
#include "ListCourses.h"
// Constructor
Student::Student()
{
	mssv = "";
	name = "";
}

Student::Student(string _mssv, string _name)
{
	mssv = _mssv;
	name = _name;
}

Student::Student(const Student& std)
{
	mssv = std.mssv;
	name = std.name;
	sche = std.sche;
}

Student& Student::operator=(Student& std)
{
	mssv = std.mssv;
	name = std.name;
	sche.SetSize(std.sche.GetSize());
	sche.SetSchedule(std.sche.GetSchedule(), std.sche.GetSize());
	return *this;
}

Student::~Student()
{
	mssv = name = "";
}

// Setter - Getter
string Student::GetID(){return mssv;}
string Student::GetName() { return name; }
Schedule Student::GetSchedule() { return sche; }
// Nhap xuat
void Student::Input()
{
	textBgColor(0, 3);
	gotoXY(26, 12);
	cout << "Nhap MSSV: ";
	gotoXY(26, 14);
	cout << "Nhap ho ten: ";

	textBgColor(0, 7);
	gotoXY(26, 13);
	getline(cin, mssv);
	gotoXY(26, 15);
	getline(cin, name);
	cout << endl;
}

void Student::Output(const ListCourse list)
{
	string temp = "Cac Khoa hoc da dang ki cua " + name + " la: ";
	titleMid(15, 15, temp, 7, 2, 51, 1);
	sche.PrintCourse(list);
	cout << endl;
}


// Cac phuong thuc khac
bool Student::AddCourse(string idCourse)
{
	if (sche.IsFull()) {
		return false;
	}
	sche.Push(idCourse);
	return true;
}

bool Student::CancelCourse(string idCourse)
{
	if (sche.Remove(idCourse) == true) {
		return true;
	}
	return false;
}


bool Student::IsFullCourse()
{
	return sche.IsFull();
}

bool Student::CheckExistsCourse(string makh)
{
	return sche.CheckExistsCourse(makh);
}

bool Student::IsEmptyCourse()
{
	return (sche.GetSize() == 0);
}
