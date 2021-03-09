/**
 * Project Untitled
 */

#include "Jamnik.h"

#include <iostream>

#include "../util.h"

/**
 * Jamnik implementation
 */

/**
 * @param imie
 * @param jestPlciMeskiej
 * @param wysokoscMm
 * @param dlugoscSiersci
 * @param masaG
 * @param wielkosc
 * @param wiekDni
 * @return
 */
Jamnik::Jamnik(std::string imie, bool jestPlciMeskiej, unsigned int wysokoscMm,
               DlugoscSiersci dlugoscSiersci, unsigned int masaG,
               Wielkosc wielkosc, unsigned int wiekDni)
    : Pies(imie, jestPlciMeskiej, Pies::KsztaltGlowy_dlugi,
           Pies::TypUszu_dlugie, dlugoscSiersci, masaG, wysokoscMm, wiekDni) {
  this->wielkosc = wielkosc;
}

/**
 * @param imie
 * @param jestPlciMeskiej
 * @param dlugoscSiersci
 * @param wielkosc
 * @param masaG
 * @param wysokoscMm
 * @return
 */
Jamnik::Jamnik(std::string imie, bool jestPlciMeskiej,
               DlugoscSiersci dlugoscSiersci, Wielkosc wielkosc,
               unsigned int masaG, unsigned int wysokoscMm)
    : Pies(imie, jestPlciMeskiej, Pies::KsztaltGlowy_dlugi,
           Pies::TypUszu_dlugie, dlugoscSiersci, masaG, wysokoscMm) {
  this->wielkosc = wielkosc;
}

/**
 * @return Wielkosc
 */
Jamnik::Wielkosc Jamnik::getWielkosc() { return wielkosc; }

/**
 * @param jamnik
 * @param imie
 * @return Jamnik*
 */
Jamnik* Jamnik::rozmnoz(Jamnik* jamnik, std::string imie) {
  if (getJestPlciMeskiej() == jamnik->getJestPlciMeskiej()) {
    std::cout << "dwa jamniki tej samej plci nie moga sie rozmnozyc"
              << std::endl;
    return nullptr;
  }
  auto nowyJamnik = new Jamnik(
      imie, random({getJestPlciMeskiej(), jamnik->getJestPlciMeskiej()}),
      random({getDlugoscSiersci(), jamnik->getDlugoscSiersci()}),
      random({wielkosc, jamnik->wielkosc}), random(500, 1000), random(100, 50));

  std::cout << "Narodzil się nowy jamnik " << imie << "." << std::endl;

  return nowyJamnik;
}
