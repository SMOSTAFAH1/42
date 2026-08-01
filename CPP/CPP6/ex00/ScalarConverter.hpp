#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

class ScalarConverter {
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

public:
	static void convert(const std::string& str);
};

#endif
