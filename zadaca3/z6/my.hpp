#pragma once
#include <functional>
#include <iterator>

namespace my {
template <typename Iter, typename lambda>
void sort(Iter begin, Iter end, lambda f) {
  if (begin == end)
    return;
  bool swapped;
  Iter last_swap = --end;
  Iter it = begin;
  do {
    swapped = false;
    for (; it != last_swap; ++it) {
      if (!f(*it, *(std::next(it)))) {
        std::swap(*it, *(std::next(it)));
        swapped = true;
      }
    }
    last_swap = begin;
    std::advance(last_swap, std::distance(begin, it) - 1);
    it = begin;
  } while (swapped);
}

template <typename Iter> void sort(Iter begin, Iter end) {
  if (begin == end)
    return;
  bool swapped;
  Iter last_swap = --end;
  Iter it = begin;
  do {
    swapped = false;
    for (; it != last_swap; ++it) {
      if (*it > *(std::next(it))) {
        std::swap(*it, *(std::next(it)));
        swapped = true;
      }
    }
    last_swap = begin;
    std::advance(last_swap, std::distance(begin, it) - 1);
    it = begin;
  } while (swapped);
}
} // namespace my
