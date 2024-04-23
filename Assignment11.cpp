#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student {
	int rollNumber;
	string name;
	string division;
	string address;
public:

	void addStudent() {
		Student student;
		cout << "Enter Roll Number: ";
		cin >> student.rollNumber;
		cin.ignore(); // Ignore the newline character in the input buffer
		cout << "Enter Name: ";
		getline(cin, student.name);
		cout << "Enter Division: ";
		getline(cin, student.division);
		cout << "Enter Address: ";
		getline(cin, student.address);

		ofstream outFile("student_info.dat", ios::app);
		outFile << student.rollNumber << endl;
		outFile << student.name << endl;
		outFile << student.division << endl;
		outFile << student.address << endl;

		cout << "Student information added successfully." << endl;
		outFile.close();
	}

	void deleteStudent() {
		int rollNumber;
		cout << "Enter Roll Number of the student to delete: ";
		cin >> rollNumber;

		ifstream inFile("student_info.dat");
		ofstream tempFile("temp.dat");

		int currentRollNumber;
		bool found = false;

		while (inFile >> currentRollNumber) {
			string name, division, address;
			inFile.ignore(); // Ignore the newline character in the input buffer
			getline(inFile, name);
			getline(inFile, division);
			getline(inFile, address);

			if (currentRollNumber != rollNumber) {
				tempFile << currentRollNumber << endl;
				tempFile << name << endl;
				tempFile << division << endl;
				tempFile << address << endl;
			} else {
				found = true;
			}
		}

		inFile.close();
		tempFile.close();

		remove("student_info.dat");
		rename("temp.dat", "student_info.dat");

		if (found) {
			cout << "Student information deleted successfully." << endl;
		}
		else {
			cout << "Student not found." << endl;
		}
	}

	void displayStudent() {
		int rollNumber;
		cout << "Enter Roll Number of the student to display: ";
		cin >> rollNumber;

		ifstream inFile("student_info.dat");

		int currentRollNumber;
		bool found = false;

		while (inFile >> currentRollNumber) {
			string name, division, address;
			inFile.ignore();
			getline(inFile, name);
			getline(inFile, division);
			getline(inFile, address);

			if (currentRollNumber == rollNumber) {
				cout << "Roll Number: " << currentRollNumber << endl;
				cout << "Name: " << name << endl;
				cout << "Division: " << division << endl;
				cout << "Address: " << address << endl;
				found = true;
				break;
			}
		}

		inFile.close();

		if (!found) {
			cout << "Student not found." << endl;
		}
	}
};

int main() {
	int choice;
	Student s;
	do {
		cout << "\n***** Student Information System *****" << endl;
		cout << "1. Add Student" << endl;
		cout << "2. Delete Student" << endl;
		cout << "3. Display Student Information" << endl;
		cout << "5. Delete File" << endl;
		cout << "4. Quit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				s.addStudent();
				break;
			case 2:
				s.deleteStudent();
				break;
			case 3:
				s.displayStudent();
				break;
			case 4:
				cout << "Exiting program. Goodbye!" << endl;
				break;
			case 5:
				remove("student_info.dat");
				cout<<"file removed";
				break;
			default:
				cout << "Invalid choice. Please try again." << endl;
				break;
		}
	} while (choice != 4);

	return 0;
}

