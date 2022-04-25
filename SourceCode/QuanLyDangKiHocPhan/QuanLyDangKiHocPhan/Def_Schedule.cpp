#include "Schedule.h"
#include "ListCourses.h"
#include "Graphic.h"

// CONSTRUCTOR
Schedule::Schedule()
{
	schedule = NULL;
	size_schedule = 0;
}

Schedule::Schedule(const Schedule& sche)
{
	size_schedule = sche.size_schedule;

	schedule = new string[size_schedule];

	for (int i = 0; i < size_schedule; i++)
	{
		schedule[i] = sche.schedule[i];
	}
}
Schedule& Schedule::operator=(const Schedule& sche)
{
	size_schedule = sche.size_schedule;
	if (schedule != NULL)
		delete[] schedule;
	schedule = new string[size_schedule];
	for (int i = 0; i < size_schedule; i++) {
		schedule[i] = sche.schedule[i];
	}
	return *this;
}

Schedule::~Schedule()
{
	if (schedule != NULL) delete[]schedule;
}

// Setter - Getter
string* Schedule::GetSchedule()
{
	string* sche = new string[size_schedule];
	for (int i = 0; i < size_schedule; i++) {
		sche[i] = schedule[i];
	}
	return sche;
}

void Schedule::SetSchedule(string* sche, int _size)
{
	if (schedule) delete[]schedule;
	size_schedule = _size;
	schedule = sche;
}

int Schedule::GetSize() {
	return size_schedule;
}

void Schedule::SetSize(int _size) {
	size_schedule = _size;
}


// Phuong thuc bo tro
void Schedule::Resize(int newSize)
{
	string* temp = schedule;

	schedule = new string[newSize];
	int sizeTemp = (newSize >= size_schedule) ? size_schedule : newSize;
	for (int i = 0; i < sizeTemp; i++)
	{
		schedule[i] = temp[i];
	}
	size_schedule = newSize;
	if (temp != NULL) delete[]temp;
}

// Cac phuong thuc khac
bool Schedule::Push(string idCourse)
{
	if (IsFull()) return false;
	Resize(size_schedule + 1);
	schedule[size_schedule - 1] = idCourse;
	return true;
}

bool Schedule::Remove(string idCourse)
{
	if (size_schedule <= 0) return false;

	if (size_schedule == 1)
	{
		if (schedule[0] == idCourse)
		{
			if (schedule)
			{
				delete[]schedule;
				size_schedule = 0;
				schedule = NULL;
			}
			return true;
		}
		else return false;
	}

	for (int i = 0; i < size_schedule; i++)
	{
		if (schedule[i] == idCourse)
		{
			for (int j = i; j < size_schedule - 1; j++)
			{
				schedule[j] = schedule[j + 1];
			}
			Resize(size_schedule - 1);
			break;
		}
	}
	return true;
}

bool Schedule::IsFull()
{
	if (size_schedule == maxSize) return true;
	return false;
}
bool Schedule::CheckExistsCourse(string makh)
{
	for (int i = 0; i < size_schedule; i++)
	{
		if (schedule[i] == makh) return true;
	}
	return false;
}


// Xuat danh sach cac khoa hoc ma Student dang ki
void Schedule::PrintCourse(ListCourse listCourse)
{
	drawRectangle(15, 16, 51, 1, 1);
	textBgColor(7, 1);
	verticalLine(19, 16, 1, 7, 1);
	verticalLine(34, 16, 1, 7, 1);

	gotoXY(15, 16); cout << "STT"; // 5 + 15 + 31
	gotoXY(20, 16); cout << "MA KHOA HOC";
	gotoXY(35, 16); cout << "TEN KHOA HOC";
	for (int i = 0; i < size_schedule; i++)
	{
		drawRectangle(15, 17 + i, 51, 1, 3);
		verticalLine(19, 17 + i, 1, 7, 3);
		verticalLine(34, 17 + i, 1, 7, 3);
		textBgColor(0, 3);
		gotoXY(15, 17 + i);  cout << i;
		gotoXY(20, 17 + i);  cout << schedule[i];
		gotoXY(35, 17 + i);  cout << listCourse.FindNameCourseWithID(schedule[i]);
		/*cout<<left<<setw(5)<<i << left << setw(20) << schedule[i] << setw(50) << listCourse.FindNameCourseWithID(schedule[i]) << endl;*/
	}
}

