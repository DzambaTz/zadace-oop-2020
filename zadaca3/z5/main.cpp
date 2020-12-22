#include <algorithm>
#include <iostream>
#include <string>
template <typename T>
bool jednako(typename T::const_iterator begin1, typename T::const_iterator end,
             typename T::const_iterator begin2) {

  while (begin1 != end) {
    if (*begin1 != *begin2) {
      return false;
    }
    ++begin1;
    ++begin2;
  }
  return true;
}

int main() {
  std::string word;
  while (std::cin >> word) {
    std::string reverse = std::string(word.rbegin(), word.rend());
    if (jednako<std::string>(word.cbegin(), word.cend(), reverse.cbegin())) {
      std::cout << word << ": Palindrom" << std::endl;
    }
  }
  return 0;
}
