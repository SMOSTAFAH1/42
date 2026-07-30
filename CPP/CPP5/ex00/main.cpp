#include "Bureaucrat.hpp"

int main() {
	std::cout << "=== Test 1: Valid bureaucrat creation ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 75);
		std::cout << bob << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Grade too high (0) ===" << std::endl;
	try {
		Bureaucrat invalid("Invalid", 0);
		std::cout << invalid << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Grade too low (151) ===" << std::endl;
	try {
		Bureaucrat invalid("Invalid", 151);
		std::cout << invalid << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Increment grade at boundary (grade 1) ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 1);
		std::cout << alice << std::endl;
		alice.incrementGrade();
		std::cout << alice << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Decrement grade at boundary (grade 150) ===" << std::endl;
	try {
		Bureaucrat charlie("Charlie", 150);
		std::cout << charlie << std::endl;
		charlie.decrementGrade();
		std::cout << charlie << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: Valid increment and decrement ===" << std::endl;
	try {
		Bureaucrat diana("Diana", 75);
		std::cout << diana << std::endl;
		diana.incrementGrade();
		std::cout << "After increment: " << diana << std::endl;
		diana.decrementGrade();
		std::cout << "After decrement: " << diana << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 7: Copy constructor ===" << std::endl;
	try {
		Bureaucrat original("Original", 50);
		Bureaucrat copy(original);
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy: " << copy << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
