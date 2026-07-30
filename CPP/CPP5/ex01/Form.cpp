#include "Form.hpp"
#include "Bureaucrat.hpp"

void Form::_validateGrade(int grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Form::Form() : _name("Default Form"), _isSigned(false), _signGrade(150), _execGrade(150) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, int signGrade, int execGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
	_validateGrade(signGrade);
	_validateGrade(execGrade);
	std::cout << "Form parametric constructor called for " << _name << std::endl;
}

Form::Form(const Form& other)
	: _name(other._name), _isSigned(other._isSigned),
	  _signGrade(other._signGrade), _execGrade(other._execGrade) {
	std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other) {
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

Form::~Form() {
	std::cout << "Form destructor called for " << _name << std::endl;
}

const std::string& Form::getName() const {
	return _name;
}

bool Form::isSigned() const {
	return _isSigned;
}

int Form::getSignGrade() const {
	return _signGrade;
}

int Form::getExecGrade() const {
	return _execGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "Form " << form.getName()
	   << " [signed: " << (form.isSigned() ? "yes" : "no")
	   << ", sign grade: " << form.getSignGrade()
	   << ", exec grade: " << form.getExecGrade() << "]";
	return os;
}
