#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal Constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal Destructor called" << std::endl;

}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal makesound called" << std::endl;
}

std::string	WrongAnimal::getType( void ) const{
	return this->type;
}