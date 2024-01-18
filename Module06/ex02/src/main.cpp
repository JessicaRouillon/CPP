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
			std::cout << "\033[32mType = A\033[0m" << std::endl;
		else if (dynamic_cast<B*>(p))
			std::cout << "\033[32mType = B\033[0m" << std::endl;
		else if (dynamic_cast<C*>(p))
			std::cout << "\033[32mType = C\033[0m" << std::endl;
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
		A& a = dynamic_cast<A &>(p);
		std::cout << "\033[32mType A = good cast\033[0m" << std::endl;
		(void)a;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Type A = " << e.what() << std::endl;
	}
	try
	{
		B& b = dynamic_cast<B &>(p);
		std::cout << "\033[32mType B = good cast\033[0m" << std::endl;
		(void)b;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Type B = " << e.what() << std::endl;
	}
	try
	{
		C& c = dynamic_cast<C &>(p);
		std::cout << "\033[32mType C = good cast\033[0m" << std::endl;
		(void)c;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Type C = " << e.what() << std::endl;
	}
}

int	main()
{
	Base	*instance = generate();

	std::cout << "\033[34mCast from pointer\033[0m" << std::endl;
	identify(instance);
	std::cout << "\033[34mCast from reference\033[0m" << std::endl;
	identify(*instance);

	delete instance;
	return (0);
}