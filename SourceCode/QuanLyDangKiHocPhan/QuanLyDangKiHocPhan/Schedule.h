#pragma once
#include <iostream>
#include <string>
#include <iomanip>

class ListCourse;

using namespace std;

class Schedule
{
private:
	string* schedule; // contains id of courses
	const int maxSize = 5;
	int size_schedule;
private:
	void Resize(int newSize);
public:
	// Constructor
	Schedule();
	Schedule(const Schedule& sche);
	Schedule& operator=(const Schedule& sche);
	~Schedule();

	// Cac phuong thuc khac
	bool Push(string idCourse);
	bool Remove(string idCourse);
	bool IsFull(); // Kiem tra khoa hoc da day chua
	bool CheckExistsCourse(string makh);  //Kiểm tra khóa học đã được đăng kí hay chưa 

	// Xuat danh sach cac khoa hoc ma hoc sinh da dang ki
	void PrintCourse(ListCourse listCourse);  

	// Setter - Getter
	string* GetSchedule();
	void SetSchedule(string* sche, int _size);
	int GetSize();
	void SetSize(int _size);
};