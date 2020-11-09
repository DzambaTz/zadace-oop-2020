#include <iostream>

namespace Weight {
const float kg_to_lb_coeff = 2.20462;
}

void weight() {
  float weight;
  int option;
  std::cout << "Please choose converter: " << std::endl;
  std::cout << "\t1. Kilogram to pound" << std::endl;
  std::cout << "\t2. Pound to kilogram" << std::endl;

  do {
    std::cout << "Your option: ";
    std::cin >> option;

    if (option < 1 || option > 2)
      std::cout << "There is no such option!" << std::endl;

  } while (option < 1 || option > 2);

  switch (option) {
  case 1:
    do {
      std::cout << "Enter the weight in kilogram: ";
      std::cin >> weight;
      if (weight < 0)
        std::cout << "Weight cannot be negative!" << std::endl;
    } while (weight < 0);
    std::cout << weight << "kg is " << weight * Weight::kg_to_lb_coeff << "lb"
              << std::endl;
    break;
  case 2:
    do {
      std::cout << "Enter the weight in pounds: ";
      std::cin >> weight;
      if (weight < 0)
        std::cout << "Weight cannot be negative!" << std::endl;
    } while (weight < 0);
    std::cout << weight << "lb is " << weight / Weight::kg_to_lb_coeff << "kg"
              << std::endl;
    break;
  }
}
