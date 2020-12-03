#include <functional>
#include <iostream>
#include <math.h>
#include <vector>

// Adds user input to `number` parameter passed by ref
// Returns user input
double add(double &number) {
  double input;
  std::cout << "Number to add: ";
  std::cin >> input;
  std::cin.ignore();
  number += input;
  return input;
}

double subtract(double &number) {
  double input;
  std::cout << "Number to subtract: ";
  std::cin >> input;
  std::cin.ignore();
  number -= input;
  return input;
}

double multiply(double &number) {
  double input;
  std::cout << "Number to multiply with: ";
  std::cin >> input;
  std::cin.ignore();
  number *= input;
  return input;
}

double divide(double &number) {
  double input;
  std::cout << "Number to divide with: ";
  std::cin >> input;
  std::cin.ignore();
  number /= input;
  return input;
}

double square(double &number) { return number *= number; }

int main(void) {
  double number = 0;
  std::vector<std::function<double()>> undoFunctions;
  std::vector<std::function<double()>> redoFunctions;
  int choice = -1;
  while (choice != 9) {
    std::cout << std::endl;
    std::cout << "****************************" << std::endl;
    std::cout << "New value: " << number << std::endl;
    std::cout << "****************************" << std::endl;
    std::cout << std::endl;
    std::cout << "1. Add" << std::endl;
    std::cout << "2. Subtract" << std::endl;
    std::cout << "3. Multiply" << std::endl;
    std::cout << "4. Divide" << std::endl;
    std::cout << "5. Square" << std::endl;
    std::cout << "6. Square root" << std::endl;
    std::cout << "7. Undo" << std::endl;
    std::cout << "8. Redo" << std::endl;
    std::cout << "9. Exit" << std::endl;
    std::cout << "Choice: ";
    std::cin >> choice;
    std::cin.ignore();
    if (choice == 1) {
      auto input = add(number);
      undoFunctions.push_back([input, &number]() {
        auto oldNumber = number;
        number -= input;
        return oldNumber;
      });
    } else if (choice == 2) {
      auto input = subtract(number);
      undoFunctions.push_back([input, &number]() {
        auto oldNumber = number;
        number += input;
        return oldNumber;
      });
    } else if (choice == 3) {
      auto input = multiply(number);
      undoFunctions.push_back([input, &number]() {
        auto oldNumber = number;
        number /= input;
        return oldNumber;
      });
    } else if (choice == 4) {
      auto input = divide(number);
      undoFunctions.push_back([input, &number]() {
        auto oldNumber = number;
        number *= input;
        return oldNumber;
      });
    } else if (choice == 5) {
      square(number);
      undoFunctions.push_back([&number]() {
        auto oldNumber = number;
        number = std::sqrt(number);
        return oldNumber;
      });
    } else if (choice == 6) {
      number = std::sqrt(number);
      undoFunctions.push_back([&number]() {
        auto oldNumber = number;
        square(number);
        return oldNumber;
      });
    } else if (choice == 7) {
      if (!undoFunctions.empty()) {
        std::cout << std::endl;
        std::cout << "Undoing..." << std::endl;
        std::cout << std::endl;
        auto &undoFunction = undoFunctions.back();
        double oldNumber = undoFunction();
        redoFunctions.push_back([oldNumber, &number]() {
          double old = number;
          number = oldNumber;
          return old;
        });
        undoFunctions.pop_back();
      } else {
        std::cout << "Nothing to undo!" << std::endl;
      }
    } else if (choice == 8) {
      if (!redoFunctions.empty()) {
        std::cout << std::endl;
        std::cout << "Redoing..." << std::endl;
        std::cout << std::endl;
        auto &redoFunction = redoFunctions.back();
        double oldNumber = redoFunction();
        undoFunctions.push_back([oldNumber, &number]() {
          double old = number;
          number = oldNumber;
          return old;
        });
        redoFunctions.pop_back();
      } else {
        std::cout << "Nothing to redo" << std::endl;
      }
    }
  }

  return 0;
}
