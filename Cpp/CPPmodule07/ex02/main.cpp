#include "Array.hpp"
#define MAX_VAL 750

int main() {
  // 기본 생성자 테스트
  Array<int> emptyArray;
  std::cout << "Empty array size: " << emptyArray.size()
            << std::endl;

  // 크기를 지정한 생성자 테스트
  Array<int> intArray(5);
  std::cout << "Integer array size: " << intArray.size()
            << std::endl;
  for (unsigned int i = 0; i < intArray.size(); ++i) {
    std::cout << intArray[i] << " ";
  }
  std::cout << std::endl;

  // 값 할당 테스트
  for (unsigned int i = 0; i < intArray.size(); ++i) {
    intArray[i] = i * 10;
  }
  for (unsigned int i = 0; i < intArray.size(); ++i) {
    std::cout << intArray[i] << " ";
  }
  std::cout << std::endl;

  // 복사 생성자 테스트
  Array<int> copiedArray(intArray);
  std::cout << "Copied array: ";
  for (unsigned int i = 0; i < copiedArray.size(); ++i) {
    std::cout << copiedArray[i] << " ";
  }
  std::cout << std::endl;

  // 대입 연산자 테스트
  Array<int> assignedArray;
  assignedArray = intArray;
  std::cout << "Assigned array: ";
  for (unsigned int i = 0; i < assignedArray.size(); ++i) {
    std::cout << assignedArray[i] << " ";
  }
  std::cout << std::endl;

  // 엣지 케이스: 비어 있는 배열에서 인덱스 접근
  try {
    std::cout << emptyArray[0] << std::endl;
  } catch (const std::out_of_range& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  // 엣지 케이스: 범위를 벗어난 인덱스 접근
  try {
    std::cout << intArray[10] << std::endl;
  } catch (const std::out_of_range& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  // 상수 배열 테스트
  const Array<int> constArray(3);
  try {
    std::cout << constArray[0] << std::endl;
  } catch (const std::out_of_range& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  const Array<int> constArray2(intArray);
  try {
    std::cout << "Copied array: ";
    for (unsigned int i = 0; i < copiedArray.size(); ++i) {
      std::cout << copiedArray[i] << " ";
    }
  } catch (const std::out_of_range& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  std::cout << std::endl;

  Array<double> doubleArray(5);
  for (unsigned int i = 0; i < doubleArray.size(); ++i) {
      doubleArray[i] = i * 0.1;
  }
  std::cout << "Double array size: " << doubleArray.size()
            << std::endl;
  for (unsigned int i = 0; i < doubleArray.size(); ++i) {
    std::cout << doubleArray[i] << " ";
  }
  std::cout << std::endl;

  Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
  return 0;
}
