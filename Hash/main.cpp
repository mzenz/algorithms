#include <iostream>
#include "Hash.h"

using namespace std;

int main(int argc, const char * argv[])
{
  HashTable<std::string, std::string> table(10);

  const auto k = "hello";
  table[k] = "good bye";
  cout << "(\"" << k << "\", \"" << table[k] << "\")" << endl;
}
