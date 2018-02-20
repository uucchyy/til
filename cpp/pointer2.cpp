#include <iostream>
#include <locale>

class Test {
public:
    int a;

    Test(int _a) {
        this->a = _a;
    }

    void hello() {
        std::cout << "Test.hello: " << a << " \n";
    }
};

int main() {

    Test test(999);
    Test* test2 = new Test(1234);

    test.hello();
    test2->hello();

    std::cout << "&test: " << &test << " \n";
    std::cout << "&test2: " << &test2 << " \n";
    std::cout << "&test2: " << sizeof(test2) << " \n";

    delete test2;
    test2 = NULL;

    return 0;

}
