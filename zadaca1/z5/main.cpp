#include <iostream>
#include <math.h>

int main() {
  short c = 0;
  short option;
  std::cout << "Unesite opciju koju zelite: " << std::endl;
  std::cout << "\t1. Provjera trougla" << std::endl;
  std::cout << "\t2. Ispis trouglova" << std::endl;
  std::cout << "Vasa opcija: ";

  std::cin >> option;

  switch (option) {
  case 1:
    short a, b, c;
    std::cout << "Unesite duzine stranica: ";
    std::cin >> a >> b >> c;

    if (sqrt(a * a + b * b) == floor(sqrt(a * a + b * b)))
      printf("Trougao (%d, %d, %d) je pravougli trougao\n", a, b, c);
    else
      std::cout << "Uneseni trougao nije pravougli" << std::endl;
    break;
  case 2:
    std::cout << "Unesite maksimalnu duzinu hipotenuze: ";
    std::cin >> c;

    for (int a = 1; a < c; ++a) {
      for (int b = a; b <= floor(sqrt(c * c - a * a)); ++b) {
        if (sqrt(a * a + b * b) == floor(sqrt(a * a + b * b))) {
          printf("(%d, %d, %d)\n", a, b, (int)floor(sqrt(a * a + b * b)));
        }
      }
    }
    break;
  }

  return 0;
}
