#include "Exercises.h"
#include "../utils/utils.h"
#include <iostream>

using namespace std;

typedef std::vector<std::pair<uint, std::string>> Prefixes;

void fizzBuzz(size_t count) {
  for (auto i = 0; i < count; ++i) {
    const bool div3 = i % 3 == 0;
    const bool div5 = i % 5 == 0;
    if (div3 && div5) {
      cout << "fizzbuzz" << endl;
    } else if (div3) {
      cout << i << " fizz" << endl;
    } else if (div5) {
      cout << i << " buzz" << endl;
    } else {
      cout << i << endl;
    }
  }
}

int main(int argc, const char * argv[])
{
  // vector<int> v { 1,1,1,2,2,100,100,55,44,11 };
  // const auto k = 2;
  // const auto topK = findTopK(v, k);

  // cout << "TOP " << k << " elements:" << endl;
  // printVector(topK);

  fizzBuzz(100);
}
