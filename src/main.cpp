// Copyright 2020 Nikita Semaev
#include <iostream>
#include "../include/MyString.h"

int main() {
  MyString a;
  std::cout << a.length();
  MyString b("123");
  std::cout << b.length();

  MyString aa("123");
  MyString c(aa);
  std::cout << '^' << c.get() << '^';

  std::cout << "!";
  return 0;
}
