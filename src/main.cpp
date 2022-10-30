#include <iostream>
#include "../headers/coord-conv.h"

int main() {
	lv95 input;
	input.e = 2722636.0;
	input.n = 1252762.0;

	wgs84 output;
	output = lv95ToWgs84(input);

	std::cout << "Coordinates: N " << output.n << ", E " << output.e << "\n";

	return 0;
}