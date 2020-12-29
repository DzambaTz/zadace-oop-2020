#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "my.hpp"

#include <algorithm>
#include <list>
#include <string>
#include <vector>

TEST_CASE("my::sort sorts an empty vector") {
  std::vector<int> v;
  my::sort(std::begin(v), std::end(v));
  CHECK(v.size() == 0);
}

TEST_CASE("my::sort sorts a vector of one element") {
  std::vector<int> v{5};
  my::sort(begin(v), end(v));
  CHECK(v[0] == 5);
}

TEST_CASE("my::sort sorts a vector of two ints") {
  std::vector<int> v{5, 1};
  my::sort(begin(v), end(v));
  bool is_sorted = v[0] == 1 && v[1] == 5;
  CHECK(is_sorted);
}

TEST_CASE("my::sort sorts a vector of four ints with repeating elements") {
  std::vector<int> v{5, 1, 5, 1};
  my::sort(begin(v), end(v));
  bool is_sorted = v[0] == 1 && v[1] == 1 && v[2] == 5 && v[3] == 5;
  CHECK(is_sorted);
}

TEST_CASE("my::sort sorts a vector of six ints") {
  std::vector<int> v{0, 10, -8, 1, 18, -22};
  std::vector<int> s{-22, -8, 0, 1, 10, 18};
  my::sort(begin(v), end(v));
  CHECK(equal(begin(v), end(v), begin(s)));
}

TEST_CASE("my::sort sorts a list of six ints with a predicate function") {
  std::list<int> v{0, 10, -8, 1, 18, -8};
  std::list<int> s{-8, -8, 0, 1, 10, 18};
  my::sort(begin(v), end(v),
           [](const auto &a, const auto &b) { return a > b; });
  reverse(begin(s), end(s));
  CHECK(equal(begin(v), end(v), begin(s)));
}

TEST_CASE("my::sort sorts a vector of four strings with a predicate function") {
  std::vector<std::string> v{"ako", "p", "onda", "q"};
  std::vector<std::string> s{"onda", "ako", "p", "q"};
  my::sort(begin(v), end(v),
           [](const auto &a, const auto &b) { return a.size() >= b.size(); });
  CHECK(equal(begin(v), end(v), begin(s)));
}
