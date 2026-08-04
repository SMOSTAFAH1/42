#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <map>
#include <cctype>

class BitcoinExchange {
private:
	std::map<std::string, float> _data;

	bool isValidDate(const std::string& date) const;
	bool isLeapYear(int year) const;
	int getDaysInMonth(int year, int month) const;
	bool isValidValue(float value) const;
	std::string trim(const std::string& str) const;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	bool loadDatabase(const std::string& filename);
	void processInput(const std::string& filename);
	float getExchangeRate(const std::string& date) const;
};

#endif
