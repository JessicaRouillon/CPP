#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{

public:

	Weapon(const std::string& weapon);
	~Weapon();

	void				setType(const std::string& weapon);
	const std::string&	getType(void) const;

private:

	std::string		_type;

};

#endif