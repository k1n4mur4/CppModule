#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat Constructor called" << std::endl;
	this->type = "WrongCat";

}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor called" << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << "Mew mew" << std::endl;

}
