#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		delete j;
		delete i;
	}
	std::cout << "=== 1. Array Test ===" << std::endl;
	const int count = 4;
	const Animal* animals[count];

	for (int i = 0; i < count; i++)
	{
		if (i < count / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < count; i++)
		animals[i]->makeSound();

	for (int i = 0; i < count; i++)
		delete animals[i];

	std::cout << "\n=== 2. Deep Copy Test ===" << std::endl;

	Dog basic;
	basic.setIdea(0, "Original idea");
	{
		Dog tmp = basic;
		tmp.setIdea(0, "Tmp idea");
		std::cout << "basic idea[0]: " << basic.getIdea(0) << std::endl;
		std::cout << "tmp idea[0]: " << tmp.getIdea(0) << std::endl;
	} 

	std::cout << "End of main (basic will be destroyed here)" << std::endl;

	return 0;
}
