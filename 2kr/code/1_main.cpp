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
  "{3} Заполнить характеристики автомобилей через консоль\n"                             \
  "{4} Выйти из программы\n\n";

#define CASE_CHOICE						                                                           \
  "\nВыберите один из пунктов:\n"                                                        \
  "{1} Добавить средство передвижения\n"                                                 \
  "{2} Удалить средство передвижения\n"                                                  \
  "{3} Показать список средств передвижения\n"                                           \
  "{4} Выйти в главное меню\n\n";


/*______HEADER-FILES______*/
#include "0_input_check.h"
#include "3_utilities.h"
/*________________________*/


/*__________ENUMS__________*/
enum FIRST_CHOICE{RUN_TEST = 1, IMPORT_FROM_FILE, CONSOLE_INPUT, EXIT};

enum SECOND_CHOICE{ADD = 1, DEL, SHOW, BACK};
/*_________________________*/


/*_____________main_____________*/
int main(void)
{
  std::ios::sync_with_stdio(false);
	setlocale(LC_ALL, "Russian");
  InputCheck _input;
  int first_choice{ 0 }, second_choice{ 0 };

  std::cout << GREETINGS;
  
  for (;;) {
    std::cout << MAIN_CHOICE;
    first_choice = make_choice();

    first_choice = static_cast<FIRST_CHOICE>(first_choice);

    switch (first_choice) {

    case RUN_TEST: {

      break;
    }
    case IMPORT_FROM_FILE: {

      break;
    }
    case CONSOLE_INPUT: {
      for (;;) {
        std::cout << CASE_CHOICE;
        second_choice = make_choice();
        second_choice = static_cast<SECOND_CHOICE>(second_choice);
        switch (second_choice) {
        case ADD: {
          break;
        }
        case DEL: {
          break;
        }
        case SHOW: {
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
/*______________________________*/