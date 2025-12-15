#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "ClapTrap Constructor called" << std::endl;
	_hit_points = 10;
	_energy_point = 10;
	_attack_damage = 0;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "ClapTrap Copy Assignment Operator called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_hit_points = other._hit_points;
		this->_energy_point = other._energy_point;
		this->_attack_damage = other._attack_damage;
	}
	return *this;
}

ClapTrap::ClapTrap(std::string name) {
	std::cout << "ClapTrap Constructor called" << std::endl;
	this->_name = name;
	this->_hit_points = 10;
	this->_energy_point = 10;
	this->_attack_damage = 0;
}

void	ClapTrap::attack(const std::string& target) {
	if (this->_hit_points > 0) {
		if (this->_energy_point > 0)
		{
			std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing "<< this->_attack_damage <<" points of damage!" << std::endl;
			this->_energy_point--;
		}
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (amount > this->_hit_points)
	{
		this->_hit_points = 0;
		std::cout << "ClapTrap " << this->_name << " took " << this->_hit_points << " damage! (HP: " << this->_hit_points << ")" << std::endl;
	}
	else {
		if (this->_hit_points > 0)
		{
			this->_hit_points -= amount;
			std::cout << "ClapTrap " << this->_name << " took " << amount << " damage! (HP: " << this->_hit_points << ")" << std::endl;
		}
	}
}

void	ClapTrap::beRepaired(unsigned int	amount) {
	if (this->_hit_points > 0) {
		if (this->_energy_point > 0)
		{
			std::cout << "ClapTrap " << this->_name << " consumes energy to repair itself! +" << amount << " HP!" << std::endl;
			this->_energy_point--;
			this->_hit_points += amount;
		}
	}
}

unsigned ClapTrap::getHitPoint( void ) {
	return this->_hit_points;
}

std::string	ClapTrap::getName( void ) {
	return this->_name;
}
