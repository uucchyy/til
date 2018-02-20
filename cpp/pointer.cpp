#include <iostream>
#include <locale>

int main() {

    int count = 123;
    int* pCount = &count;

    std::cout << "count=" << count << " \n";
    std::cout << "pCount=" << pCount << " \n";

    *pCount = 456;

    std::cout << "*pCount=" << *pCount << " \n";

    return 0;

}
