#include "registrar.h"
#include "course.h"
#include "student.h"

using namespace std;

namespace BrooklynPoly {

	class Student;
	class Course;

	size_t Registrar::findCourse(const string& courseName) {
		for(size_t i = 0; i < courses.size(); ++i) {
			if(courses[i]->getName() == courseName) {
				return i;
			}
		}
		return courses.size();
	}

	size_t Registrar::findStudent(const string& studentName) {
		for(size_t i = 0; i < students.size(); ++i) {
			if(students[i]->getName() == studentName) {
				return i;
			}
		}
		return students.size();
	}

	void Registrar::addCourse(string& courseName) {
		Course* theCourse = new Course(courseName);
		courses.push_back(theCourse);
	}

	void Registrar::addStudent(string& studentName) {
		Student* theStudent = new Student(studentName);
		students.push_back(theStudent);
	}

	void Registrar::enrollStudent(string& studentName, string& courseName) {
		size_t studentPos = findStudent(studentName);
		size_t coursePos = findCourse(courseName);
		if (studentPos == students.size()) {
			cerr << "Returns out of vector index";
			return;
		}
		if (coursePos == courses.size()) {
			cerr << "Returns out of vector index";
			return;
		}
		students[studentPos]->addCourse(courses[coursePos]);
		courses[coursePos]->addStudent(students[studentPos]);
	}

	void Registrar::cancelCourse(string& courseName) {
		size_t coursePos = findCourse(courseName);
		delete courses[coursePos];
		courses[coursePos] = courses[courses.size()-1];
		courses.pop_back();
	}

	bool Registrar::checkIfStudentExists(string& studentName) {
		if(findStudent(studentName)==students.size()) {
			return 0;
		}
		else
			return 1;
	}

	bool Registrar::checkIfCourseExists(string& courseName) {
		if(findCourse(courseName)==courses.size()) {
			return 0;
		}
		else
			return 1;
	}

	ostream& operator<<(ostream& lhs, const Registrar& rhs) {
		lhs << "Students: " << endl;
		for(Student* aStudent: rhs.students) {
			lhs << " ";
			aStudent->display();
			lhs << endl;
		}
		lhs << "Courses: " << endl;
		for(Course* aCourse: rhs.courses) {
			lhs << " ";
			aCourse->display();
			lhs << endl;
		}
		return lhs;
	}

	void Registrar::printReport() const {
		cout << "Total Students: " << students.size() << endl;
		cout << "Total Courses: " << courses.size() << endl;
		// operator<<(cout,*(this));
		cout << *(this);
	}
}