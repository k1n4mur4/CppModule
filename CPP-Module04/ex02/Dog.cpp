#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog Constructor called" << std::endl;
	this->type = "Dog";
	this->_brain = new Brain();
}

Dog::~Dog() {
	std::cout << "Dog Destructor called" << std::endl;
	delete this->_brain;
}

void Dog::makeSound() const {
	std::cout << "Bow wow!" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src) {
	std::cout << "Dog Copy Constructor called" << std::endl;

	this->_brain = new Brain();
	*this->_brain = *src._brain;
}

Dog &Dog::operator=(const Dog &src) {
	std::cout << "Dog Copy Assignment Operator called" << std::endl;
	if (this != &src) {
		this->type = src.type;
		if (this->_brain)
			delete this->_brain;

		this->_brain = new Brain();
		*this->_brain = *src._brain;
	}
	return *this;
}
