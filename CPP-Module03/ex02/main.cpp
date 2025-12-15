#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main() {
	std::cout << "===== ScavTrap TEST =====" << std::endl;
	{
		ScavTrap scav("Serena");
		scav.attack("TargetA");
		scav.guardGate();
	}

	std::cout << "\n===== FragTrap TEST =====" << std::endl;
	{
		FragTrap frag("Bomber");
		frag.attack("TargetB"); 
		frag.highFivesGuys();
	}

	return 0;
}