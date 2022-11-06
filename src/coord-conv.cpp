#include <math.h>
#include "../headers/coord-conv.h"

wgs84 lv95ToWgs84(const lv95& input_coord) {
	double y_prime = (input_coord.e - 2600000.0) / 1000000.0;
	double x_prime = (input_coord.n - 1200000.0) / 1000000.0;

	double lambda_prime = 2.6779094
		+ 4.728982 * y_prime
		+ 0.791484 * y_prime * x_prime
		+ 0.1306 * y_prime * pow(x_prime, 2.0)
		- 0.0436 * pow(y_prime, 3.0);

	double phi_prime = 16.9023892
		+ 3.238272 * x_prime
		- 0.270978 * pow(y_prime, 2.0)
		- 0.002528 * pow(x_prime, 2.0)
		- 0.0447 * pow(y_prime, 2.0) * x_prime
		- 0.0140 * pow(x_prime, 3.0);

	double lambda = lambda_prime * 100.0 / 36.0;
	double phi = phi_prime * 100.0 / 36.0;

	wgs84 result;
	result.e = lambda;
	result.n = phi;

	return result;
}

lv95 wgs84ToLv95(const wgs84& input_coord) {
	double phi = input_coord.e * 3600;
	double lambda = input_coord.n * 3600;

	double phi_prime = (phi - 169028.66) / 1000;
	double lambda_prime = (lambda - 26782.5) / 1000;

	double e = 2600072.37
		+ 211455.93 * lambda_prime
		- 10938.51 * lambda_prime * phi_prime
		- 0.36 * lambda_prime * pow(phi_prime, 2)
		- 44.54 * pow(lambda_prime, 3);

	double n = 1200147.07
		+ 308807.95 * phi_prime
		+ 3745.25 * pow(lambda_prime, 2)
		+ 76.63 * pow(phi_prime, 2)
		- 194.56 * pow(lambda_prime, 2) * phi_prime
		+ 119.79 * pow(phi_prime, 3);

	lv95 result;
	result.e = e;
	result.n = n;

	return result;
}
