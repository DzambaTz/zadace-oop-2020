#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> over25chars(std::vector<std::string> &v) {
  std::vector<std::string> result;

  for (auto &str : v) {
    if (str.size() > 25) {
      result.push_back(str);
    }
  }

  return result;
}

int main() {
  std::ifstream dictionaryFile("words.txt");
  std::vector<std::string> dictionary;
  std::string word;
  while (dictionaryFile >> word) {
    dictionary.push_back(word); // std::move(word);
  }

  std::cout << "Words longer that 25 characters:" << std::endl;

  for (auto &str : over25chars(dictionary)) {
    std::cout << str << std::endl;
  }
  return 0;
}
