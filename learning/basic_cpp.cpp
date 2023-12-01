#include <iostream>

size_t	main(void)
{
	char	buff[512];

	std::cout << "Hello World !" << std::endl;
	std::cin >> buff;
	std::cout << "You entered: [" << buff << "]" << std::endl;

	return (0);
}
