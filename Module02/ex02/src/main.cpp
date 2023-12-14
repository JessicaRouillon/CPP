// #include "Fixed.hpp"

// int main( void )
// {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;

// 	std::cout << b << std::endl;

// 	std::cout << Fixed::max( a, b ) << std::endl;

// 	return 0;
// }

#include "Fixed.hpp"
#include "colors.hpp"
#include <string>

#define INVARG "Invalid number of arguments"
#define TRUE _FOREST_GREEN "TRUE\t(0)" _END
#define FALSE _RED "FALSE\t(1)" _END
int main() {

{
	std::cout << _BOLD << _CYAN << "\n/////////\t\tCOMPARISON OPERATORS\t\t/////////\n" << _END << std::endl;
	
	Fixed cold(0), hot(35.5f);

	std::cout << _BOLD << "Value of cold:\t\t" << cold << _END << std::endl;
	std::cout << _BOLD <<"Value of hot:\t\t" << hot << _END << std::endl;

	std::cout << "\ncold > hot ?\t\t" << (cold > hot ?TRUE:FALSE) << std::endl;
	std::cout << "cold < hot ?\t\t" << (cold < hot ?TRUE:FALSE) << std::endl;

	std::cout << "\ncold >= hot ?\t\t" << (cold >= hot ?TRUE:FALSE) << std::endl;
	std::cout << "cold >= cold ?\t\t" << (cold >= cold ?TRUE:FALSE) << std::endl;
	std::cout << "cold <= hot ?\t\t" << (cold <= hot ?TRUE:FALSE) << std::endl;

	std::cout << "\ncold == cold ?\t\t" << (cold == cold ?TRUE:FALSE) << std::endl;
	std::cout << "cold != cold ?\t\t" << (cold != cold ?TRUE:FALSE) << std::endl;
}
{
	std::cout << _BOLD << _CYAN << "\n/////////\t\tARITMETIC OPERATORS\t\t/////////\n" << _END << std::endl;
	
	Fixed x(2), y(1.5f);

	std::cout << _BOLD << "Value of x:\t\t" << x << _END << std::endl;
	std::cout << _BOLD << "Value of y:\t\t" << y << _END << std::endl;

	std::cout << _BOLD << _YELLOW << "\nAdditions" << _END << std::endl;
	std::cout << x << " + " << y << "\t\t=\t" << x + y << std::endl;
	std::cout << x << " + " << x << "\t\t=\t" << x + x  << std::endl;
	std::cout << y << " + " << y << "\t=\t" << y + y << std::endl;

	std::cout << _BOLD << _YELLOW << "\nSubtractions" << _END << std::endl;
	std::cout << x << " - " << y << "\t\t=\t" << x - y << std::endl;
	std::cout << x << " - " << x << "\t\t=\t" << x - x  << std::endl;
	std::cout << y << " - " << y << "\t=\t" << y - y << std::endl;

	std::cout << _BOLD << _YELLOW << "\nMultiplications" << _END << std::endl;
	std::cout << x << " * " << y << "\t\t=\t" << x * y << std::endl;
	std::cout << x << " * " << x << "\t\t=\t" << x * x  << std::endl;
	std::cout << y << " * " << y << "\t=\t" << y * y << std::endl;

	std::cout << _BOLD << _YELLOW << "\nDivisions" << _END << std::endl;
	std::cout << x << " / " << y << "\t\t=\t" << x / y << std::endl;
	std::cout << x << " / " << x << "\t\t=\t" << x / x  << std::endl;
	std::cout << y << " / " << y << "\t=\t" << y / y << std::endl;
}
{
	std::cout << _BOLD << _CYAN << "\n/////////\t\tINCREMENTATION OPERATORS\t/////////\n" << _END << std::endl;
	Fixed a;

	std::cout << _BOLD << "Value of a:\t\t" << a << _END << std::endl;
	std::cout << "\nPre-incrementing a:\t" << ++a << std::endl;
	std::cout << "Value of a:\t\t" << a << std::endl;
	std::cout << "Post-incrementing a:\t" << a++ << std::endl;
	std::cout << "\nValue of a:\t\t" << a << std::endl;

	std::cout << "\nPre-decrementing a:\t" << --a << std::endl;
	std::cout << "Value of a:\t\t" << a << std::endl;
	std::cout << "Post-decrementing a:\t" << a-- << std::endl;
	std::cout << "Value of a:\t\t" << a << std::endl;
}
{
	std::cout << _BOLD << _CYAN << "\n/////////\t\tMIN - MAX FUNCTION\t\t/////////\n" << _END << std::endl;

	Fixed min(-122), max(123.5f);

	std::cout << _BOLD << "Value of min:\t\t" << min << _END << std::endl;
	std::cout << _BOLD <<"Value of max:\t\t" << max << _END << std::endl;

	std::cout << "\nWho is max ?\t\t" << Fixed::max( min, max ) << std::endl;
	std::cout << "Who is min ?\t\t" << Fixed::min( min, max ) << std::endl;

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << _BOLD << "\nValue of a:\t\t" << a << _END << std::endl;
	std::cout << _BOLD <<"Value of b:\t\t" << b << _END << std::endl;
	std::cout << "\nWho is max ?\t\t" << Fixed::max( a, b ) << std::endl;
	std::cout << "Who is min ?\t\t" << Fixed::min( a, b ) << std::endl;

}
	return 0;
}