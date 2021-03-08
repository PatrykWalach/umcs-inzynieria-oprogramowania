#include <vector>

int random(int, int);

template <typename T>
T random(std::vector<T>);
template <typename T>
T random(std::initializer_list<T>);
