#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

bool validate_sequence(std::string &sequence) {
  for (char &c : sequence) {
    if (c != 'A' && c != 'B' && c != 'C' && c != 'D') {
      std::cout << "Unesena sekvenca sadrzi nedozvoljene karaktere!"
                << std::endl;
      return false;
    }
  }
  return true;
}

int main() {
  std::string sequence;
  std::unordered_map<std::string, int> seq_map;
  std::unordered_map<char, short> char_values = {
      {'A', 135}, {'B', 151}, {'C', 111}, {'D', 126}};

  std::cout << "Unesite sekvence: " << std::endl;
  do {
    std::cin >> sequence;
    if (sequence == "END") {
      std::vector<std::pair<std::string, int>> sorted;
      auto compare = [](std::pair<std::string, int> &a,
                        std::pair<std::string, int> &b) {
        return a.second != b.second ? a.second > b.second : a.first > b.first;
      };
      for (auto &p : seq_map) {
        sorted.push_back(p);
      }
      std::sort(sorted.begin(), sorted.end(), compare);
      for (auto &[seq, value] : sorted) {
        std::cout << seq << ": " << value << std::endl;
      }
      break;
    } else {
      if (validate_sequence(sequence)) {
        if (seq_map[sequence] == 0) {
          for (auto &c : sequence) {
            seq_map[sequence] += char_values[c] + 180;
          }
        }
      }
    }
  } while (true);

  return 0;
}
