#pragma once
#include "Roster.h"

class ListStudent;

class Course
{
private:
	string makh;
	string name;
	Roster rost;
public:
	// Constructor
	Course();
	Course(string, string);
	Course(Course& cour);
	Course& operator=( Course& cour);
	~Course();

	// Setter - Getter
	string GetID();
	string GetName();

	// Nhap Xuat
	void Input();
	void Output(const ListStudent list); // Tham số ListStudent để lấy tên học sinh từ id lưu trong rost 


	// Cac phuong thuc khac
	bool AddStudent(string idStudent);
	bool RemoveStudent(string idStudent);

	bool IsFullStudent(); // Kiểm tra khóa học đã đầy học sinh chưa 
};
