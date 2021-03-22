
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
    Factorial factorial;

    return (double)factorial(n) / (double)(factorial(k) * factorial(n - k));
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
    BinomialCoefficient bc;
    Power pow;

    return bc(n, k) * pow(p, k) * pow(1 - p, n - k);
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