#include <vector>
#include <string>
#include <array>
#include <sstream>
#include <fstream>

class StudentDatabase {
private:
    std::array<Student*, 100> students;

public:
    StudentDatabase();
    ~StudentDatabase();

    StudentDatabase(const StudentDatabase& other);
    StudentDatabase(StudentDatabase&& other);

    StudentDatabase& operator=(const StudentDatabase& other);
    StudentDatabase& operator=(StudentDatabase&& other);

    void addStudent(const Student& s);
    Student* findById(int id);
    void saveToFile(const std::string& filename);
    //void loadFromFile(const std::string& filename);
};