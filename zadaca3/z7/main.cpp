#include "Baza.hpp"
#include "Radnik.hpp"
#include <iostream>
int main() {
  BazaRadnika b1;
  b1.ucitaj(std::cin);
  if (b1.izbrisi_radnika("Alen")) {
    std::cout << "Alen izbrisan" << std::endl;
  } else {
    std::cout << "Brisanje nije moguce !" << std::endl;
  }
  std::cout << "U bazi su : " << std::endl;
  b1.ispisi(std::cout);
  std::cout << "Prosjek plata je : " << b1.prosjek_plata() << std::endl;
  std::cout << "Prosjek godina je : " << b1.prosjek_godina() << std::endl;
  return 0;
}
