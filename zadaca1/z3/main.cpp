#include <chrono>
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

int main() {
  char symbols[4] = {'|', '/', '-', '\\'};
  while (true) {
    for (int i = 0; i < broj_kolona(); ++i) {
      std::cout << "\b " << symbols[i % 4];
      pauziraj(35);
    }
    std::cout << "\b |";
    pauziraj(100);
    std::cout << "\b  ";
    for (int i = broj_kolona(); i > 0; --i) {
      std::cout << "\b\b" << symbols[i % 4] << " \b";
      pauziraj(35);
    }
    std::cout << "\b|";
    pauziraj(100);
  }
  return 0;
}
