// Convert LV95 coordinates to WGS84 and vice-versa
// Copyright (C) 2022  Timo Früh

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.


#define VERSION "1.0.3"

#include <iostream>
#include <CLI/CLI.hpp>
#include "coord-conv.hpp"

int main(int argc, char** argv) {

	// initialise CLI11 parser
	CLI::App app{"Convert LV95 coordinates to WGS84 and vice-versa"};

	app.set_version_flag("-v,--version", VERSION, "Print version and exit");

	// add required ubcommands lv95 and wgs84
	CLI::App* lv95_scmd = app.add_subcommand("lv95", "convert LV95 to WGS84");
	CLI::App* wgs84_scmd = app.add_subcommand("wgs84", "convert WGS84 to LV95");
	app.require_subcommand(1, 1);
	
	// add required CLI options -e and -n for lv95
	coord::lv95 lv95_input;
	lv95_scmd->add_option<double>("-e,--east", lv95_input.e, "Easting coordinate in LV95")->required();
	lv95_scmd->add_option<double>("-n,--north", lv95_input.n, "Northing coordinate in LV95")->required();

	// add required CLI options -e and -n for wgs84
	coord::wgs84 wgs84_input;
	wgs84_scmd->add_option<double>("-e,--east", wgs84_input.e, "Easting coordinate in WGS84")->required();
	wgs84_scmd->add_option<double>("-n,--north", wgs84_input.n, "Northing coordinate in WGS84")->required();

	// parse CLI arguments
	CLI11_PARSE(app, argc, argv);

	// execute selected subcommand with arguments
	if (*lv95_scmd) {

		// convert lv95 to wgs84
		coord::wgs84 output;
		output = coord::lv95ToWgs84(lv95_input);

		// print out result
		std::cout << "\nCoordinates in WGS84: N " << output.n << ", E " << output.e << "\n";

	} else {

		// convert wgs84 to lv95
		coord::lv95 output;
		output = coord::wgs84ToLv95(wgs84_input);

		// print out result
		std::cout << "\nCoordinates in LV95: E " << output.e << ", N " << output.n << "\n";
	}

	return 0;
}
