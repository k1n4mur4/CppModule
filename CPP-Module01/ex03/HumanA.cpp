#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):_weapon(weapon) {
	this->_name = name;
	std::cout << this->_name <<" joined the battlefield and grabbed a " << this->_weapon.getType() << " to fight." << std::endl;
}

HumanA::~HumanA(void) {
	std::cout << this->_name << " died." << std::endl;
}

void	HumanA::attack(void) {
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << "." << std::endl;
}
