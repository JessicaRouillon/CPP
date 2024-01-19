#include "Array.hpp"

int	main()
{
	std::cout << std::endl << "\033[34m========== INT TESTS ==========\033[0m" << std::endl << std::endl;

	std::cout << "\033[34mInt Constructors\033[0m" << std::endl;
	Array<int>		array1;
	Array<int>		array2(3);
	Array<int>		array3(array2);
	std::cout << std::endl;

// *******************************************************************************

	std::cout << "\033[34mInt Array 2\033[0m" << std::endl;
	for (size_t	i = 0; i < array2.size(); i++)
	{
		try
		{
			array2[i] = i + 1;
			std::cout << array2[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

// *******************************************************************************

	std::cout << "\033[34mInt Array 3 before copy\033[0m" << std::endl;
	for (size_t	i = 0; i < array3.size(); i++)
	{
		try
		{
			std::cout << array3[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "\033[34mInt Array 3 after copy\033[0m" << std::endl;
	array3 = array2;
	for (size_t	i = 0; i < array3.size(); i++)
	{
		try
		{
			std::cout << array3[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

// *******************************************************************************

	std::cout << "\033[34mInt Array sizes\033[0m" << std::endl;
	std::cout << "Array1 size = " << array1.size() << std::endl;
	std::cout << "Array2 size = " << array2.size() << std::endl;
	std::cout << "Array3 size = " << array3.size() << std::endl;
	array1 = array3;
	std::cout << "Array1 size after copy of Array3 = " << array1.size() << std::endl;
	std::cout << std::endl;

// *******************************************************************************

	std::cout << "\033[34mInvalid index\033[0m" << std::endl;
	try
	{
		std::cout << "Array1 = " << array1[array1.size()] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

// ===============================================================================

	std::cout << std::endl << "\033[34m========== STRING TESTS ==========\033[0m" << std::endl << std::endl;

	Array<std::string>	strArray1;
	Array<std::string>	strArray2(3);
	Array<std::string>	strArray3(strArray2);
	std::cout << std::endl;

// *******************************************************************************

	std::cout << "\033[34mString Array 2\033[0m" << std::endl;
	for (size_t	i = 0; i < strArray2.size(); i++)
	{
		std::ostringstream	oss;
		oss << "You are number " << i + 1;
		try
		{
			strArray2[i] = oss.str();;
			std::cout << strArray2[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

// *******************************************************************************

	std::cout << "\033[34mString Array 3 before copy\033[0m" << std::endl;
	for (size_t	i = 0; i < strArray3.size(); i++)
	{
		try
		{
			std::cout << strArray3[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "\033[34mString Array 3 after copy\033[0m" << std::endl;
	strArray3 = strArray2;
	for (size_t	i = 0; i < strArray3.size(); i++)
	{
		try
		{
			std::cout << strArray3[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

// *******************************************************************************

	std::cout << "\033[34mString Array sizes\033[0m" << std::endl;
	std::cout << "strArray1 size = " << strArray1.size() << std::endl;
	std::cout << "strArray2 size = " << strArray2.size() << std::endl;
	std::cout << "strArray3 size = " << strArray3.size() << std::endl;
	strArray1 = strArray3;
	std::cout << "strArray1 size after change = " << strArray1.size() << std::endl;
	std::cout << std::endl;

// *******************************************************************************

	std::cout << "\033[34mInvalid index\033[0m" << std::endl;
	try
	{
		std::cout << "strArray1 = " << strArray1[strArray1.size()] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}