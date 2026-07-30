#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	std::cout << "=== Test 1: ShrubberyCreationForm ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 100);
		ShrubberyCreationForm shrub("home");

		std::cout << shrub << std::endl;
		bob.signForm(shrub);
		bob.executeForm(shrub);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: RobotomyRequestForm - Success case ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 40);
		RobotomyRequestForm robot("Bender");

		std::cout << robot << std::endl;
		alice.signForm(robot);
		alice.executeForm(robot);
		alice.executeForm(robot);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: PresidentialPardonForm - Success case ===" << std::endl;
	try {
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Arthur Dent");

		std::cout << pardon << std::endl;
		president.signForm(pardon);
		president.executeForm(pardon);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Execute unsigned form ===" << std::endl;
	try {
		Bureaucrat charlie("Charlie", 1);
		PresidentialPardonForm unsignedForm("John Doe");

		charlie.executeForm(unsignedForm);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Execute with insufficient grade ===" << std::endl;
	try {
		Bureaucrat lowGrade("LowGrade", 50);
		PresidentialPardonForm pardon("Jane Doe");

		Bureaucrat highGrade("HighGrade", 1);
		highGrade.signForm(pardon);

		lowGrade.executeForm(pardon);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: Sign with insufficient grade ===" << std::endl;
	try {
		Bureaucrat lowGrade("LowGrade", 100);
		PresidentialPardonForm pardon("Test Subject");

		lowGrade.signForm(pardon);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 7: All forms with high-grade bureaucrat ===" << std::endl;
	try {
		Bureaucrat supreme("Supreme", 1);

		ShrubberyCreationForm shrub("garden");
		RobotomyRequestForm robot("Marvin");
		PresidentialPardonForm pardon("Ford Prefect");

		supreme.signForm(shrub);
		supreme.executeForm(shrub);

		supreme.signForm(robot);
		supreme.executeForm(robot);

		supreme.signForm(pardon);
		supreme.executeForm(pardon);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
