#include "iter.hpp"

static void	ft_increment(int& nb) { nb += 1;}

static void	ft_decrement(int& nb) { nb -= 1;}

static void	ft_toupper(char& str) {str = toupper(str);}

static void	ft_tolower(char& str) {str = tolower(str);}

int	main()
{
	int		i[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	char	str[13] = {"Hello World!"};

	std::cout << "\033[34mINT Increment Test\033[0m" << std::endl;
	iter(i, 10, ft_increment);
	iter(i, 10, print);
	std::cout << std::endl;

	std::cout << "\033[34mINT Decrement Test\033[0m" << std::endl;
	iter(i, 10, ft_decrement);
	iter(i, 10, print);
	std::cout << std::endl;

	std::cout << "\033[34mSTRING Toupper Test\033[0m" << std::endl;
	iter(str, 13, ft_toupper);
	iter(str, 13, print);
	std::cout << std::endl;

	std::cout << "\033[34mSTRING Tolower Test\033[0m" << std::endl;
	iter(str, 13, ft_tolower);
	iter(str, 13, print);

	return (0);
}
