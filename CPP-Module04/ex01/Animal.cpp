#include "Animal.hpp"


Animal::Animal() : type("Animal"){
	std::cout << "Animal Constructor called" << std::endl;
}

Animal::~Animal(){
	std::cout << "Animal Destructor called" << std::endl;
}

void Animal::makeSound() const{
	std::cout << "Animal makesound called" << std::endl;
	
}

std::string	Animal::getType() const{
	return this->type;
}
