#include "3_utilities.h"



int make_choice(int count)
{
	InputCheck _input;

	int res{ 0 };
	const int  begin_choice = 1, end_choice = count;

	do {
		std::cout << "Выберите один из пунктов:";
		res = _input.get_int();
		std::cout << std::endl;
	} while (res < begin_choice || res > end_choice);

	return res;
}

void more_0(int &res)
{
	InputCheck _input;

	while (res < 1) {
		std::cout << "\nВведите число > 0.";
		res = _input.get_int();
		std::cout << "\n";
	}
}


void save_to_file(std::vector<std::unique_ptr<____car>> &cars)
{
	InputCheck _input;
	const int save = 1, not_save = 0;
	int save_to_file = 0;

	std::cout << "\n\nХотите сохранить список в файл? (0 - Нет, "
		"1 - Да): ";

	save_to_file = _input.get_int();
	while (save_to_file != not_save && save_to_file != save) {
		std::cout << "Сделайте выбор (0 - Не сохранять в файл, 1 - Сохранить в "
			"файл): ";
		save_to_file = _input.get_int();
	}

	if (save_to_file == 1) {

		std::vector<std::string> reserved_names = { "CON.", "PRN.", "AUX.", "NUL.",
																							"COM1.", "COM2.", "COM3.", "COM4.", "COM5", "COM6", "COM7", "COM8.", "COM9.",
																							"LPT1.", "LPT2.", "LPT3.", "LPT4.", "LPT5.", "LPT6.", "LPT7.", "LPT8.", "LPT9.",
																							"CONIN$.", "CONOUT$.", "PRINTER$.", "CLOCK$.", "NUL$." };

		for (;;) {
			std::string file_name;
			std::cout << "Введите имя файла или 'exit' для выхода: ";
			std::cin >> file_name;

			if (file_name == "exit")
				break;

			std::string file_name_copy = file_name;
			size_t found = file_name_copy.find_last_of('\\');

			if (found != std::string::npos)
				file_name_copy = file_name_copy.substr(found + 1);


			bool err_sym = false;
			for (char c : file_name_copy)
				if (c == ':' || c == '/' || c == ',' || c == '*' || c == '"' || c == '<' || c == '>' || c == '|') {
					err_sym = true;
					break;
				}

			if (err_sym) {
				std::cout << "Имя файла содержит недопустимые символы!\n";
				break;
			}
			std::transform(file_name_copy.begin(), file_name_copy.end(), file_name_copy.begin(), ::toupper);

			bool is_reserved = false;

			if (file_name_copy.size() >= 5) {
				for (const std::string& reserved : reserved_names) {
					size_t search_length = std::min(file_name_copy.size(), reserved.size());
					size_t pos = file_name_copy.substr(0, search_length).find(reserved, 0);

					if (pos != std::string::npos) {
						is_reserved = true;
						break;
					}
				}
			}
			else {
				is_reserved = true;
			}



			if (is_reserved) {
				std::cout << "Введено зарезервированное имя для OC Windows 10 или расширение файла не .txt" << std::endl;
				continue;
			}

			if (file_name_copy.substr(file_name_copy.size() - 4) != ".TXT") {
				std::cout << "Должен быть формат .txt, повторите попытку!" << std::endl;
				continue;
			}



			if (std::filesystem::exists(file_name)) {
				std::cout << "\nФайл с именем '" << file_name << "' существует.\n";
				std::cout << "Выберите один из пунктов.\n0)Сохранить данные в этот файл(данные будут стерты)\n1)Выбрать другой файл для сохранения\n";
				save_to_file = _input.get_int();
				while (save_to_file != not_save && save_to_file != save) {
					std::cout << "Сделайте выбор (0 - Сохранить данные в этот файл(данные будут стерты), 1 - Сохранить в "
						"другой файл): ";
					save_to_file = _input.get_int();
				}
				if (save_to_file == 0) {
					std::ofstream output_file(file_name);
					if (output_file.is_open()) {
						for (const auto& car : cars) {
							output_file << car->save_info();
						}
						std::cout << "Данные успешно сохранены в файл: " << file_name << "\n";
						break;
					}
					else {
						std::cout << "Файл не доступен для записи, повторите попытку!\n";
						continue;
					}
				}
				else continue;
			}
			else {
				std::ofstream output_file(file_name);
				if (output_file.is_open()) {
					for (const auto& car : cars) {
						output_file << car->save_info();
					}
					std::cout << "Данные успешно сохранены в файл: " << file_name << "\n";
					break;
				}
				else {
					std::cout << "Файл не доступен для записи, повторите попытку!\n";
					continue;
				}
			}
		}
	}
	else std::cout << "Данные не будут сохранены в файл";
}



#define ASSERT(condition)                                                      \
  do {                                                                         \
    if (!(condition)) {                                                        \
      std::cerr << "\t\t\t\tТЕСТ ПРОВАЛЕН!!!\n\tПричина: " #condition          \
                << " в файле " << __FILE__ << " строка " << __LINE__           \
                << std::endl;                                                  \
      return;                                                                   \
    }                                                                          \
  } while (0)


void start_test(void) 
{
	____sport_car test_sport_car(2, 3, 4, 5, 6, 7, 8);
	ASSERT(test_sport_car.get_weight() == 2);

	ASSERT(test_sport_car.get_engine_power() == 3);

	ASSERT(test_sport_car.get_speed() == 4);

	ASSERT(test_sport_car.get_num_wheels() == 5);

	ASSERT(test_sport_car.get_num_windows() == 6);
	
	ASSERT(test_sport_car.get_up_to_100() == 7);

	ASSERT(test_sport_car.get_num_turbines() == 8);



	____truck test_truck(2, 3, 4, 5, 6, 7, 8);
	ASSERT(test_truck.get_weight() == 2);

	ASSERT(test_truck.get_engine_power() == 3);

	ASSERT(test_truck.get_speed() == 4);

	ASSERT(test_truck.get_num_wheels() == 5);

	ASSERT(test_truck.get_num_windows() == 6);

	ASSERT(test_truck.get_mileage() == 7);

	ASSERT(test_truck.get_body_volume() == 8);


	std::cout << "Тестирование прошло успешно!!!\n";
}