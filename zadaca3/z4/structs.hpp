#pragma once
#include <list>
#include <string>
#include <vector>

struct Predmet {
  std::string naziv;
  std::string odsjek;
};

struct OcjenaIzPredmeta {
  int ocjena;
  std::list<Predmet>::const_iterator predmet;
};

struct Student {
  std::string brojIndeksa;
  std::string ime;
  std::string prezime;
  std::string grad;
  std::vector<OcjenaIzPredmeta> ocjene;
};
