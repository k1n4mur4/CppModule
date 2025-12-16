#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

void printTitle(std::string title) {
	std::cout << "\n=== " << title << " ===" << std::endl;
}

void subjectTest() {
	printTitle("1. Subject Basic Test");
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void materiaSourceTest() {
	printTitle("2. MateriaSource Test (Limits & Unknown)");
	IMateriaSource* src = new MateriaSource();
	
	std::cout << "[Info] Learning 4 Materias..." << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << "[Test] Learning 5th Materia (Should be ignored)..." << std::endl;
	AMateria* extra = new Ice();
	src->learnMateria(extra); 
	// learnMateria 内で clone を保持するので extra は呼び出し側が解放する必要なし

	std::cout << "[Test] Creating unknown Materia 'fire'..." << std::endl;
	AMateria* unknown = src->createMateria("fire");
	if (unknown == NULL)
	std::cout << "OK: Unknown materia returned NULL" << std::endl;
	else
	std::cout << "KO: Unknown materia returned valid pointer!" << std::endl;

	delete src;
}

void inventoryTest() {
	printTitle("3. Character Inventory & Unequip Test");
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* cloud = new Character("Cloud");

	std::cout << "[Info] Equipping 4 slots..." << std::endl;
	cloud->equip(src->createMateria("ice"));
	cloud->equip(src->createMateria("cure"));
	cloud->equip(src->createMateria("ice"));
	cloud->equip(src->createMateria("cure"));

	std::cout << "[Test] Equipping 5th item (Should not crash)..." << std::endl;
	AMateria* extra = src->createMateria("ice");
	cloud->equip(extra);
	delete extra;

	std::cout << "[Test] Using all slots..." << std::endl;
	ICharacter* target = new Character("Dummy");
	cloud->use(0, *target);
	cloud->use(1, *target);
	cloud->use(2, *target);
	cloud->use(3, *target);
	
	std::cout << "[Test] Unequipping slot 0 and 1..." << std::endl;
	
	AMateria* m1 = src->createMateria("ice");
	ICharacter* tifa = new Character("Tifa");
	tifa->equip(m1); 
	
	std::cout << " -> Using slot 0 (Should work)" << std::endl;
	tifa->use(0, *target);
	
	std::cout << " -> Unequipping slot 0" << std::endl;
	tifa->unequip(0); 

	std::cout << " -> Using slot 0 (Should do nothing)" << std::endl;
	tifa->use(0, *target);

	std::cout << " -> Deleting unequipped materia manually" << std::endl;
	delete m1; 

	delete target;
	delete cloud;
	delete tifa;
	delete src;
}

void deepCopyTest() {
	printTitle("4. Deep Copy Test");

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	Character* original = new Character("Original");
	original->equip(src->createMateria("ice"));
	
	std::cout << "[Info] Creating Copy from Original..." << std::endl;
	Character* copy = new Character(*original); 

	std::cout << "[Info] Original uses slot 0:" << std::endl;
	original->use(0, *copy);

	std::cout << "[Info] Copy uses slot 0:" << std::endl;
	copy->use(0, *original);

	std::cout << "[Test] Modifying Original (Equipping Cure)..." << std::endl;
	original->equip(src->createMateria("cure"));

	std::cout << "Original inventory: [Ice, Cure, Empty, Empty]" << std::endl;
	std::cout << "Copy inventory	: [Ice, Empty, Empty, Empty] (Should be)" << std::endl;

	std::cout << "Original uses slot 1 (Cure): ";
	original->use(1, *copy); 
	
	std::cout << "Copy uses slot 1 (Empty):	";
	copy->use(1, *original); 

	delete original;
	delete copy;
	delete src;
}

int main() {
	subjectTest();
	materiaSourceTest();
	inventoryTest();
	deepCopyTest();
	
	return 0;
}
