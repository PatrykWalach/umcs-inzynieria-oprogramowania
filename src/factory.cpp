#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class ButelkaNapoju {
 public:
  int getCena() { return cena; };

  /**
   * @param cena
   * @param objetosc
   * @param skladniki
   */
  ButelkaNapoju(int cena, int objetosc, std::vector<std::string> skladniki) {
    this->cena = cena;
    this->objetosc = objetosc;
    this->skladniki = skladniki;
  }

  int getObjetosc() { return objetosc; }

  std::vector<std::string> getSkladniki() { return skladniki; }

 private:
  int cena;
  std::vector<std::string> skladniki;
  int objetosc;
};

class CocaCola : public ButelkaNapoju {
 public:
  /**
   * @param cena
   * @param objetosc
   */
  CocaCola(int cena, int objetosc)
      : ButelkaNapoju(cena, objetosc, {"woda", "cukier", "kofeina"}) {}
};

class FabrykaCocaCola {
 public:
  void usunCocaCole(CocaCola& cocaCola) {
    auto f = std::find_if(
        produkty.begin(), produkty.end(), [&](CocaCola& cocaColaB) {
          return (cocaCola.getCena() == cocaColaB.getCena()) &&
                 (cocaCola.getObjetosc() == cocaColaB.getObjetosc());
        });

    if (f != produkty.end()) {
      produkty.erase(f);
      std::cout << "usunieto cole o pojemnosci "
                << (float)cocaCola.getObjetosc() / (float)1000 << "l za "
                << (float)cocaCola.getCena() / (float)100 << "zl" << std::endl;
    }
  }

  /**
   * @param cocaCola
   */
  void dodajNowaCocaCole(CocaCola& cocaCola) {
    produkty.push_back(cocaCola);

    std::cout << "dodano cole o pojemnosci "
              << (float)cocaCola.getObjetosc() / (float)1000 << "l za "
              << (float)cocaCola.getCena() / (float)100 << "zl" << std::endl;
  }

 private:
  std::vector<CocaCola> produkty;
};

int main() {
  FabrykaCocaCola fabryka;

  CocaCola polLitra(300, 500);

  std::cout << "skladniki coca-coli to:";
  for (auto& skladnik : polLitra.getSkladniki()) {
    std::cout << " " << skladnik;
  }
  std::cout << std::endl;

  fabryka.dodajNowaCocaCole(polLitra);

  CocaCola dwaLitry(900, 2000);
  fabryka.dodajNowaCocaCole(dwaLitry);

  CocaCola jedenLitr(600, 1000);
  fabryka.dodajNowaCocaCole(jedenLitr);

  fabryka.usunCocaCole(polLitra);
  fabryka.usunCocaCole(dwaLitry);
}