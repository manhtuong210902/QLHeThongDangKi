#include "ListCourses.h"
#include "Student.h"
#include "ListStudents.h"
#include "Graphic.h"


// Constructor 
ListCourse::ListCourse()
{
	list_cour = NULL;
	size_listCourse = 0;
}

ListCourse::ListCourse(const ListCourse& listCourse)
{
	size_listCourse = listCourse.size_listCourse;

	list_cour = new Course[size_listCourse];
	for (int i = 0; i < size_listCourse; i++)
	{
		list_cour[i] = listCourse.list_cour[i];
	}
}

ListCourse::~ListCourse()
{
	if(list_cour!=NULL) delete[] list_cour;
	size_listCourse = -1;
}

// Thêm hoặc xóa khóa học khỏi danh sách 
void ListCourse::Resize(int newSize)
{
	Course* temp = list_cour;

	list_cour = new Course[newSize];
	int sizeTemp = (newSize >= size_listCourse) ? size_listCourse : newSize;
	for (int i = 0; i < sizeTemp; i++) {
		list_cour[i] = temp[i];
	}
	size_listCourse = newSize;
	if(temp!=NULL) delete[] temp;
}

bool ListCourse::AddCourse(Course& cour)
{
	Resize(++size_listCourse);
	this->list_cour[size_listCourse - 1] = cour;
	return true;
}

bool ListCourse::RemoveCourse(string idCourse)
{
	for (int i = 0; i < size_listCourse; i++) {
		if (list_cour[i].GetID() == idCourse) {
			for (int j = i; j < size_listCourse - 1; j++) {
				list_cour[j] = list_cour[j + 1];
			}
			Resize(--size_listCourse);
			return true;
		}
	}
	return false;
}


// Nhập danh sách các khóa học 
void ListCourse::InputListCourse()
{
	do
	{
		system("cls");
		titleMid(15, 1, "NHAP DANH SACH KHOA HOC", 7, 2, 51, 3);
		drawRectangle(25, 5, 31, 4, 3);
		drawRectangle(26, 7, 29, 1, 7);

		gotoXY(26, 6);
		textBgColor(0, 3);
		cout << "Nhap so khoa hoc: ";

		textBgColor(0, 7);
		gotoXY(26, 7);
		cin >> size_listCourse;
		if (size_listCourse <= 0 || cin.fail())
		{
			cin.clear();
			cin.ignore();
			size_listCourse = -1;
			titleMid(24, 6, "Khong hop le !!! Nhap lai", 7, 4, 33, 3);
			textBgColor(7, 0);
			Sleep(600);
		}
	} while (size_listCourse <= 0 || cin.fail());
	cin.ignore();
	list_cour = new Course[size_listCourse];
	for (int i = 0; i < size_listCourse; i++)
	{
		string temp_1 = "NHAP KHOA HOC THU " + to_string(i + 1);
		titleMid(25, 10, temp_1, 7, 1, 31, 1);
		drawRectangle(25, 11, 31, 6, 3);
		drawRectangle(26, 13, 29, 1, 7);
		drawRectangle(26, 15, 29, 1, 7);
		list_cour[i].Input();	

		string temp_2 = "NHAP THANH CONG K.HOC THU " + to_string(i + 1);
		titleMid(25, 11, temp_2, 7, 2, 31, 1);
		textBgColor(7, 0);
		Sleep(800);
	}
}


// Hiện danh sách các sinh viên đăng kí khóa học 
void ListCourse::ShowRosterOfCourse(string idCourse, const ListStudent list)
{
	for (int i = 0; i < size_listCourse; i++) {
		if (list_cour[i].GetID() == idCourse) {
			list_cour[i].Output(list);
			break;
		}
	}
}

// Thêm học sinh hoặc xóa học sinh khỏi Roster 
bool ListCourse::AddStudentToCourse(string idCourse, string idStudent)
{
	for (int i = 0; i < size_listCourse; i++) {
		if (list_cour[i].GetID() == idCourse) {
			list_cour[i].AddStudent(idStudent);
			return true;
		}
	}
	return false;
}

bool ListCourse::RemoveStudentFromCourse(string idCourse, string idStudent)
{
	for (int i = 0; i < size_listCourse; i++) {
		if (list_cour[i].GetID() == idCourse) {
			list_cour[i].RemoveStudent(idStudent);
			return true;
		}
	}
	return false;
}

string ListCourse::FindNameCourseWithID(string id)
{
	for (int i = 0; i < size_listCourse; i++)
	{
		if (list_cour[i].GetID() == id) return list_cour[i].GetName();
	}
}


// Tìm các khóa học mà một sinh viên có thể đăng kí 
void ListCourse::ShowCoursesCanRegister(Student std)
{
	string* sche = std.GetSchedule().GetSchedule();
	int sizeSche = std.GetSchedule().GetSize();

	drawRectangle(15, 15, 51, 1, 1);
	textBgColor(7, 1);
	verticalLine(19, 15, 1, 7, 1);
	verticalLine(34, 15, 1, 7, 1);

	gotoXY(15, 15); cout << "STT"; // 5 + 15 + 31
	gotoXY(20, 15); cout << "MA KHOA HOC";
	gotoXY(35, 15); cout << "TEN KHOA HOC";
	int count = 1;
	for (int i = 0; i < size_listCourse; i++)
	{
		/*bool canRegis = true;
		for (int j = 0; j < sizeSche; j++)
		{
			if (list_cour[i].GetID() == sche[j])
			{
				canRegis = false;
				break;
			}
		}*/
		if (!list_cour[i].IsFullStudent())
		{
			drawRectangle(15, 16 + i, 51, 1, 3);
			verticalLine(19, 16 + i, 1, 7, 3);
			verticalLine(34, 16 + i, 1, 7, 3);
			textBgColor(0, 3);
			gotoXY(15, 16 + i);  cout << count++;
			gotoXY(20, 16 + i);  cout << list_cour[i].GetID();
			gotoXY(35, 16 + i);  cout << list_cour[i].GetName();
			/*cout<< left << setw(5) << count++ << left << setw(20) << list_cour[i].GetID() << left << setw(50) << list_cour[i].GetID() << endl;*/
		}
	}

	if (sche != NULL) delete[]sche;
}

bool ListCourse::IsEmpty()
{
	if (size_listCourse == 0) return true;
	else return false;
}
bool ListCourse::CheckExistCourse(string id)
{
	for (int i = 0; i < size_listCourse; i++)
	{
		if (list_cour[i].GetID() == id) return true;
	}
	return false;
}
bool ListCourse::CheckIsFullCourse(string makh)
{
	for (int i = 0; i < size_listCourse; i++)
	{
		if (list_cour[i].GetID() == makh && list_cour[i].IsFullStudent()) return true;
	}
	return false;
}

// Get
int ListCourse::GetSize()
{
	return size_listCourse;
}

Course ListCourse::GetCourse(int index)
{
	return list_cour[index];
}
