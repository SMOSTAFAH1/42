#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	std::cout << "=== Testing array of AAnimals ===" << std::endl;
	const int arraySize = 6;
	AAnimal* animals[arraySize];
	
	std::cout << "\nCreating animals:" << std::endl;
	for (int i = 0; i < arraySize; i++) {
		if (i < arraySize / 2) {
			animals[i] = new Dog();
		} else {
			animals[i] = new Cat();
		}
	}
	
	std::cout << "\nMaking sounds:" << std::endl;
	for (int i = 0; i < arraySize; i++) {
		std::cout << animals[i]->getType() << ": ";
		animals[i]->makeSound();
	}
	
	std::cout << "\nDeleting animals:" << std::endl;
	for (int i = 0; i < arraySize; i++) {
		delete animals[i];
	}
	
	std::cout << "\n=== Testing deep copy ===" << std::endl;
	std::cout << "\nCreating original dog:" << std::endl;
	Dog* originalDog = new Dog();
	originalDog->getBrain()->setIdea(0, "I like bones");
	originalDog->getBrain()->setIdea(1, "I like to play fetch");
	
	std::cout << "\nCreating copy of dog:" << std::endl;
	Dog* copiedDog = new Dog(*originalDog);
	
	std::cout << "\nOriginal dog ideas:" << std::endl;
	std::cout << "Idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
	std::cout << "Idea 1: " << originalDog->getBrain()->getIdea(1) << std::endl;
	
	std::cout << "\nCopied dog ideas:" << std::endl;
	std::cout << "Idea 0: " << copiedDog->getBrain()->getIdea(0) << std::endl;
	std::cout << "Idea 1: " << copiedDog->getBrain()->getIdea(1) << std::endl;
	
	std::cout << "\nModifying original dog's idea 0:" << std::endl;
	originalDog->getBrain()->setIdea(0, "I REALLY like bones");
	
	std::cout << "\nOriginal dog idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
	std::cout << "Copied dog idea 0 (should be unchanged): " << copiedDog->getBrain()->getIdea(0) << std::endl;
	
	std::cout << "\nVerifying brain addresses are different:" << std::endl;
	std::cout << "Original brain: " << originalDog->getBrain() << std::endl;
	std::cout << "Copied brain: " << copiedDog->getBrain() << std::endl;
	
	std::cout << "\nDeleting dogs:" << std::endl;
	delete originalDog;
	delete copiedDog;
	
	// Uncommenting the following line should cause a compilation error
	// because AAnimal is an abstract class:
	// AAnimal* test = new AAnimal();
	
	return 0;
}
