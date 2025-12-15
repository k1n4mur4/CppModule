#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	this->_hit_points = 100;
	this->_energy_point = 50;
	this->_attack_damage = 20;
	std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_hit_points = 100;
	this->_energy_point = 50;
	this->_attack_damage = 20;
	std::cout << "ScavTrap " << this->_name << " constructed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	std::cout << "ScavTrap Assignment Operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

void ScavTrap::attack(const std::string& target) {
	if (this->_hit_points > 0 && this->_energy_point > 0) {
		std::cout << "ScavTrap " << this->_name << " attacks " << target 
				  << " aggressively, causing " << this->_attack_damage << " points of damage!" << std::endl;
		this->_energy_point--;
	} else {
		std::cout << "ScavTrap " << this->_name << " is out of fuel!" << std::endl;
	}
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}