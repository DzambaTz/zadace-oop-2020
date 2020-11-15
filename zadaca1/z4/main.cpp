#include <chrono>
#include <cstdio>
#include <iostream>
#include <sys/ioctl.h>
#include <thread>

size_t broj_kolona() {
  winsize sz;
  ioctl(0, TIOCGWINSZ, &sz);
  return sz.ws_col;
}

void pauziraj(unsigned int msec) {
  std::flush(std::cout);
  std::this_thread::sleep_for(std::chrono::milliseconds{msec});
}

void print_segment(const int length, const char c) {
  std::string segment(length, c);
  std::cout << segment;
}

void print_segment(const int length, const char c, const int timeout) {
  std::string segment(length, c);
  std::cout << segment;
  pauziraj(timeout);
}

int main() {
  short g1, g2, g3, g4, col_num, extra;

  std::cout << "Insert 4 animation boundaries (0-100): ";
  std::cin >> g1 >> g2 >> g3 >> g4;

  if (g1 + g2 + g3 + g4 != 100) {
    std::cout << "Boundaries must have a sum equal to 100" << std::endl;
    return 0;
  }

  while (true) {
    col_num = broj_kolona();
    print_segment(col_num - 1, ' ');
    col_num -= 2;
    extra = col_num - col_num * g1 / 100 - col_num * g2 / 100 -
            col_num * g3 / 100 - col_num * g4 / 100;
    std::cout << ']';
    std::cout << '\r';
    std::cout << '[';
    print_segment(col_num * g1 / 100, '=', 600);
    print_segment(col_num * g2 / 100, '=', 600);
    print_segment(col_num * g3 / 100, '=', 600);
    print_segment(col_num * g4 / 100 + extra, '=', 600);
    std::cout << '\r';
    std::cout << '[';
    print_segment(col_num * g1 / 100, ' ', 600);
    print_segment(col_num * g2 / 100, ' ', 600);
    print_segment(col_num * g3 / 100, ' ', 600);
    print_segment(col_num * g4 / 100 + extra, ' ');
    std::cout << '\r';
  }
  return 0;
}
