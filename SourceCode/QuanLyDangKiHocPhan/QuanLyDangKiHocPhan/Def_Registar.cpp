#include "Registar.h"
#include "Graphic.h"

bool Registar::Register(ListStudent& listStd, ListCourse& listCour)
{
	//setConsoleSize(200, 30);
	if (listStd.IsEmpty() || listCour.IsEmpty()) {
		titleMid(25, 6, "DS sv/kh rong !!!", 7, 4, 31, 3);
		return false;
	}
	
	string mssv = "";

	drawRectangle(25, 5, 31, 4, 3);
	drawRectangle(26, 7, 29, 1, 7);

	gotoXY(26, 6);
	textBgColor(0, 3);
	cout << "Nhap mssv can dang ki: ";

	textBgColor(0, 7);
	gotoXY(26, 7);
	getline(cin, mssv);

	if (!listStd.CheckExistStudent(mssv))
	{
		titleMid(25, 6, "MSSV khong hop le !!!", 7, 4, 31, 3);
		return false;
	}

	if (listStd.GetStudent(mssv).IsFullCourse())
	{
		titleMid(25, 6, "Khoa hoc cua ban da day!", 7, 4, 31, 1);
		titleMid(25, 7, "Khong duoc phep dang ki them!", 7, 4, 31, 1);
		return false;
	}

	//xuat ds kh
	listCour.ShowCoursesCanRegister(listStd.GetStudent(mssv));

	drawRectangle(25, 10, 31, 4, 1);
	drawRectangle(26, 12, 29, 1, 7);

	gotoXY(26, 11);
	textBgColor(7, 1);
	cout << "Nhap Ma KH can dang ki: ";
	string makh = "";

	gotoXY(26, 12);
	textBgColor(0, 7);
	getline(cin, makh);

	if (!listCour.CheckExistCourse(makh) || listCour.CheckIsFullCourse(makh))
	{
		titleMid(25, 6, "Ma kh khong hop le !!!", 7, 4, 31, 3);
		return false;
	}

	if (listStd.GetStudent(mssv).CheckExistsCourse(makh)) {
		titleMid(25, 6, "KH nay ban da dang ki !!!", 7, 4, 31, 3);
		return false;
	}

	listStd.AddCourseToStudent(mssv, makh);
	listCour.AddStudentToCourse(makh, mssv);
}

bool Registar::CancelCourse(ListStudent& listStd, ListCourse& listCour)
{
	if (listStd.IsEmpty() || listCour.IsEmpty()) {
		titleMid(25, 6, "DS sv/kh rong !!!", 7, 4, 31, 3);
		return false;
	}
	string mssv = "";
	drawRectangle(25, 5, 31, 4, 3);
	drawRectangle(26, 7, 29, 1, 7);

	gotoXY(26, 6);
	textBgColor(0, 3);
	cout << "Nhap mssv can huy khoa hoc: ";

	textBgColor(0, 7);
	gotoXY(26, 7);
	getline(cin, mssv);

	if (!listStd.CheckExistStudent(mssv))
	{
		titleMid(25, 6, "MSSV khong hop le!", 7, 4, 31, 3);
		return false;
	}

	Student std = listStd.GetStudent(mssv);
	if (std.IsEmptyCourse())
	{
		titleMid(25, 6, "Ban chua dang ki khoa hoc nao!", 7, 4, 31, 3);
		return false;
	}
	else
	{
		std.Output(listCour);

		drawRectangle(25, 10, 31, 4, 1);
		drawRectangle(26, 12, 29, 1, 7);

		gotoXY(26, 11);
		textBgColor(7, 1);
		cout << "Nhap ma kh can huy: ";

		string makh = "";

		gotoXY(26, 12);
		textBgColor(0, 7);
		getline(cin, makh);

		if (!std.CheckExistsCourse(makh))
		{
			titleMid(25, 6, "Nhap sai ma khoa hoc!", 7, 10, 31, 3);
			return false;
		}

		listStd.CanCelCourse(mssv, makh);
		listCour.RemoveStudentFromCourse(makh, mssv);
	}

	return true;
}