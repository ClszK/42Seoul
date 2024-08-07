#include <cstdlib>
#include <ctime>

#include "Span.hpp"  // Span 클래스의 정의가 포함된 헤더 파일

int main() {
  // 난수 생성을 위한 시드 설정
  std::srand(std::time(0));

  // Span 클래스의 인스턴스 생성
  Span sp(10000);  // 10,000개의 숫자를 저장할 수 있는 Span 객체

  // 10,000개의 난수를 Span 객체에 추가
  try {
    for (int i = 0; i < 10000; ++i) {
      sp.addNumber((std::rand() % 4294967294) + 1);
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  // Span 클래스의 기능 테스트
  std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
  std::cout << "Longest span: " << sp.longestSpan() << std::endl;

  std::cout << "------------------------------" << std::endl;

  Span test(1000);
  std::vector<int> vecTest;

  try {
    for (int i = 0; i < 5; ++i) test.addNumber(std::rand() % 20);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  vecTest = test.getIntVec();

  std::cout << "Shortest span: " << test.shortestSpan() << std::endl;
  std::cout << "Longest span: " << test.longestSpan() << std::endl;

  for (int i = 0; i < 5; ++i) std::cout << vecTest[i] << " ";
  std::cout << std::endl;

  Span test2(6);
  std::vector<int> vecTest2;
  std::cout << "------------------------------" << std::endl;

  test2.addNumber(6);
  try {
    test2.addNumberWithContainer(test.getIntVec());
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  vecTest2 = test2.getIntVec();
  for (std::vector<int>::iterator it = vecTest2.begin(); it != vecTest2.end();
       ++it)
    std::cout << *it << " ";
  std::cout << std::endl;

  Span sp1 = Span(5);
  sp1.addNumber(6);
  sp1.addNumber(3);
  sp1.addNumber(17);
  sp1.addNumber(9);
  sp1.addNumber(11);
  std::cout << sp1.shortestSpan() << std::endl;
  std::cout << sp1.longestSpan() << std::endl;

  Span sp2 = Span(2);
  try {
    std::cout << sp2.longestSpan() << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}