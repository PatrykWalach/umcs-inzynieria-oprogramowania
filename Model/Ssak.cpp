/**
 * Project Untitled
 */

#include "Ssak.h"
#include <iostream>

/**
 * Ssak implementation
 */

/**
 * @param imie
 * @param jestPlciMeskiej
 * @param masaG
 * @param wysokoscMm
 * @param wiekDni
 * @return
 */
Ssak::Ssak(std::string imie, bool jestPlciMeskiej, unsigned int masaG,
           unsigned int wysokoscMm, unsigned int wiekDni) {
  this->imie = imie;
  this->jestPlciMeskiej = jestPlciMeskiej;
  this->masaG = masaG;
  this->wysokoscMm = wysokoscMm;
  this->wiekDni = wiekDni;
}

/**
 * @param imie
 * @param jestPlciMeskiej
 * @param masaG
 * @param wysokoscMm
 * @return
 */
Ssak::Ssak(std::string imie, bool jestPlciMeskiej, unsigned int masaG,
           unsigned int wysokoscMm) {
  this->imie = imie;
  this->jestPlciMeskiej = jestPlciMeskiej;
  this->masaG = masaG;
  this->wysokoscMm = wysokoscMm;
}

/**
 * @return unsigned int
 */
unsigned int Ssak::getMasaG() { return masaG; }

/**
 * @return unsigned int
 */
unsigned int Ssak::getWiekDni() { return wiekDni; }

/**
 * @return unsigned int
 */
unsigned int Ssak::getWysokoscMm() { return wysokoscMm; }

/**
 * @return bool
 */
bool Ssak::getJestPlciMeskiej() { return jestPlciMeskiej; }

/**
 * @return std::string
 */
std::string Ssak::getImie() { return imie; }

void Ssak::mow() { std::cout << getImie() << " mowi" << std::endl; }

void Ssak::rusz() { std::cout << getImie() << " rusza sie" << std::endl; }