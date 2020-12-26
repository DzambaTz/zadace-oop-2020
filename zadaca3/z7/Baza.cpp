#include "Baza.hpp"
#include <iostream>
#include <stdexcept>

void BazaRadnika::ucitaj(std::istream &is) {
  Radnik radnik;
  while (is >> radnik.ime >> radnik.plata >> radnik.godine) {
    try {
      for (auto &[ime, plata, godine] : this->baza) {
        if (radnik.ime == ime) {
          throw std::domain_error("Radnik vec u bazi");
        }
      }
      this->baza.push_back(radnik);
    } catch (std::domain_error e) {
      std::cout << e.what() << std::endl;
    }
  }
}

bool BazaRadnika::izbrisi_radnika(const std::string &ime) {
  for (auto it = this->baza.begin(); it != this->baza.end(); ++it) {
    if (it->ime == ime) {
      this->baza.erase(it);
      return true;
    }
  }
  return false;
}

void BazaRadnika::ispisi(std::ostream &os) {
  for (auto &[ime, plata, godine] : this->baza) {
    os << ime << " " << plata << " " << godine << std::endl;
  }
}

float BazaRadnika::prosjek_plata() {
  float prosjek = 0;
  for (auto &[ime, plata, godine] : this->baza) {
    prosjek += plata;
  }
  return prosjek / this->baza.size();
}

float BazaRadnika::prosjek_godina() {
  float prosjek = 0;
  for (auto &[ime, plata, godine] : this->baza) {
    prosjek += godine;
  }
  return prosjek / this->baza.size();
}
