#include "AForm.hpp"
#include "Bureaucrat.hpp"

void AForm::_validateGrade(int grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

AForm::AForm() : _name("Default AForm"), _isSigned(false), _signGrade(150), _execGrade(150) {
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int signGrade, int execGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
	_validateGrade(signGrade);
	_validateGrade(execGrade);
	std::cout << "AForm parametric constructor called for " << _name << std::endl;
}

AForm::AForm(const AForm& other)
	: _name(other._name), _isSigned(other._isSigned),
	  _signGrade(other._signGrade), _execGrade(other._execGrade) {
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
	std::cout << "AForm assignment operator called" << std::endl;
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

AForm::~AForm() {
	std::cout << "AForm destructor called for " << _name << std::endl;
}

const std::string& AForm::getName() const {
	return _name;
}

bool AForm::isSigned() const {
	return _isSigned;
}

int AForm::getSignGrade() const {
	return _signGrade;
}

int AForm::getExecGrade() const {
	return _execGrade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "AForm grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "AForm grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << "AForm " << form.getName()
	   << " [signed: " << (form.isSigned() ? "yes" : "no")
	   << ", sign grade: " << form.getSignGrade()
	   << ", exec grade: " << form.getExecGrade() << "]";
	return os;
}
