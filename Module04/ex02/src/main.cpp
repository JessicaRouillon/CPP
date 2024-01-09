#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	// Abstract class testing

	// const Animal *animal = new Animal();
	// animal->makeSound();


	// Exercise testing

	std::cout << "\033[34mConstructor (Animal)\033[0m" << std::endl;
	size_t nb_obj = 10;
	Animal *objects[nb_obj];
	// objects[0] = new Animal();
	for (size_t i = 0; i < nb_obj; i++)
	{
		std::cout << i + 1 << "/" << std::endl;
		if (i % 2 == 0)
		{
			objects[i] = new Dog();
			if (objects[i] == NULL)
			{
				std::cout << "Cat allocation failed." << std::endl;
				exit(1);
			}
		}
		else
		{
			objects[i] = new Cat();
			if (objects[i] == NULL)
			{
				std::cout << "Dog allocation failed." << std::endl;
				exit(1);
			}
		}
	}
	std::cout << std::endl;

	std::cout << "\033[34mSounds\033[0m" << std::endl;
	for (size_t i = 0; i < nb_obj; i++)
	{
		std::cout << i + 1 << "/" << std::endl;
		std::cout << "Animal type:" << objects[i]->getType() << std::endl;
		objects[i]->makeSound();
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructor\033[0m" << std::endl;
	for (size_t i = 0; i < nb_obj; i++)
	{
		std::cout << i + 1 << "/" << std::endl;
		delete (objects[i]);
	}

	// Deep copy testing

	std::cout << std::endl
			  << std::endl;
	std::cout << "\033[34m===== Testing Deep Copy =====\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[34mConstructor (Dog)\033[0m" << std::endl;
	Dog *doggo_a = new Dog();
	if (doggo_a == NULL)
	{
		std::cout << "Dog allocation failed." << std::endl;
		exit(1);
	}

	std::cout << "Setting idea 0..." << std::endl;
	doggo_a->setIdea(0, "I need to bark at the mail.");
	std::cout << "Setting idea 1..." << std::endl;
	doggo_a->setIdea(1, "Lemme just sit on your lap.");
	std::cout << "Setting idea 2..." << std::endl;
	doggo_a->setIdea(2, "Did you say PARK ?");
	std::cout << "Setting idea 200..." << std::endl;
	doggo_a->setIdea(200, "This idea is not even gonna make it.");

	// copy
	Dog *doggo_b = new Dog(*doggo_a);
	if (doggo_b == NULL)
	{
		std::cout << "Dog allocation failed." << std::endl;
		exit(1);
	}
	std::cout << std::endl;

	std::cout << "\033[34mIdeas of doggo_a\033[0m" << std::endl;
	std::cout << "The " << doggo_a->getType() << " doggo_a is thinking :" << std::endl;
	doggo_a->getIdeas();
	std::cout << std::endl;
	std::cout << "\033[34mDeconstructor doggo_a\033[0m" << std::endl;
	delete (doggo_a);
	std::cout << std::endl;

	std::cout << "\033[34mIdeas of doggo_b\033[0m" << std::endl;
	std::cout << "The " << doggo_b->getType() << " doggo_b is thinking :" << std::endl;
	doggo_b->getIdeas();
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructor doggo_b\033[0m" << std::endl;
	delete (doggo_b);

	return (EXIT_SUCCESS);
}
