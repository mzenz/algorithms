#include <iostream>

using namespace std;

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
