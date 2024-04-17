#pragma once

/*______HEADER-FILES______*/
#include "2_vehicle.h"
/*________________________*/


/*_____________class-car_____________*/
class ____car : public ____vehicle {
protected:
	int num_wheels;
	int num_windows;

public:
	____car() : ____vehicle(), num_wheels{ 0 }, num_windows{ 0 } {}
	____car(double _wght, double _engPwr, double _spd, int _nWhl, int _nWinds)
		        : ____vehicle(_wght, _engPwr, _spd), num_wheels{ _nWhl }, num_windows{ _nWinds } {}

	int get_num_wheels()  const { return num_wheels; }
	int get_num_windows() const { return num_windows; }

	void set_num_wheels(int new_num_wheels)   { num_wheels = new_num_wheels; }
	void set_num_windows(int new_num_windows) { num_windows = new_num_windows; }
};
/*___________________________________*/
