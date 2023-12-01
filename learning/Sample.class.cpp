#include "Sample.class.hpp"

/******* with arguments *******/

// Sample2::Sample2(char p1, size_t p2, float p3) : a1(p1), a2(p2), a3(p3)
// {
// 	std::cout << "Constructor called" << std::endl;
// 	std::cout << "this->a1 = " << this->a1 << std::endl;
// 	std::cout << "this->a2 = " << this->a2 << std::endl;
// 	std::cout << "this->a3 = " << this->a3 << std::endl;
// }

// size_t	main()
// {
// 	Sample2	instance2('z', 13, 3.14f);
	
// 	return 0;
// }




/******* Basic constructor / desctructor *******/

// Sample::Sample(void)
// {
// 	std::cout << "Constructor called" << std::endl;

// 	this->foo = 42;
// 	std::cout << "this->foo: " << this->foo << std::endl;

// 	this->bar();
// 	return;
// }

// Sample::~Sample(void)
// {
// 	std::cout << "Destructor called" << std::endl;
// 	return;
// }

// size_t main(void)
// {
// 	Sample instance;

// 	return 0;
// }



/******* Function in class *******/

// Sample2::~Sample2(void)
// {
// 	std::cout << "Deconstructor called" << std::endl;
// 	return;
// }

// void Sample::bar(void)
// {
// 	std::cout << "Member function bar called" << std::endl;
// 	return;
// }

// size_t	main(void) {
// 	Sample	instance;

// 	instance.foo = 42;
// 	std::cout << "instance.foo: " << instance.foo << std::endl;

// 	instance.bar();

// 	return 0;
// }



/******* Fonctions getFoo / setFoo *******/

size_t		Sample3::getFoo(void)const
{
	return this->_foo;
}

void	Sample3::setFoo(size_t v)
{
	if (v >= 0)
		this->_foo = v;
	return ;
}

size_t	main()
{
	Sample3	instance;

	instance.setFoo(42);
	std::cout << "instance.getFoo() : " << instance.getFoo() << std::endl;
	instance.setFoo(-42);
	std::cout << "instance.getFoo() : " << instance.getFoo() << std::endl;

	return 0;
}
