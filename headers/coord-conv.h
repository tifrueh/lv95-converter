#ifndef COORD_CONV
#define COORD_CONV

struct lv95 {
	double e;
	double n;
};
struct wgs84 {
	double e;
	double n;
}; 
wgs84 lv95ToWgs84(const lv95& input_coord);

#endif
