#include "set.h"
#include <cassert>
#include <iostream>

void testCollection() {
    Set col1, col2, result;

    assert(col1.size() == 0);

    col1.add("Pizza Hut");
    col1.add("McDonald's");
    assert(col1.size() == 2);

    col1.add("Pizza Hut");
    assert(col1.size() == 2);

    col1.remove("McDonald's");
    assert(col1.size() == 1);


    col2.add("Pizza Hut");
    col2.add("KFC");
    result = col1 && col2;
    assert(result.size() == 1);
    assert(result.findNode("Pizza Hut") != nullptr);

    col1 << "Burger King";
    col1.saveToFile("restaurants.txt");
    Set col3;
    col3.loadFromFile("restaurants.txt");
    assert(col1 == col3);

    col2.clear();
    result = col1 && col2;
    assert(result.size() == 0);

    std::cout << "All tests passed successfully!" << std::endl;
}
