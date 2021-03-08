/**
 * Project Untitled
 */

#include "Pies.h"

#include <iostream>


#include "Czlowiek.h"
#include "../util.h"
/**
 * Pies implementation
 */

/**
 * @param imie
 * @param jestPlciMeskiej
 * @param ksztaltGlowy
 * @param typUszu
 * @param dlugoscSiersci
 * @param masaG
 * @param wysokoscMm
 * @param wiekDni
 * @return
 */
Pies::Pies(std::string imie, bool jestPlciMeskiej, KsztaltGlowy ksztaltGlowy,
           TypUszu typUszu, DlugoscSiersci dlugoscSiersci, unsigned int masaG,
           unsigned int wysokoscMm, unsigned int wiekDni)
    : Ssak(imie, jestPlciMeskiej, masaG, wysokoscMm, wiekDni) {
  this->ksztaltGlowy = ksztaltGlowy;
  this->typUszu = typUszu;
  this->dlugoscSiersci = dlugoscSiersci;
}

/**
 * @param imie
 * @param jestPlciMeskiej
 * @param ksztaltGlowy
 * @param typUszu
 * @param dlugoscSiersci
 * @param masaG
 * @param wysokoscMm
 * @return
 */
Pies::Pies(std::string imie, bool jestPlciMeskiej, KsztaltGlowy ksztaltGlowy,
           TypUszu typUszu, DlugoscSiersci dlugoscSiersci, unsigned int masaG,
           unsigned int wysokoscMm)
    : Ssak(imie, jestPlciMeskiej, masaG, wysokoscMm) {
  this->ksztaltGlowy = ksztaltGlowy;
  this->typUszu = typUszu;
  this->dlugoscSiersci = dlugoscSiersci;
}

/**
 * @param pies
 * @param imie
 * @return Pies*
 */
Pies* Pies::rozmnoz(Pies* pies, std::string imie) {
  if (getJestPlciMeskiej() == pies->getJestPlciMeskiej()) {
    std::cout << "dwa psy tej samej plci nie moga sie rozmnozyc" << std::endl;
    return nullptr;
  }
  auto nowyPies =
      new Pies(imie, random({getJestPlciMeskiej(), pies->getJestPlciMeskiej()}),
               random({ksztaltGlowy, pies->ksztaltGlowy}),
               random({typUszu, pies->typUszu}),
               random({dlugoscSiersci, pies->dlugoscSiersci}),
               random(500, 1000), random(100, 50));

  std::cout << "narodzil się nowy pies " << imie << std::endl;

  return nowyPies;
}

void Pies::mow() {
  std::cout << getImie() << ": \"" << random({"RROWFF!!", "WOOF!!"}) << "\""
            << std::endl;
}
/**
 * @return KsztaltGlowy
 */
Pies::KsztaltGlowy Pies::getKsztaltGlowy() { return ksztaltGlowy; }

/**
 * @return TypUszu
 */
Pies::TypUszu Pies::getTypUszu() { return typUszu; }

/**
 * @return DlugoscSiersci
 */
Pies::DlugoscSiersci Pies::getDlugoscSiersci() { return dlugoscSiersci; }

/**
 * @param czlowiek
 */
void Pies::podajLape(Czlowiek czlowiek) {
  std::cout << getImie() << " podaje lape " << czlowiek.getImie() << std::endl;
}

void Pies::aportuj() { std::cout << getImie() << " aportuje" << std::endl; }
void Pies::rusz() {
    std::cout << getImie() << " podbiega energicznie" << std::endl;
}