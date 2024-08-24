#include <iostream>

#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "Error: Invalid input" << std::endl;
    return 1;
  }

  try {
    BitcoinExchange bitcoin(argv[1]);
    bitcoin.printValidateValue();

  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}