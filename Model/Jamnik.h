/**
 * Project Untitled
 */


#ifndef _JAMNIK_H
#define _JAMNIK_H

#include "Pies.h"


class Jamnik: public Pies {
public: 
      enum Wielkosc { Wielkosc_krolicza, Wielkosc_miniaturowa, Wielkosc_standardowa };
/**
 * @param imie
 * @param jestPlciMeskiej
 * @param wysokoscMm
 * @param dlugoscSiersci
 * @param masaG
 * @param wielkosc
 * @param wiekDni
 */
  Jamnik(std::string imie, bool jestPlciMeskiej, unsigned int wysokoscMm, DlugoscSiersci dlugoscSiersci, unsigned int masaG, Wielkosc wielkosc, unsigned int wiekDni);
    
/**
 * @param imie
 * @param jestPlciMeskiej
 * @param dlugoscSiersci
 * @param wielkosc
 * @param masaG
 * @param wysokoscMm
 */
  Jamnik(std::string imie, bool jestPlciMeskiej, DlugoscSiersci dlugoscSiersci, Wielkosc wielkosc, unsigned int masaG, unsigned int wysokoscMm);
    
Wielkosc getWielkosc();
    
/**
 * @param jamnik
 * @param imie
 */
Jamnik* rozmnoz(Jamnik* jamnik, std::string imie);

private: 
    Wielkosc wielkosc;
};

#endif //_JAMNIK_H