/**
 * Project Untitled
 */

#ifndef _SSAK_H
#define _SSAK_H
#include <string>

class Ssak {
 public:
  /**
   * @param imie
   * @param jestPlciMeskiej
   * @param masaG
   * @param wysokoscMm
   * @param wiekDni
   */
  Ssak(std::string imie, bool jestPlciMeskiej, unsigned int masaG,
       unsigned int wysokoscMm, unsigned int wiekDni);

  /**
   * @param imie
   * @param jestPlciMeskiej
   * @param masaG
   * @param wysokoscMm
   */
  Ssak(std::string imie, bool jestPlciMeskiej, unsigned int masaG,
       unsigned int wysokoscMm);

  unsigned int getMasaG();

  unsigned int getWiekDni();

  unsigned int getWysokoscMm();

  bool getJestPlciMeskiej();

  std::string getImie();

 private:
  std::string imie;
  bool jestPlciMeskiej;
  unsigned int masaG;
  unsigned int wysokoscMm;
  unsigned int wiekDni = 0;
};

#endif  //_SSAK_H