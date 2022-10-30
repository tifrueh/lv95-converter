#include <iostream>
#include "headers/coord-conv.h"

int main() {
	coord::lv95 input;
	input.e = 2722636.0;
	input.n = 1252762.0;

	coord::wgs84 output;
	output = coord::lv95ToWgs84(input);

	std::cout << "Coordinates: N " << output.n << ", E " << output.e << "\n";

	return 0;
}