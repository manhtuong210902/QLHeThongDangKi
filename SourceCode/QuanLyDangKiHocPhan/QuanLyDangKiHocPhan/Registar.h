#pragma once

#include "ListStudents.h"
#include "ListCourses.h"

class Registar
{
public:
	// Đăng kí
	bool Register(ListStudent& listStd, ListCourse& listCour);

	// Hủy khóa học 
	bool CancelCourse(ListStudent& listStd, ListCourse& listCour);
};
