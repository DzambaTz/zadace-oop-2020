#include "options.h"
#include <iostream>

int main() {
  int option;
  std::cout
      << "Welcome to Unit converter. Please enter one of the following options:"
      << std::endl;
  std::cout << "\t1. Temperature" << std::endl;
  std::cout << "\t2. Speed" << std::endl;
  std::cout << "\t3. Length" << std::endl;
  std::cout << "\t4. Weight" << std::endl;
  std::cout << "\t5. Fuel economy" << std::endl;

  do {
    std::cout << "Your choice: ";
    std::cin >> option;
    if (option < 0 || option > 5)
      std::cout << "There is no such option!" << std::endl;
  } while (option < 0 || option > 5);

  switch (option) {
  case 1:
    temperature();
    break;
  case 2:
    speed();
    break;
  case 3:
    length();
    break;
  case 4:
    weight();
    break;
  case 5:
    fuel_eco();
    break;
  }

  return 0;
}
