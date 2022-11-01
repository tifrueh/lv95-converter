#include <iostream>
#include "../headers/coord-conv.h"

int main() {
	lv95 input;

	std::cout << "Enter E (LV95): ";
	std::cin >> input.e;

	std::cout << "Enter N (LV95): ";
	std::cin >> input.n;

	wgs84 output;
	output = lv95ToWgs84(input);

	std::cout << "\nCoordinates: N " << output.n << ", E " << output.e << "\n";

	return 0;
}
