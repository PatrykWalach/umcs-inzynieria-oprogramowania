

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
  ~Singleton() { instance = nullptr; }
};

Singleton* Singleton::instance = nullptr;

int main() {}