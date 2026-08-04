#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <list>

class RPN {
public:
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();

	static int evaluate(const std::string& expression);
};

#endif
