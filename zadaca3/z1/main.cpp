#include <iostream>
#include <list>

std::list<int> parni_neparni(std::list<int>::const_iterator &&begin,
                             std::list<int>::const_iterator &&end) {
  std::list<int> result;
  while (begin != end) {
    if ((*begin) % 2 == 0) {
      result.push_front(*begin);
    } else {
      result.push_back(*begin);
    }
    begin++;
  }
  return result;
}

int main() {
  std::list<int> numbers{15, 20, 25, -10, -75, 100, -255, 430, 200};
  std::list<int> result = parni_neparni(numbers.cbegin(), numbers.cend());

  for (int &e : result) {
    std::cout << e << " ";
  }
  std::cout << std::endl;

  return 0;
}
