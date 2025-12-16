#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
	private:
		Brain *_brain;
	public:
		Dog();
		~Dog();

		void makeSound() const;
		Dog &operator=(const Dog &src);
		Dog(const Dog &src);
		void setIdea(int idx, const std::string& idea);
		std::string getIdea(int idx) const;
};

#endif
