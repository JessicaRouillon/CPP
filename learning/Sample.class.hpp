#ifndef SAMPLE_CLASS_H
#define SAMPLE_CLASS_H

#include <iostream>

class Sample
{

public:
	size_t foo;

	Sample(void);
	~Sample(void);

	void bar(void);
};

class Sample2
{

public:
	char a1;
	size_t a2;
	float a3;

	Sample2(char p1, size_t p2, float p3);
	~Sample2(void);
};

/* Fonctions getFoo / setFoo */

class Sample3
{

public:

	Sample3(void);
	~Sample3(void);

	size_t 	getFoo(void) const;
	void	setFoo(size_t v);

private:

	size_t		_foo;
};

#endif