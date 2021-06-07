

#include <iostream>

class Strategia {
 public:
  virtual void AlgorithmInterface(double oprocentowanie) = 0;
};

class NaliczanieOprocentowania {
  double oprocentowanie;

 public:
  NaliczanieOprocentowania(double _oprocentowanie)
      : oprocentowanie(_oprocentowanie){};

  Strategia* strategy;
  void ContextInterface() { strategy->AlgorithmInterface(oprocentowanie); }
};

class Frank : public Strategia {
  double wkladPoczatkowy;

 public:
  Frank(double _wkladPoczatkowy) : wkladPoczatkowy(_wkladPoczatkowy) {}
  void AlgorithmInterface(double oprocentowanie) {
    double walutaNaKoncuCHR = wkladPoczatkowy * (1 + oprocentowanie / 100);
    std::cout << walutaNaKoncuCHR << "CHR" << std::endl;
    wkladPoczatkowy = walutaNaKoncuCHR;
  }
};
class Euro : public Strategia {
  double wkladPoczatkowy;

 public:
  Euro(double _wkladPoczatkowy) : wkladPoczatkowy(_wkladPoczatkowy) {}
  void AlgorithmInterface(double oprocentowanie) {
    double walutaNaKoncuEUR = wkladPoczatkowy * (1 + oprocentowanie / 100);

    std::cout << walutaNaKoncuEUR << "EUR" << std::endl;
    wkladPoczatkowy = walutaNaKoncuEUR;
  }
};
class Zloty : public Strategia {
  double wkladPoczatkowy;

 public:
  Zloty(double _wkladPoczatkowy) : wkladPoczatkowy(_wkladPoczatkowy) {}
  void AlgorithmInterface(double oprocentowanie) {
    double walutaNaKoncu = wkladPoczatkowy * (1 + oprocentowanie / 100);

    std::cout << walutaNaKoncu << "PLN" << std::endl;
    wkladPoczatkowy = walutaNaKoncu;
  }
};

class Dolar : public Strategia {
  double wkladPoczatkowy;

 public:
  Dolar(double _wkladPoczatkowy) : wkladPoczatkowy(_wkladPoczatkowy) {}
  void AlgorithmInterface(double oprocentowanie) {
    double walutaNaKoncuUSD = wkladPoczatkowy * (1 + oprocentowanie / 100);
    std::cout << walutaNaKoncuUSD << "USD" << std::endl;
    wkladPoczatkowy = walutaNaKoncuUSD;
  }
};

int main() {
  NaliczanieOprocentowania naliczanieOprocentowania(20);
  naliczanieOprocentowania.strategy = new Euro(200);
  std::cout.precision(2);

  naliczanieOprocentowania.ContextInterface();
  naliczanieOprocentowania.ContextInterface();
}