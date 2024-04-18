#pragma once

/*______HEADER-FILES______*/
#include "0_input_check.h"
/*________________________*/


/*________________class-vehicle________________*/
class ____vehicle {
protected:
	static int next_id;
	int id;
	int weight;
	int engine_power;
	int speed;

public:
	____vehicle() : id(++next_id), weight(0), engine_power(0), speed(0) { if (next_id == 0) next_id = 1; }
	____vehicle(int _wght, int _engPwr, int _spd)
	       : id(++next_id), weight(_wght), engine_power(_engPwr), speed(_spd) {}


	virtual ~____vehicle() {}


	int get_weight()       const { return weight; }
	int get_engine_power() const { return engine_power; }
	int get_speed()        const { return speed; }
	int get_id()           const { return id; }


	void set_weight(int new_weight)             { weight = new_weight; }
	void set_engine_power(int new_engine_power) { engine_power = new_engine_power; }
	void set_speed(int new_speed)               { speed = new_speed; }
	void set_next_id(int new_nID)               { next_id = new_nID;  }

	virtual void show_info() const = 0;
};
/*_____________________________________________*/


/*_____________class-car_____________*/
class ____car : public ____vehicle {
protected:
	int num_wheels;
	int num_windows;

public:
	____car() : ____vehicle(), num_wheels{ 0 }, num_windows{ 0 } {}
	____car(int _wght, int _engPwr, int _spd, int _nWhl, int _nWinds)
		: ____vehicle(_wght, _engPwr, _spd), num_wheels{ _nWhl }, num_windows{ _nWinds } {}

	int get_num_wheels()  const { return num_wheels; }
	int get_num_windows() const { return num_windows; }

	void set_num_wheels(int new_num_wheels)   { num_wheels = new_num_wheels; }
	void set_num_windows(int new_num_windows) { num_windows = new_num_windows; }
};
/*___________________________________*/


/*_____________class-sport-car_____________*/
class ____sport_car : public ____car {
protected:
	int time_up_to_100km; // время разгона до 100
	int num_turbines;     // кол-во турбин

public:
	____sport_car() : ____car(), time_up_to_100km{ 0 }, num_turbines{ 0 } {}
	____sport_car(int _wght, int _engPwr, int _spd, int _nWhl, int _nWinds, int _tUT100, int _nTrb)
		: ____car(_wght, _engPwr, _spd, _nWhl, _nWinds), time_up_to_100km{ _tUT100 }, num_turbines{ _nTrb } {}

	~____sport_car() override {}
	void show_info() const override {
		std::cout
			<< get_id() << ":" << get_weight() << ":"
			<< get_engine_power() << ":" << get_speed() << ":"
			<< get_num_wheels() << ":" << get_num_windows()
			<< ":" << time_up_to_100km << ":" << num_turbines << ":\n";
	}
};
/*_________________________________________*/


/*_______________class-truck_______________*/
class ____truck : public ____car {
protected:
	int mileage;     // пробег
	int body_volume; // объем кузова

public:
	____truck() : ____car(), mileage{ 0 }, body_volume{ 0 } {}
	____truck(int _wght, int _engPwr, int _spd, int _nWhl, int _nWinds, int _mil, int _bVol)
	           	: ____car(_wght, _engPwr, _spd, _nWhl, _nWinds), mileage{ _mil }, body_volume{ _bVol } {}

	~____truck() override {}

	void show_info() const override {
		std::cout 
		<< get_id() << ":"  << get_weight() << ":" 
		<< get_engine_power() << ":" << get_speed() << ":" 
		<< get_num_wheels()   << ":" << get_num_windows() 
		<< ":" << mileage     << ":" << body_volume << ":\n";
	}
};
/*__________________________________________*/