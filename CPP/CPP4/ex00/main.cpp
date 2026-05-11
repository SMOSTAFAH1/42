#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << "=== Testing correct polymorphism ===" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << "\nTypes:" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	std::cout << "\nSounds:" << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	std::cout << "\nDeleting animals:" << std::endl;
	delete meta;
	delete j;
	delete i;
	
	std::cout << "\n=== Testing wrong polymorphism ===" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	
	std::cout << "\nTypes:" << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;
	
	std::cout << "\nSounds:" << std::endl;
	wrongCat->makeSound(); // will output WrongAnimal sound (NOT WrongCat)!
	wrongMeta->makeSound();
	
	std::cout << "\nDeleting wrong animals:" << std::endl;
	delete wrongMeta;
	delete wrongCat;
	
	return 0;
}
