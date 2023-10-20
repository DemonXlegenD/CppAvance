#include "Header.h"
#include "GameObjectLib.h"
#include "../../GameObjectLib/includes/Container.h"
void CallLibFunction()
{
	Container<int> cont;
	cont.push_back(1);	
	Container<int> cont2;
	cont2.push_back(1);
	cont2.push_back(1);
	cont2.push_back(1);
	cont2.push_back(1);
	cont2.push_back(1);
	cont2.push_back(1);
	cont2.push_back(1);
	cont2.push_back(1);
	cont2.push_back(1);
	cont2.push_back(1);
	cont2.push_back(1);

	std::cout << (cont == cont2) << std::endl;
}
