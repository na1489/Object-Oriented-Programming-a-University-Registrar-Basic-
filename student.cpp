#include "student.h"

using namespace std;

namespace BrooklynPoly {

	class Course;

	Student::Student(const string& studentName) : name(studentName) {}

	void Student::addCourse(Course* coursePtr) {
		courses.push_back(coursePtr);
	}

	void Student::dropCourse(Course* coursePtr) {
		for(size_t i=0; i < courses.size(); ++i) {
			if(courses[i] == coursePtr) {
				courses[i] = courses[courses.size()-1];
				courses.pop_back();
				return;
			}
		}
	}

	string Student::getName() {
		return name;
	}

	// ostream& operator<<(ostream& lhs, const Student& rhs) {
	// 	lhs << "Name: " << rhs.name;
	// 	return lhs;
	// }

	void Student::display() const {
		cout << name;
	}
}