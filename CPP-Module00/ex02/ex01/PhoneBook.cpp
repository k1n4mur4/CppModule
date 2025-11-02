#include "PhoneBook.hpp"
#include <string>

static std::string	format_field(const std::string& field) {
	if (field.length() > 10)
		return (field.substr(0, 9) + ".");
	if (field.length() == 10)
		return (field);
	return (std::string(10 - field.length(), ' ') + field);
}

int	PhoneBook::get_size(void) const {
	return (this->size);
}

void	PhoneBook::add_contact(std::string data[5]) {
	int	index;

	index = this->index;
	this->contacts[index].set_firstname(data[0]);
	this->contacts[index].set_lastname(data[1]);
	this->contacts[index].set_nickname(data[2]);
	this->contacts[index].set_number(data[3]);
	this->contacts[index].set_secret(data[4]);
	this->index = (index + 1) % 8;

	if (this->size < 8)
		this->size++;
}

void	PhoneBook::display_contact(int index) const {
	std::cout << "First Name: " << this->contacts[index].get_firstname() << std::endl;
	std::cout << "Last Name: " << this->contacts[index].get_lastname() << std::endl;
	std::cout << "Nickname: " << this->contacts[index].get_nickname() << std::endl;
	std::cout << "Phone Number: " << this->contacts[index].get_number() << std::endl;
	std::cout << "Darkest Secret: " << this->contacts[index].get_secret() << std::endl;
}

void	PhoneBook::display_phonebook(void) const {
	std::cout << "|" << format_field("index");
	std::cout << "|" << format_field("first name");
	std::cout << "|" << format_field("last name");
	std::cout << "|" << format_field("nickname") << "|" << std::endl;
	for (int i = 0; i < this->size; i++) {
		std::cout << "|" << format_field(std::to_string(i));
		std::cout << "|" << format_field(this->contacts[i].get_firstname());
		std::cout << "|" << format_field(this->contacts[i].get_lastname());
		std::cout << "|" << format_field(this->contacts[i].get_nickname());
		std::cout << "|" << std::endl;
	}
}
