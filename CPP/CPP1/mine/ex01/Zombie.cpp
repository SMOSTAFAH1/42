#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) : name("") {
}

Zombie::Zombie(const std::string& name) : name(name) {
}

Zombie::~Zombie(void) {
	std::cout << name << " destroyed" << std::endl;
}

void Zombie::announce(void) const {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string& name) {
	this->name = name;
}
