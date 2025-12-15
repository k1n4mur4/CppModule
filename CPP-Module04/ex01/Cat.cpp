#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat Constructor called" << std::endl;
	this->type = "Cat";
	this->_brain = new Brain();
}

Cat::~Cat() {
	std::cout << "Cat Destructor called" << std::endl;
	delete this->_brain;
}

void Cat::makeSound() const {
	std::cout << "Mew mew" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src) {
	std::cout << "Cat Copy Constructor called" << std::endl;

	this->_brain = new Brain();
	*this->_brain = *src._brain;
}

Cat &Cat::operator=(const Cat &src) {
	std::cout << "Cat Copy Assignment Operator called" << std::endl;
	if (this != &src) {
		this->type = src.type;
		if (this->_brain)
			delete this->_brain;

		this->_brain = new Brain();
		*this->_brain = *src._brain;
	}
	return *this;
}
