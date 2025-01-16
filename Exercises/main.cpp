#include "TopK.h"
#include "FizzBuzz.h"
#include "ListMerge.h"
#include "../utils/utils.h"
#include <iostream>

using namespace std;

// int main(int argc, const char * argv[])
// {
//   fizzBuzz(100);
// }

// int main(int argc, const char * argv[])
// {
//   vector<int> v { 1,1,1,2,2,100,100,55,44,11 };
//   const auto k = 2;
//   const auto topK = findTopK(v, k);

//   cout << "TOP " << k << " elements:" << endl;
//   printVector(topK);
// }

int main() {
    list<int> a {1,3,5,7};
    list<int> b {2,4,5,8,10};
    list<int> c {0,20,30,45,55};
    list<int> d {500,2000,3500};
    list<int> ab;
    list<int> abcd;
    vector<list<int>> lists {a,b,c,d};

    mergeInPlace(a, b);
    cout << "a + b:" << endl;
    for (auto it = b.begin(); it != b.end(); ++it)
      cout << *it << ", ";
    cout << endl;

    mergeListsInPlace(lists, abcd);
    cout << "a + b + c + d:" << endl;
    for (auto it = abcd.begin(); it != abcd.end(); ++it)
        cout << *it << ", ";
    cout << endl;
}
