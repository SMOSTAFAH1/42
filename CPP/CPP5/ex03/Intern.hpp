#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
private:

	AForm* _createShrubberyForm(const std::string& target);
	AForm* _createRobotomyForm(const std::string& target);
	AForm* _createPresidentialForm(const std::string& target);

public:

	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	AForm* makeForm(const std::string& formName, const std::string& target);
};

#endif
