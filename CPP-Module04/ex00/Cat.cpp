#include "Cat.hpp"


Cat::Cat() {
	std::cout << "Cat Constructor called" << std::endl;
	this->type = "Cat";
}

Cat::~Cat() {
	std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Mew mew" << std::endl;
}
