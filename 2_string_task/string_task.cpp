#include <cstring>
#include <fmt/format.h>
#include <iostream>
#include <sstream>
#include <string>

using std::cin;
using std::cout;
using std::string;

class Student {
  int id;
  char *name;
  char *edu_background;

  void copy_name(const char *new_name, std::size_t length) {
    if (name != nullptr) {
      delete[] name;
    }
    name = new char[length + 1];
    strncpy(name, new_name, length);
    name[length] = '\0';
  }

  void copy_edu_background(const char *new_edu_background, std::size_t length) {
    if (edu_background != nullptr) {
      delete[] edu_background;
    }
    edu_background = new char[length + 1];
    strncpy(edu_background, new_edu_background, length);
    edu_background[length] = '\0';
  }

public:
  Student() : id(0), name(new char[]{"\0"}), edu_background(new char[]{"\0"}){};

  Student(const Student &other_student) {
    id = other_student.id;
    name = nullptr;
    edu_background = nullptr;
    copy_name(other_student.name, strlen(other_student.name));
    copy_edu_background(other_student.edu_background,
                        strlen(other_student.edu_background));
  }

  Student(Student &&) = delete;

  ~Student() {
    if (name != nullptr) {
      delete[] name;
    }
    if (edu_background != nullptr) {
      delete[] edu_background;
    }
  }

  friend std::istream &operator>>(std::istream &is, Student &student) {
    std::string inputstring{};
    std::getline(is, inputstring);

    std::istringstream linestream{inputstring};

    int input_id{};

    linestream >> input_id;
    student.id = input_id;

    if (!linestream.eof()) {
      string input_name{};
      linestream >> input_name;
      student.copy_name(input_name.c_str(), input_name.length());
    }

    if (!linestream.eof()) {
      string input_edu_background{};
      linestream >> input_edu_background;
      student.copy_edu_background(input_edu_background.c_str(),
                                  input_edu_background.length());
    }

    return is;
  }

  friend std::ostream &operator<<(std::ostream &os, const Student &student) {
    return os << fmt::format("{} {} {}\n", student.id, student.name,
                             student.edu_background);
  }

  Student &operator=(const Student &other_student) {
    id = other_student.id;
    if (other_student.name != name) {
      copy_name(other_student.name, strlen(other_student.name));
    }
    if (edu_background != other_student.edu_background) {
      copy_edu_background(other_student.edu_background,
                          strlen(other_student.edu_background));
    }
    return *this;
  }

  void SetId(int newid) { id = newid; }

  void SetName(const string &newname) {
    copy_name(newname.c_str(), newname.length());
  }
};

int main() {
  Student s1;
  cin >> s1;
  Student s2(s1);
  int id1;
  string name1;
  cin >> id1 >> name1;
  s2.SetId(id1);
  s2.SetName(name1);
  Student s3;
  s3 = s1;
  cin >> id1;
  s3.SetId(id1);
  cout << s1;
  cout << s2;
  cout << s3;
  return 0;
}
