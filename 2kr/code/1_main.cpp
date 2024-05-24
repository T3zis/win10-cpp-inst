/* 

  K   K  RRRR    222
  K  K   R   R  2   2
  KKK    RRRR      22
  K  K   R  R     22
  K   K  R   R  222222

  ***********************************************************
  * Project:                                                *
  *    2 control work in the c++ programming language       *
  * Developer:                                              *
  *    Sergey Shcherbakov                                   *
  * Description:                                            *
  *    In this project,a base and derived class are defined *
  *    The task involves designing fields and methods       *
  *    inherited from the base class, as well as custom     *
  *    components for the derived classes. The base class   *
  *    can be abstract. Implement the ability to retrieve   *
  *    a list of objects in a container.                    *
  *                                                         *
  * Variant 1:                                              *
  *    Base class - means of transportation.                *
  *    Fields in it:                                        *
  *    weight, engine power, speed.                         *
  *    Derived class - car;                                 *         
  *    Second generation derived classes - sports car,truck.*
  ***********************************************************
  
*/

#define GREETINGS							                                                           \
  "Щербаков Сергей Игоревич\nГруппа 4304\nВариант 1\n\nТекст задания:\nВ контр"          \
  "ольной работе задается базовый и производный класс.\nНеобходимо разработать поля"     \
  " и методы, наследуемые из базового класса,\nа также собственные компоненты"           \
  " производных классов.\nБазовый класс может быть абстрактным.\nРеализовать"            \
  " возможность получения списка объектов в контейнере.\nПредусмотреть необходимые"      \
  " проверки исходных данных.\nБазовый класс – средство передвижения.\nПоля в"           \
  " нем: вес, мощность мотора, скорость.\nПроизводный класс  – автомобиль;\nпроизводный" \
	" класс второго поколения – спортивный автомобиль, грузовой автомобиль.\n\n";


#define MAIN_CHOICE							                                                         \
  "\n\nВыберите один из пунктов:\n"                                                      \
  "{1} Провести тесты для программы\n"                                                   \
  "{2} Загрузить характеристики автомобилей из файла\n"	                                 \
  "{3} Ввести характеристики автомобилей через консоль\n"                                \
  "{4} Выйти из программы\n\n";

#define CASE_CHOICE						                                                           \
  "\nВыберите один из пунктов:\n"                                                        \
  "{1} Создать новый список средств передвижения\n"                                      \
  "{2} Выйти в главное меню\n\n"


#include "3_utilities.h"


enum FIRST_CHOICE  {RUN_TEST = 1, IMPORT_FROM_FILE, CONSOLE_INPUT, EXIT};

enum SECOND_CHOICE {ADD = 1, BACK};

enum LAST_CHOICE   {SHOW = 1, SAVE, TO_MENU};


int main(void)
{
  std::ios::sync_with_stdio(false);
	setlocale(LC_ALL, "Russian");
  InputCheck _input;
  int first_choice{ 0 }, second_choice{ 0 };

  std::cout << GREETINGS;
  
  for (;;) {
    std::cout << MAIN_CHOICE;
    first_choice = make_choice(4);

    first_choice = static_cast<FIRST_CHOICE>(first_choice);

    switch (first_choice) {

    case RUN_TEST: {
      start_test();
      break;
    }
    case IMPORT_FROM_FILE: {
      std::vector<std::unique_ptr<____car>> cars;
      int counter = 0;
      std::string file_location;
      std::cout << "Первая строка файла указывает тип автомобиля(1-спортивный, 2-грузовой)\n";

      /* |проверка на корректность файла| */
      bool valid_file = false;
      while (!valid_file) {
        std::cout << "\nДля выхода в главное меню напишите exit.\nВведите путь к файлу: ";
        std::cin >> file_location;
        if (file_location == "exit") break;
        /* |проверка файла через good (возвращает bool). Фактически проверяется
         * существует ли файл и можно ли его открыть| */
        std::ifstream file_check(file_location);
        if (!file_check.good()) {
          std::cerr << "Ошибка! Файл не существует или не доступен для чтения.\n";
          file_check.close();
        }
        else {
          /* |проверка файла на соответствие формату .txt| */
          if (file_location.size() < 5 || file_location.substr(file_location.size() - 4) != ".txt")
            std::cerr << "Ошибка! Файл должен иметь расширение .txt\n";
          else {
            /* |проверка файла на пустоту. Если начало файла равно концу, то
             * |файл пуст. Исполняется при помощи eof и peek| */
            file_check.close();
            file_check.open(file_location);
            if (file_check.peek() == std::ifstream::traits_type::eof())
              std::cerr << "Ошибка! Файл пустой.\n";
            else {
              std::string line;
              bool validation_of_all_line = true;
              while (std::getline(file_check, line)) {
                int semicolon_count = static_cast<int>(std::count(line.begin(), line.end(), ';'));
                if (semicolon_count != 7) { //
                  std::cerr << "Ошибка! В строке должно быть 7 точек с запятой.\n";
                  validation_of_all_line = false;
                  break;
                }

                for (int i = 0; i < line.size(); i++) 
                  if (line[i] == ';' && (i == 0 || i == line.size() - 1 || line[i - 1] == ';')) {
                    std::cerr << "Ошибка! формат файла не корректен.\n";
                    validation_of_all_line = false;
                    break;
                  }
                if (validation_of_all_line == false) break;

                if (line.empty()) {
                  std::cerr << "Ошибка! В файл есть пустые строки.\n";
                  validation_of_all_line = false;
                  break;
                }
                bool valid_symbols = std::all_of(line.begin(), line.end(), [](char c) {
                  return std::isdigit(c) || c == ';';
                  });
                if (!valid_symbols) {
                  validation_of_all_line = false;
                  break;
                }
                std::stringstream ss(line);
                std::string part;
                bool num_valid = true;
                while (std::getline(ss, part, ';')) {
                  int number = std::stoi(part);
                  if (number < 1) {
                    num_valid = false;
                    break;
                  }
                }
                if (!num_valid) {
                  std::cerr << "Ошибка! В строке числа должны быть >= 1.\n";
                  validation_of_all_line = false;
                  break;
                }
              }
              if (validation_of_all_line) {
                std::cout << "Файл успешно сканирован!\n";
                valid_file = true;
              }
              else
                std::cout << "Файл не прошел проверку, повторите попытку.\n";
            }
          }
        }
      }
      int sport_or_truck,weight, engine_power, speed, num_wheels, num_windows, time_up_to_100km, num_turbines, mileage, body_volume;

      std::ifstream file(file_location);
      std::string line;
      while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string var;
        std::getline(ss, var, ';');
        sport_or_truck = std::stoi(var);
        if (sport_or_truck != 1)
          continue;
        std::getline(ss, var, ';');
        weight = std::stoi(var);

        std::getline(ss, var, ';');
        engine_power = std::stoi(var);

        std::getline(ss, var, ';');
        speed = std::stoi(var);

        std::getline(ss, var, ';');
        num_wheels = std::stoi(var);

        std::getline(ss, var, ';');
        num_windows = std::stoi(var);

        std::getline(ss, var, ';');
        time_up_to_100km = std::stoi(var);

        std::getline(ss, var, ';');
        num_turbines = std::stoi(var);

        cars.push_back(std::make_unique<____sport_car>(weight, engine_power, speed, num_wheels, num_windows, time_up_to_100km, num_turbines));

      }

      std::ifstream file_truck(file_location);
      while (std::getline(file_truck, line)) {
        std::stringstream ss(line);
        std::string var;
        std::getline(ss, var, ';');
        sport_or_truck = std::stoi(var);
        if (sport_or_truck == 1)
          continue;
        std::getline(ss, var, ';');
        weight = std::stoi(var);

        std::getline(ss, var, ';');
        engine_power = std::stoi(var);

        std::getline(ss, var, ';');
        speed = std::stoi(var);

        std::getline(ss, var, ';');
        num_wheels = std::stoi(var);

        std::getline(ss, var, ';');
        num_windows = std::stoi(var);

        std::getline(ss, var, ';');
        mileage = std::stoi(var);

        std::getline(ss, var, ';');
        body_volume = std::stoi(var);

        cars.push_back(std::make_unique<____truck>(weight, engine_power, speed, num_wheels, num_windows, mileage, body_volume));


      }

      for (const auto& car : cars) {
        counter++;
        std::cout << counter << "\n";
        car->show_info();
      }
      if (file_location != "exit")
        save_to_file(cars);

      int last_choice = 0;
      int to_menu = 0;
      for (;;) {
        if (to_menu == 1) break;
        std::cout << "\n{1} Показать список средств передвижения\n"
                       "{2} Сохранить список средств передвижения\n"
                       "{3} Вернуться к созданию списка\n";
        last_choice = make_choice(3);
        last_choice = static_cast<LAST_CHOICE>(last_choice);

        switch (last_choice)
        {
        case SHOW: {
          for (const auto& car : cars) {
            counter++;
            std::cout << counter << "\n";
            car->show_info();
          }
          break;
        }
        case SAVE: {
          save_to_file(cars);
          break;
        }
        case TO_MENU: {
          to_menu = 1;
          break;
        }
        }
      }
      break;
    }
    case CONSOLE_INPUT: {
      for (;;) {
        std::cout << CASE_CHOICE;
        second_choice = make_choice(2);
        second_choice = static_cast<SECOND_CHOICE>(second_choice);
        switch (second_choice) {
        case ADD: {
          int num_sport_car = 0, num_truck = 0, counter = 0;
          std::vector<std::unique_ptr<____car>> cars;

          std::cout << "Введите количество спортивных автомобилей.";
          num_sport_car = _input.get_int();
          while (num_sport_car < 0) {
            std::cout << "Количество должно быть >= 0";
            num_sport_car = _input.get_int();
            std::cout << "\n";
          }

          while (counter < num_sport_car) {
            int weight, engine_power, speed, num_wheels, num_windows, time_up_to_100km, num_turbines;
            std::cout << "\nВведите высоту.";
            weight = _input.get_int();
            more_0(weight);
            std::cout << "\nВведите мощность мотора.";
            engine_power = _input.get_int();
            more_0(engine_power);
            std::cout << "\nВведите скорость.";
            speed = _input.get_int();
            more_0(speed);
            std::cout << "\nВведите количество колес.";
            num_wheels = _input.get_int();
            more_0(num_wheels);
            std::cout << "\nВведите количество окон.";
            num_windows = _input.get_int();
            more_0(num_windows);
            std::cout << "\nВведите время разгона до 100 км/ч.";
            time_up_to_100km = _input.get_int();
            more_0(time_up_to_100km);
            std::cout << "\nВведите количесво турбин.";
            num_turbines = _input.get_int();
            more_0(num_turbines);
            cars.push_back(std::make_unique<____sport_car>(weight, engine_power, speed, num_wheels, num_windows, time_up_to_100km, num_turbines));
            counter++;
          }
          counter = 0;

          std::cout << "\nВведите количество грузовых автомобилей.";
          num_truck = _input.get_int();
          while (num_truck < 0) {
            std::cout << "\nКоличество должно быть >= 0";
            num_truck = _input.get_int();
            std::cout << "\n";
          }

          while (counter < num_truck) {
            int weight, engine_power, speed, num_wheels, num_windows, mileage, body_volume;
            std::cout << "\nВведите высоту.";
            weight = _input.get_int();
            more_0(weight);
            std::cout << "\nВведите мощность мотора.";
            engine_power = _input.get_int();
            more_0(engine_power);
            std::cout << "\nВведите скорость.";
            speed = _input.get_int();
            more_0(speed);
            std::cout << "\nВведите количество колес.";
            num_wheels = _input.get_int();
            more_0(num_wheels);
            std::cout << "\nВведите количество окон.";
            num_windows = _input.get_int();
            more_0(num_windows);
            std::cout << "\nВведите пробег.";
            mileage = _input.get_int();
            more_0(mileage);
            std::cout << "\nВведите объем кузова.";
            body_volume = _input.get_int();
            more_0(body_volume);
            cars.push_back(std::make_unique<____truck>(weight, engine_power, speed, num_wheels, num_windows, mileage, body_volume));
            counter++;
          }
          counter = 0;


          
          save_to_file(cars);
          int last_choice = 0;
          int to_menu = 0;
          for (;;) {
            if (to_menu == 1) break;
            std::cout << "\n{1} Показать список средств передвижения\n"
                           "{2} Сохранить список средств передвижения\n"
                           "{3} Вернуться к созданию списка\n";
            last_choice = make_choice(3);
            last_choice = static_cast<LAST_CHOICE>(last_choice);
            
            switch (last_choice)
            {
            case SHOW: {
              for (const auto& car : cars) {
              counter++;
              std::cout << counter << "\n";
              car->show_info();
              }
              break;
            }
            case SAVE: {
              save_to_file(cars);
              break;
            }
            case TO_MENU: {
              to_menu = 1;
              break;
            }
            }
          }
          break;
        }
        }
        if (second_choice == BACK) break;
      }
      break;
    }
    case EXIT: exit(EXIT_SUCCESS);
    }
  }
}
