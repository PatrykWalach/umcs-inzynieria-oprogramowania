

class Singleton {
  static Singleton* instance;
  Singleton() {}

 public:
  static Singleton* getInstance() {
    if (instance == nullptr) {
      instance = new Singleton();
    }
    return instance;
  }

  Singleton(Singleton& other) = delete;
  void operator=(const Singleton&) = delete;

  ~Singleton() { instance = nullptr; }
};

Singleton* Singleton::instance = nullptr;

int main() { Singleton* s = Singleton::getInstance(); }