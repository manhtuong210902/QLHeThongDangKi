#include "Roster.h"
#include "ListStudents.h"
#include "Graphic.h"

// Constructor
Roster::Roster()
{
	roster = NULL;
	size_roster = 0;
}

Roster::Roster(const Roster& ros)
{
	size_roster = ros.size_roster;

	roster = new string[size_roster];
	for (int i = 0; i < size_roster; i++)
	{
		roster[i] = ros.roster[i];
	}
}

Roster& Roster::operator=(const Roster& rost)
{
	size_roster = rost.size_roster;
	if (roster != NULL)
		delete[] roster;
	roster = new string[size_roster];
	for (int i = 0; i < size_roster; i++) {
		roster[i] = rost.roster[i];
	}
	return *this;
}

Roster::~Roster()
{
	if (roster != NULL) delete[]roster;
}

// Ham bo tro
void Roster::Resize(int newSize)
{
	string* temp = roster;
	
	roster = new string[newSize];

	int sizeTemp = (newSize >= size_roster) ? size_roster : newSize;
	for (int i = 0; i < sizeTemp; i++)
	{
		roster[i] = temp[i];
	}
	size_roster = newSize;
	if (temp != NULL) delete[]temp;
}

// Cac phuong thuc khac
bool Roster::Push(string idStudent)
{
	if (IsFull()) return false;
	Resize(size_roster + 1);
	roster[size_roster - 1] = idStudent;
	return true;
}

bool Roster::Remove(string idStudent)
{
	if (size_roster <= 0) return false;
	
	if (size_roster == 1)
	{
		if (roster[0] == idStudent)
		{
			if (roster)
			{
				delete[]roster;
				roster = NULL;
				size_roster = 0;
			}
			return true;
		}
		else return false;
	}

	for (int i = 0; i < size_roster; i++)
	{
		if (roster[i] == idStudent)
		{
			for (int j = i; j < size_roster - 1; j++)
			{
				roster[j] = roster[j + 1];
			}
			Resize(size_roster - 1);
			break;
		}
	}
	return true;
}

bool Roster::IsFull()
{
	if (size_roster == maxSize) return true;
	return false;
}

// Xuat danh sach Student da dang ki khoa hoc nay
void Roster::PrintStudent(ListStudent listStudent)
{
	drawRectangle(15, 16, 51, 1, 1);
	textBgColor(7, 1);
	verticalLine(19, 16, 1, 7, 1);
	verticalLine(34, 16, 1, 7, 1);

	gotoXY(15, 16); cout << "STT"; // 5 + 15 + 31
	gotoXY(20, 16); cout << "MA HOC SINH";
	gotoXY(35, 16); cout << "TEN HOC SINH";
	for (int i = 0; i < size_roster; i++)
	{
		drawRectangle(15, 17 + i, 51, 1, 3);
		verticalLine(19, 17 + i, 1, 7, 3);
		verticalLine(34, 17 + i, 1, 7, 3);
		textBgColor(0, 3);
		gotoXY(15, 17 + i);  cout << i;
		gotoXY(20, 17 + i);  cout << roster[i];
		gotoXY(35, 17 + i);  cout << listStudent.FindNameStudentWithID(roster[i]);
	}
	//cout << left << setw(5) << "STT" << left << setw(20) << "Ma Hoc Sinh" << left << setw(50) << "Ten Hoc Sinh" << endl;
	//for (int i = 0; i < size_roster; i++)
	//{
	//	cout << left << setw(5) << i << left << setw(20) << roster[i] << setw(50) << listStudent.FindNameStudentWithID(roster[i]) << endl;
	//}
}


// Setter - getter
string* Roster::GetRoster()
{
	string* ros = new string[size_roster];
	for (int i = 0; i < size_roster; i++) {
		ros[i] = roster[i];
	}
	return ros;
}

void Roster::SetRoster(string* ros, int sz)
{
	if (roster != NULL) delete[]roster;
	size_roster = sz;
	roster = ros;
}

int Roster::GetSize() { return size_roster; }

void Roster::SetSize(int _size) { size_roster = _size; }
