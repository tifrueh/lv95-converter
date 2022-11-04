#include <iostream>
#include "../lib/CLI11.hpp"
#include "../headers/coord-conv.h"

int main(int argc, char** argv) {
	CLI::App app{"Convert LV95 coordinates to WGS84"};
	
	lv95 input;
	app.add_option<double>("-e,--east", input.e, "Easting coordinate (LV95)")->required();
	app.add_option<double>("-n,--north", input.n, "Northing coordinate (LV95)")->required();

	CLI11_PARSE(app, argc, argv);

	wgs84 output;
	output = lv95ToWgs84(input);

	std::cout << "\nCoordinates: N " << output.n << ", E " << output.e << "\n";

	return 0;
}
