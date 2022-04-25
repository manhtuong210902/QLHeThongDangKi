#pragma once
#include"Graphic.h"
#include "Schedule.h"

class ListCourse;
class Student
{
private:
	string mssv;
	string name;
	Schedule sche;
public:
	// Constructor
	Student();
	Student(string, string);
	Student(const Student& std);
	Student &operator =(Student&std);
	~Student();

	// Setter - Getter
	string GetID();
	string GetName();
	Schedule GetSchedule();

	// Nhap Xuat
	void Input();
	void Output(const ListCourse list);  // Tham số ListCourse để lấy tên khóa học từ id lưu trong sche 

	// Cac phuong thuc khac
	bool AddCourse(string idCourse);
	bool CancelCourse(string idCourse);

	// Bo tro

	bool IsEmptyCourse();  // Kiểm tra học sinh chưa đăng kí khóa học nào 

	bool CheckExistsCourse(string makh);  // Kiểm tra khóa học đã được đăng kí hay chưa 

	bool IsFullCourse();
};
