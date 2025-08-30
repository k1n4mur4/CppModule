#include "PhoneBook.hpp"

int	PhoneBook::getSize(void) const {
	return (this->size);
}

void	PhoneBook::addContact(std::string data[5]) {
	int	index;

	index = this->index;
	this->contacts[index].setFirstName(data[0]);
	this->contacts[index].setLastName(data[1]);
	this->contacts[index].setNickName(data[2]);
	this->contacts[index].setPhoneNumber(data[3]);
	this->contacts[index].setSecret(data[4]);
	this->index = (index + 1) % 8;

	if (this->size < 8)
		this->size++;
}

void	PhoneBook::displayContact(int index) const {
	std::cout << "First Name: " << this->contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << this->contacts[index].getNickName() << std::endl;
	std::cout << "Phone Number: " << this->contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->contacts[index].getSecret() << std::endl;

}

void	PhoneBook::displayPhoneBook(void) const {
	for (int i = 0; i < this->size; i++) {
		std::cout << "|" << i << "\t|";
		std::cout << this->contacts[i].getFirstName() << "\t|";
		std::cout << this->contacts[i].getLastName() << "\t|";
		std::cout << this->contacts[i].getNickName() << "\t|" << std::endl;
	}
}
