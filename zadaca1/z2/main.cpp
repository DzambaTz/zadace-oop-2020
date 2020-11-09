#include <bitset>
#include <iostream>
#include <math.h>
// Poziv funkcije printBits rezultovace sa ispisom
// proslijedjenog broja u binarnoj formi.
//
// Primjer:
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// unsigned short s = 5;
// printBits(s);
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Ispis:
// 0000000000000101
//
void printBits(unsigned short reg) {
  std::bitset<16> bits(reg);
  std::cout << bits << std::endl;
}

int main() {
  unsigned short reg1 = 0, reg2 = 0, bit;
  unsigned short *active_reg = nullptr;
  int option;
  while (true) {
    std::cout << "Select the register you want to edit: " << std::endl;
    std::cout << "\t1. Register 1" << std::endl;
    std::cout << "\t2. Register 2" << std::endl;
    std::cout << "\t3. Exit" << std::endl;

    std::cout << "Enter option: ";
    std::cin >> option;
    if (option == 3) {
      break;
    }
    active_reg = (option == 1 ? &reg1 : &reg2);

    std::cout << "\t1. Print register" << std::endl;
    std::cout << "\t2. Set bit in register" << std::endl;
    std::cout << "\t3. Reset bit in register" << std::endl;
    std::cout << "\t4. Swap register values" << std::endl;
    std::cout << "\t5. Exit" << std::endl;

    std::cout << "Enter option: ";
    std::cin >> option;

    if (option == 1) {
      printBits(*active_reg);
    } else if (option == 2) {
      std::cout << "Enter bit number: ";
      std::cin >> bit;
      *active_reg += pow(2, bit);
      std::cout << "New register value: " << *active_reg << std::endl;
      printBits(*active_reg);
    } else if (option == 3) {
      std::cout << "Enter bit number: ";
      std::cin >> bit;
      *active_reg -= pow(2, bit);
      std::cout << "New register value: " << active_reg << std::endl;
      printBits(*active_reg);
    } else if (option == 4) {
      reg1 = reg1 ^ reg2;
      reg2 = reg1 ^ reg2;
      reg1 = reg1 ^ reg2;
      std::cout << "Register values have been swapped!" << std::endl;
    } else if (option == 5) {
      break;
    }
    std::cout << std::endl;
  }
  return 0;
}
