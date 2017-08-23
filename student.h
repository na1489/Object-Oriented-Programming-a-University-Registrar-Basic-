#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <vector>
#include <iostream>

namespace BrooklynPoly {
	class Course;
	class Student{
	// friend std::ostream& operator<<(std::ostream& lhs, const Student& rhs);
	public:
		Student(const std::string& studentName);
		void addCourse(Course* coursePtr);
		void dropCourse(Course* coursePtr);
		std::string getName();
		void display() const;
	private:
		std::string name;
		std::vector<Course*> courses;
	};
}

#endif