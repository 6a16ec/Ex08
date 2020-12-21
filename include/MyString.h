// Copyright 2020 Nikita Semaev
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_
#include <string>
#include <iostream>

class MyString {
 private:
  char *str;

 public:
  MyString();
  MyString(const char *str);
  MyString(std::string str);
  MyString(const MyString &);
  MyString(MyString &&second) : str(second.str) {
    second.str = nullptr;
  }

  size_t length();
  char *get();

  MyString operator+(const MyString &);
  MyString operator-(const MyString &);
  MyString operator*(unsigned n);
  MyString operator=(const MyString &);
  MyString &operator=(MyString &&second) {
    str = second.str;
    second.str = nullptr;
    return *this;
  }
  bool operator==(MyString &);
  bool operator!=(MyString &);
  bool operator>(MyString &);
  bool operator<(MyString &);
  bool operator>=(MyString &);
  bool operator<=(MyString &);

  void operator!();
  char operator[](unsigned index);
  unsigned operator()(const char *);

  friend std::ostream &operator<<(std::ostream &out, MyString &str);
  friend std::istream &operator>>(std::istream &in, MyString &str);

  ~MyString();
};


#endif  // INCLUDE_MYSTRING_H_
