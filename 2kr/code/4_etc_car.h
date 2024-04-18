#pragma once

/*______HEADER-FILES______*/
#include "3_car.h"
/*________________________*/

/*_____________class-sport-car_____________*/
class ____sport_car : public ____car {
protected:
	int time_up_to_100km; // время разгона до 100
	int num_turbines;     // кол-во турбин

public:
	____sport_car() : ____car(), time_up_to_100km{ 0 }, num_turbines{ 0 } {}
	____sport_car(double _wght, double _engPwr, double _spd, int _nWhl, int _nWinds, int _tUT100, int _nTrb)
		: ____car(_wght, _engPwr, _spd, _nWhl, _nWinds), time_up_to_100km{ _tUT100 }, num_turbines{ _nTrb } {}

	~____sport_car() override {}


};
/*_________________________________________*/


/*_______________class-truck_______________*/
class ____truck : public ____car {
protected:
	int mileage;     // пробег
	int body_volume; // объем кузова

public:
	____truck() : ____car(), mileage{ 0 }, body_volume{ 0 } {}
	____truck(double _wght, double _engPwr, double _spd, int _nWhl, int _nWinds, int _mil, int _bVol)
		: ____car(_wght, _engPwr, _spd, _nWhl, _nWinds), mileage{ _mil }, body_volume{ _bVol } {}

	~____truck() override {}



};
/*__________________________________________*/
