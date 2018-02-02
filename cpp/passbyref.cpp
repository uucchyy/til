#include <iostream>
#include <locale>

void parseUrl(std::string s, int& queryIndex, int& hashIndex) {
	int a = 123;
	int& b;
	b = queryIndex;
	
	std::cout << "b:" << b<< "\r\n";

	queryIndex = s.find('?');
	hashIndex = s.find('#');
	std::cout << "b:" << b<< "\r\n";
	
}

int main() {
	std::string url("/foo/?abc=123#xxxx");

	int queryIndex = -1;
	int hashIndex = -1;

	parseUrl(url, queryIndex, hashIndex);

	std::cout << "query:" << queryIndex << "\r\n";
	std::cout << "hash:" << hashIndex << "\r\n";
	
	return 0;
}

