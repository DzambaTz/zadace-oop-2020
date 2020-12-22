#include <functional>
#include <iostream>
#include <list>

std::list<int> podijeli(std::list<int>::const_iterator begin,
                        std::list<int>::const_iterator end,
                        std::function<bool(int)> predicate) {
  std::list<int> result;
  try {
    for (auto it = begin; it != end; ++it) {
      if (predicate(*it)) {
        result.push_front(*it);
      } else {
        result.push_back(*it);
      }
    }
  } catch (...) {
    result.assign(begin, end);
  }
  return result;
}

int main() {
  std::list<int> numbers{15, 20, 25, -10, -75, 100, -255, 430, 200};

  std::cout << "Original list:" << std::endl;
  for (int &e : numbers) {
    std::cout << e << " ";
  }
  std::cout << std::endl << std::endl;

  std::cout << "[](int num) { return !(num % 2); }" << std::endl;
  std::list<int> result = podijeli(numbers.cbegin(), numbers.cend(),
                                   [](int num) { return !(num % 2); });
  for (int &e : result) {
    std::cout << e << " ";
  }
  std::cout << std::endl << std::endl;

  std::cout << "[](int num) { return num > 0; }" << std::endl;
  result = podijeli(numbers.cbegin(), numbers.cend(), [](int num) {
    if (num > 400)
      throw 5;
    return num > 0;
  });
  for (int &e : result) {
    std::cout << e << " ";
  }
  std::cout << std::endl << std::endl;

  std::cout << "[](int num) { return !(num % 10); }" << std::endl;
  result = podijeli(numbers.cbegin(), numbers.cend(),
                    [](int num) { return !(num % 10); });
  for (int &e : result) {
    std::cout << e << " ";
  }
  std::cout << std::endl << std::endl;

  std::cout << "[](int num) { return std::abs(num) > 99 }" << std::endl;
  result = podijeli(numbers.cbegin(), numbers.cend(),
                    [](int num) { return std::abs(num) > 99; });
  for (int &e : result) {
    std::cout << e << " ";
  }
  std::cout << std::endl << std::endl;

  return 0;
}
