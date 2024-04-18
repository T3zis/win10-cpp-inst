/*______HEADER-FILES______*/
#include "3_utilities.h"
/*________________________*/


int make_choice(void)
{
	InputCheck _input;
	int res{ 0 };
	const int  begin_choice{ 1 }, end_choice = { 4 };

	do {
		std::cout << "Выберите один из пунктов:";
		res = _input.get_int();
		std::cout << std::endl;
	} while (res < begin_choice || res > end_choice);

	return res;
}