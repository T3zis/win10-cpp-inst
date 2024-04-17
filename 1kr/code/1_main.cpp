#include "4_interaction_with_abonents.h"
#include "5_alg.h"


#define GREETINGS							                                                   \
  "Щербаков Сергей Игоревич\nГруппа 4304\nВариант 13\nТекст задания:\nПервая "   \
  "контрольная работа предназначена для приобретения\nпрактического опыта в "    \
  "создании простейших классов с\nиспользованием языка программирования С++. "   \
  "Необходимо\nразработать класс для указанной предметной области.\nДоступ к "   \
  "данным реализовать с помощью методов Set, Get, Show.\nПредусмотреть "         \
  "необходимые проверки исходных данных.\nАбонент: фамилия, имя, отчество, "     \
  "адрес, номер телефона, время внутригородских разговоров, время "						   \
	"междугородних разговоров.\nСоздать массив объектов. Реализовать возможность " \
	"получения :\n– списка абонентов, время внутригородских разговоров которых"    \
  "превышает заданное,\n– списка абонентов, воспользовавшихся междугородней"     \
	"связью,\n– списка абонентов, выведенных в алфавитном порядке.\n\n";

#define FILTER_INFO							                                                 \
  "\nВыберите один из пунктов для фильтрации:\n1) Вывести список абонентов, "    \
  "у которых время внутригородских разговоров превышает заданное\n2) Вывести "   \
  "список абонентов воспользовавшихся междугородней связью\n3) Вывести "         \
  "список абонентов в алфавитном порядке\n4) Перейти в главное меню\n"

#define CHOICE							                                                     \
  "\n\nВыберите один из пунктов:\n1) Провести тесты для программы\n2) "	         \
  "Выбрать свой файл для фильтрации\n3) Заполнить файл для фильтрации через "    \
  "консоль\n4) Выйти из программы\n"



/* |ASSERT. Если утверждение не верно отображается отображается
 * информация об ошибке, также возвращается EXIT_FAILURE| */

#define ASSERT(condition)                                                      \
  do {                                                                         \
    if (!(condition)) {                                                        \
      std::cerr << "\t\t\t\tТЕСТ ПРОВАЛЕН!!!\n\tПричина: " #condition          \
                << " в файле " << __FILE__ << " строка " << __LINE__           \
                << std::endl;                                                  \
      std::exit(EXIT_FAILURE);                                                 \
    }                                                                          \
  } while (0)




void run_test() {
	Algorithm _alg;

	/* |тесты для метода filter_by_lct| */
	/* |test 1.1| */
	std::vector <AbonentInfo> abonents_lct = {
			AbonentInfo("Иванов", "Иван", "Иванович", "123", "123456789", 15, 0),
			AbonentInfo("Петров", "Петр", "Петрович", "321", "987654321", 5, 20),
			AbonentInfo("Романов", "Роман", "Романович", "213", "123421345", 18, 12) };

	std::vector <AbonentInfo> filtered_list_by_lct;
	int min_lct = 10;

	_alg.filter_by_lct(abonents_lct, filtered_list_by_lct, min_lct);

	ASSERT(filtered_list_by_lct.size() == 2);

	abonents_lct.clear();
	filtered_list_by_lct.clear();

	/* |test 1.2| */
	abonents_lct = {
			AbonentInfo("Иванов", "Иван", "Иванович", "123", "123456789", 15, 0),
			AbonentInfo("Петров", "Петр", "Петрович", "321", "987654321", 5, 20),
			AbonentInfo("Романов", "Роман", "Романович", "213", "123421345", 18, 12),
			AbonentInfo("Александров", "Александр", "Александров", "2132",
									"123451111", 100, 111) };

	min_lct = 7;

	_alg.filter_by_lct(abonents_lct, filtered_list_by_lct, min_lct);

	ASSERT(filtered_list_by_lct.size() == 3);

	abonents_lct.clear();
	filtered_list_by_lct.clear();

	/* |test 1.3| */
	abonents_lct = {
			AbonentInfo("Иванов", "Иван", "Иванович", "123", "123456789", 15, 0),
			AbonentInfo("Петров", "Петр", "Петрович", "321", "987654321", 5, 20),
			AbonentInfo("Романов", "Роман", "Романович", "213", "123421345", 18, 12),
			AbonentInfo("Александров", "Александр", "Александров", "2132",
									"123451111", 100, 111),
			AbonentInfo("Бексултанов", "Бексултан", "Бексултанов", "2132",
									"123433543", 12, 1000) };

	min_lct = 30;

	_alg.filter_by_lct(abonents_lct, filtered_list_by_lct, min_lct);

	ASSERT(filtered_list_by_lct.size() == 1);

	abonents_lct.clear();
	filtered_list_by_lct.clear();


	/* |тесты для метода filter_by_ict| */
	/* |test 2.1| */
	std::vector <AbonentInfo> abonents_ict = {
			AbonentInfo("Иванов", "Иван", "Иванович", "123", "123456789", 15, 0),
			AbonentInfo("Петров", "Петр", "Петрович", "321", "987654321", 5, 20),
			AbonentInfo("Романов", "Роман", "Романович", "213", "123421345", 18, 12) };

	std::vector <AbonentInfo> filtered_list_by_ict;

	_alg.filter_by_ict(abonents_ict, filtered_list_by_ict);

	ASSERT(filtered_list_by_ict.size() == 2);

	abonents_ict.clear();
	filtered_list_by_ict.clear();

	/* |test 2.2| */
	abonents_ict = {
			AbonentInfo("Иванов", "Иван", "Иванович", "123", "123456789", 15, 0),
			AbonentInfo("Петров", "Петр", "Петрович", "321", "987654321", 5, 20),
			AbonentInfo("Романов", "Роман", "Романович", "213", "123421345", 18, 12),
			AbonentInfo("Александров", "Александр", "Александров", "2132",
									"123451111", 100, 111) };

	_alg.filter_by_ict(abonents_ict, filtered_list_by_ict);

	ASSERT(filtered_list_by_ict.size() == 3);

	abonents_ict.clear();
	filtered_list_by_ict.clear();

	/* |test 2.3| */
	abonents_ict = {
			AbonentInfo("Иванов", "Иван", "Иванович", "123", "123456789", 15, 0),
			AbonentInfo("Петров", "Петр", "Петрович", "321", "987654321", 5, 20),
			AbonentInfo("Романов", "Роман", "Романович", "213", "123421345", 18, 0),
			AbonentInfo("Александров", "Александр", "Александров", "2132",
									"123451111", 100, 0) };

	_alg.filter_by_ict(abonents_ict, filtered_list_by_ict);

	ASSERT(filtered_list_by_ict.size() == 1);

	abonents_ict.clear();
	filtered_list_by_ict.clear();


	/* |тесты для метода filter_by_alf_order| */
	/* |test 3.1| */
	std::vector <AbonentInfo> abonents_alf_order = {
		AbonentInfo("Иванов", "Иван", "Иванович", "123", "123456789", 15, 0),
		AbonentInfo("Петров", "Петр", "Петрович", "321", "987654321", 5, 20),
		AbonentInfo("Романов", "Роман", "Романович", "213", "123421345", 18, 12)
	};
	std::vector <AbonentInfo> filtered_list_by_alf_order;

	_alg.filter_by_alf_order(abonents_alf_order, filtered_list_by_alf_order);

	ASSERT(filtered_list_by_alf_order[0].get_surname() == "Иванов" &&
		filtered_list_by_alf_order[1].get_surname() == "Петров");

	abonents_alf_order.clear();
	filtered_list_by_alf_order.clear();

	/* |test 3.2| */
	abonents_alf_order = {
			AbonentInfo("Иванов", "Иван", "Иванович", "123", "123456789", 15, 0),
			AbonentInfo("Петров", "Петр", "Петрович", "321", "987654321", 5, 20),
			AbonentInfo("Романов", "Роман", "Романович", "213", "123421345", 18, 12),
			AbonentInfo("Александров", "Александр", "Александров", "2132",
									"123451111", 100, 111) };

	_alg.filter_by_alf_order(abonents_alf_order, filtered_list_by_alf_order);

	ASSERT(filtered_list_by_alf_order[0].get_surname() == "Александров" &&
		filtered_list_by_alf_order[1].get_surname() == "Иванов");

	abonents_alf_order.clear();
	filtered_list_by_alf_order.clear();

	/* |test 3.3| */
	abonents_alf_order = {
			AbonentInfo("Иванов", "Иван", "Иванович", "123", "123456789", 15, 0),
			AbonentInfo("Петров", "Петр", "Петрович", "321", "987654321", 5, 20),
			AbonentInfo("Романов", "Роман", "Романович", "213", "123421345", 18, 12),
			AbonentInfo("Александров", "Александр", "Александров", "2132",
									"123451111", 100, 111),
			AbonentInfo("Бексултанов", "Бексултан", "Бексултанович", "2132",
									"123433543", 12, 1000) };

	_alg.filter_by_alf_order(abonents_alf_order, filtered_list_by_alf_order);

	ASSERT(filtered_list_by_alf_order[0].get_surname() == "Александров" &&
		filtered_list_by_alf_order[1].get_surname() == "Бексултанов");

	abonents_alf_order.clear();
	filtered_list_by_alf_order.clear();
}


enum main_choice
{
	RUN_TEST = 1,
	FILTER_FROM_FILE = 2,
	FILTER_FROM_CONSOLE = 3,
	EXIT = 4
};


enum filtering_choice
{
	FILTER_BY_LCT = 1,
	FILTER_BY_ICT = 2,
	FILTER_BY_ALF = 3
};

int main(void)
{
	setlocale(LC_ALL, "Russian");
	InputCheck _input;
	EnteringValues _entering;
	AbonentInfo _abonent;
	InterectionWithAbonents _interection;
	Algorithm _alg;
	const int begin_choice = 1, end_choice = 4;
	int choice = 0;

	std::cout << GREETINGS;

	for (;;) {
		/* |основное меню| */
		std::cout << CHOICE;
		choice = _entering.main_choice();

		while (begin_choice < choice && choice > end_choice) {
			std::cout << "Выберите один из пунктов: ";
			choice = _entering.main_choice();
			std::cout << "\n";
		}
		
		choice = static_cast<main_choice>(choice);
		switch (choice) {
			/* |проведение тестов| */
		case RUN_TEST:
			run_test();
			std::cout << "Тестирование прошло успешно!";
			break;
			/* |фильтрация абонентов из файла| */
		case FILTER_FROM_FILE: {
			std::vector <AbonentInfo> abonents;
			int counter = 0, filter_selection = 0;
			std::string file_location;

			/* |проверка на корректность файла| */
			bool valid_file = false;
			while (!valid_file) {
				std::cout << "\t\t\tПРЕДУПРЕЖДЕНИЕ!\nЕсли в полях времени будет введено не целое число, автоматически будет подставлен 0\n";
				std::cout << "Введите путь к файлу: ";
				std::cin >> file_location;
				/* |проверка файла через good (возвращает bool). Фактически проверяется
				 * существует ли файл и можно ли его открыть| */
				std::ifstream file_check(file_location);
				if (!file_check.good()) {
					std::cerr << "Ошибка! Файл не существует или не доступен для чтения.\n";
					file_check.close();
				}
				else {
					/* |проверка файла на соответствие формату .txt| */
					if (file_location.size() < 5 || file_location.substr(file_location.size() - 4) != ".txt") {
						std::cerr << "Ошибка! Файл должен иметь расширение .txt\n";
					}
					else {
						/* |проверка файла на пустоту. Если начало файла равно концу, то
						 * файл пуст. Исполняется при помощи eof и peek| */
						file_check.close();
						file_check.open(file_location);
						if (file_check.peek() == std::ifstream::traits_type::eof()) {
							std::cerr << "Ошибка! Файл пустой.\n";
						}
						else {
							std::string line;
							bool valid_format = true;
							/* |проверка на отсутствие ключевых слов в файле| */
							while (std::getline(file_check, line)) {
								if (line.find("Фамилия:") == std::string::npos ||
									line.find("Имя:") == std::string::npos ||
									line.find("Отчество:") == std::string::npos ||
									line.find("Адрес:") == std::string::npos ||
									line.find("Номер телефона:") == std::string::npos ||
									line.find("Время внутригородских звонков:") ==
									std::string::npos ||
									line.find("Время междугородних звонков:") ==
									std::string::npos) {

									valid_format = false;
									break;
								}

								size_t pos = line.find(":");
								/* |поиск :| */
								if (pos != std::string::npos) {
									std::string data = line.substr(pos + 1);
									/* |проверка на пустую строку или отсутствие данных в параметре, если условие
									 * не выполняется, то файл не корректен| */
									if (data.empty() ||
										data.find_first_not_of(' ') == std::string::npos) {
										valid_format = false;
										break;
									}
								}
							}
							if (!valid_format)
								std::cerr << "Ошибка! Формат данных в файле некорректный.\n";
							else
								valid_file = true;
						}
					}
				}
			}
			
			/* чтение информации об абонентах и запись в вектор*/
			bool valid_f = false;
			_interection.read_abonents_data(abonents, counter, file_location, valid_f);
			if (abonents.empty())
				break;
			
			int war = EXIT_SUCCESS;
			for (int i = 0; i < counter; ++i)
				if (abonents[i].get_local_call_time() < 0 || abonents[i].get_long_distance_call_time() < 0) {
					war = EXIT_FAILURE;
					break;
				}

			if (war == EXIT_FAILURE) {
				std::cout << "Время одного из абонентов отрицательное, выберите другой файл";
				break;
			}
				

			_alg.output_filtered_list(abonents);

			_interection.save_to_file(abonents);

			/* |запуск основного алгоритма| */
			for (;;) {
				/* |выбор ключевого параметра для фильтрации| */
				std::cout << FILTER_INFO;
				filter_selection = _input.get_int();

				while (begin_choice < filter_selection && filter_selection > end_choice) {
					std::cout << "Выберите один из пунктов:";
					filter_selection = _input.get_int();
					std::cout << "\n";
				}

				switch (filter_selection) {
					/* |фильтрация абонентов по времени внутригородских звонков| */
				case FILTER_BY_LCT: {
					std::vector <AbonentInfo> filtering_by_lct;
					int min_local_call_time = 0;
					std::cout << "Введите минимальное время для фильтрации абонентов.\n";
					min_local_call_time = _input.get_int();
					while (min_local_call_time < 0) {
						std::cout << "\nВведите положительное число: ";
						min_local_call_time = _input.get_int();
						std::cout << "\n";
					}

					_alg.filter_by_lct(abonents, filtering_by_lct, min_local_call_time);

					if (filtering_by_lct.empty()) {
						std::cout << "Отфильтрованный список пуст.\n";
						break;
					}

					_alg.output_filtered_list(filtering_by_lct);

					_interection.save_to_file(filtering_by_lct);

					break;
				}
							/* |фильтрация абонентов по времени междугородних звонков| */
				case FILTER_BY_ICT: {
					std::vector <AbonentInfo> filtering_by_ict;

					_alg.filter_by_ict(abonents, filtering_by_ict);

					if (filtering_by_ict.empty()) {
						std::cout << "Отфильтрованный список пуст.\n";
						break;
					}

					_alg.output_filtered_list(filtering_by_ict);

					_interection.save_to_file(filtering_by_ict);
					_alg.output_filtered_list(filtering_by_ict);

					_interection.save_to_file(filtering_by_ict);

					break;
				}
							/* |фильтрация абонентов в алфавитном порядке| */
				case FILTER_BY_ALF: {
					std::vector <AbonentInfo> filtering_by_alph_order;
					_alg.filter_by_alf_order(abonents, filtering_by_alph_order);

					if (filtering_by_alph_order.empty()) {
						std::cout << "Отфильтрованный список пуст.\n";
						break;
					}


					_alg.output_filtered_list(filtering_by_alph_order);

					_interection.save_to_file(filtering_by_alph_order);

					break;
				}
				}
				/* |выход в главное меню| */
				if (filter_selection == 4) break;
			}
			break;
		}
					/* |фильтрация абонентов из консольного ввода| */
		case FILTER_FROM_CONSOLE: {
			/* |ввод информации о абонентах| */
			int num_abonent = 0, filter_selection = 0;
			std::vector <AbonentInfo> abonent_info;

			std::cout << "\nКаково количество абонентов?\n";
			num_abonent = _input.get_int();
			while (num_abonent < 1) {
				std::cout << "Введите количество абонентов >= 1: ";
				num_abonent = _input.get_int();
				std::cout << "\n";
			}
			for (int i = 0; i < num_abonent; i++) {
				std::cout << "\nВведите информацию об абоненте " << i + 1 << ".\n";
				_interection.input_abonent_info(abonent_info);
			}

			_alg.output_filtered_list(abonent_info);

			_interection.save_to_file(abonent_info);
			/* |запуск основного алгоритма| */
			for (;;) {
				std::cout << FILTER_INFO;
				filter_selection = _input.get_int();

				while (begin_choice < filter_selection && filter_selection > end_choice) {
					std::cout << "Выберите один из пунктов: ";
					filter_selection = _input.get_int();
				}
				switch (filter_selection) {
					/* |фильтрация абонентов по времени внутригородских звонков| */
				case FILTER_BY_LCT: {
					std::vector <AbonentInfo> filtering_by_lct;
					int min_local_call_time = 0;
					std::cout << "Введите минимальное время для фильтрации абонентов.\n";
					min_local_call_time = _input.get_int();
					while (min_local_call_time < 0) {
						std::cout << "\nВведите положительное число: ";
						min_local_call_time = _input.get_int();
					}
					_alg.filter_by_lct(abonent_info, filtering_by_lct,
						min_local_call_time);

					if (filtering_by_lct.empty()) {
						std::cout << "Отфильтрованный список пуст.\n";
						break;
					}
					
					_alg.output_filtered_list(filtering_by_lct);

					_interection.save_to_file(filtering_by_lct);

					break;
				}
				/* |фильтрация абонентов по времени междугородних звонков| */
				case FILTER_BY_ICT: {
					std::vector <AbonentInfo> filtering_by_ict;

					_alg.filter_by_ict(abonent_info, filtering_by_ict);

					if (filtering_by_ict.empty()) {
						std::cout << "Отфильтрованный список пуст.\n";
						break;
					}
					_alg.output_filtered_list(filtering_by_ict);

					_interection.save_to_file(filtering_by_ict);

					break;
				}
							/* |фильрация абонентов в алфовитном порядке| */
				case FILTER_BY_ALF: {
					std::vector <AbonentInfo> filtering_by_alph_order;
					_alg.filter_by_alf_order(abonent_info, filtering_by_alph_order);
					if (filtering_by_alph_order.empty()) {
						std::cout << "Отфильтрованный список пуст.\n";
						break;
					}
					_alg.output_filtered_list(filtering_by_alph_order);

					_interection.save_to_file(filtering_by_alph_order);

					break;
				}
				}
				/* |выход в главное меню| */
				if (filter_selection == 4) break;
			}
			break;
		}
		/* |завершение программы| */
		case EXIT: exit(EXIT_SUCCESS);
		}
	}
}