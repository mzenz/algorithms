#include <iostream>
#include "binary_heap.h"
#include "binary_heap_1_based.h"

int main(int argc, const char * argv[])
{
//    binary_heap_1_based<char> h;
    binary_heap<char> h;
    h.insert('S');
    h.insert('O');
    h.insert('R');
    h.insert('T');
    h.insert('E');
    h.insert('X');
    h.insert('A');
    h.insert('M');
    h.insert('P');
    h.insert('L');
    h.insert('E');
    
    std::cout << "Heap before:" << std::endl;
    h.print();
    std::cout << std::endl;
    
    while (!h.empty()) {
        std::cout << h.remove() << " ";
    }
    
    std::cout << std::endl;
}
