#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
	private:
		Brain *_brain;
	public:
		Cat();
		~Cat();

		void makeSound() const;
		Cat(const Cat &src);
		Cat &operator=(const Cat &src);
		void setIdea(int idx, const std::string& idea);
		std::string getIdea(int idx) const;
};

#endif
