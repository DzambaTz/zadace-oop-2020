#include <ios>
#include <iostream>

namespace Length {
const double ly_km_coeff = 9.461e+12;
const float ft_m_coeff = 3.28084;
const float inch_to_cm_coeff = 2.54;
} // namespace Length

void ly_to_km() {
  float length;
  do {
    std::cout << "Enter the length ih light years: ";
    std::cin >> length;
    if (length < 0)
      std::cout << "Length cannot be negative!" << std::endl;
  } while (length < 0);

  std::cout << length << " light years is " << std::scientific
            << length * Length::ly_km_coeff << "km" << std::endl;
}

void km_to_ly() {
  float length;
  do {
    std::cout << "Enter the length ih kilometers: ";
    std::cin >> length;
    if (length < 0)
      std::cout << "Length cannot be negative!" << std::endl;
  } while (length < 0);

  std::cout << length << " kilometers is " << std::scientific
            << length / Length::ly_km_coeff << "km" << std::endl;
}

void ft_to_m() {
  float length;
  do {
    std::cout << "Enter the length in feet: ";
    std::cin >> length;
    if (length < 0)
      std::cout << "Length cannot be negative!" << std::endl;
  } while (length < 0);
  std::cout << length << "ft is " << length / Length::ft_m_coeff << "m"
            << std::endl;
}

void m_to_ft() {
  float length;
  do {
    std::cout << "Enter the length in meters: ";
    std::cin >> length;
    if (length < 0)
      std::cout << "Length cannot be negative!" << std::endl;
  } while (length < 0);
  std::cout << length << "m is " << length * Length::ft_m_coeff << "ft"
            << std::endl;
}

void inch_to_cm() {
  float length;
  do {
    std::cout << "Enter the length in inches: ";
    std::cin >> length;
    if (length < 0)
      std::cout << "Length cannot be negative!" << std::endl;
  } while (length < 0);
  std::cout << length << " inches is " << length * Length::inch_to_cm_coeff
            << " centimeters" << std::endl;
}

void cm_to_inch() {
  float length;
  do {
    std::cout << "Enter the length in centimeters: ";
    std::cin >> length;
    if (length < 0)
      std::cout << "Length cannot be negative!" << std::endl;
  } while (length < 0);
  std::cout << length << " centimeters is " << length / Length::inch_to_cm_coeff
            << " inches" << std::endl;
}

void length() {
  short option;
  std::cout << "Please choose converter: " << std::endl;
  std::cout << "\t1. Light years to kilometers" << std::endl;
  std::cout << "\t2. Kilometers to light years" << std::endl;
  std::cout << "\t3. Feet to meters" << std::endl;
  std::cout << "\t4. Meters to feet" << std::endl;
  std::cout << "\t5. Inches to centimeters" << std::endl;
  std::cout << "\t6. Centimeters to inches" << std::endl;

  do {
    std::cout << "Your choice: ";
    std::cin >> option;
    if (option < 1 || option > 6)
      std::cout << "There is no such option!" << std::endl;
  } while (option < 1 || option > 6);

  switch (option) {
  case 1:
    ly_to_km();
    break;
  case 2:
    km_to_ly();
    break;
  case 3:
    ft_to_m();
    break;
  case 4:
    m_to_ft();
    break;
  case 5:
    inch_to_cm();
    break;
  case 6:
    cm_to_inch();
    break;
  }
}
