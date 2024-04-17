#include "0_input_check.h"

/* |проверка на тип int| */
int InputCheck::get_int(void)
{
  int res = 0;
  std::string input_str;
  bool correctness = false;

  while (!correctness) {
    std::cout << "Введите целое число: ";
    std::cin >> input_str;
    try {
      size_t pos_symbol;
      res = std::stoi(input_str, &pos_symbol);
      if (pos_symbol != input_str.size())
        throw std::invalid_argument(
            "Ошибка! Введенное значение не является целым числом.");     
      correctness = true;
    }
    catch (const std::invalid_argument) {
      std::cout << "Повторите попытку.\n";
    }
    catch (const std::out_of_range) {
      std::cout << "Ошибка! Введенное значение находится вне диапазона целых "
                   "чисел. Повторите попытку.\n";      
    }
    std::cin.clear(); // сброс состояния потока ввода + сбрасывает любые флаги ошибок
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    // игнорирование всех символов во входном буфере до \n 
  }
  return res;
}