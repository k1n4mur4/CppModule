#pragma once

#include <iostream>
#include <string>

class Weapon {
	private:
		std::string		_type;

	public:
		// Constructor
		Weapon(const std::string &weapon);
		~Weapon();

		// Getter
		std::string		getType() const;
		// Setter
		void			setType(const std::string &weapon);
};
