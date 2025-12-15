#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	this->_hit_points = 100;
	this->_energy_point = 100;
	this->_attack_damage = 30;
	std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap " << this->_name << " constructed." << std::endl;
	this->_hit_points = 100;
	this->_energy_point = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout << "FragTrap Copy Constructor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	std::cout << "FragTrap Assignment Operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

void FragTrap::attack(const std::string& target) {
	if (this->_hit_points > 0 && this->_energy_point > 0) {
		std::cout << "FragTrap " << this->_name << " attacks " << target 
				  << " aggressively, causing " << this->_attack_damage << " points of damage!" << std::endl;
		this->_energy_point--;
	} else {
		std::cout << "FragTrap " << this->_name << " is out of fuel!" << std::endl;
	}
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << this->_name << " says: High five, anyone?" << std::endl;
}