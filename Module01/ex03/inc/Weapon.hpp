#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{

public:

	Weapon(const std::string& weapon);
	~Weapon();

	void			setType(const std::string& weapon);
	std::string		&getType();

private:

	std::string		_type;

};

#endif