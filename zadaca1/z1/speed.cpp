#include <iostream>

void speed() {
  int option;
  float speed;
  std::cout << "Please choose converter: " << std::endl;
  std::cout << "\t1. MPH to KMH" << std::endl;
  std::cout << "\t2. KMH to MPH" << std::endl;

  do {
    std::cout << "Your choice: ";
    std::cin >> option;
    if (option < 1 || option > 2)
      std::cout << "There is no such option!" << std::endl;
  } while (option < 1 || option > 2);

  switch (option) {
  case 1:
    do {
      std::cout << "Enter the speed in miles per hour: ";
      std::cin >> speed;
      if (speed < 0)
        std::cout << "Speed cannot be negative!" << std::endl;
    } while (speed < 0);
    std::cout << speed << "MPH is " << speed * 1.60934 << "KMH" << std::endl;
    break;
  case 2:
    do {
      std::cout << "Enter the speed in kilometers per hour: ";
      std::cin >> speed;
      if (speed < 0)
        std::cout << "Speed cannot be negative!" << std::endl;
    } while (speed < 0);
    std::cout << speed << "KMH is " << speed / 1.60934 << "MPH" << std::endl;
    break;
  }
}
