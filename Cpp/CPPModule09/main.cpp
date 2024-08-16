#include "PmergeMe.hpp"

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "Error: need more integers." << std::endl;
    return 1;
  }

  try {
    PmergeMe deq;
    clock_t start = clock();

    for (int i = 1; i < argc; i++) {
      char *end;
      errno = 0;
      long number = std::strtol(argv[i], &end, 10);

      if (*end != '\0' || errno == ERANGE || number < 0 || number > INT_MAX) {
        throw std::out_of_range(
            "The number is out of range or not a valid integer.");
      }
      deq.pushDeque(static_cast<int>(number));
    }
    deq.sortDeque();
    clock_t end = clock();
    std::cout << "Time to process a range of " << argc - 1
              << " elements with std::deque : "
              << static_cast<double>(end - start) * 1000.0 / CLOCKS_PER_SEC
              << " ms" << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
    return 1;
  }

  // try {
  //   PmergeMe vec;
  //   clock_t start = clock();

  //   for (int i = 1; i < argc; i++) {
  //     char *end;
  //     errno = 0;
  //     long number = std::strtol(argv[i], &end, 10);

  //     if (*end != '\0' || errno == ERANGE || number < 0 || number > INT_MAX)
  //     {
  //       throw std::out_of_range(
  //           "The number is out of range or not a valid integer.");
  //     }
  //     vec.pushVector(static_cast<int>(number));
  //   }
  //   vec.sortVector();
  //   clock_t end = clock();
  //   std::cout << "Time to process a range of " << argc - 1
  //             << " elements with std::vector : "
  //             << static_cast<double>(end - start) * 1000.0 / CLOCKS_PER_SEC
  //             << " ms" << std::endl;
  // } catch (const std::exception &e) {
  //   std::cout << e.what() << std::endl;
  //   return 1;
  // }

  return 0;
}