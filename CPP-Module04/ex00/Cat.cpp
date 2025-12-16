#include "Cat.hpp"


Cat::Cat() {
	std::cout << "Cat Constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Mew mew" << std::endl;
}
