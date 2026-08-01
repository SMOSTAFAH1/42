#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

static bool isChar(const std::string& str) {
	if (str.length() == 1 && !isdigit(str[0]))
		return true;
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return true;
	return false;
}

static bool isInt(const std::string& str) {
	size_t i = 0;
	int digitCount = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i >= str.length())
		return false;
	while (i < str.length()) {
		if (!isdigit(str[i]))
			return false;
		digitCount++;
		i++;
	}
	return (digitCount > 0);
}

static bool isFloat(const std::string& str) {
	if (str == "nanf" || str == "+inff" || str == "-inff" || str == "inff")
		return true;
	if (str.length() < 2 || str[str.length() - 1] != 'f')
		return false;
	std::string numPart = str.substr(0, str.length() - 1);
	size_t i = 0;
	bool hasDot = false;
	int digitCount = 0;
	if (numPart[i] == '+' || numPart[i] == '-')
		i++;
	if (i >= numPart.length())
		return false;
	while (i < numPart.length()) {
		if (numPart[i] == '.') {
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (isdigit(numPart[i]))
			digitCount++;
		else
			return false;
		i++;
	}
	return (digitCount > 0);
}

static bool isDouble(const std::string& str) {
	if (str == "nan" || str == "+inf" || str == "-inf" || str == "inf")
		return true;
	size_t i = 0;
	bool hasDot = false;
	int digitCount = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i >= str.length())
		return false;
	while (i < str.length()) {
		if (str[i] == '.') {
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (isdigit(str[i]))
			digitCount++;
		else
			return false;
		i++;
	}
	return (hasDot && digitCount > 0);
}

static void printChar(char c, bool impossible, bool nonDisplayable) {
	std::cout << "char: ";
	if (impossible)
		std::cout << "impossible";
	else if (nonDisplayable)
		std::cout << "Non displayable";
	else
		std::cout << "'" << c << "'";
	std::cout << std::endl;
}

static void printInt(int n, bool impossible) {
	std::cout << "int: ";
	if (impossible)
		std::cout << "impossible";
	else
		std::cout << n;
	std::cout << std::endl;
}

static void printFloat(float f, bool impossible) {
	std::cout << "float: ";
	if (impossible) {
		std::cout << "impossible" << std::endl;
		return;
	}
	if (f != f) {
		std::cout << "nanf" << std::endl;
		return;
	}
	if (f == std::numeric_limits<float>::infinity()) {
		std::cout << "+inff" << std::endl;
		return;
	}
	if (f == -std::numeric_limits<float>::infinity()) {
		std::cout << "-inff" << std::endl;
		return;
	}
	std::ostringstream ss;
	ss << f;
	std::string s = ss.str();
	if (s.find('.') == std::string::npos && s.find('e') == std::string::npos)
		s += ".0";
	std::cout << s << "f" << std::endl;
}

static void printDouble(double d, bool impossible) {
	std::cout << "double: ";
	if (impossible) {
		std::cout << "impossible" << std::endl;
		return;
	}
	if (d != d) {
		std::cout << "nan" << std::endl;
		return;
	}
	if (d == std::numeric_limits<double>::infinity()) {
		std::cout << "+inf" << std::endl;
		return;
	}
	if (d == -std::numeric_limits<double>::infinity()) {
		std::cout << "-inf" << std::endl;
		return;
	}
	std::ostringstream ss;
	ss << d;
	std::string s = ss.str();
	if (s.find('.') == std::string::npos && s.find('e') == std::string::npos)
		s += ".0";
	std::cout << s << std::endl;
}

void ScalarConverter::convert(const std::string& str) {
	if (str.empty()) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	char c = 0;
	int n = 0;
	float f = 0.0f;
	double d = 0.0;
	bool charImpossible = false;
	bool intImpossible = false;
	bool floatImpossible = false;
	bool doubleImpossible = false;
	bool nonDisplayable = false;

	if (isChar(str)) {
		if (str.length() == 1)
			c = str[0];
		else
			c = str[1];
		n = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
	}
	else if (isInt(str)) {
		errno = 0;
		char* endptr;
		long temp = std::strtol(str.c_str(), &endptr, 10);
		if (errno == ERANGE || temp > std::numeric_limits<int>::max() || temp < std::numeric_limits<int>::min()) {
			intImpossible = true;
			charImpossible = true;
			d = std::strtod(str.c_str(), 0);
			f = static_cast<float>(d);
		}
		else {
			n = static_cast<int>(temp);
			f = static_cast<float>(n);
			d = static_cast<double>(n);
			if (n < 0 || n > 127)
				charImpossible = true;
			else if (n < 32 || n == 127) {
				nonDisplayable = true;
				c = static_cast<char>(n);
			}
			else
				c = static_cast<char>(n);
		}
	}
	else if (isFloat(str)) {
		if (str == "nanf" || str == "+inff" || str == "-inff" || str == "inff") {
			charImpossible = true;
			intImpossible = true;
			if (str == "nanf") {
				f = std::numeric_limits<float>::quiet_NaN();
				d = static_cast<double>(f);
			}
			else if (str == "-inff") {
				f = -std::numeric_limits<float>::infinity();
				d = static_cast<double>(f);
			}
			else {
				f = std::numeric_limits<float>::infinity();
				d = static_cast<double>(f);
			}
		}
		else {
			d = std::strtod(str.c_str(), 0);
			f = static_cast<float>(d);
			if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max() || (d != d) || (d == std::numeric_limits<double>::infinity()) || (d == -std::numeric_limits<double>::infinity())) {
				intImpossible = true;
				charImpossible = true;
			}
			else {
				n = static_cast<int>(f);
				if (n < 0 || n > 127)
					charImpossible = true;
				else if (n < 32 || n == 127) {
					nonDisplayable = true;
					c = static_cast<char>(n);
				}
				else
					c = static_cast<char>(n);
			}
		}
	}
	else if (isDouble(str)) {
		if (str == "nan" || str == "+inf" || str == "-inf" || str == "inf") {
			charImpossible = true;
			intImpossible = true;
			if (str == "nan") {
				d = std::numeric_limits<double>::quiet_NaN();
				f = static_cast<float>(d);
			}
			else if (str == "-inf") {
				d = -std::numeric_limits<double>::infinity();
				f = static_cast<float>(d);
			}
			else {
				d = std::numeric_limits<double>::infinity();
				f = static_cast<float>(d);
			}
		}
		else {
			d = std::strtod(str.c_str(), 0);
			f = static_cast<float>(d);
			if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max() || (d != d) || (d == std::numeric_limits<double>::infinity()) || (d == -std::numeric_limits<double>::infinity())) {
				intImpossible = true;
				charImpossible = true;
			}
			else {
				n = static_cast<int>(d);
				if (n < 0 || n > 127)
					charImpossible = true;
				else if (n < 32 || n == 127) {
					nonDisplayable = true;
					c = static_cast<char>(n);
				}
				else
					c = static_cast<char>(n);
			}
		}
	}
	else {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	printChar(c, charImpossible, nonDisplayable);
	printInt(n, intImpossible);
	printFloat(f, floatImpossible);
	printDouble(d, doubleImpossible);
}
