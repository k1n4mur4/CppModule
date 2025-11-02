#pragma once

#include "Contact.hpp"
#include <iostream>

class PhoneBook {

	private:
		Contact	contacts[8];
		int		size;
		int		index;

	public:
		PhoneBook() : index(0), size(0) {}
		int		get_size(void) const;
		void	add_contact(std::string data[5]);
		void	display_contact(int index) const;
		void	display_phonebook(void) const;

};
