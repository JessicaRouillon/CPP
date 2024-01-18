#include "../inc/Base.hpp"

Base*	generate(void)
{
	srand(time(NULL));
	const int randomNumber = rand() % 3 + 1;

	if (randomNumber == 1)
		return (new A);
	else if (randomNumber == 2)
		return (new B);
	else if (randomNumber ==3)
		return (new C);
	return (NULL);
}

void	identify(Base* p)
{
	try
	{
		if (dynamic_cast<A*>(p))
			std::cout << "Type = A" << std::endl;
		else if (dynamic_cast<B*>(p))
			std::cout << "Type = B" << std::endl;
		else if (dynamic_cast<C*>(p))
			std::cout << "Type = C" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	identify(Base& p)
{
	try
	{
		if (dynamic_cast<A*>(&p))
			std::cout << "Type = A" << std::endl;
		else if (dynamic_cast<B*>(&p))
			std::cout << "Type = B" << std::endl;
		else if (dynamic_cast<C*>(&p))
			std::cout << "Type = C" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main()
{
	Base	*instance1 = generate();

	identify(instance1);
	identify(*instance1);

	delete instance1;

	return (0);
}