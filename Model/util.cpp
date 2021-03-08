
#include <cstdlib>
#include <vector>

int random(int min, int max) { return min + std::rand() % (max - min + 1); }

template <typename T>
T random(std::vector<T> v) {
  return v[random(0, v.size() - 1)];
}

template <typename T>
T random(std::initializer_list<T> l) {
  std::vector<T> v(l.begin(), l.end());
  return random(v);
}
