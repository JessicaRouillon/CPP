#include "Span.hpp"

int main()
{
	std::cout << "\033[34m=========== Tests du Sujet ===========\033[0m" << std::endl << std::endl;
	Span sp1 = Span(5);

	sp1.addNumber(6);
	sp1.addNumber(3);
	sp1.addNumber(17);
	sp1.addNumber(9);
	sp1.addNumber(11);

	std::cout << "Shortest span = " << sp1.shortestSpan() << std::endl;
	std::cout << "Longest span = "  << sp1.longestSpan() << std::endl;
	std::cout << std::endl;

/**********************************************************************************************************/

	std::cout << "\033[34m=========== Tests avec Négatif ===========\033[0m" << std::endl << std::endl;

	Span sp2 = Span(5);

	sp2.addNumber(6);
	sp2.addNumber(3);
	sp2.addNumber(-17);
	sp2.addNumber(9);
	sp2.addNumber(11);

	std::cout << "Shortest span = " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest span = "  << sp2.longestSpan() << std::endl;
	std::cout << std::endl;

/**********************************************************************************************************/

	std::cout << "\033[34m=========== Tests avec 100 RANDOM ===========\033[0m" << std::endl << std::endl;
	Span sp3 = Span(100);
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	for (size_t i = 0; i < sp3._nb; i++)
	{
		
	}
	return (0);
}
