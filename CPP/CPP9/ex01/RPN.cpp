#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}

RPN::RPN(const RPN& other) {
	(void)other;
}

RPN& RPN::operator=(const RPN& other) {
	(void)other;
	return *this;
}

static bool isOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

static bool isDigit(char c) {
	return c >= '0' && c <= '9';
}

int RPN::evaluate(const std::string& expression) {
	std::stack<int, std::list<int> > stack;
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token) {
		if (token.length() != 1) {
			std::cerr << "Error" << std::endl;
			return 1;
		}

		char c = token[0];

		if (isDigit(c))
			stack.push(c - '0');
		else if (isOperator(c)) {
			if (stack.size() < 2) {
				std::cerr << "Error" << std::endl;
				return 1;
			}

			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();

			int result;
			switch (c) {
				case '+':
					result = a + b;
					break;
				case '-':
					result = a - b;
					break;
				case '*':
					result = a * b;
					break;
				case '/':
					if (b == 0) {
						std::cerr << "Error" << std::endl;
						return 1;
					}
					result = a / b;
					break;
				default:
					std::cerr << "Error" << std::endl;
					return 1;
			}

			stack.push(result);
		}
		else {
			std::cerr << "Error" << std::endl;
			return 1;
		}
	}

	if (stack.size() != 1) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	std::cout << stack.top() << std::endl;
	return 0;
}
