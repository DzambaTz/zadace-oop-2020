#include <iostream>

namespace Fuel {
const float lkm_to_mpg_coeff = 235.215;
}
void fuel_eco() {
  int option;
  float fuel;
  std::cout << "Please choose converter: " << std::endl;
  std::cout << "\t1. Liter per 100 kilometers to miles per gallon" << std::endl;
  std::cout << "\t2. Miles per gallon to liter per 100 kilometers" << std::endl;

  do {
    std::cout << "Your option: ";
    std::cin >> option;
    if (option < 1 || option > 2)
      std::cout << "There is no such option!" << std::endl;
  } while (option < 1 || option > 2);

  switch (option) {
  case 1:
    do {
      std::cout << "Enter the fuel expenditure in liters: ";
      std::cin >> fuel;
      if (fuel < 0)
        std::cout << "Fuel expenditure cannot be negative!" << std::endl;
    } while (fuel < 0);

    std::cout << fuel << " liter per 100 kilometers is "
              << fuel * Fuel::lkm_to_mpg_coeff << " mpg" << std::endl;
    break;
  case 2:
    do {
      std::cout << "Enter the fuel expenditure in gallons: ";
      std::cin >> fuel;
      if (fuel < 0)
        std::cout << "Fuel expenditure cannot be negative!" << std::endl;
    } while (fuel < 0);

    std::cout << fuel << " mpg is " << fuel / Fuel::lkm_to_mpg_coeff
              << " liters per 100 kilometers" << std::endl;
    break;
  }
}
