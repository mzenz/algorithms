#include "Exercises.h"
#include "../utils/utils.h"
#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
  vector<int> v { 1,1,1,2,2,100,100,55,44,11 };
  const auto k = 2;
  const auto topK = findTopK(v, k);

  cout << "TOP " << k << " elements:" << endl;
  printVector(topK);
}
