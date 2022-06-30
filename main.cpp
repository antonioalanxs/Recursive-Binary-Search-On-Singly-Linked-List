//
// Created by antonioalanxs
//

#include <iostream>
#include "SinglyLinkedList.h"

using std::cout;
using std::endl;

int main() {
    TList l;
    Create(l);
    for (int i = 0; i < 11; i++) {
        PushBack(l, i);
    }
    Show(l);
    cout << endl;
    cout << BinarySearch(l, nullptr, 0) << endl; // 1
    cout << BinarySearch(l, nullptr, 10) << endl; // 1
    cout << BinarySearch(l, nullptr, 5) << endl; // 1
    cout << BinarySearch(l, nullptr, -1) << endl; // 0
    cout << BinarySearch(l, nullptr, 11); // 0

    return 0;
}
