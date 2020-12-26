#pragma once
#include "Radnik.hpp"
#include <vector>
struct BazaRadnika {
  std::vector<Radnik> baza;
  void ucitaj(std::istream &);
  bool izbrisi_radnika(const std::string &);
  void ispisi(std::ostream &);
  float prosjek_plata();
  float prosjek_godina();
};
