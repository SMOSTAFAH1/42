#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main() {
	std::cout << "=== Test 1: Intern creates shrubbery creation form ===" << std::endl;
	{
		Intern someRandomIntern;
		AForm* form;

		form = someRandomIntern.makeForm("shrubbery creation", "home");
		if (form) {
			std::cout << *form << std::endl;

			Bureaucrat bob("Bob", 100);
			bob.signForm(*form);
			bob.executeForm(*form);

			delete form;
		}
	}

	std::cout << "\n=== Test 2: Intern creates robotomy request form ===" << std::endl;
	{
		Intern someRandomIntern;
		AForm* form;

		form = someRandomIntern.makeForm("robotomy request", "Bender");
		if (form) {
			std::cout << *form << std::endl;

			Bureaucrat alice("Alice", 40);
			alice.signForm(*form);
			alice.executeForm(*form);

			delete form;
		}
	}

	std::cout << "\n=== Test 3: Intern creates presidential pardon form ===" << std::endl;
	{
		Intern someRandomIntern;
		AForm* form;

		form = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
		if (form) {
			std::cout << *form << std::endl;

			Bureaucrat president("President", 1);
			president.signForm(*form);
			president.executeForm(*form);

			delete form;
		}
	}

	std::cout << "\n=== Test 4: Intern tries to create unknown form ===" << std::endl;
	{
		Intern someRandomIntern;
		AForm* form;

		form = someRandomIntern.makeForm("unknown form", "target");
		if (form) {
			std::cout << *form << std::endl;
			delete form;
		} else
			std::cout << "Form creation failed (returned NULL)" << std::endl;
	}

	std::cout << "\n=== Test 5: Multiple forms from same intern ===" << std::endl;
	{
		Intern intern;
		Bureaucrat supreme("Supreme", 1);

		AForm* form1 = intern.makeForm("shrubbery creation", "garden");
		AForm* form2 = intern.makeForm("robotomy request", "Marvin");
		AForm* form3 = intern.makeForm("presidential pardon", "Ford Prefect");

		if (form1) {
			supreme.signForm(*form1);
			supreme.executeForm(*form1);
			delete form1;
		}

		if (form2) {
			supreme.signForm(*form2);
			supreme.executeForm(*form2);
			delete form2;
		}

		if (form3) {
			supreme.signForm(*form3);
			supreme.executeForm(*form3);
			delete form3;
		}
	}

	std::cout << "\n=== Test 6: Case sensitivity test ===" << std::endl;
	{
		Intern intern;
		AForm* form;

		form = intern.makeForm("Shrubbery Creation", "test");
		if (!form)
			std::cout << "Correctly rejected wrong case" << std::endl;

		form = intern.makeForm("shrubbery creation", "test");
		if (form) {
			std::cout << "Correctly created form with exact case" << std::endl;
			delete form;
		}
	}

	return 0;
}
