#pragma once

/*______HEADER-FILES______*/
#include "0_input_check.h"
/*________________________*/


/*________________class-vehicle________________*/
class ____vehicle {
protected:
	double weight;
	double engine_power;
	double speed;

public:
	____vehicle() : weight{0.0}, engine_power{0.0}, speed{0.0} {}
	____vehicle(double _wght, double _engPwr, double _spd) 
		     : weight(_wght), engine_power(_engPwr), speed(_spd) {}


	virtual ~____vehicle() {}


	double get_weight()       const { return weight; }
	double get_engine_power() const { return engine_power; }
	double get_speed()        const { return speed; }


	void set_weight(double new_weight)             { weight = new_weight; }
	void set_engine_power(double new_engine_power) { engine_power = new_engine_power; }
	void set_speed(double new_speed)               { speed = new_speed; }

	virtual void show_info() const = 0;
};
/*_____________________________________________*/

//дописать проверки на ввод < 0