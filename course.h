#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <vector>
#include <iostream>

namespace BrooklynPoly {
	class Student;
	class Course{
	// friend std::ostream& operator<<(std::ostream& lhs, const Course& rhs);
	public:
		Course(const std::string& courseName);
		void addStudent(Student* studentPtr);
		void dropStudent(Student* studentPtr);
		std::string getName();
		void display() const;
	private:
		std::string name;
		std::vector<Student*> students;
	};
}

#endif