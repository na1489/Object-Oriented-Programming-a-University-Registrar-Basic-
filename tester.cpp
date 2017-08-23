#include <string>
#include "registrar.h"
#include "student.h"
#include "course.h"
#include <fstream>

using namespace std;
using namespace BrooklynPoly;

int main() {
	Registrar registrar;
	string action, courseName, studentName, dummyO;
	ifstream ifs("transactions.txt");
	while(ifs>>action){
		if(action == "PrintReport") {
			registrar.printReport();
		}
		else if(action == "AddCourse") {
			ifs >> courseName;
			registrar.addCourse(courseName);
		}
		else if(action == "AddStudent") {
			ifs >> studentName;
			registrar.addStudent(studentName);
		}
		else if(action == "EnrollStudentInCourse") {
			ifs >> studentName;
			if(registrar.checkIfStudentExists(studentName) == 0) {
				ifs >> dummyO;
			}
			else {
				ifs >> courseName;
				if ((registrar.checkIfCourseExists(courseName) == 0)) {
					ifs >> dummyO;
				}
				else if (courseName == " ") {
					ifs >> dummyO;
				}
				else {
					registrar.enrollStudent(studentName, courseName);
				}
			}
		}
		else if(action == "CancelCourse") {
			ifs >> courseName;
			registrar.cancelCourse(courseName);
		}
	}
}