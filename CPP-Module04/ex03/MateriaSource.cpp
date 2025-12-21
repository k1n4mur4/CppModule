#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource Constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->_materias[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &src) {
	std::cout << "MateriaSource Copy Constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (src._materias[i])
			this->_materias[i] = src._materias[i]->clone();
		else
			this->_materias[i] = NULL;
	}
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource Destructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->_materias[i])
			delete this->_materias[i];
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src) {
	std::cout << "MateriaSource Copy Assignment Operator called" << std::endl;
	if (this != &src) {
		for (int i = 0; i < 4; i++) {
			if (this->_materias[i])
				delete this->_materias[i];
			this->_materias[i] = NULL;
		}

		for (int i = 0; i < 4; i++) {
			if (src._materias[i])
				this->_materias[i] = src._materias[i]->clone();
			else
				this->_materias[i] = NULL;
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* materia) {
	if (!materia)
		return;

	for (int i = 0; i < 4; i++) {
		if (this->_materias[i] == NULL) {
			this->_materias[i] = materia->clone();
			delete materia;
			return;
		}
	}
	delete materia;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (this->_materias[i] && this->_materias[i]->getType() == type) {
			return this->_materias[i]->clone();
		}
	}
	return 0;
}
