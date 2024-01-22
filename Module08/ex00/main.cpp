#include "easyfind.hpp"

int	main()
{
	std::list<int>	a;

	a.push_back(0);
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);

	std::cout << "\033[34mSuccessful tests\033[0m" << std::endl;
	easyfind(a, 0);
	easyfind(a, 1);
	easyfind(a, 2);
	easyfind(a, 3);
	easyfind(a, 4);
	easyfind(a, 5);
	std::cout << std::endl;

	std::cout << "\033[34mFailed tests\033[0m" << std::endl;
	easyfind(a, 6);
	easyfind(a, 7);
	easyfind(a, -1);
	easyfind(a, 42);

	return (0);
}
