#include "4_interaction_with_abonents.h"


void InterectionWithAbonents::input_abonent_info(
	std::vector<AbonentInfo>& abonent_info)
{

	InputCheck _input;

	/* |объявление параметров класса для передачи в конструктор| */
	std::string _name;
	std::string _surname;
	std::string _patronymic;
	std::string _address;
	std::string _phone_number;
	int _local_call_time;
	int _long_distance_call_time;

	/* |заполнение информации об абоненте через консоль и проверка на корректность данных| */
	std::cout << "\nВведите фамилию: ";
	std::cin >> _surname;
	std::cout << "Введите имя: ";
	std::cin >> _name;
	std::cout << "Введите отчество: ";
	std::cin >> _patronymic;
	std::cout << "Введите адрес: ";
	std::cin >> _address;
	std::cout << "Введите номер телефона: ";
	std::cin >> _phone_number;
	std::cout << "Введите время внутригородских звонков: ";
	_local_call_time = _input.get_int();
	while (_local_call_time < 0) {
		std::cout << "Время не может быть отрицательным, повторите попытку.";
		_local_call_time = _input.get_int();
		std::cout << "\n";
	}
	std::cout << "Введите время междугородних звонков: ";
	_long_distance_call_time = _input.get_int();
	while (_long_distance_call_time < 0) {
		std::cout << "Время не может быть отрицательным, повторите попытку.";
		_long_distance_call_time = _input.get_int();
		std::cout << "\n";
	}

	AbonentInfo abonent(_surname, _name, _patronymic, _address, _phone_number, _local_call_time, _long_distance_call_time);

	abonent_info.push_back(abonent);

}

void InterectionWithAbonents::read_abonents_data(
	std::vector<AbonentInfo>& abonents, int& counter,
	std::string& file_location, bool& valid_file)
{
	std::ifstream input_file(file_location);

	if (input_file.is_open()) {
		valid_file = true;
		std::string line;
		bool all_abonents_valid = true;

		while (std::getline(input_file, line)) {
			if (line.empty()) break;

			std::vector<std::string> fields;
			std::stringstream str_stream(line);
			std::string temp;
			while (std::getline(str_stream, temp, ','))
				fields.push_back(temp);

			for (auto& field : fields) {
				size_t colon_pos = field.find(":");
				if (colon_pos != std::string::npos && colon_pos + 1 < field.size()) {
					size_t start_pos = colon_pos + 1;
					while (start_pos < field.size() && field[start_pos] == ' ')
						++start_pos;
					field = field.substr(0, colon_pos + 1) + field.substr(start_pos);
				}
			}

			bool abonent_valid = true;
			for (const std::string& required_field : { "Фамилия:", "Имя:", "Отчество:", "Адрес:", "Номер телефона:", "Время внутригородских звонков:", "Время междугородних звонков:" }) {
				bool field_found = false;
				for (const std::string& field : fields) {
					if (field.find(required_field) != std::string::npos) {
						field_found = true;
						std::string field_data = field.substr(field.find(":") + 1);
						if (field_data.find_first_not_of(' ') == std::string::npos || field_data.empty()) {
							std::cout << "Ошибка! Поле '" << required_field << "' не содержит данных.\n";
							abonent_valid = false;
							break;
						}
					}
				}
				if (!field_found) {
					abonent_valid = false;
					break;
				}
			}

			if (!abonent_valid) {
				std::cout << "Один из абонентов не соответствует формату. Прерывание обработки файла.\n";
				all_abonents_valid = false;
				abonents.clear();
				break;
			}

			AbonentInfo abonent;
			for (const auto& field : fields) {
				if (field.find("Фамилия:") != std::string::npos)
					abonent.set_surname(field.substr(field.find(":") + 1));
				if (field.find("Имя:") != std::string::npos)
					abonent.set_name(field.substr(field.find(":") + 1));
				if (field.find("Отчество:") != std::string::npos)
					abonent.set_patronymic(field.substr(field.find(":") + 1));
				if (field.find("Адрес:") != std::string::npos)
					abonent.set_address(field.substr(field.find(":") + 1));
				if (field.find("Номер телефона:") != std::string::npos)
					abonent.set_phone_number(field.substr(field.find(":") + 1));
				if (field.find("Время внутригородских звонков:") != std::string::npos) {
					std::string time_str = field.substr(field.find(":") + 1);
					try {
						abonent.set_local_call_time(std::stoi(time_str));
					}
					catch (const std::invalid_argument&) {
						std::cout << "Ошибка преобразования времени внутригородских звонков!\n";
					}
				}
				if (field.find("Время междугородних звонков:") != std::string::npos) {
					std::string time_str = field.substr(field.find(":") + 1);
					try {
						abonent.set_long_distance_call_time(std::stoi(time_str));
					}
					catch (const std::invalid_argument&) {
						std::cout << "Ошибка преобразования времени междугородних звонков!";
					}
				}
			}

			if (all_abonents_valid) {
				abonents.push_back(abonent);
				++counter;
			}
		}

		if (counter >= 1 && all_abonents_valid)
			std::cout << "Файл успешно сканирован!\n";
		input_file.close();
	}
	else {
		std::cerr << "Ошибка! Не удалось открыть файл для чтения.\n";
		valid_file = false;
	}
}




void InterectionWithAbonents::save_to_file(
	std::vector<AbonentInfo>& filtred_list)
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
						for (const auto& abonent : filtred_list) {
							output_file << "Фамилия: " << abonent.get_surname()
								<< ", Имя: " << abonent.get_name()
								<< ", Отчество: " << abonent.get_patronymic()
								<< ", Адрес: " << abonent.get_address()
								<< ", Номер телефона: " << abonent.get_phone_number()
								<< ", Время внутригородских звонков: "
								<< abonent.get_local_call_time()
								<< ", Время междугородних звонков: "
								<< abonent.get_long_distance_call_time() << "\n";
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
					for (const auto& abonent : filtred_list) {
						output_file << "Фамилия: " << abonent.get_surname()
							<< ", Имя: " << abonent.get_name()
							<< ", Отчество: " << abonent.get_patronymic()
							<< ", Адрес: " << abonent.get_address()
							<< ", Номер телефона: " << abonent.get_phone_number()
							<< ", Время внутригородских звонков: "
							<< abonent.get_local_call_time()
							<< ", Время междугородних звонков: "
							<< abonent.get_long_distance_call_time() << "\n";
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
