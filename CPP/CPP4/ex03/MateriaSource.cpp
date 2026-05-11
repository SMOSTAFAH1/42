#include "MateriaSource.hpp"

// Constructor
MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		_templates[i] = NULL;
	}
}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < 4; i++) {
		if (other._templates[i] != NULL) {
			_templates[i] = other._templates[i]->clone();
		} else {
			_templates[i] = NULL;
		}
	}
}

// Assignment operator
MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		// Delete old templates
		for (int i = 0; i < 4; i++) {
			if (_templates[i] != NULL) {
				delete _templates[i];
			}
		}
		// Clone new templates
		for (int i = 0; i < 4; i++) {
			if (other._templates[i] != NULL) {
				_templates[i] = other._templates[i]->clone();
			} else {
				_templates[i] = NULL;
			}
		}
	}
	return *this;
}

// Destructor
MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (_templates[i] != NULL) {
			delete _templates[i];
		}
	}
}

// Member functions
void MateriaSource::learnMateria(AMateria* m) {
	if (m == NULL) {
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (_templates[i] == NULL) {
			_templates[i] = m;
			return;
		}
	}
	// Templates are full, delete the materia to prevent memory leak
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (_templates[i] != NULL && _templates[i]->getType() == type) {
			return _templates[i]->clone();
		}
	}
	return NULL;
}
