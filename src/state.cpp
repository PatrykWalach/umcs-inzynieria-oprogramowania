#include <iostream>

class Stan {
 public:
  virtual void wlaczAplikacje() = 0;
  virtual void wcisnijPrzyciskZasilania() = 0;
  virtual void wcisnijPrzyciskUspienia() = 0;
};

class Komputer {
  Stan *stan;

 public:
  ~Komputer() { delete this->stan; }
  Komputer();
  void setStan(Stan *stan) {
    delete this->stan;
    this->stan = stan;
  }
  void wlaczAplikacje() { stan->wlaczAplikacje(); };
  void wcisnijPrzyciskZasilania() { stan->wcisnijPrzyciskZasilania(); };
  void wcisnijPrzyciskUspienia() { stan->wcisnijPrzyciskUspienia(); };
};

class StanWlaczony : public Stan {
  Komputer *komputer;

 public:
  StanWlaczony(Komputer *komputer);
  void wlaczAplikacje();

  void wcisnijPrzyciskZasilania();

  void wcisnijPrzyciskUspienia();
};

class StanWylaczony : public Stan {
  Komputer *komputer;

 public:
  StanWylaczony(Komputer *komputer) { this->komputer = komputer; }

  void wlaczAplikacje() {
    std::cout << "Nie mozna wlaczyc aplikacji kiedy komputer jest wylaczony"
              << std::endl;
  };

  void wcisnijPrzyciskZasilania() {
    std::cout << "Wlaczono komputer" << std::endl;
    komputer->setStan(new StanWlaczony(komputer));
  };

  void wcisnijPrzyciskUspienia() {
    std::cout << "Nie mozna uspic komputera kiedy jest wylaczony" << std::endl;
  };
};

class StanUspiony : public Stan {
  Komputer *komputer;

 public:
  StanUspiony(Komputer *komputer) { this->komputer = komputer; }

  void wlaczAplikacje() {
    std::cout << "Nie mozna wlaczyc aplikacji kiedy komputer jest uspiony"
              << std::endl;
  };

  void wcisnijPrzyciskZasilania() {
    // komputer->setStan(new StanWylaczony(komputer));
    std::cout << "Nie mozna zamknac komputera kiedy jest uspiony" << std::endl;
  };

  void wcisnijPrzyciskUspienia() {
    std::cout << "Wybudzono komputer" << std::endl;
    komputer->setStan(new StanWlaczony(komputer));
  };
};

StanWlaczony::StanWlaczony(Komputer *komputer) { this->komputer = komputer; }

void StanWlaczony::wlaczAplikacje() {
  std::cout << "Wlaczono aplikacje" << std::endl;
};

void StanWlaczony::wcisnijPrzyciskZasilania() {
  std::cout << "Wylaczono komputer" << std::endl;
  komputer->setStan(new StanWylaczony(komputer));
};

void StanWlaczony::wcisnijPrzyciskUspienia() {
  std::cout << "Uspiono komputer" << std::endl;
  komputer->setStan(new StanUspiony(komputer));
};

Komputer::Komputer() { stan = new StanWylaczony(this); }

int main() {
  Komputer komputer;
  komputer.wlaczAplikacje();
  komputer.wcisnijPrzyciskUspienia();
  komputer.wcisnijPrzyciskZasilania();
  komputer.wlaczAplikacje();
  komputer.wcisnijPrzyciskUspienia();
  komputer.wlaczAplikacje();
  komputer.wcisnijPrzyciskZasilania();
  komputer.wcisnijPrzyciskUspienia();
  komputer.wcisnijPrzyciskZasilania();
}