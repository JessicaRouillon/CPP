#include "Sample.class.hpp"

Sample2::Sample2(char p1, int p2, float p3) : a1(p1), a2(p2), a3(p3)
{
	std::cout << "Constructor called" << std::endl;
	std::cout << "this->a1 = " << this->a1 << std::endl;
	std::cout << "this->a2 = " << this->a2 << std::endl;
	std::cout << "this->a3 = " << this->a3 << std::endl;
}

Sample2::~Sample2(void)
{
	std::cout << "Deconstructor called" << std::endl;
	return;
}

Sample::Sample(void)
{
	std::cout << "Constructor called" << std::endl;

	this->foo = 42;
	std::cout << "this->foo: " << this->foo << std::endl;

	this->bar();
	return;
}

Sample::~Sample(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

void Sample::bar(void)
{
	std::cout << "Member function bar called" << std::endl;
	return;
}

// int main(void)
// {
// 	Sample instance;

// 	return 0;
// }

// int	main(void) {
// 	Sample	instance;

// 	instance.foo = 42;
// 	std::cout << "instance.foo: " << instance.foo << std::endl;

// 	instance.bar();

// 	return 0;
// }

int	main()
{
	Sample2	instance2('z', 13, 3.14f);
	
	return 0;
}