#include <iostream>
#include <locale>

class Position {
public:
	int x;
	int y;

	Position(int x, int y) {
		this->x = x;
		this->y = y;
	}
	
};

void dump1(Position& pos) {
	std::cout << "x=" << pos.x << " y=" << pos.y << "\r\n";
}

void dump2(Position pos) {
	std::cout << "x=" << pos.x << " y=" << pos.y << "\r\n";
}


int main() {
	Position pos1(10, 20);
	Position* pos3 = new Position(10, 20);
	
	dump1(pos1);
	dump2(pos1);
	
	Position& pos2 = pos1;

	dump1(pos2);
	dump2(*pos2);

	return 0;
}

