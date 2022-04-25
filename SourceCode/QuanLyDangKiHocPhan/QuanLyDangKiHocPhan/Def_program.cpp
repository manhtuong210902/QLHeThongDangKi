#include "Program.h"

void Program::Menu() {
	setConsoleSize(81, 30);
	string line[] =
	{
		"Nhap danh sach sv",
		"Nhap danh sach khoa hoc",
		"Dang ki khoa hoc theo mssv",
		"Huy dang ki khoa hoc theo mssv",
		"Xuat danh sach khoa hoc theo mssv",
		"Xuat danh sach sinh vien theo ma khoa hoc",
		"Thoat"
	};
	//
	int n = 7;
	int x = 15;
	int y = 5;
	int index = 0;
	do
	{
		system("cls");
		nocursortype();
		gotoXY(15, 1);
		titleMid(15, 1, "HE THONG QUAN LY", 7, 2, 51, 3);

		for (int i = 0; i < n; i++)
		{
			if (index == i)
			{
				titleMid(x, y + i, line[i], 7, 1, 51, 1);
			}
			else
			{
				titleMid(x, y + i, line[i], 0, 9, 51, 1);
			}
		}
		int check = 0;
		//
		textColor(7);
		while (true)
		{
			char key = _getch();
			if (key == 13)
			{
				// Nhap danh sach sv
				if (index == 0)
				{
					system("cls");
					yescursortype();
					l_std.InputListStudent();
					gotoXY(0, 25);
					textBgColor(7, 0);
					cout << ">> Nhan phim bat ki de thoat <<" << endl;
					nocursortype();
					textBgColor(0, 0);
					system("pause");
				}
				//Nhap danh sach khoa hoc
				else if (index == 1)
				{
					system("cls");
					yescursortype();
					l_cour.InputListCourse();
					gotoXY(0, 25);
					textBgColor(7, 0);
					cout << ">> Nhan phim bat ki de thoat <<" << endl;
					nocursortype();
					textBgColor(0, 0);
					system("pause");
				}
				//Dang ki khoa hoc theo mssv
				else if (index == 2)
				{
					system("cls");
					titleMid(15, 1, "DANG KI KHOA HOC", 7, 2, 51, 3);
					textBgColor(7, 0);
					yescursortype();
					Registar regis;
					if (!regis.Register(l_std, l_cour)) {
						titleMid(25, 11, "DANG KI THAT BAI", 7, 12, 31, 3);
					}
					else {
						titleMid(25, 11, "DANG KI THANH CONG", 7, 10, 31, 3);
					}
					gotoXY(0, 25);
					textBgColor(7, 0);
					cout << ">> Nhan phim bat ki de thoat <<" << endl;
					nocursortype();
					textBgColor(0, 0);
					system("pause");
				}
				//Huy dang ki khoa hoc theo mssv
				else if (index == 3)
				{
					system("cls");
					titleMid(15, 1, "HUY DANG KI KHOA HOC", 7, 2, 51, 3);
					yescursortype();

					Registar regis;
					if (!regis.CancelCourse(l_std, l_cour)) {
						titleMid(25, 11, "HUY THAT BAI", 7, 12, 31, 3);
					}
					else {
						titleMid(25, 11, "HUY THANH CONG", 7, 10, 31, 3);
					}
					gotoXY(0, 25);
					textBgColor(7, 0);
					cout << ">> Nhan phim bat ki de thoat <<" << endl;
					nocursortype();
					textBgColor(0, 0);
					system("pause");
				}
				//Xuat danh sach khoa hoc theo mssv
				else if (index == 4)
				{
					system("cls");
					titleMid(15, 1, "XUAT DS KHOA HOC THEO MSSV", 7, 2, 51, 3);
					yescursortype();
					drawRectangle(25, 7, 31, 4, 3);
					drawRectangle(26, 9, 29, 1, 7);

					gotoXY(26, 8);
					textBgColor(0, 3);
					cout << "Nhap mssv: ";
		
					string mssv = "";
					textBgColor(0, 7);
					gotoXY(26, 9);
					getline(cin, mssv);
					if (!l_std.CheckExistStudent(mssv))
					{
						titleMid(25, 8, "Ma sv khong ton tai!", 7, 4, 31, 3);
					}
					else
					{
						l_std.ShowScheduleOfStudent(mssv, l_cour);
					}
					gotoXY(0, 25);
					textBgColor(7, 0);
					cout << ">> Nhan phim bat ki de thoat <<" << endl;
					nocursortype();
					textBgColor(0, 0);
					system("pause");
				}
				//Xuat danh sach sinh vien theo makh
				else if (index == 5)
				{
					system("cls");
					titleMid(15, 1, "XUAT DS SINH VIEN THEO MA KH", 7, 2, 51, 3);
					yescursortype();
					drawRectangle(25, 7, 31, 4, 3);
					drawRectangle(26, 9, 29, 1, 7);

					gotoXY(26, 8);
					textBgColor(0, 3);
					cout << "Nhap ma kh: ";
					string makh = "";

					textBgColor(0, 7);
					gotoXY(26, 9);
					getline(cin, makh);
					if (!l_cour.CheckExistCourse(makh))
					{
						titleMid(25, 8, "Ma kh khong ton tai!", 7, 4, 31, 3);
					}
					else
					{
						l_cour.ShowRosterOfCourse(makh, l_std);
					}
					gotoXY(0, 25);
					textBgColor(7, 0);
					cout << ">> Nhan phim bat ki de thoat <<" << endl;
					nocursortype();
					textBgColor(0, 0);
					system("pause");
				}
				else if (index == 6)
				{
					return;
				}
				check = 1;
				break;
			}
			//
			else if (key == 72)
			{
				//PlaySound(TEXT("Beep1.wav"), NULL, SND_ASYNC);
				index--;
				check = 1;
			}
			//
			else if (key == 80)
			{
				//PlaySound(TEXT("Beep1.wav"), NULL, SND_ASYNC);
				index++;
				check = 1;
			}
			//

			if (index == -1) {
				index = n - 1;
			}
			//
			else if (index == n)
			{
				index = 0;
			}
			//
			if (check == 1)
			{
				break;
			}

		}
		Sleep(200);
	} while (true);
}