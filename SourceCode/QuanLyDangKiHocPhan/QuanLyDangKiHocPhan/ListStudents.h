#pragma once
#include "Student.h"

class ListCourse;

class ListStudent
{
private:
	Student* list_std;
	int size_listStudent;
private:
	void Resize(int newSize);
public:
	// Constructor
	ListStudent();
	ListStudent(const ListStudent& listStudent);
	~ListStudent();

	// Thêm hoặc xóa khóa học khỏi danh sách 
	bool AddStudent( Student&std);
	bool RemoveStudent(string id);

	// Nhập danh sách học sinh 
	void InputListStudent();

	// Hiện các khóa học mà sinh viên đã đăng kí 
	void ShowScheduleOfStudent(string idStudent,const ListCourse list);

	// Đăng kí hoặc hủy khóa học 
	bool AddCourseToStudent(string idStudent, string idCourse);
	bool CanCelCourse(string idStudent, string idCourse);
	string FindNameStudentWithID(string idStudent);

	// Ham bo tro
	bool IsEmpty();
	bool CheckExistStudent(string id);

	// Get- set
	Student GetStudent(int index);
	Student GetStudent(string id);
	int GetSize();
};
