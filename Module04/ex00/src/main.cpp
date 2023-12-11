#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\033[34mConstructor (Animal)\033[0m" << std::endl;
	const Animal	*meta = new Animal();
	std::cout << std::endl;
	std::cout << "\033[34mSounds\033[0m" << std::endl;

	std::cout << "Animal type: " << meta->getType() << std::endl;
	meta->makeSound();
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructor\033[0m" << std::endl;
	delete meta;
	std::cout << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;

	std::cout << std::endl;
	std::cout << "\033[34mConstructor (Animal > Cat)\033[0m" << std::endl;
	const Animal	*catto = new Cat();
	std::cout << std::endl;

	std::cout << "\033[34mSounds\033[0m" << std::endl;
	std::cout << "Animal type: " << catto->getType() << std::endl;
	catto->makeSound();
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructor\033[0m" << std::endl;
	delete catto;
	std::cout << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[34mConstructor (Animal > Dog)\033[0m" << std::endl;
	const Animal	*doggo = new Dog();
	std::cout << std::endl;
	std::cout << "\033[34mSounds\033[0m" << std::endl;
	std::cout << "Animal type: " << doggo->getType() <<std::endl;
	doggo->makeSound();
	std::cout << std::endl;
	std::cout << "\033[34mDeconstructor\033[0m" << std::endl;
	delete doggo;
	std::cout << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;

	std::cout << "\033[34mConstructor (Dog > Dog)\033[0m" << std::endl;
	const Dog	*metaDog = new Dog();
	std::cout << std::endl;
	std::cout << "\033[34mSounds\033[0m" << std::endl;

	std::cout << "Dog type: " << metaDog->getType() << std::endl;
	metaDog->makeSound();
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructor\033[0m" << std::endl;
	delete metaDog;
	std::cout << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;

	std::cout << "\033[34mConstructor (Cat > Cat)\033[0m" << std::endl;
	const Cat	*metaCat = new Cat();
	std::cout << std::endl;
	std::cout << "\033[34mSounds\033[0m" << std::endl;

	std::cout << "Cat type: " << metaCat->getType() << std::endl;
	metaCat->makeSound();
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructor\033[0m" << std::endl;
	delete metaCat;
	std::cout << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;

	std::cout << std::endl;
	std::cout << "\033[34mConstructor (WrongAnimal)\033[0m" << std::endl;
	const WrongAnimal	*wrong_meta = new WrongAnimal();
	std::cout << std::endl;

	std::cout << "\033[34mSounds\033[0m" << std::endl;
	std::cout << "WrongAnimal type: " << wrong_meta->getType() << std::endl;
	wrong_meta->makeSound();
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructor\033[0m" << std::endl;
	delete wrong_meta;
	std::cout << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;

	std::cout << "\033[34mConstructor (WrongAnimal > WrongCat)\033[0m" << std::endl;
	const WrongAnimal	*wrong_catto = new WrongCat();
	std::cout << std::endl;

	std::cout << "\033[34mSounds\033[0m" << std::endl;
	std::cout << "WrongAnimal type: " << wrong_catto->getType() <<std::endl;
	wrong_catto->makeSound();
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructor\033[0m" << std::endl;
	delete wrong_catto;
	std::cout << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;

	std::cout << "\033[34mConstructor (WrongCat)\033[0m" << std::endl;
	const WrongCat	*wrong_catta = new WrongCat();
	std::cout << std::endl;

	std::cout << "\033[34mSounds\033[0m" << std::endl;
	std::cout << "WrongCat type: " << wrong_catta->getType() <<std::endl;
	wrong_catta->makeSound();
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructor\033[0m" << std::endl;
	delete wrong_catta;
	std::cout << std::endl;

	return (EXIT_SUCCESS);
}
