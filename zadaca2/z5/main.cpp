#include <iostream>
#include <map>
#include <string>

int main() {
  std::string recenica;
  std::cout << "Unesite recenicu: " << std::endl;
  std::getline(std::cin, recenica);

  std::map<char, short> counter;
  for (auto &c : recenica) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
      ++counter[tolower(c)];
    }
  }

  std::cout << "Broj pojavljivanja karaktera: " << std::endl;
  for (auto &[c, count] : counter) {
    std::cout << c << ": " << count << std::endl;
  }

  return 0;
}
