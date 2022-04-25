#include "ListStudents.h"
#include "ListCourses.h"
#include "Graphic.h"

// Constructor
ListStudent::ListStudent() {
	list_std = NULL;
	size_listStudent = 0;
}

ListStudent::ListStudent(const ListStudent& listStudent)
{
	size_listStudent = listStudent.size_listStudent;

	list_std = new Student[size_listStudent];

	for (int i = 0; i < size_listStudent; i++)
	{
		list_std[i] = listStudent.list_std[i];
	}
}
ListStudent::~ListStudent()
{
	if(list_std!=NULL) delete[] list_std;
	size_listStudent = -1;
}


// Thêm hoặc xóa khóa học khỏi danh sách 
void ListStudent::Resize(int newSize)
{
	Student* temp = list_std;
	
	list_std = new Student[newSize];
	int sizeTemp = (newSize >= size_listStudent) ? size_listStudent : newSize;
	for (int i = 0; i < sizeTemp; i++) {
		list_std[i] = temp[i];
	}
	size_listStudent = newSize;
	if (temp != NULL) delete[] temp;
}

bool ListStudent::AddStudent( Student& std)
{
	Resize(++size_listStudent);
	list_std[size_listStudent - 1] = std;
	return true;
}

bool ListStudent::RemoveStudent(string id)
{
	for (int i = 0; i < size_listStudent; i++) {
		if (list_std[i].GetID() == id) {
			for (int j = i; j < size_listStudent - 1; j++) {
				list_std[j] = list_std[j + 1];
			}
			Resize(--size_listStudent);
			return true;
		}
	}
	return false;
}


// Nhập danh sách học sinh 
void ListStudent::InputListStudent()
{
	do
	{
		system("cls");
		titleMid(15, 1, "NHAP DANH SACH SINH VIEN", 7, 2, 51, 3);
		drawRectangle(25, 5, 31, 4, 3);
		drawRectangle(26, 7, 29, 1, 7);

		gotoXY(26, 6);
		textBgColor(0, 3);
		cout << "Nhap so sinh vien: ";

		textBgColor(0, 7);
		gotoXY(26, 7);
		cin >> size_listStudent;
		if (size_listStudent <= 0 || cin.fail())
		{
			cin.clear();
			cin.ignore();
			size_listStudent = -1;
			titleMid(24, 6, "Khong hop le !!!", 7, 4, 33, 3);
			textBgColor(7, 0);
			Sleep(600);
			/*cout << "Khong hop le.\n";*/
		}
	} while (size_listStudent <= 0 || cin.fail());
	cin.ignore(100,'\n');
	list_std = new Student[size_listStudent];
	for (int i = 0; i < size_listStudent; i++)
	{
		string temp_1 = "NHAP SINH VIEN THU " + to_string(i + 1);
		titleMid(25, 10, temp_1, 7, 1, 31, 1);
		drawRectangle(25, 11, 31, 6, 3);
		drawRectangle(26, 13, 29, 1, 7);
		drawRectangle(26, 15, 29, 1, 7);
		list_std[i].Input();

		string temp_2 = "NHAP THANH CONG SV THU " + to_string(i + 1);
		titleMid(25, 11, temp_2, 7, 2, 31, 1);
		textBgColor(7, 0);
		Sleep(800);
	}
}

// Hiện các khóa học mà sinh viên đã đăng kí 
void ListStudent::ShowScheduleOfStudent(string idStudent, const ListCourse list)
{
	for (int i = 0; i < size_listStudent; i++) {
		if (list_std[i].GetID() == idStudent) {
			list_std[i].Output(list);
			return;
		}
	}
}


// Đăng kí hoặc hủy khóa học 
bool ListStudent::AddCourseToStudent(string idStudent, string idCourse)
{
	for (int i = 0; i < size_listStudent; i++) {
		if (list_std[i].GetID() == idStudent) {
			list_std[i].AddCourse(idCourse);
			return true;
		}
	}
	return false;
}

bool ListStudent::CanCelCourse(string idStudent, string idCourse)
{
	for (int i = 0; i < size_listStudent; i++) {
		if (list_std[i].GetID() == idStudent) {
			list_std[i].CancelCourse(idCourse);
			return true;
		}
	}
	return false;
}

string ListStudent::FindNameStudentWithID(string idStudent)
{
	for (int i = 0; i < size_listStudent; i++)
	{
		if (list_std[i].GetID() == idStudent) return list_std[i].GetName();
	}
}


// Ham bo tro
bool ListStudent::IsEmpty()
{
	if (size_listStudent == 0)
		return true;
	return false;
}
bool ListStudent::CheckExistStudent(string id)
{
	for (int i = 0; i < size_listStudent; i++)
	{
		if (id == list_std[i].GetID()) return true;
	}
	return false;
}

// Get - Set

int ListStudent::GetSize()
{
	return size_listStudent;
}

Student ListStudent::GetStudent(int index)
{
	return list_std[index];
}

Student ListStudent::GetStudent(string id)
{
	for (int i = 0; i < size_listStudent; i++)
	{
		if (list_std[i].GetID() == id) return list_std[i];
	}
	Student std;
	return std;
}






