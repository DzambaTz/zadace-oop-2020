#pragma once
#include "structs.hpp"

Predmet unesi_predmet(std::list<Predmet> &);
Student unesi_studenta(std::list<Predmet> &, std::vector<Student> &);
void ispisi_studente(std::vector<Student> &);
void edit(std::list<Predmet> &, std::vector<Student> &);
std::vector<OcjenaIzPredmeta> unesi_ocjene(std::list<Predmet> &,
                                           std::vector<Student> &);
void main_menu(short &);
