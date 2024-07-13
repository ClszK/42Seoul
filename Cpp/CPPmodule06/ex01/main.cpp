#include "Serializer.hpp"

int main() {
  {
    Data dataStruct;
    Data* deserializeData = NULL;

    dataStruct.name = "stack test";
    deserializeData = Serializer::deserialize(
        Serializer::serialize(&dataStruct));
    std::cout << "Before reinterpret_cast : " << dataStruct.name
              << std::endl;
    std::cout << "After reinterpret_cast : "
              << deserializeData->name << std::endl;
  }

  std::cout << "-------------------------------------------"
            << std::endl;

  try {
    Data* dataPtr = NULL;
    dataPtr = new Data;
    Data* afterDataPtr = NULL;

    dataPtr->name = "heap test";
    afterDataPtr =
        Serializer::deserialize(Serializer::serialize(dataPtr));

    std::cout << "Before reinterpret_cast : " << dataPtr->name
              << std::endl;
    std::cout << "After reinterpret_cast : "
              << afterDataPtr->name << std::endl;

    delete dataPtr;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}