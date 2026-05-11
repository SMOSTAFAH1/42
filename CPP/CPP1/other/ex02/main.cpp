#include <string>
#include <iostream>

int main(void) {
	std::string  brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &brain;
	std::string& stringREF = brain;
	
	std::cout << "Memory address of string:\t\t" << &brain << std::endl;
	std::cout << "Memory address of stringPTR:\t\t" << &stringPTR << std::endl;
	std::cout << "Memory address held by stringPTR:\t" << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF:\t" << &stringREF << std::endl;
	
	std::cout << std::endl;
	
	std::cout << "Value of string:\t\t\t" << brain << std::endl;
	std::cout << "Value pointed by stringPTR:\t\t" << *stringPTR << std::endl;
	std::cout << "Value pointed by stringREF:\t\t" << stringREF << std::endl;
	
	return 0;
}
