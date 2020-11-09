#include <cctype>
#include <iostream>
#include <string.h>

int main() {
  std::string s1, s2;
  short distance = 0;
  do {
    std::cout << "Unesite prvi string: ";
    std::cin >> s1;
    std::cout << "Unesite drugi string: ";
    std::cin >> s2;
    if (s1.length() != s2.length())
      std::cout << "Uneseni stringovi moraju biti iste duzine!" << std::endl;
  } while (s1.length() != s2.length());

  for (int i = 0; i < s1.length(); ++i) {
    if (tolower(s1[i]) != tolower(s2[i]))
      ++distance;
  }

  std::cout << "Hammingova udaljenost je: " << distance << std::endl;

  return 0;
}
