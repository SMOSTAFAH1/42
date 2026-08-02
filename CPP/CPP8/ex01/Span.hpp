#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <stdexcept>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Span {
private:
	unsigned int _N;
	std::vector<int> _numbers;

public:
	Span();
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int number);

	template<typename Iterator>
	void addRange(Iterator begin, Iterator end) {
		typename std::iterator_traits<Iterator>::difference_type distance = std::distance(begin, end);
		if (distance < 0 || _numbers.size() + static_cast<unsigned int>(distance) > _N)
			throw FullException();
		_numbers.insert(_numbers.end(), begin, end);
	}

	int shortestSpan() const;
	int longestSpan() const;

	class FullException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class NotEnoughElementsException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

#endif
