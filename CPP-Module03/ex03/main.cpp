#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main() {
	// ... (ScavとFragのテストは省略してもOK) ...

	std::cout << "\n===== DiamondTrap TEST =====" << std::endl;
	{
		DiamondTrap diamond("Monster");
		
		diamond.attack("Mario");
		
		diamond.whoAmI();

	}

	return 0;
}