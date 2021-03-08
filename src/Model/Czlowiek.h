/**
 * Project Untitled
 */


#ifndef _CZLOWIEK_H
#define _CZLOWIEK_H

#include "Ssak.h"
#include "Pies.h"


class Czlowiek: public Ssak {
public: 
    
/**
 * @param imie
 * @param jestPlciMeskiej
 * @param masaG
 * @param wysokoscMm
 * @param wiekDni
 */
  Czlowiek(std::string imie, bool jestPlciMeskiej, unsigned int masaG, unsigned int wysokoscMm, unsigned int wiekDni);
    
void prowadzSwojegoPsaNaSpacer();
    
Pies* getPies();
    
/**
 * @param value
 */
void setPies(Pies* value);
    
/**
 * @param czlowiek
 * @param imie
 */
Czlowiek* rozmnoz(Czlowiek* czlowiek, std::string imie);
void mow();
    
void rusz();
private: 
    Pies* pies;
    
/**
 * @param pies
 */
void prowadzPsaNaSpacer(Pies pies);
};

#endif //_CZLOWIEK_H