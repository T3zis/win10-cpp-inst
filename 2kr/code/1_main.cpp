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




/*______HEADER-FILES______*/
 #include "0_input_check.h"
/*________________________*/


/*__________ENUMS__________*/
enum main_choice
{
	RUN_TEST            = 1,
	FILTER_FROM_FILE    = 2,
	FILTER_FROM_CONSOLE = 3,
	EXIT                = 4
};


enum filtering_choice
{
	FILTER_BY_LCT = 1,
	FILTER_BY_ICT = 2,
	FILTER_BY_ALF = 3
};
/*_________________________*/


/*_____________main_____________*/
int main(void)
{
  std::ios::sync_with_stdio(false);
	setlocale(LC_ALL, "Russian");
	//InputCheck _input;

  
	
  return 0;
}
/*______________________________*/