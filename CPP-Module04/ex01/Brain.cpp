#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain Constructor called" << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain Destructor called" << std::endl;
}


Brain::Brain(const Brain &src) {
	std::cout << "Brain Copy Constructor called" << std::endl;
	*this = src;
}

Brain &Brain::operator=(const Brain &src) {
	std::cout << "Brain Copy Assignment Operator called" << std::endl;
	if (this != &src) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = src.ideas[i];
		}
	}
	return *this;
}
