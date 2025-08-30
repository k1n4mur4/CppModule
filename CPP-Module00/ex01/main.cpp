#include "PhoneBook.hpp"

static bool is_phonenumber(const std::string& number) {
	int	i;

	if (number.length() != 10)
		return false;
	for (i = 0; i < number.length(); ++i) {
		unsigned char c = static_cast<unsigned char>(number[i]);
		if (!std::isdigit(c))
			return false;
	}
	return true;
}

void	commandAdd(PhoneBook& phoneBook) {
	std::string data[5];
	int		 	count;

	std::cout << "First Name: ";
	std::getline(std::cin, data[0]);
	if (data[0].empty()) {
		std::cout << "First Name cannot be empty" << std::endl;
		return;
	}

	std::cout << "Last Name: ";
	std::getline(std::cin, data[1]);
	if (data[1].empty()) {
		std::cout << "Last Name cannot be empty" << std::endl;
		return;
	}

	std::cout << "Nick Name: ";
	std::getline(std::cin, data[2]);
	if (data[2].empty()) {
		std::cout << "Nick Name cannot be empty" << std::endl;
		return;
	}

	count = 0;
	while (true)
	{
		std::cout << "Phone Number: ";
		std::getline(std::cin, data[3]);
		if (is_phonenumber(data[3])) {
			break ;
		}
		std::cout << "Invalid input. A phone number must contain exactly 10 digits." << std::endl;
		if (count > 3) {
			std::cout << "Permission denied (you have only 3 attempts)." << std::endl;
			return ;
		}
		count++;
	}

	std::cout << "Darkest Secret: ";
	std::getline(std::cin, data[4]);
	if (data[4].empty()) {
		std::cout << "Darkest Secret cannot be empty" << std::endl;
		return;
	}

	phoneBook.addContact(data);
	std::cout << "Success!" << std::endl;
}

void	commandSearch(PhoneBook& phoneBook) {
	int			index;
	std::string	command;

	phoneBook.displayPhoneBook();
	std::cout << "Index: ";
	std::getline(std::cin, command);
	index = std::atoi(command.c_str());
	if (index < 0 || index >= phoneBook.getSize()) {
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	phoneBook.displayContact(index);
}

int		main(void) {
	PhoneBook	phoneBook;
	std::string	command;
	int			index;

	while (true) {
		std::cout << "PhoneBook ";
		std::getline(std::cin, command);
		if (command == "ADD") {
			commandAdd(phoneBook);
		}
		else if (command == "SEARCH") {
			commandSearch(phoneBook);
		}
		else if (command == "EXIT") {
			std::cout << "exit" << std::endl;
			break ;
		}
		else
			std::cout << "command not found: " << command << std::endl;
	}
	return 0;
}