
#include <cstdlib>
#include <initializer_list>
#include <iostream>
#include <vector>

int random(int min, int max) { return min + std::rand() % (max - min + 1); }

template <typename T>
T random(std::vector<T> v) {
  return v[random(0, v.size() - 1)];
}

template <typename T>
T random(std::initializer_list<T> l) {
  std::vector<T> v(l);
  return random(v);
}

class Ssak {
 public:
  Ssak(std::string imie, bool jestPlciMeskiej, unsigned int masaG,
       unsigned int wysokoscMm, unsigned int wiekDni) {
    this->imie = imie;
    this->jestPlciMeskiej = jestPlciMeskiej;
    this->masaG = masaG;
    this->wysokoscMm = wysokoscMm;
    this->wiekDni = wiekDni;
  }

  Ssak(std::string imie, bool jestPlciMeskiej, unsigned int masaG,
       unsigned int wysokoscMm) {
    this->imie = imie;
    this->jestPlciMeskiej = jestPlciMeskiej;
    this->masaG = masaG;
    this->wysokoscMm = wysokoscMm;
  }

  unsigned int getMasaG() { return masaG; }

  unsigned int getWiekDni() { return wiekDni; }

  unsigned int getWysokoscMm() { return wysokoscMm; }

  bool getJestPlciMeskiej() { return jestPlciMeskiej; }

  std::string getImie() { return imie; }

  virtual void mow() = 0;

  virtual void rusz() = 0;

  virtual void spij() = 0;

 private:
  std::string imie;
  bool jestPlciMeskiej;
  unsigned int masaG;
  unsigned int wysokoscMm;
  unsigned int wiekDni = 0;
};

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

  Pies(std::string imie, bool jestPlciMeskiej, KsztaltGlowy ksztaltGlowy,
       TypUszu typUszu, DlugoscSiersci dlugoscSiersci, unsigned int masaG,
       unsigned int wysokoscMm, unsigned int wiekDni)
      : Ssak(imie, jestPlciMeskiej, masaG, wysokoscMm, wiekDni) {
    this->ksztaltGlowy = ksztaltGlowy;
    this->typUszu = typUszu;
    this->dlugoscSiersci = dlugoscSiersci;
  }

  Pies(std::string imie, bool jestPlciMeskiej, KsztaltGlowy ksztaltGlowy,
       TypUszu typUszu, DlugoscSiersci dlugoscSiersci, unsigned int masaG,
       unsigned int wysokoscMm)
      : Ssak(imie, jestPlciMeskiej, masaG, wysokoscMm) {
    this->ksztaltGlowy = ksztaltGlowy;
    this->typUszu = typUszu;
    this->dlugoscSiersci = dlugoscSiersci;
  }

  Pies* rozmnoz(Pies* pies, std::string imie) {
    if (getJestPlciMeskiej() == pies->getJestPlciMeskiej()) {
      std::cout << "dwa psy tej samej plci nie moga sie rozmnozyc" << std::endl;
      return nullptr;
    }
    auto nowyPies = new Pies(
        imie, random({getJestPlciMeskiej(), pies->getJestPlciMeskiej()}),
        random({ksztaltGlowy, pies->ksztaltGlowy}),
        random({typUszu, pies->typUszu}),
        random({dlugoscSiersci, pies->dlugoscSiersci}), random(500, 1000),
        random(100, 50));

    std::cout << "Narodzil się nowy pies " << imie << "." << std::endl;

    return nowyPies;
  }

  void mow() {
    std::cout << getImie() << ": \""
              << random<std::string>({"RROWFF!!", "WOOF!!"}) << "\""
              << std::endl;
  }

  KsztaltGlowy getKsztaltGlowy() { return ksztaltGlowy; }

  TypUszu getTypUszu() { return typUszu; }

  DlugoscSiersci getDlugoscSiersci() { return dlugoscSiersci; }

  void aportuj() {
    std::cout << getImie() << " aportuje"
              << "." << std::endl;
  }
  void rusz() {
    std::cout << getImie() << " podbiega energicznie"
              << "." << std::endl;
  }

  void spij() {
    std::cout << getImie() << " poszedł spać" << std::endl;
    std::cout << getImie() << ": \"zzz\"" << std::endl;
    std::cout << getImie() << " obudził się" << std::endl;
  }

 private:
  KsztaltGlowy ksztaltGlowy;
  TypUszu typUszu;
  DlugoscSiersci dlugoscSiersci;
};

class Czlowiek : public Ssak {
 public:
  Czlowiek(std::string imie, bool jestPlciMeskiej, unsigned int masaG,
           unsigned int wysokoscMm, unsigned int wiekDni)
      : Ssak(imie, jestPlciMeskiej, masaG, wysokoscMm, wiekDni) {}

  void prowadzSwojegoPsaNaSpacer() { prowadzPsaNaSpacer(pies); }

  Pies* getPies() { return pies; }

  void setPies(Pies* value) { this->pies = value; }

  Czlowiek* rozmnoz(Czlowiek* czlowiek, std::string imie) {
    if (getJestPlciMeskiej() == czlowiek->getJestPlciMeskiej()) {
      std::cout << "dwoje ludzi tej samej plci nie moga sie rozmnozyc"
                << std::endl;
      return nullptr;
    }
    auto nowyCzlowiek = new Czlowiek(
        imie, random({getJestPlciMeskiej(), czlowiek->getJestPlciMeskiej()}),
        random(2500, 3500), random(300, 500), 0);

    std::cout << "Narodzil się nowy czlowiek " << imie << "." << std::endl;

    return nowyCzlowiek;
  }

  void spij() {
    std::cout << getImie() << " poszedł spać" << std::endl;
    std::cout << getImie() << ": \"snore snore\"" << std::endl;
    std::cout << getImie() << " obudził się" << std::endl;
  }

  void mow() {
    std::cout << getImie() << ": \""
              << random<std::string>(
                     {"Ale ładna dzisiaj pogoda", "Cześć, jestem " + getImie()})
              << "\"" << std::endl;
  }

  void rusz() {
    std::cout << getImie() << " robi kilka kroków "
              << random<std::string>(
                     {"w lewo", "do przodu", "w bok", "do tyłu"})
              << "." << std::endl;
  }

 private:
  Pies* pies;

  void prowadzPsaNaSpacer(Pies* pies) {
    std::cout << getImie() << " wyprowadza " << pies->getImie() << " na spacer"
              << "." << std::endl;
  }
};

class Jamnik : public Pies {
 public:
  enum Wielkosc {
    Wielkosc_krolicza,
    Wielkosc_miniaturowa,
    Wielkosc_standardowa
  };

  Jamnik(std::string imie, bool jestPlciMeskiej, unsigned int wysokoscMm,
         DlugoscSiersci dlugoscSiersci, unsigned int masaG, Wielkosc wielkosc,
         unsigned int wiekDni)
      : Pies(imie, jestPlciMeskiej, Pies::KsztaltGlowy_dlugi,
             Pies::TypUszu_dlugie, dlugoscSiersci, masaG, wysokoscMm, wiekDni) {
    this->wielkosc = wielkosc;
  }

  Jamnik(std::string imie, bool jestPlciMeskiej, DlugoscSiersci dlugoscSiersci,
         Wielkosc wielkosc, unsigned int masaG, unsigned int wysokoscMm)
      : Pies(imie, jestPlciMeskiej, Pies::KsztaltGlowy_dlugi,
             Pies::TypUszu_dlugie, dlugoscSiersci, masaG, wysokoscMm) {
    this->wielkosc = wielkosc;
  }

  Wielkosc getWielkosc() { return wielkosc; }

  Jamnik* rozmnoz(Jamnik* jamnik, std::string imie) {
    if (getJestPlciMeskiej() == jamnik->getJestPlciMeskiej()) {
      std::cout << "dwa jamniki tej samej plci nie moga sie rozmnozyc"
                << std::endl;
      return nullptr;
    }
    auto nowyJamnik = new Jamnik(
        imie, random({getJestPlciMeskiej(), jamnik->getJestPlciMeskiej()}),
        random({getDlugoscSiersci(), jamnik->getDlugoscSiersci()}),
        random({wielkosc, jamnik->wielkosc}), random(500, 1000),
        random(100, 50));

    std::cout << "Narodzil się nowy jamnik " << imie << "." << std::endl;

    return nowyJamnik;
  }

 private:
  Wielkosc wielkosc;
};

int main() {
  Jamnik foo("Foo", true, 320, Jamnik::DlugoscSiersci_krotka, 9000,
             Jamnik::Wielkosc_miniaturowa, 365 * 3);
  Jamnik bar("Bar", false, 280, Jamnik::DlugoscSiersci_szorstka, 7500,
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
  owczarekNiemiecki.mow();
  owczarekNiemiecki.mow();
  artur.mow();
  artur.spij();
}
