#include "Point.hpp"
#include "Fixed.hpp"

int	main()
{
	std::cout << "\033[1;34mTest 1\033[0m" << std::endl;
	if (bsp(Point(1.0f, 3.0f), Point(5.0f, 4.0f), Point(2.0f, 10.0f), Point(10.0f, 10.0f)) == true)
		std::cout << "\033[32m" << "Point is inside the triangle." << "\033[0m" << std::endl;
	else
		std::cout << "\033[31m" << "Point is outside the triangle." << "\033[0m" << std::endl;
	std::cout << std::endl;

/********************************************************************************************************/

	std::cout << "\033[1;34mTest 2\033[0m" << std::endl;
	if (bsp(Point(8.0f, 4.0f), Point(5.0f, 4.0f), Point(2.0f, 10.0f), Point(8.0f, 4.0f)) == true)
		std::cout << "\033[32m" << "Point is inside the triangle." << "\033[0m" << std::endl;
	else
		std::cout << "\033[31m" << "Point is outside the triangle." << "\033[0m" << std::endl;
	std::cout << std::endl;

/********************************************************************************************************/

	std::cout << "\033[1;34mTest 3\033[0m" << std::endl;
	if (bsp(Point(10.0f, 0.0f), Point(0.0f, 20.0f), Point(20.0f, 20.0f), Point(10.0f, 1.0f)) == true)
		std::cout << "\033[32m" << "Point is inside the triangle." << "\033[0m" << std::endl;
	else
		std::cout << "\033[31m" << "Point is outside the triangle." << "\033[0m" << std::endl;
	std::cout << std::endl;

/********************************************************************************************************/

	std::cout << "\033[1;34mTest 4\033[0m" << std::endl;
	if (bsp(Point(-10.0f, 0.0f), Point(0.0f, -20.0f), Point(-20.0f, -20.0f), Point(-10.0f, -10.0f)) == true)
		std::cout << "\033[32m" << "Point is inside the triangle." << "\033[0m" << std::endl;
	else
		std::cout << "\033[31m" << "Point is outside the triangle." << "\033[0m" << std::endl;

	return (EXIT_SUCCESS);
}
