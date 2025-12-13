#include "ClapTrap.hpp"
#include <iostream>

int selecter_move( void ) {
	std::string input_str;
	int input_num = 0;

	do {
		std::cout << "Select your move:" << std::endl;
		std::cout << "1: Attack" << std::endl;
		std::cout << "2: Repair" << std::endl;
		std::cout << "3: Run away (Leave)" << std::endl;
		std::cout << "> ";
		
		if (!std::getline(std::cin, input_str))
			return 3; 

		input_num = std::atoi(input_str.c_str());

	} while (input_num < 1 || input_num > 3);

	return input_num;
}

bool turnChange(ClapTrap &attacker, ClapTrap &defender) {
	std::cout << "\n=== " << attacker.getName() << "'s Turn ===" << std::endl;
	std::cout << "Target: " << defender.getName() << " (HP: " << defender.getHitPoint() << ")" << std::endl;

	int choice = selecter_move();

	switch (choice) {
		case 1:
			attacker.attack(defender.getName());
			defender.takeDamage(2);
			break;
		
		case 2:
			attacker.beRepaired(3);
			break;

		case 3:  // ★ここ！
			std::cout << attacker.getName() << " ran away!" << std::endl;
			return false;

		default:
			return false;
	}
	return true;
}

int main(void) {
	std::string name;

	do {
		std::cout << "Input your name (1-16 chars): ";
		if (!std::getline(std::cin, name))
			return 1;
	} while(name.length() == 0 || name.length() > 16);

	ClapTrap player(name);
	ClapTrap enemy("R2D2");

	std::cout << "\nBattle Start!" << std::endl;

	while (player.getHitPoint() > 0 && enemy.getHitPoint() > 0) {
		
		if (!turnChange(player, enemy))
			break;
		
		if (enemy.getHitPoint() > 0) {
			std::cout << "\n[Enemy Turn]" << std::endl;
			enemy.attack(player.getName());
			player.takeDamage(2);
		}
	}

	std::cout << "\n=== Game Over ===" << std::endl;
	if (player.getHitPoint() == 0)
		std::cout << "You Lose..." << std::endl;
	else if (enemy.getHitPoint() == 0)
		std::cout << "You Win!" << std::endl;
	else
		std::cout << "Draw (Run away)" << std::endl;

	return 0;
}