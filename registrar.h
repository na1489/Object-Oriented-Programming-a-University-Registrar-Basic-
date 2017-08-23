#ifndef REGISTRAR_H
#define REGISTRAR_H
#include <string>
#include <vector>
#include <iostream>

namespace BrooklynPoly {
	class Student;
	class Course;
	class Registrar {
	friend std::ostream& operator<<(std::ostream& lhs, const Registrar& rhs);
	public:
		bool checkIfStudentExists(std::string& studentName);
		bool checkIfCourseExists(std::string& courseName);
		void addCourse(std::string& courseName);
		void addStudent(std::string& studentName);
		void enrollStudent(std::string& studentName, std::string& courseName);
		void cancelCourse(std::string& courseName);
		void printReport() const;
	private:
		std::vector<Course*> courses;
		std::vector<Student*> students;
		size_t findCourse(const std::string& courseName);
		size_t findStudent(const std::string& studentName);
	};
	std::ostream& operator<<(std::ostream& lhs, const Registrar& rhs);
}



#endif