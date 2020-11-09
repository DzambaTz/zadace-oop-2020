#include <iostream>

void c_to_f() {
  float temp;
  do {
    std::cout << "Enter the temperature in celsius: ";
    std::cin >> temp;
    if (temp < -273.15) {
      std::cout << "Temperature cannot be below -273.15 celsius!" << std::endl;
    }
  } while (temp < -273.15);

  std::cout << temp << "C is " << temp * 9 / 5 + 32 << "F" << std::endl;
}

void f_to_c() {
  float temp;
  do {
    std::cout << "Enter the temperature in fahrenheit: ";
    std::cin >> temp;
    if (temp < -459.67) {
      std::cout << "Temperature cannot be below -459.67 fahrenheit!"
                << std::endl;
    }
  } while (temp < -459.67);

  std::cout << temp << "F is " << (temp - 32) * 5 / 9 << "C" << std::endl;
}

void c_to_k() {
  float temp;
  do {
    std::cout << "Enter the temperature in celsius: ";
    std::cin >> temp;
    if (temp < -273.15) {
      std::cout << "Temperature cannot be below -273.15 celsius!" << std::endl;
    }
  } while (temp < -273.15);
  std::cout << temp << "C is " << temp + 273.15 << "K" << std::endl;
}

void k_to_c() {
  float temp;
  do {
    std::cout << "Enter the temperature in kelvin: ";
    std::cin >> temp;
    if (temp < 0) {
      std::cout << "Temperature cannot be below 0 kelvin!" << std::endl;
    }
  } while (temp < 0);
  std::cout << temp << "K is " << temp - 273.15 << "C" << std::endl;
}

void f_to_k() {
  float temp;
  do {
    std::cout << "Enter the temperature in fahrenheit: ";
    std::cin >> temp;
    if (temp < -459.67) {
      std::cout << "Temperature cannot be below -459.67 fahrenheit!"
                << std::endl;
    }
  } while (temp < -459.67);

  std::cout << temp << "F is " << (temp - 32) * 5 / 9 + 273.15 << "K"
            << std::endl;
}

void k_to_f() {
  float temp;
  do {
    std::cout << "Enter the temperature in kelvin: ";
    std::cin >> temp;
    if (temp < 0) {
      std::cout << "Temperature cannot be below 0 kelvin!" << std::endl;
    }
  } while (temp < 0);
  std::cout << temp << "K is " << (temp - 273.15) * 9 / 5 + 32 << "C"
            << std::endl;
}

void temperature() {
  int option;
  std::cout << "Please choose converter: " << std::endl;
  std::cout << "\t1. Celsius to Fahrenheit" << std::endl;
  std::cout << "\t2. Fahrenheit to Celsius" << std::endl;
  std::cout << "\t3. Celsius to Kelvin" << std::endl;
  std::cout << "\t4. Kelvin to Celsius" << std::endl;
  std::cout << "\t5. Fahrenheit to Kelvin" << std::endl;
  std::cout << "\t6. Kelvin to Fahrenheit" << std::endl;

  do {
    std::cout << "Your choice: ";
    std::cin >> option;
    if (option < 0 || option > 6) {
      std::cout << "There is no such option!";
    }
  } while (option < 0 || option > 6);
  switch (option) {
  case 1:
    c_to_f();
    break;
  case 2:
    f_to_c();
    break;
  case 3:
    c_to_k();
    break;
  case 4:
    k_to_c();
    break;
  case 5:
    f_to_k();
    break;
  case 6:
    k_to_f();
    break;
  }
}
