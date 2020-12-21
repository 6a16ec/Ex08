// Copyright 2020 Nikita Semaev
#define _CRT_SECURE_NO_WARNINGS
#include "../include/MyString.h"
#include <cstring>
#include <string>
#include <cmath>

MyString::MyString() {
  this->str = nullptr;
}

MyString::MyString(const char *str) {
  size_t len = (str != nullptr) ? strlen(str) : 0;
  if (len > 0) {
    std::cout << str << std::endl;
    this->str = new char[len + 1];
    strcpy(this->str, str);
  }
}

MyString::MyString(std::string str) {
  size_t len = str.size();
  this->str = new char[len + 1];
  for (int i = 0; i < len; i++) {
    this->str[i] = str[i];
  }
  this->str[len] = '\0';
}

MyString::MyString(const MyString& second) {
  char *str = second.str;
  this->str = new char[strlen(str) + 1];
  strcpy(this->str, str);
}

size_t MyString::length() {
  return str != nullptr ? strlen(str) : 0;
}

char *MyString::get() { return str; }

MyString MyString::operator+(const MyString &second) {
  MyString newString;
  char *first_str = str;
  char *second_str = second.str;
  size_t first_len = first_str != nullptr ? strlen(first_str) : 0;
  size_t second_len = second_str != nullptr ? strlen(second_str) : 0;
  newString.str = new char[first_len + second_len + 1];
  for (size_t i = 0; i < first_len; i++) {
    newString.str[i] = first_str[i];
  }
  for (size_t i = first_len; i < first_len + second_len; i++) {
    newString.str[i] = second_str[i - first_len];
  }
  newString.str[first_len + second_len] = '\0';
  return newString;
}

MyString MyString::operator-(const MyString &second) {
  MyString newString(str);
  size_t index = 0;
  for (int i = 0; i < strlen(str); i++) {
    bool flag = true;
    for (int j = 0; j < strlen(second.str); j++) {
      if (str[i] == second.str[j]) {
        flag = false;
        break;
      }
    }
    if (flag) {
      newString.str[index++] = str[i];
    }
  }
  newString.str[index] = '\0';
  return newString;
}

MyString MyString::operator*(unsigned n) {
  MyString newString;
  size_t len = strlen(str);
  newString.str = new char[len * n + 1];
  for (unsigned i = 0; i < n; i++) {
    for (size_t j = 0; j < len; j++) {
      newString.str[i * len + j] = str[j];
    }
  }
  newString.str[len * n] = '\0';
  return newString;
}

MyString MyString::operator=(const MyString& second) {
  delete[] str;
  size_t len = strlen(second.str);
  str = new char[len + 1];
  strcpy(str, second.str);
  return *this;
}

bool MyString::operator==(MyString& second) {
  size_t first_len = this->length(), second_len = second.length();
  bool flag = true;
  if (first_len == second_len) {
    for (int i = 0; i < first_len; i++) {
      if (str[i] != second.str[i]) {
        flag = false;
        break;
      }
    }
  } else {
    flag = false;
  }
  return flag;
}

bool MyString::operator!=(MyString &second) { return !(*this == second); }

bool MyString::operator>(MyString &second) {
  size_t first_len = this->length(), second_len = second.length();
  for (int i = 0; i < std::min(first_len, second_len); i++) {
    if (str[i] != second.str[i]) {
      if (str[i] > second.str[i]) {
        return true;
      } else {
        return false;
      }
    }
  }
  if (first_len > second_len) {
    return true;
  } else {
    return false;
  }
}

bool MyString::operator<(MyString &second) {
   return !(*this == second) and !(*this > second);
}

bool MyString::operator>=(MyString&second) {
  return *this == second || *this > second;
}

bool MyString::operator<=(MyString &second) {
  return !(*this > second);
}

void MyString::operator!() {
  size_t len = this->length();
  for (size_t i = 0; i < len; i++) {
    if ('a' <= str[i] && str[i] <= 'z') {
      str[i] -= ('a' - 'A');
    } else {
      if ('A' <= str[i] && str[i] <= 'Z') {
        str[i] += ('a' - 'A');
      }
    }
  }
}

char MyString::operator[](unsigned index) {
  return str[index];
}

unsigned MyString::operator()(const char *substr) {
  size_t substr_len = strlen(substr);
  size_t len = this->length();
  size_t index = -1;
  for (int i = 0; i < len - substr_len; i++) {
    bool flag = true;
    for (int j = 0; j < substr_len; j++) {
      if (str[i + j] != substr[j]) {
        flag = false;
        break;
      }
    }
    if (flag == true) {
      index = i;
      break;
    }
  }
  return index;
}

std::ostream &operator<<(std::ostream &out, MyString &obj) {
  return out << obj.str << std::endl;
}

std::istream& operator>>(std::istream &in, MyString &obj) {
  return in >> obj.str;
}

MyString::~MyString() {
  delete[] str;
}
