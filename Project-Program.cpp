#include <iostream>
#include <fstream>
#include <string>
class Student {
public:
    std::string name;
    int studentID;
    float grade;
public:
    Student() {
        name = "";
        studentID = 0;
        grade = 0.0;
    }
    void setStudentInfo(std::string studentName, int id, float studentGrade) {
        name = studentName;
        studentID = id;
        grade = studentGrade;
    }
    void displayStudentInfo() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "ID: " << studentID << std::endl;
        std::cout << "Grade: " << grade << std::endl;
    }
};
void saveReportCard(Student student) {
    std::ofstream file("report_cards.txt", std::ios::app);
    if (file.is_open()) {
        file << student.name << " " << student.studentID << " " << student.grade << std::endl;
        file.close();
        std::cout << "Report card saved successfully." << std::endl;
    } else {
        std::cerr << "Unable to open file." << std::endl;
    }
}

void displayReportCards() {
    std::ifstream file("report_cards.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file." << std::endl;
    }
}
int main() {
    Student student1;
    student1.setStudentInfo("Alice", 12345, 85.5);
    saveReportCard(student1);

    Student student2;
    student2.setStudentInfo("Bob", 67890, 92.3);
    saveReportCard(student2);

    displayReportCards();

    return 0;
}