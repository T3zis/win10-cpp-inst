#pragma once
#include "3_abonent_info.h"


/* |класс с алгоритмами для фильтрации абонентов| */
class Algorithm {
public:
	/* |фильтрация абонентов по времени внутригородских звонков| */
	void filter_by_lct(const std::vector <AbonentInfo>& abonents_info,
		std::vector <AbonentInfo>& filtering_by_local_call_time,
		int min_local_call_time);

	/* |фильтрация абонентов по времени междугородних звонков| */
	void
		filter_by_ict(const std::vector <AbonentInfo>& abonents_info,
			std::vector <AbonentInfo>& filtering_by_intercity_call_time);

	/* |сортировка абонентов в алфавитном порядке| */
	void filter_by_alf_order(std::vector <AbonentInfo>& abonents_info,
		std::vector <AbonentInfo>& filtering_by_alph_order);

	/* |вывод информации об абонентах в консоль| */
	void output_filtered_list(const std::vector <AbonentInfo>& filtered_list);
};