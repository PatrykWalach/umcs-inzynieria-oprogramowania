

#include "Czlowiek.h"
#include "Jamnik.h"
#include "Pies.h"

int main() {
  Jamnik foo("Foo", true, 320, Pies::DlugoscSiersci_krotka, 9000,
             Jamnik::Wielkosc_miniaturowa, 365 * 3);
  Jamnik bar("Bar", false, 280, Pies::DlugoscSiersci_szorstka, 7500,
             Jamnik::Wielkosc_standardowa, 365 * 2);

  auto fooBar = foo.rozmnoz(&bar, "FooBar");
  fooBar->mow();
  fooBar->rusz();

  Czlowiek artur("Artur", true, 80000, 1800, 365 * 24);

  Pies owczarekNiemiecki("John", true, Pies::KsztaltGlowy_dlugi,
                         Pies::TypUszu_stojace, Pies::DlugoscSiersci_krotka,
                         35000, 630, 365 * 2);


  artur.setPies(&owczarekNiemiecki);

  artur.prowadzSwojegoPsaNaSpacer();
  artur.getPies()->aportuj();
  owczarekNiemiecki.rusz();
  artur.rusz();
  artur.mow();
}
