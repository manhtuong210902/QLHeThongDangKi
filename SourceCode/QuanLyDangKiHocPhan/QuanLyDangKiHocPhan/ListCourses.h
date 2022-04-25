#pragma once
#include "Course.h"

class Student;
class ListStudent;

class ListCourse
{
private:
	Course* list_cour;
	int size_listCourse;

private:
	void Resize(int newSize);
public:
	ListCourse();
	ListCourse(const ListCourse& listCourse);
	~ListCourse();

	// Thêm hoặc xóa khóa học khỏi danh sách 
	bool AddCourse(Course& cour);
	bool RemoveCourse(string idCourse);


	// Nhập danh sách các khóa học 
	void InputListCourse();


	// Hiện danh sách các sinh viên đăng kí khóa học 
	void ShowRosterOfCourse(string idCourse,const ListStudent list);


	// Thêm học sinh hoặc xóa học sinh khỏi Roster 
	bool AddStudentToCourse(string idCourse, string idStudent);  
	bool RemoveStudentFromCourse(string idCourse, string idStudent);

	// Tìm tên của sinh viên bằng id 
	string FindNameCourseWithID(string id);    

	// Tìm các khóa học mà một sinh viên có thể đăng kí 
	void ShowCoursesCanRegister(Student std);

	//Hàm bổ trợ 
	bool IsEmpty();
	bool CheckExistCourse(string id); // Kiểm tra một mã khóa học được nhập vào có tồn tại trong dữ liệu hay không 
	bool CheckIsFullCourse(string makh);  // Kiểm tra khóa học đã đầy hay chưa 

	// Get
	int GetSize();
	Course GetCourse(int index);
};
