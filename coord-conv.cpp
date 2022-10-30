#include <math.h>
#include "headers/coord-conv.h"
using namespace coord;

wgs84 lv95ToWgs84(const lv95& input_coord) {
	double y_prime = (input_coord.e - 2600000) / 1000000;
	double x_prime = (input_coord.n - 1200000) / 1000000;

	double lambda_prime = 2.6779094
		+ 4.728982 * y_prime
		+ 0.791484 * y_prime * x_prime
		+ 0.1306 * y_prime * pow(x_prime, 2)
		- 0.0436 * pow(y_prime, 3);

	double phi_prime = 16.9023892
		+ 3.238272 * x_prime
		- 0.270978 * pow(y_prime, 2)
		- 0.002528 * pow(x_prime, 2)
		- 0.0447 * pow(y_prime, 2) * x_prime
		- 0.0140 * x_prime * 3;

	double lambda = lambda_prime * 100 / 36;
	double phi = phi_prime * 100 / 36;

	wgs84 result;
	result.e = lambda;
	result.n = phi;

	return result;
}
