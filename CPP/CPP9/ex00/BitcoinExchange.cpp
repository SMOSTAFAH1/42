#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
		_data = other._data;
	return *this;
}

std::string BitcoinExchange::trim(const std::string& str) const {
	size_t first = str.find_first_not_of(" \t\n\r");
	if (first == std::string::npos)
		return "";
	size_t last = str.find_last_not_of(" \t\n\r");
	return str.substr(first, last - first + 1);
}

bool BitcoinExchange::isLeapYear(int year) const {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int BitcoinExchange::getDaysInMonth(int year, int month) const {
	const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if (month < 1 || month > 12)
		return 0;
	if (month == 2 && isLeapYear(year))
		return 29;
	return daysInMonth[month - 1];
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	for (size_t i = 0; i < date.length(); i++) {
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return false;
	}

	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > getDaysInMonth(year, month))
		return false;
	return true;
}

bool BitcoinExchange::isValidValue(float value) const {
	return value >= 0 && value <= 1000;
}

bool BitcoinExchange::loadDatabase(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return false;
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line)) {
		size_t comma = line.find(',');
		if (comma == std::string::npos)
			continue;

		std::string date = trim(line.substr(0, comma));
		std::string valueStr = trim(line.substr(comma + 1));

		if (!isValidDate(date))
			continue;

		float value = static_cast<float>(atof(valueStr.c_str()));
		_data[date] = value;
	}

	file.close();
	return true;
}

float BitcoinExchange::getExchangeRate(const std::string& date) const {
	std::map<std::string, float>::const_iterator it = _data.find(date);
	
	if (it != _data.end())
		return it->second;

	it = _data.upper_bound(date);
	
	if (it == _data.begin()) 
		return -1;

	--it;
	return it->second;
}

void BitcoinExchange::processInput(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	bool firstLine = true;
	while (std::getline(file, line)) {
		std::string trimmedLine = trim(line);
		if (trimmedLine.empty())
			continue;

		if (firstLine) {
			firstLine = false;
			if (trimmedLine == "date | value")
				continue;
		}

		size_t pipe = line.find('|');
		if (pipe == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = trim(line.substr(0, pipe));
		std::string valueStr = trim(line.substr(pipe + 1));

		if (!isValidDate(date)) {
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		if (valueStr.empty()) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		char* end;
		double rawValue = strtod(valueStr.c_str(), &end);
		
		if (*end != '\0' && *end != '\n' && *end != '\r') {
			std::cerr << "Error: bad input => " << valueStr << std::endl;
			continue;
		}

		if (rawValue < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}

		if (rawValue > 1000) {
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		float value = static_cast<float>(rawValue);
		float rate = getExchangeRate(date);
		if (rate < 0) {
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
	}

	file.close();
}
