#pragma once

#include "0_input_check.h"



class ____vehicle {
protected:
	int weight;
	int engine_power;
	int speed;

public:
	____vehicle() : weight(0), engine_power(0), speed(0) {}
	____vehicle(int _wght, int _engPwr, int _spd)
	       : weight(_wght), engine_power(_engPwr), speed(_spd) {}


	virtual ~____vehicle() {}


	int get_weight()       const { return weight; }
	int get_engine_power() const { return engine_power; }
	int get_speed()        const { return speed; }
	

	void set_weight(int new_weight)             { weight = new_weight; }
	void set_engine_power(int new_engine_power) { engine_power = new_engine_power; }
	void set_speed(int new_speed)               { speed = new_speed; }
	
	virtual std::string save_info() const = 0;

	virtual void show_info() const = 0;
};


class ____car : public ____vehicle {
protected:
	int num_wheels;
	int num_windows;

public:
	____car() : ____vehicle(), num_wheels{ 0 }, num_windows{ 0 } {}
	____car(int _wght, int _engPwr, int _spd, int _nWhl, int _nWinds)
	         	: ____vehicle(_wght, _engPwr, _spd), num_wheels{ _nWhl }, num_windows{ _nWinds } {}

	virtual ~____car() {}

	int get_num_wheels()  const { return num_wheels; }
	int get_num_windows() const { return num_windows; }

	void set_num_wheels(int new_num_wheels)   { num_wheels = new_num_wheels; }
	void set_num_windows(int new_num_windows) { num_windows = new_num_windows; }
};


class ____sport_car : public ____car {
protected:
	int time_up_to_100km; // время разгона до 100
	int num_turbines;     // кол-во турбин

public:
	____sport_car() : ____car(), time_up_to_100km{ 0 }, num_turbines{ 0 } {}
	____sport_car(int _wght, int _engPwr, int _spd, int _nWhl, int _nWinds, int _tUT100, int _nTrb)
		              : ____car(_wght, _engPwr, _spd, _nWhl, _nWinds), 
		              time_up_to_100km{ _tUT100 }, num_turbines{ _nTrb } {}

	virtual ~____sport_car()  {}

	int get_up_to_100() const    { return time_up_to_100km; }
	int get_num_turbines() const { return num_turbines; }

	// написать геттеры и сеттеры
	void show_info() const override {
		std::cout
			<< "Спортивный автомобиль\n"
			<< "Вес: " << get_weight() << "\n"
			<< "Мощность двигателя: " << get_engine_power() << "\n"
			<< "Скорость: " << get_speed() << "\n"
			<< "Количество колес: " << get_num_wheels() << "\n"
			<< "Количество окон: " << get_num_windows() << "\n"
			<< "Время разгона до 100 км/ч: " << time_up_to_100km << "\n"
			<< "Количество турбин: " << num_turbines << "\n\n";
	}

	std::string save_info() const override {
		return "2;" + std::to_string(get_weight()) + ";" + std::to_string(get_engine_power())
			+ ";" + std::to_string(get_speed()) + ";" + std::to_string(get_num_wheels())
			+ ";" + std::to_string(get_num_windows()) + ";" + std::to_string(time_up_to_100km) + ";"
			+ std::to_string(num_turbines) + "\n";
	}


};



class ____truck : public ____car {
protected:
	int mileage;     // пробег
	int body_volume; // объем кузова

public:
	____truck() : ____car(), mileage{ 0 }, body_volume{ 0 } {}
	____truck(int _wght, int _engPwr, int _spd, int _nWhl, int _nWinds, int _mil, int _bVol)
		: ____car(_wght, _engPwr, _spd, _nWhl, _nWinds), mileage{ _mil }, body_volume{ _bVol } {}

	virtual ~____truck() override {}

	void show_info() const override {
		std::cout
			<< "Грузовой автомобиль\n"
			<< "Вес: " << get_weight() << "\n"
			<< "Мощность двигателя: " << get_engine_power() << "\n"
			<< "Скорость: " << get_speed() << "\n"
			<< "Количество колес: " << get_num_wheels() << "\n"
			<< "Количество окон: " << get_num_windows() << "\n"
			<< "Пробег: " << mileage << "\n"
			<< "Объем кузова: " << body_volume << "\n\n";
	}

	std::string save_info() const override {
		return "1;" + std::to_string(get_weight()) + ";" + std::to_string(get_engine_power())
			+ ";" + std::to_string(get_speed()) + ";" + std::to_string(get_num_wheels())
			+ ";" + std::to_string(get_num_windows()) + ";" + std::to_string(mileage) + ";"
			+ std::to_string(body_volume) + "\n";
	}

	int get_mileage()  const    { return mileage; }
	int get_body_volume() const { return body_volume; }
};

