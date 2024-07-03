#pragma once

#include <iostream>

typedef unsigned long uintptr_t;

struct Data {
  std::string name;
};

class Serializer {
 private:
  Serializer();
  Serializer(const Serializer& ref);
  Serializer operator=(const Serializer& other);
  ~Serializer();

 public:
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);
};
