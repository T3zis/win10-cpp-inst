#pragma once
#include "3_abonent_info.h"



/* |класс для манипуляций с данными абонентов| */
class InterectionWithAbonents {
public:

	void input_abonent_info(std::vector <AbonentInfo>& abonent_info);

	void read_abonents_data(
		std::vector<AbonentInfo>& abonents, int& counter,
		std::string& file_location, bool& valid_file);

	void save_to_file(std::vector<AbonentInfo>& filtred_list);

};