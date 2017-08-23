#include "course.h"

using namespace std;

namespace BrooklynPoly {

	class Student;

	Course::Course(const string& courseName) : name(courseName) {}

	void Course::addStudent(Student* studentPtr) {
		students.push_back(studentPtr);
	}

	void Course::dropStudent(Student* studentPtr) {
		for(size_t i=0; i < students.size(); ++i) {
			if(students[i] == studentPtr) {
				students[i] = students[students.size()-1];
				students.pop_back();
				return;
			}
		}
	}

	string Course::getName() {
		return name;
	}

	// ostream& operator<<(ostream& lhs, const Course& rhs) {
	// 	lhs << "Name: " << rhs.name;
	// 	return lhs; 
	// }

	void Course::display() const {
		cout << name;
	}
}