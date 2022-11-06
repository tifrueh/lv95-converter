#include <iostream>
#include "../lib/CLI11.hpp"
#include "../headers/coord-conv.h"

int main(int argc, char** argv) {
	CLI::App app("Convert LV95 coordinates to WGS84 and vice-versa");

	CLI::App* lv95_scmd = app.add_subcommand("lv95", "convert LV95 to WGS84");
	CLI::App* wgs84_scmd = app.add_subcommand("wgs84", "convert WGS84 to LV95");
	app.require_subcommand(1, 1);
	
	coord::lv95 lv95_input;
	lv95_scmd->add_option<double>("-e,--east", lv95_input.e, "Easting coordinate (LV95)")->required();
	lv95_scmd->add_option<double>("-n,--north", lv95_input.n, "Northing coordinate (LV95)")->required();

	coord::wgs84 wgs84_input;
	wgs84_scmd->add_option<double>("-e,--east", wgs84_input.e, "Easting coordinate in WGS84")->required();
	wgs84_scmd->add_option<double>("-n,--north", wgs84_input.n, "Northing coordinate in WGS84")->required();

	CLI11_PARSE(app, argc, argv);

	if (*lv95_scmd) {
		coord::wgs84 output;
		output = coord::lv95ToWgs84(lv95_input);
		std::cout << "\nCoordinates in WGS84: N " << output.n << ", E " << output.e << "\n";
	} else {
		coord::lv95 output;
		output = coord::wgs84ToLv95(wgs84_input);
		std::cout << "\nCoordinates in LV95: E " << output.e << ", N " << output.n << "\n";
	}

	return 0;
}
