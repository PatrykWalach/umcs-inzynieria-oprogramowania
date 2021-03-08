/**
 * Project Untitled
 */

#include "Czlowiek.h"

#include <iostream>
#include <stdexcept>

#include "util.h"

/**
 * Czlowiek implementation
 */

/**
 * @param imie
 * @param jestPlciMeskiej
 * @param masaG
 * @param wysokoscMm
 * @param wiekDni
 * @return
 */
Czlowiek::Czlowiek(std::string imie, bool jestPlciMeskiej, unsigned int masaG,
                   unsigned int wysokoscMm, unsigned int wiekDni)
    : Ssak(imie, jestPlciMeskiej, masaG, wysokoscMm, wiekDni) {}

void Czlowiek::prowadzSwojegoPsaNaSpacer() { prowadzPsaNaSpacer(*pies); }

/**
 * @return Pies*
 */
Pies* Czlowiek::getPies() { return pies; }

/**
 * @param value
 */
void Czlowiek::setPies(Pies* value) { this->pies = value; }

/**
 * @param czlowiek
 * @param imie
 * @return Czlowiek*
 */
Czlowiek* Czlowiek::rozmnoz(Czlowiek* czlowiek, std::string imie) {
  if (getJestPlciMeskiej() == czlowiek->getJestPlciMeskiej()) {
    std::cout << "dwoje ludzi tej samej plci nie moga sie rozmnozyc"
              << std::endl;
    return nullptr;
  }
  auto nowyCzlowiek = new Czlowiek(
      imie, random({getJestPlciMeskiej(), czlowiek->getJestPlciMeskiej()}),
      random(2500, 3500), random(300, 500), 0);

  std::cout << "narodzil się nowy czlowiek " << imie << std::endl;

  return nowyCzlowiek;
}

/**
 * @param pies
 */
void Czlowiek::prowadzPsaNaSpacer(Pies pies) {
  std::cout << getImie() << " wyprowadza " << pies.getImie() << " na spacer"
            << std::endl;
}