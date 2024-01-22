#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	iter(T* array, const size_t len, void(*function)(T &))
{
	for(size_t i = 0; i < len; i++)
		function(array[i]);
}

template <typename T>
void	iter(const T* array, const size_t len, void(*function)(const T &))
{
	for(size_t i = 0; i < len; i++)
		function(array[i]);
}


// Uncomment if using main.cpp

// template <typename T>
// void	print(T& instance)
// {
// 	std::cout << instance << std::endl;
// }

#endif