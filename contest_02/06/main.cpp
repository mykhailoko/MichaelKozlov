#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Student {
    std::string name;
    std::string group;
};

Student make_student(const std::string& line) {
    size_t pos = line.find(';');
    Student student;
    student.name = line.substr(0, pos);
    student.group = line.substr(pos + 1);
    return student;
}

bool is_upper(const Student& a, const Student& b) {
    if (a.group == b.group) {
        return a.name < b.name;
    }
    return a.group < b.group;
}

void print(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "Empty list!" << std::endl;
        return;
    }

    std::string current_group = students[0].group;
    std::cout << current_group << std::endl;

    for (const Student& student : students) {
        if (student.group != current_group) {
            current_group = student.group;
            std::cout << current_group << std::endl;
        }
        std::cout << "- " << student.name << std::endl;
    }
}

int main()
{
    int count;
    std::cin >> count;
    std::cin.ignore(1);  // Убираем из потока символ \n для корректной работы getline
    
    std::vector<Student> students(count);
    for(auto& student: students) {
        std::string line;
        std::getline(std::cin, line);
        student = make_student(line);
    }
    
    std::sort(students.begin(), students.end(), is_upper);
    
    print(students);
}
