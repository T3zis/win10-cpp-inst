#include "2_entering_values.h"

/* |метод для вывода главного меню программы| */
int EnteringValues::main_choice(void)
{
  InputCheck _input;
  
  int res = 0;

  res = _input.get_int();

  return res;
}