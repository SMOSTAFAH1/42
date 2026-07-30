#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	std::cout << "=== Test 1: Create valid form ===" << std::endl;
	try {
		Form taxForm("Tax Form", 50, 25);
		std::cout << taxForm << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Form with invalid sign grade (too high) ===" << std::endl;
	try {
		Form invalidForm("Invalid Form", 0, 25);
		std::cout << invalidForm << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Form with invalid exec grade (too low) ===" << std::endl;
	try {
		Form invalidForm("Invalid Form", 50, 151);
		std::cout << invalidForm << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Bureaucrat successfully signs form ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 30);
		Form permitForm("Building Permit", 50, 25);
		std::cout << permitForm << std::endl;
		alice.signForm(permitForm);
		std::cout << permitForm << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Bureaucrat fails to sign form (grade too low) ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 100);
		Form topSecretForm("Top Secret", 25, 10);
		std::cout << topSecretForm << std::endl;
		bob.signForm(topSecretForm);
		std::cout << topSecretForm << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: Bureaucrat at exact grade threshold ===" << std::endl;
	try {
		Bureaucrat charlie("Charlie", 50);
		Form licenseForm("Driver License", 50, 30);
		std::cout << licenseForm << std::endl;
		charlie.signForm(licenseForm);
		std::cout << licenseForm << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 7: Multiple signatures on same form ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 20);
		Bureaucrat bob("Bob", 30);
		Form contract("Contract", 40, 20);
		std::cout << contract << std::endl;
		alice.signForm(contract);
		bob.signForm(contract);
		std::cout << contract << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
