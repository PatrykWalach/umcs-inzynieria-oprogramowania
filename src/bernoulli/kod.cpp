
#include <iostream>

class Factorial {
 public:
  int operator()(int n) {
    auto result = 1;
    for (auto i = 1; i <= n; i++) {
      result *= i;
    }
    return result;
  }
};

class BinomialCoefficient {
 public:
  double operator()(int n, int k) {
    auto factorial = new Factorial();

    auto r = (double)(*factorial)(n) /
             (double)((*factorial)(k) * (*factorial)(n - k));
    delete factorial;
    return r;
  }
};

class Power {
 public:
  double operator()(double base, int exponent) {
    double result = 1;
    for (;;) {
      if (exponent & 1) result *= base;
      exponent >>= 1;
      if (!exponent) break;
      base *= base;
    }

    return result;
  }
};

class BernoulliScheme {
 public:
  double operator()(int n, int k, double p) {
    auto bc = new BinomialCoefficient();
    auto pow = new Power();

    auto r = (*bc)(n, k) * (*pow)(p, k) * (*pow)(1 - p, n - k);

    delete bc;
    delete pow;

    return r;
  }
};

int main() {
  Factorial f;
  std::cout << f(0) << std::endl;
  std::cout << f(3) << std::endl;
  std::cout << f(5) << std::endl;

  BinomialCoefficient bc;
  std::cout << bc(4, 2) << std::endl;
  Power pow;
  std::cout << pow(4, 2) << std::endl;
  std::cout << pow(3, 3) << std::endl;
  BernoulliScheme bs;
  std::cout << bs(3, 2, (double)1 / (double)6) << std::endl;
}