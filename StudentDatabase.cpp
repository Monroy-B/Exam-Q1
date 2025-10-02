#include "Student.hpp"

Student::Student() : name(""), id(0), scores(std::vector<int>()) {}
Student::Student(const char* name, int id) : name(std::string(name)), id(id) {
    scores = std::vector<int>();
}

Student::Student(const Student& other) : name(other.name), id(other.id), scores(other.scores) {}
Student::Student(Student&& other) {
    name = std::move(other.name);
    id = other.id;
    scores= std::move(other.scores);
}

Student& Student::operator=(const Student& other) {
    name = other.name;
    id = other.id;
    scores = other.scores;

    return *this;
}

Student& Student::operator=(Student&& other) {
    name = std::move(other.name);
    id = other.id;
    scores = std::move(other.scores);

    return *this;
}

void Student::addScore(int score) { scores.push_back(score); }

double Student::average() const {
    if(scores.size() == 0) { return 0.0; }

    int sum = scores[0];

    for(size_t i = 1; i < scores.size(); ++i) {
        sum += scores[i];
    }

    return static_cast<double>(sum) / static_cast<double>(scores.size());
}

const std::string& Student::getName() const { return name; }
int Student::getId() const { return id; }

std::array<Student*, 100> students;

StudentDatabase::StudentDatabase() {
    students = std::array<Student*, 100>();

    for(size_t i = 0; i < students.size(); ++i) {
        students[i] = nullptr;
    }
}

StudentDatabase::~StudentDatabase() {
    for(size_t i = 0; i < students.size(); ++i) {
        delete students[i];
    }
}

StudentDatabase::StudentDatabase(const StudentDatabase& other) {
    students = std::array<Student*, 100>();

    for(size_t i = 0; i < students.size() && other.students[i] != nullptr; ++i) {
        *students[i] = *other.students[i];
    }
}
StudentDatabase::StudentDatabase(StudentDatabase&& other) {
    students = std::array<Student*, 100>();

    for(size_t i = 0; i < students.size() && other.students[i] != nullptr; ++i) {
        students[i] = other.students[i];
        other.students[i] = nullptr;
    }
}

StudentDatabase& StudentDatabase::operator=(const StudentDatabase& other) {
    for(size_t i = 0; i < students.size(); ++i) {
        delete students[i];
        students[i] = new Student;
        if (other.students[i] != nullptr) {
            *students[i] = *other.students[i];
        }
    }

    return *this;
}
StudentDatabase& StudentDatabase::operator=(StudentDatabase&& other) {
    for(size_t i = 0; i < students.size(); ++i) {
        students[i] = other.students[i];
        other.students[i] = nullptr;
    }

    return *this;
}

void StudentDatabase::addStudent(const Student& s) {
    size_t i = 0;

    while(students[i] != nullptr && i < students.size()) { ++i; }

    if (i == students.size()) { return; }

    students[i] = new Student(s);
}

Student* StudentDatabase::findById(int id) {
    size_t i = 0;

    while(students[i] != nullptr
        && i < students.size()
        && students[i]->id != id) {
            ++i;
    }

    if (i == students.size()) { return nullptr; }

    return students[i];
}

void StudentDatabase::saveToFile(const std::string& filename) {
    std::ofstream file(filename);

    for (size_t i = 0; i < students.size() && students[i] != nullptr; ++i) {
        file << students[i]->id << " " << students[i]->name;
        for(size_t j = 0; j < students[i]->scores.size(); ++j) {
            file << " " << students[i]->scores[j];
        }
    }
}

void StudentDatabase::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);

    int id;
    file >> id;
    int score;
    for(size_t i = 0; i < 100; ++i) {
        std::string name;
        if(!(file >> name)) { return; };

        Student student(name.c_str(), id);

        int old_score;

        while(file >> score) {
            student.addScore(old_score);
            old_score = score;
        }

        addStudent(student);

        id = score;
    }
}