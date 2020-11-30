#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "hamming.h"

int main() {
  std::ifstream input("words.txt");
  std::vector<std::string> dictionary;
  std::string word;

  while (input >> word) {
    dictionary.push_back(word);
  }

  std::cout << "Enter a word: ";
  std::cin >> word;

  for (auto &e : similarStrings(sameLength(dictionary, word.size()), word)) {
    std::cout << e << std::endl;
  }

  return 0;
}
