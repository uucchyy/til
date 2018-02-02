#include <iostream>
#include <locale>

int max(int i1, int i2) {
	if (i1 > i2) {
		return i1;
	} else {
		return i2;
	}
}

float max(float f1, float f2) {
	if (f1 > f2) {
		return f1;
	} else {
		return f2;
	}
}

int main() {
	int i1 = max(123, 456);
	float f1 = max(1.23f, 4.56f);

	std::cout << "i1=" << i1 << " \n";
	std::cout << "f1=" << f1 << " \n";

	return 0;
}
