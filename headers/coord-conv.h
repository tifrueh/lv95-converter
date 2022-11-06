#ifndef COORD_CONV
#define COORD_CONV

namespace coord {
	struct lv95 {
		double e;
		double n;
	};

	struct wgs84 {
		double e;
		double n;
	}; 

	wgs84 lv95ToWgs84(const lv95& input_coord);

	lv95 wgs84ToLv95(const wgs84& input_coord);

}
#endif
