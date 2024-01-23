#include "Span.hpp"

static void printNumbers(Span &span)
{
	std::vector<long> array = span.getArray();
	for (size_t i = 0; i < span.getNumber(); i++)
	{
		std::cout << array[i];
		if (i < span.getNumber() - 1)
			std::cout << " / ";
	}
	std::cout << std::endl;
}

int main()
{
	std::cout << "\033[34m=========== Test du Sujet ===========\033[0m" << std::endl
			  << std::endl;

	Span sp1 = Span(5);

	try
	{
		sp1.addNumber(6);
		sp1.addNumber(3);
		sp1.addNumber(17);
		sp1.addNumber(9);
		sp1.addNumber(11);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	if (PRINT == true)
		printNumbers(sp1);

	try
	{
		size_t shortest = sp1.shortestSpan();
		std::cout << "Shortest span = " << shortest << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		size_t longest = sp1.longestSpan();
		std::cout << "Longest span = " << longest << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	/**********************************************************************************************************/

	std::cout << "\033[34m========= Test dans l'ordre =========\033[0m" << std::endl
			  << std::endl;

	Span sp2 = Span(5);

	try
	{
		sp2.addNumber(1);
		sp2.addNumber(2);
		sp2.addNumber(3);
		sp2.addNumber(4);
		sp2.addNumber(5);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	if (PRINT == true)
		printNumbers(sp2);

	try
	{
		size_t shortest = sp2.shortestSpan();
		std::cout << "Shortest span = " << shortest << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		size_t longest = sp2.longestSpan();
		std::cout << "Longest span = " << longest << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	/**********************************************************************************************************/

	std::cout << "\033[34m========= Test avec Négatif ==========\033[0m" << std::endl
			  << std::endl;

	Span sp3 = Span(5);

	try
	{
		sp3.addNumber(6);
		sp3.addNumber(3);
		sp3.addNumber(-17);
		sp3.addNumber(9);
		sp3.addNumber(11);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	if (PRINT == true)
		printNumbers(sp3);

	try
	{
		size_t shortest = sp3.shortestSpan();
		std::cout << "Shortest span = " << shortest << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		size_t longest = sp3.longestSpan();
		std::cout << "Longest span = " << longest << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	/**********************************************************************************************************/

	std::cout << "\033[34m======== Test avec 100 RANDOM ========\033[0m" << std::endl
			  << std::endl;

	Span sp4 = Span(100);

	for (size_t i = 0; i < sp4.getNumber(); i++)
	{
		long randValue = static_cast<long>(std::rand());
		sp4.addNumber(randValue);
	}

	if (PRINT == true)
		printNumbers(sp4);

	try
	{
		size_t shortest = sp4.shortestSpan();
		std::cout << "Shortest span = " << shortest << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		size_t longest = sp4.longestSpan();
		std::cout << "Longest span = " << longest << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	/**********************************************************************************************************/

	std::cout << "\033[34m====== Test avec 10.000 RANDOM =======\033[0m" << std::endl
			  << std::endl;

	Span sp5 = Span(10000);

	for (size_t i = 0; i < sp5.getNumber(); i++)
	{
		long randValue = static_cast<long>(std::rand());
		sp5.addNumber(randValue);
	}

	if (PRINT == true)
		printNumbers(sp5);

	try
	{
		size_t shortest = sp5.shortestSpan();
		std::cout << "Shortest span = " << shortest << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		size_t longest = sp5.longestSpan();
		std::cout << "Longest span = " << longest << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	/**********************************************************************************************************/

	std::cout << "\033[34m=========== Test un nombre ===========\033[0m" << std::endl
			  << std::endl;

	Span sp6 = Span(1);

	try
	{
		sp6.addNumber(42);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	if (PRINT == true)
		printNumbers(sp6);

	try
	{
		size_t shortest = sp6.shortestSpan();
		std::cout << "Shortest span = " << shortest << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		size_t longest = sp6.longestSpan();
		std::cout << "Longest span = " << longest << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	/**********************************************************************************************************/

	std::cout << "\033[34m=========== Test aucun nombre ===========\033[0m" << std::endl
			  << std::endl;

	Span sp7 = Span();

	try
	{
		sp7.addNumber(42);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	if (PRINT == true)
		printNumbers(sp7);

	try
	{
		size_t shortest = sp7.shortestSpan();
		std::cout << "Shortest span = " << shortest << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		size_t longest = sp7.longestSpan();
		std::cout << "Longest span = " << longest << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	/**********************************************************************************************************/

	std::cout << "\033[34m=========== Test overflow ===========\033[0m" << std::endl
			  << std::endl;

	Span sp8 = Span(3);

	try
	{
		sp8.addNumber(42);
		sp8.addNumber(52);
		sp8.addNumber(72);
		sp8.addNumber(39);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	if (PRINT == true)
		printNumbers(sp8);

	try
	{
		size_t shortest = sp8.shortestSpan();
		std::cout << "Shortest span = " << shortest << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		size_t longest = sp8.longestSpan();
		std::cout << "Longest span = " << longest << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	return (0);
}
