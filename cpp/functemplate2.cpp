#include <iostream>
#include <locale>

template <class T>
T max(T i1, T i2) {
	if (i1 > i2) {
		return i1;
	} else {
		return i2;
	}
}

int main() {
	int i1 = max(123, 456);
	float f1 = max(1.23f, 4.56f);

	std::cout << "i1=" << i1 << " \n";
	std::cout << "f1=" << f1 << " \n";

	return 0;
}
