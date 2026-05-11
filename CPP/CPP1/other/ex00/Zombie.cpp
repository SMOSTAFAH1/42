#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(const std::string& name) : name(name) {
	std::cout << name << " constructed" << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << name << " destroyed" << std::endl;
}

void Zombie::announce(void) const {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
