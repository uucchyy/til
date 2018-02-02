#include <iostream>
#include <locale>

int main() {
//	std::setlocale(LC_CTYPE, "");
	std::setlocale(LC_ALL, "en_US.UTF-8");

	int i = 123;
	char c = 'A';
	wchar_t wc = L'あ';
	std::string s = "ABCあ";
	std::wstring ws = L"ABCあ";

	std::cout << "i=" << i << " \n";
	std::cout << "c=" << c << " \n";
	std::wcout << "wc=" << wc << " \n";
	std::cout << "s=" << s << " \n";
	std::wcout << "ws=" << ws << " \n";
	std::cout << "s.length=" << s.length() << " \n";
	std::cout << "ws.length=" << ws.length() << " \n";
	
	return 0;
}
