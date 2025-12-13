#include "ScavTrap.hpp"
#include <iostream>

int main() {
	std::cout << "--- 1. Creating ScavTrap ---" << std::endl;
	ScavTrap scav("GateKeeper");

	std::cout << "\n--- 2. Testing Stats & Attack ---" << std::endl;
	scav.attack("Intruder"); 

	std::cout << "\n--- 3. Testing Special Ability ---" << std::endl;
	scav.guardGate(); 

	std::cout << "\n--- 4. Destruction Chain ---" << std::endl;

	return 0;
}