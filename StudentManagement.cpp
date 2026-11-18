        getline(cin, c);
        double m = readMarks();

        students.emplace_back(roll, n, c, m);
        saveToFile();
        cout << "Student record added successfully.\n";
    }

    void displayAll() const {
        if (students.empty()) {
            cout << "No student records found.\n";
            return;
        }

        cout << "\n" << left << setw(10) << "Roll No"
             << setw(22) << "Name" << setw(16) << "Course"
             << setw(10) << "Marks" << "Grade\n";
        cout << string(68, '-') << '\n';

        // Base-class pointer demonstrates polymorphic function calls.
        for (const Student& s : students) {
            const Person* person = &s;
            person->display();
        }
    }

    void searchStudent() const {
        int roll = readInt("Enter roll number to search: ");
        int index = findIndex(roll);
        if (index == -1) {
            cout << "Student not found.\n";
            return;
        }
        cout << "\nStudent found:\n";
        cout << left << setw(10) << "Roll No" << setw(22) << "Name"
             << setw(16) << "Course" << setw(10) << "Marks" << "Grade\n";
        students[index].display();
    }

    void updateStudent() {
        int roll = readInt("Enter roll number to update: ");
        int index = findIndex(roll);
        if (index == -1) {
            cout << "Student not found.\n";
            return;
        }

        string n, c;
        cout << "Enter new name: ";
        getline(cin >> ws, n);
        cout << "Enter new course/branch: ";
        getline(cin, c);
        double m = readMarks();

        students[index].setName(n);
        students[index].setCourse(c);
        students[index].setMarks(m);
        saveToFile();
        cout << "Student record updated successfully.\n";
    }

    void deleteStudent() {
        int roll = readInt("Enter roll number to delete: ");
        int index = findIndex(roll);
        if (index == -1) {
            cout << "Student not found.\n";
            return;
        }
        students.erase(students.begin() + index);
        saveToFile();
        cout << "Student record deleted successfully.\n";
    }

    void run() {
        int choice;
        do {
            cout << "\n========== STUDENT MANAGEMENT SYSTEM ==========\n"
                 << "1. Add Student\n"
                 << "2. Display All Students\n"
                 << "3. Search Student\n"
                 << "4. Update Student\n"
                 << "5. Delete Student\n"
                 << "0. Exit\n";
            choice = readInt("Enter your choice: ");

            switch (choice) {
                case 1: addStudent(); break;
                case 2: displayAll(); break;
                case 3: searchStudent(); break;
                case 4: updateStudent(); break;
                case 5: deleteStudent(); break;
                case 0: cout << "Thank you for using the system.\n"; break;
                default: cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 0);
    }
};

int main() {
    StudentManager system;
    system.run();
    return 0;
}
