#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <list>
# include <vector>

template <typename T>
void	easyfind(T& a, int i)
{
	typename T::iterator it = std::find(a.begin(), a.end(), i);
	if (it != a.end())
		std::cout << "\033[0;32mInt i = " << i << " has been found in container a.\033[0m" << std::endl;
	else
		std::cout << "\033[0;31mError: Int i = " << i << " is not in container a.\033[0m" << std::endl;
}

#endif