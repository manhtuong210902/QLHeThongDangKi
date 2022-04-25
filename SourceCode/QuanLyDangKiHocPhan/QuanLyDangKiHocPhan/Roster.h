#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class ListStudent;

class Roster
{
private:
	string* roster;
	const int maxSize = 40;
	int size_roster;
private:
	void Resize(int newSize);
public:
	//Constuctor
	Roster();
	Roster(const Roster& ros);
	Roster& operator=(const Roster& rost);
	~Roster();

	// Cac phuong thuc khac
	bool Push(string idStudent); // Thêm id học sinh vào roster 
	bool Remove(string idStudent); // Xóa id học sinh khỏi roster 
	bool IsFull();  // Kiểm tra khóa học đầy hay chưa 

	// Xuat danh sach Student da dang ki mon hoc nay
	void PrintStudent(ListStudent listStudent);

	// Setter - Getter
	string* GetRoster();
	void SetRoster(string* ros, int sz);
	int GetSize();
	void SetSize(int _size);
};
