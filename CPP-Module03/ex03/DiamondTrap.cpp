#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap() {
	std::cout << "DiamondTrap Default Constructor called" << std::endl;
	this->_name = "defualt";
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_point = ScavTrap::_energy_point;
	this->_attack_damage =  ScavTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap " << this->_name << " constructed." << std::endl;
	this->_name = name;

	this->_hit_points = FragTrap::_hit_points;
	this->_energy_point = ScavTrap::_energy_point;
	this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) {
	std::cout << "DiamondTrap Copy Constructor called" << std::endl;
	*this = other;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	std::cout << "DiamondTrap Assignment Operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
		this->_name = other._name;
	}
	return *this;
}

void DiamondTrap::whoAmI() {
	std::cout << "I am DiamondTrap: " << this->_name << ", and my ClapTrap name is: " << ClapTrap::_name << std::endl;
}