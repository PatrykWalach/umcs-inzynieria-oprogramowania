/**
 * Project Untitled
 */

#ifndef _PIES_H
#define _PIES_H

#include "Ssak.h"

class Pies : public Ssak {
 public:
  enum DlugoscSiersci {
    DlugoscSiersci_dluga,
    DlugoscSiersci_krotka,
    DlugoscSiersci_szorstka
  };
  enum TypUszu { TypUszu_dlugie, TypUszu_krotkie, TypUszu_stojace };
  enum KsztaltGlowy {
    KsztaltGlowy_okragly,
    KsztaltGlowy_dlugi,
    KsztaltGlowy_kwadratowy
  };
  /**
   * @param imie
   * @param jestPlciMeskiej
   * @param ksztaltGlowy
   * @param typUszu
   * @param dlugoscSiersci
   * @param masaG
   * @param wysokoscMm
   * @param wiekDni
   */
  Pies(std::string imie, bool jestPlciMeskiej, KsztaltGlowy ksztaltGlowy,
       TypUszu typUszu, DlugoscSiersci dlugoscSiersci, unsigned int masaG,
       unsigned int wysokoscMm, unsigned int wiekDni);

  /**
   * @param imie
   * @param jestPlciMeskiej
   * @param ksztaltGlowy
   * @param typUszu
   * @param dlugoscSiersci
   * @param masaG
   * @param wysokoscMm
   */
  Pies(std::string imie, bool jestPlciMeskiej, KsztaltGlowy ksztaltGlowy,
       TypUszu typUszu, DlugoscSiersci dlugoscSiersci, unsigned int masaG,
       unsigned int wysokoscMm);

  /**
   * @param pies
   * @param imie
   */
  Pies* rozmnoz(Pies* pies, std::string imie);

  void warcz();

  KsztaltGlowy getKsztaltGlowy();

  TypUszu getTypUszu();

  DlugoscSiersci getDlugoscSiersci();

  void podajLape();

  void aportuj();

 private:
  KsztaltGlowy ksztaltGlowy;
  TypUszu typUszu;
  DlugoscSiersci dlugoscSiersci;
};

#endif  //_PIES_H