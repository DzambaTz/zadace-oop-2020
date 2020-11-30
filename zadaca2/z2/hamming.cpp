#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> sameLength(std::vector<std::string> &v, size_t size) {
  std::vector<std::string> result;
  for (auto &e : v) {
    if (e.size() == size) {
      result.push_back(e);
    }
  }
  return result;
}

std::vector<std::string> similarStrings(const std::vector<std::string> &v,
                                        std::string &word) {
  std::vector<std::string> result;
  short count;
  size_t i;
  for (auto &e : v) {
    count = 0;
    i = 0;
    while (count < 2 && i < word.size()) {
      if (tolower(e[i]) != tolower(word[i])) {
        ++count;
      }
      ++i;
    }
    if (count < 2) {
      result.push_back(e);
    }
  }
  if (result.size() == 0) {
    std::cout << "Couldn't find words with distance less than 2" << std::endl;
    return {};
  }
  std::sort(result.begin(), result.end(), [&](std::string a, std::string b) {
    for (size_t i = 0; i < a.size(); ++i) {
      if (tolower(a[i]) != tolower(word[i])) {
        return false;
      }
    }
    return true;
  });

  return result;
}
