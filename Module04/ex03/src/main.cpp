#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << "\033[34mIMateriaSource Creation\033[0m" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	std::cout << std::endl;

	std::cout << "\033[34mCharacter Creation\033[0m" << std::endl;
	Character* player = new Character("Player");
	std::cout << std::endl;

	std::cout << "\033[34mAMateria Creation & Player Equipment\033[0m" << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	player->equip(tmp);
	player->unequip(1);
	player->unequip(4);
	tmp = src->createMateria("cure");
	player->equip(tmp);
	tmp = src->createMateria("fire");
	player->equip(tmp);
	tmp = src->createMateria("ice");
	player->equip(tmp);
	tmp = src->createMateria("cure");
	player->equip(tmp);
	player->equip(tmp);
	player->unequip(3);
	std::cout << std::endl;

	std::cout << "\033[34mCharacter Opponent Creation (deep copy)\033[0m" << std::endl;
	ICharacter* bob = new Character(*player);
	player->use(0, *bob);
	player->use(1, *bob);
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructors\033[0m" << std::endl;
	delete bob;
	delete player;
	delete src;

	return 0;
}
