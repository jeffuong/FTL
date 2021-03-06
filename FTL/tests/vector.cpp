#include "../vector.hpp"

#include <vector>
#include <cassert>
#include <iostream>
int main() {

  ftl::vector<int> vint;
  assert(vint.capacity() == 0);
  vint.push_back(0);
  assert(vint.size() == 1);
  vint.insert(vint.data(), { -5, -4, -3, -2, -1 });
  assert(vint.size() == 6);
  for (int i{ 0 }; i < vint.size(); ++i) {
    assert(vint[i] == i - 5);
  }
  vint.assign({ 0,1,2,3,4,5,6,7,8,9,10 });
  assert(vint.capacity() >= 11);
  assert(vint.size() == 11);
  for (unsigned i{ 0 }; i < vint.size(); ++i) {
    assert(vint[i] == i);
  }

  auto begin = vint.begin();
  auto vint2 = std::move(vint);

  assert(vint.size() == 0);
  assert(vint.capacity() == 0);
  assert(vint2.size() == 11);
  assert(vint2.capacity() == 11);
  assert(vint2.begin() == begin);

  ftl::inline_vector<float, 24> vfin;
  assert(vfin.capacity() == 24);
  vfin.assign(24, 69.420f);
  for (unsigned i{ 0 }; i < vfin.size(); ++i) {
    assert(vfin[i] == 69.420f);
  }
  for (int i{ 0 }; i < 100; ++i) {
    vfin.push_back(i);
  }
  std::vector<int> svint{ 5,4,3,2,1 };

  vint.swap(svint);


  ftl::unordered_vector<int> uiv{ 0,1,2,3,4,5,6,7,8,9 };

  uiv.erase(uiv.begin() + 5, uiv.end()- 2);
  for (int i{ 0 }; i < 5; ++i) {
    assert(uiv[i] == i);
  }
  uiv.erase(uiv.begin());

  return 0;
}