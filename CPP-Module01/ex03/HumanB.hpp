#pragma once

#include <iostream>
#include "Weapon.hpp"

class HumanB {
	private:
		std::string	_name;
		Weapon		*_weapon;
		bool		_is_armed;
	public:
		// Constructor
		HumanB(std::string name);
		// Deconstructor
		~HumanB(void);

		// Setter
		void	setWeapon(Weapon &weapon);
		// Public Hethods
		void	attack(void);
};
