#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		this->_materias[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &src) {
	for (int i = 0; i < 4; i++) {
		if (src._materias[i])
			this->_materias[i] = src._materias[i]->clone();
		else
			this->_materias[i] = NULL;
	}
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (this->_materias[i])
			delete this->_materias[i];
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src) {
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
			this->_materias[i] = materia;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (this->_materias[i] && this->_materias[i]->getType() == type) {
			return this->_materias[i]->clone();
		}
	}
	return 0;
}
