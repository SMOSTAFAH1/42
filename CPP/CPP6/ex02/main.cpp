#include "functions.hpp"

int main() {
	std::srand(std::time(0));

	std::cout << "=== Test ===" << std::endl;
	Base* obj1 = generate();
	std::cout << "identify(pointer): ";
	identify(obj1);
	std::cout << "identify(reference): ";
	identify(*obj1);
	delete obj1;

	return 0;
}
